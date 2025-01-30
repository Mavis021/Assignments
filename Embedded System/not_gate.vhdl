library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity not_gate is
  port(i : in std_logic;
       o : out std_logic);
end not_gate;

architecture not_gate_bhv of not_gate is
  begin
    o <= not i;
end not_gate_bhv;
