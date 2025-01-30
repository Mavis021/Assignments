library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity nor_gate is
  port(i1, i2 : in std_logic;
       o : out std_logic);
end nor_gate;

architecture nor_gate_bhv of nor_gate is
  begin
    o <= i1 nor i2;
end nor_gate_bhv;
