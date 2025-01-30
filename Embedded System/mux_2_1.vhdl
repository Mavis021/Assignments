library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mux_2_1 is
  port (x1, x2, s: in std_logic;
        y : out std_logic);
end mux_2_1;

architecture mux_2_1_df of mux_2_1 is
begin
  y <= x1 when s = '0' else
       x2 when s = '1';
end mux_2_1_df;
