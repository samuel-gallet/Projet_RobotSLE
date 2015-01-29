/********
* ec2c version 0.65
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : Planificateur 
* to be used with : Planificateur.c 
********/
#ifndef _Planificateur_EC2C_H_FILE
#define _Planificateur_EC2C_H_FILE
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
//MODULE: Planificateur 2 3
//IN: _real In1
//IN: _real In2
//OUT: _boolean Out1
//OUT: _boolean bool2
//OUT: _boolean bool1
#ifndef _Planificateur_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Planificateur_I_In1(_real);
extern void Planificateur_I_In2(_real);
/*-------- Reset procedure -----------*/
extern void Planificateur_reset();
/*--------Context init = context reset --------*/
#define Planificateur_init Planificateur_reset
/*-------- Step procedure -----------*/
extern void Planificateur_step();
#endif
#endif
