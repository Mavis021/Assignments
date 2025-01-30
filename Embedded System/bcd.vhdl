library ieee;
use ieee.std_logic_1164.all;

entity bcd is
  port (clk, en, ld : in std_logic;
        d : in std_logic_vector(3 downto 0);
        q : out std_logic_vector(3 downto 0));
end bcd;

architecture bcd_struct of bcd is
  component dff
    port (d, clk, rst : in std_logic;
          q, qp : out std_logic);
  end component;

  component mux_2_1
    port (x1, x2, s : in std_logic;
          y : out std_logic);
  end component;

  signal d_int, d_tmp, d_count : std_logic_vector(3 downto 0) := "0000";
  signal q_int : std_logic_vector(3 downto 0) := "0000";
  signal qp_int : std_logic_vector(3 downto 0) := "1111";
  signal ld_int : std_logic;

begin
  ld_int <= ld;
            
  d_tmp(0) <= en; 
  d_count(0) <= d_tmp(0) xor q_int(0);
  mux1 : mux_2_1 port map(d_count(0), d(0), ld_int, d_int(0));
  dff1 : dff port map(d_int(0), clk, '0', q_int(0), qp_int(0));
  
  dffs : for i in 1 to 3 generate
    d_tmp(i) <= d_tmp(i-1) and q_int(i-1);
    d_count(i) <= d_tmp(i) xor q_int(i);
    mux_inst : mux_2_1 port map(d_count(i), d(i), ld_int, d_int(i));
    dff_inst : dff port map(d_int(i), clk, '0', q_int(i), qp_int(i));
  end generate;

  q <= q_int;
                            
end bcd_struct;
