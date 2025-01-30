library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity xor_gate is
  port(i1, i2 : in std_logic;
       o : out std_logic);
end xor_gate;

architecture xor_gate_bhv of xor_gate is
  component nor_gate
    port(i1, i2 : in std_logic;
         o : out std_logic);
  end component;

  signal t1, t2, t3, t4: std_logic;
  begin
    nor1 : nor_gate port map (i1 => i1, i2 => i1, o => t1);
    nor2 : nor_gate port map (i1 => i2, i2 => i2, o => t2);
    nor3 : nor_gate port map (i1 => i1, i2 => i2, o => t3);
    nor4 : nor_gate port map (i1 => t1, i2 => t2, o => t4);
    nor5 : nor_gate port map (i1 => t3, i2 => t4, o => o);
        
end xor_gate_bhv;
