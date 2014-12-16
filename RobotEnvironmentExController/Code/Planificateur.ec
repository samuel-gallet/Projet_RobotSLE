node Planificateur
  (In1: real;
  In2: real)
returns
  (Out1: bool);

var
  V5_w_000: bool;
  V8_w_003: bool;
  V10_w_005: bool;
  V11_w_006: bool;
  V50_w_002: bool;
  V51_w_003: bool;
  V52_w_004: bool;
  V53_w_006: bool;
  V54_w_007: bool;
  V55_w_008: bool;
  V56_w_009: bool;
  V57_w_010: bool;
  V58_w_011: bool;

let
  Out1 = (V10_w_005 or V8_w_003);
  V5_w_000 = (false -> (pre Out1));
  V8_w_003 = (if V11_w_006 then false else V5_w_000);
  V10_w_005 = (In2 <= 2.000000E+01);
  V11_w_006 = (V56_w_009 and V54_w_007);
  V50_w_002 = (not V56_w_009);
  V51_w_003 = (if V11_w_006 then false else V54_w_007);
  V52_w_004 = (if V11_w_006 then false else V58_w_011);
  V53_w_006 = (false -> (pre V51_w_003));
  V54_w_007 = (V55_w_008 or V53_w_006);
  V55_w_008 = (V50_w_002 and V58_w_011);
  V56_w_009 = (In1 >= 5.000000E+01);
  V57_w_010 = (false -> (pre V52_w_004));
  V58_w_011 = (V56_w_009 or V57_w_010);
tel

