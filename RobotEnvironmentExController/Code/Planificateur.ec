node Planificateur
  (In1: real;
  In2: real)
returns
  (Out1: bool;
  bool2: bool;
  bool1: bool);

var
  V9_w_002: bool;
  V12_w_005: bool;
  V14_w_007: bool;
  V15_w_008: bool;
  V63_w_003: bool;
  V64_w_004: bool;
  V65_w_005: bool;
  V66_w_008: bool;
  V67_w_009: bool;
  V68_w_010: bool;
  V69_w_012: bool;

let
  Out1 = (V14_w_007 or V12_w_005);
  bool2 = (false -> (pre V64_w_004));
  bool1 = (false -> (pre V65_w_005));
  V9_w_002 = (false -> (pre Out1));
  V12_w_005 = (if V15_w_008 then false else V9_w_002);
  V14_w_007 = (In2 <= 8.000000E+00);
  V15_w_008 = (V68_w_010 and V66_w_008);
  V63_w_003 = (not V68_w_010);
  V64_w_004 = (if V15_w_008 then false else V66_w_008);
  V65_w_005 = (if Out1 then V69_w_012 else false);
  V66_w_008 = (V67_w_009 or bool2);
  V67_w_009 = (V63_w_003 and V69_w_012);
  V68_w_010 = (In1 >= 5.000000E+01);
  V69_w_012 = (V68_w_010 or bool1);
tel

