node Planificateur
  (In1: real;
  In2: real)
returns
  (Out1: bool);

var
  V6_w_001: bool;
  V9_w_004: bool;
  V11_w_006: bool;
  V12_w_007: bool;
  V53_w_003: bool;
  V54_w_004: bool;
  V55_w_005: bool;
  V56_w_007: bool;
  V57_w_008: bool;
  V58_w_009: bool;
  V59_w_010: bool;
  V60_w_011: bool;
  V61_w_012: bool;

let
  Out1 = (V11_w_006 or V9_w_004);
  V6_w_001 = (false -> (pre Out1));
  V9_w_004 = (if V12_w_007 then false else V6_w_001);
  V11_w_006 = (In2 <= 8.000000E+00);
  V12_w_007 = (V59_w_010 and V57_w_008);
  V53_w_003 = (not V59_w_010);
  V54_w_004 = (if V12_w_007 then false else V57_w_008);
  V55_w_005 = (if Out1 then V61_w_012 else false);
  V56_w_007 = (false -> (pre V54_w_004));
  V57_w_008 = (V58_w_009 or V56_w_007);
  V58_w_009 = (V53_w_003 and V61_w_012);
  V59_w_010 = (In1 >= 5.000000E+01);
  V60_w_011 = (false -> (pre V55_w_005));
  V61_w_012 = (V59_w_010 or V60_w_011);
tel

