const
  pi : real;
  kp_teta : real;
  ki_teta : real;
  
node Regulateur
  (In1: real;
  In2: real;
  In3: real)
returns
  (Out1: real;
  Out2: real);

var
  V14_w_004: real;
  V16_w_006: real;
  V17_w_007: real;
  V18_w_008: real;
  V94_w_004: real;
  V113_w_003: real;
  V114_w_004: real;
  V115_w_005: real;
  V116_w_006: real;
  V117_w_007: real;
  V118_w_008: real;
  V119_w_009: real;
  V120_w_011: real;
  V121_w_012: real;
  V122_w_013: real;
  V123_w_014: real;
  V124_w_015: real;
  V125_w_016: real;

let
  Out1 = (if (In3 > 0.000000E+00) then 1.000000E+00 else V17_w_007);
  Out2 = (if (In3 > 0.000000E+00) then 1.000000E+00 else V18_w_008);
  V14_w_004 = ((pi / 2.000000E+02) * V94_w_004);
  V16_w_006 = (In2 + In1);
  V17_w_007 = ((1.000000E+00 / 2.000000E+00) * V123_w_014);
  V18_w_008 = ((1.000000E+00 / 2.000000E+00) * V122_w_013);
  V94_w_004 = (In2 - In1);
  V113_w_003 = (0.000000E+00 -> (pre V114_w_004));
  V114_w_004 = (V115_w_005 + V113_w_003);
  V115_w_005 = (2.000000E-03 * V14_w_004);
  V116_w_006 = (V125_w_016 + V124_w_015);
  V117_w_007 = ((-V119_w_009) + V120_w_011);
  V118_w_008 = (2.000000E+00 * V117_w_007);
  V119_w_009 = (if (V121_w_012 < 0.000000E+00) then (-V121_w_012) else 
  V121_w_012);
  V120_w_011 = (5.000000E-03 * V16_w_006);
  V121_w_012 = (2.000000E+00 * V116_w_006);
  V122_w_013 = ((-V116_w_006) + V118_w_008);
  V123_w_014 = (V116_w_006 + V118_w_008);
  V124_w_015 = (kp_teta * V14_w_004);
  V125_w_016 = (ki_teta * V114_w_004);
tel

