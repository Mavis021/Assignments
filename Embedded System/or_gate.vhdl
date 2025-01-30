library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity or_gate is
  port(i1, i2 : in std_logic;
       o : out std_logic);
end or_gate;

architecture or_gate_bhv of or_gate is
  begin
    o <= i1 or i2;
end or_gate_bhv;
