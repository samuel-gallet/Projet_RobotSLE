/********
* ec2c version 0.65
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : Regulateur 
* to be used with : Regulateur.c 
********/
#ifndef _Regulateur_EC2C_H_FILE
#define _Regulateur_EC2C_H_FILE
/* This program needs external declarations */
#include "Regulateur_ext.h"
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: Regulateur 3 2
//IN: _real In1
//IN: _real In2
//IN: _real In3
//OUT: _real Out1
//OUT: _real Out2
#ifndef _Regulateur_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Regulateur_I_In1(_real);
extern void Regulateur_I_In2(_real);
extern void Regulateur_I_In3(_real);
/*-------- Reset procedure -----------*/
extern void Regulateur_reset();
/*--------Context init = context reset --------*/
#define Regulateur_init Regulateur_reset
/*-------- Step procedure -----------*/
extern void Regulateur_step();
#endif
#endif
