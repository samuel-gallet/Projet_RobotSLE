/********
* ec2c version 0.65
* c file generated for node : Planificateur 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
#define _Planificateur_EC2C_SRC_FILE
#include "Planificateur.h"
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _In1;
   _real _In2;
   //OUTPUTS
   _boolean _Out1;
   //REGISTERS
   _boolean M23;
   _boolean M23_nil;
   _boolean M20;
   _boolean M20_nil;
   _boolean M17;
   _boolean M17_nil;
   _boolean M14;
} Planificateur_ctx;

// Single Static Context
static Planificateur_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Planificateur_I_In1(_real V){
   ctx._In1 = V;
}
void Planificateur_I_In2(_real V){
   ctx._In2 = V;
}
extern void Planificateur_O_Out1(_boolean);
#ifdef CKCHECK
extern void Planificateur_BOT_Out1();
#endif
/*--------
Internal reset input procedure
--------*/
static void Planificateur_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Planificateur_reset(){
   ctx.M23_nil = _true;
   ctx.M20_nil = _true;
   ctx.M17_nil = _true;
   ctx.M14 = _true;
   Planificateur_reset_input();
}
/*--------
Step procedure
--------*/
void Planificateur_step(){
//LOCAL VARIABLES
   _boolean L3;
   _boolean L7;
   _boolean L11;
   _boolean L13;
   _boolean L12;
   _boolean L10;
   _boolean L19;
   _boolean L9;
   _boolean L6;
   _boolean L22;
   _boolean L5;
   _boolean L2;
   _boolean T23;
   _boolean L21;
   _boolean T20;
   _boolean L18;
   _boolean T17;
//CODE
   L3 = (ctx._In2 <= 2.000000E+01);
   L7 = (ctx._In1 >= 5.000000E+01);
   L11 = (! L7);
   if (ctx.M14) {
      L13 = _false;
   } else {
      L13 = ctx.M17;
   }
   L12 = (L7 || L13);
   L10 = (L11 && L12);
   if (ctx.M14) {
      L19 = _false;
   } else {
      L19 = ctx.M20;
   }
   L9 = (L10 || L19);
   L6 = (L7 && L9);
   if (ctx.M14) {
      L22 = _false;
   } else {
      L22 = ctx.M23;
   }
   if (L6) {
      L5 = _false;
   } else {
      L5 = L22;
   }
   L2 = (L3 || L5);
   Planificateur_O_Out1(L2);
   T23 = L2;
   if (L6) {
      L21 = _false;
   } else {
      L21 = L9;
   }
   T20 = L21;
   if (L6) {
      L18 = _false;
   } else {
      L18 = L12;
   }
   T17 = L18;
   ctx.M23 = T23;
   ctx.M23_nil = _false;
   ctx.M20 = T20;
   ctx.M20_nil = _false;
   ctx.M17 = T17;
   ctx.M17_nil = _false;
   ctx.M14 = ctx.M14 && !(_true);
}
