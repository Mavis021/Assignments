library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity and_gate is
  port(i1, i2 : in std_logic;
       o : out std_logic);
end and_gate;

architecture and_gate_bhv of and_gate is
  begin
    o <= i1 and i2;
end and_gate_bhv;
