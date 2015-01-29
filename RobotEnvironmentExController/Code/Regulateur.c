/********
* ec2c version 0.65
* c file generated for node : Regulateur 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _Regulateur_EC2C_SRC_FILE
#include "Regulateur.h"
/*--------
 * the following ``constants'' must be defined:
extern _real pi;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _In1;
   _real _In2;
   _real _In3;
   //OUTPUTS
   _real _Out1;
   _real _Out2;
   //REGISTERS
   _real M25;
   _boolean M25_nil;
   _boolean M23;
} Regulateur_ctx;

// Single Static Context
static Regulateur_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Regulateur_I_In1(_real V){
   ctx._In1 = V;
}
void Regulateur_I_In2(_real V){
   ctx._In2 = V;
}
void Regulateur_I_In3(_real V){
   ctx._In3 = V;
}
extern void Regulateur_O_Out1(_real);
extern void Regulateur_O_Out2(_real);
#ifdef CKCHECK
extern void Regulateur_BOT_Out1();
extern void Regulateur_BOT_Out2();
#endif
/*--------
Internal reset input procedure
--------*/
static void Regulateur_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Regulateur_reset(){
   ctx.M25_nil = _true;
   ctx.M23 = _true;
   Regulateur_reset_input();
}
/*--------
Step procedure
--------*/
void Regulateur_step(){
//LOCAL VARIABLES
   _boolean L4;
   _real L8;
   _real L18;
   _real L21;
   _real L17;
   _real L15;
   _real L22;
   _real L14;
   _real L12;
   _real L26;
   _real L11;
   _real L33;
   _boolean L32;
   _real L34;
   _real L31;
   _real L30;
   _real L37;
   _real L35;
   _real L29;
   _real L28;
   _real L10;
   _real L7;
   _real L3;
   _real L40;
   _real L43;
   _real L42;
   _real L41;
   _real L39;
   _real T25;
//CODE
   L4 = (ctx._In3 != 0.000000E+00);
   L8 = (1.000000E+00 / 2.000000E+00);
   L18 = (pi / 2.000000E+02);
   L21 = (ctx._In2 - ctx._In1);
   L17 = (L18 * L21);
   L15 = (2.000000E-03 * L17);
   if (ctx.M23) {
      L22 = 0.000000E+00;
   } else {
      L22 = ctx.M25;
   }
   L14 = (L15 + L22);
   L12 = (2.000000E-01 * L14);
   L26 = (4.000000E-01 * L17);
   L11 = (L12 + L26);
   L33 = (2.000000E+00 * L11);
   L32 = (L33 < 0.000000E+00);
   L34 = (- L33);
   if (L32) {
      L31 = L34;
   } else {
      L31 = L33;
   }
   L30 = (- L31);
   L37 = (ctx._In2 + ctx._In1);
   L35 = (5.000000E-03 * L37);
   L29 = (L30 + L35);
   L28 = (2.000000E+00 * L29);
   L10 = (L11 + L28);
   L7 = (L8 * L10);
   if (L4) {
      L3 = 1.000000E+00;
   } else {
      L3 = L7;
   }
   Regulateur_O_Out1(L3);
   L40 = (- 1.000000E+00);
   L43 = (- L11);
   L42 = (L43 + L28);
   L41 = (L8 * L42);
   if (L4) {
      L39 = L40;
   } else {
      L39 = L41;
   }
   Regulateur_O_Out2(L39);
   T25 = L14;
   ctx.M25 = T25;
   ctx.M25_nil = _false;
   ctx.M23 = ctx.M23 && !(_true);
}
