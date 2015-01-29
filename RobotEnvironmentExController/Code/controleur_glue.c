

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

/**** CODE GLUE, A MODIFIER/ADAPTER */
/* Ici : inclusion du header Lustre */
#include "Planificateur.h"
#include "Regulateur.h"
#include "string.h"

/***** OSEK : NE PAS MODIFIER */
/* OSEK declarations */
DeclareCounter(SysTimerCnt);
DeclareResource(lcd);
DeclareTask(Regulateur);
DeclareTask(Planificateur);


/**Variables partagées entre les 2 taches**/
_real capteur_detect = 0;
long blancG, blancD;
long noirG, noirD;


/* LEJOS OSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void)
{
  StatusType ercd;

  ercd = SignalCounter(SysTimerCnt); /* Increment OSEK Alarm Counter */
  if(ercd != E_OK)
  {
    ShutdownOS(ercd);
  }
}
/******* FIN OSEK */

/* Initialisation et finalisations OSEK */
void ecrobot_device_initialize() {

	/*
		ICI : on peut mettre du code qui sera appelé automatiquement
		      à l'initialisation de la brique
		(ne rien mettre si pas nécessaire)
	*/
   ecrobot_set_light_sensor_active(NXT_PORT_S1);
   ecrobot_set_light_sensor_active(NXT_PORT_S2);
   ecrobot_init_sonar_sensor(NXT_PORT_S3);


}

void ecrobot_device_terminate() {

	/*
		ICI : on peut mettre du code qui sera appelé automatiquement
		      à la l'extinction de la brique
		(ne rien mettre si pas nécessaire)
	*/
   ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
   ecrobot_set_light_sensor_inactive(NXT_PORT_S2);
   ecrobot_term_sonar_sensor(NXT_PORT_S3);
}

/**
 * Affiche a l'ecran "what var"
 */
void show_var(char* what, int line, int var) {
	GetResource(lcd);
	display_goto_xy(0, line);
	display_string(what);
	display_goto_xy(strlen(what)+1, line);
	display_int(var, 5);
	display_update();
	ReleaseResource(lcd);
}

/**** CODE GLUE, A MODIFIER/ADAPTER */
/*

REMARQUE :

  Comme on doit instancier un seul noeud Lustre, on utilise
l'option -ctx-static du compilateur lus2c, car elle donne
du code plus facile àinterfacer.


On doit se débrouiller pour que NOS initialisations
soient effectuées. Comme on ne veut PAS TOUCHER
une seule ligne au code OSEK, on utilise un kernel_cfg.c
modifié, où une nouvelle fonction, "usr_init()", est
appelée à l'initialisation du système.
Cette fonction doit être définie ici, dans le code glue :
*/

void usr_init(void) {
  // Initialisation du noeud Lustre
  	
  	
	do {
		blancD = ecrobot_get_light_sensor(NXT_PORT_S1);
		blancG = ecrobot_get_light_sensor(NXT_PORT_S2);
		show_var("blanc d", 0, blancD);
		show_var("blanc g", 1, blancG);
	   }
	while (!ecrobot_is_ENTER_button_pressed());
	systick_wait_ms(500);
	display_clear(1);
	do {
		noirD = ecrobot_get_light_sensor(NXT_PORT_S1);
		noirG = ecrobot_get_light_sensor(NXT_PORT_S2);
		show_var("noir d", 0, noirD);
		show_var("noir g", 1, noirG);
	   }
	while (!ecrobot_is_ENTER_button_pressed());
	systick_wait_ms(500);
	display_clear(1);
	
  	Planificateur_init();
  	Regulateur_init();
  	do {
  		show_var("sonar", 5, (int)ecrobot_get_sonar_sensor(NXT_PORT_S3));
  	} while (!ecrobot_is_ENTER_button_pressed());
  	
}


/* Procédures de sorties */
void Regulateur_O_Out1(_real ud){
	show_var("roue droite", 0, (int)(ud * 100 * 0.2));
	nxt_motor_set_speed(NXT_PORT_A, 0, 0);
}
void Regulateur_O_Out2(_real ug){
	show_var("roue gauche", 1, (int)(ug * 100 * 0.2));
	nxt_motor_set_speed(NXT_PORT_B, 0, 0);
}
Planificateur_O_Out1(_boolean b){
	if (b)
		capteur_detect = 1.0;
	else
		capteur_detect = 0.0;
}

Planificateur_O_bool2(_boolean b){
	show_var("bool2", 6, (int)(b));
	display_update();
}

Planificateur_O_bool1(_boolean b){
	show_var("bool1", 7, (int)(b));
	display_update();
}
int i = 0;
/** OSEK : SEUL LE CORPS DE LA TACHE DOIT ETRE MODIFIE/ADAPTE */
TASK(Regulateur)
{

	long sensG, sensD;
	/* --> ICI, ON MET LE CODE QUI CORRESPOND A 1 REACTION */

	/* Positionnement des entrées */
	sensD = ecrobot_get_light_sensor(NXT_PORT_S1);
	sensG = ecrobot_get_light_sensor(NXT_PORT_S2);
   Regulateur_I_In1(((sensG - noirG)*100/(blancG - noirG)));
   Regulateur_I_In2(((sensG - noirG)*100/(blancG - noirG)));
   Regulateur_I_In3(capteur_detect);
   

   show_var("obstacle", 2, (int)capteur_detect);
   show_var("CG", 3, (int)((sensG - noirG)*100/(blancG - noirG)));
   show_var("CD", 4, (int)((sensD - noirD)*100/(blancD - noirD)));
   show_var("sonar", 5, (int)ecrobot_get_sonar_sensor(NXT_PORT_S3));

	/* Appel du step */
   Regulateur_step();

	/* Raffraichit le LCD */
   display_update();

	/* --> FIN DU CODE */


	/* OSEK : FINALISATION TASK, NE PAS TOUCHER */
   TerminateTask();
}

TASK(Planificateur)
{
	/* --> ICI, ON MET LE CODE QUI CORRESPOND A 1 REACTION */

	/* Positionnement des entrées */
	long sensG;
	sensG = ecrobot_get_light_sensor(NXT_PORT_S2);
   Planificateur_I_In1(ecrobot_get_light_sensor(((sensG - noirG)*100/(blancG - noirG))));
   Planificateur_I_In2(ecrobot_get_sonar_sensor(NXT_PORT_S3));
   

	/* Appel du step */
   Planificateur_step();

	/* Raffraichit le LCD */
   display_update();

	/* --> FIN DU CODE */


	/* OSEK : FINALISATION TASK, NE PAS TOUCHER */
   TerminateTask();
}

