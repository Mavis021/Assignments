library ieee;
use ieee.std_logic_1164.all;

entity bcd2 is
  port (clk, clr : in std_logic;
        q : out std_logic_vector(7 downto 0));
end bcd2;

architecture bcd2_struct of bcd2 is
  component bcd
    port (clk, en, ld : in std_logic;
          d : in std_logic_vector(3 downto 0);
          q : out std_logic_vector(3 downto 0));
  end component;

  signal q_int : std_logic_vector(7 downto 0);
  signal ld1, ld2, en2 : std_logic;

begin
  ld1 <= clr or (q_int(0) and q_int(3));
  ld2 <= clr or (q_int(4) and q_int(7) and q_int(0) and q_int(3));
  en2 <= (q_int(0) and q_int(3));

  bcd_1 : bcd port map(clk, '1', ld1, "0000", q_int(3 downto 0));
  bcd_2 : bcd port map(clk, en2, ld2, "0000", q_int(7 downto 4));

  q <= q_int;

end bcd2_struct;
