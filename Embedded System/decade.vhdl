library ieee;
use ieee.std_logic_1164.all;

entity decade is
  port(clk, rst : in std_logic;
       q : out std_logic_vector(3 downto 0));
end decade;

architecture decade_struct of decade is
  component tff
    port(t, clk, rst : in std_logic;
         q, qp : out std_logic);
  end component;

  signal q_int, qp_int : std_logic_vector(3 downto 0);
  signal rst_tmp, rst_int : std_logic;

begin
  rst_tmp <= rst or (q_int(1) and q_int(3));
  rst_int <= '0' when rst_tmp /= '1' else '1';
  
  tff1 : tff port map('1', clk, rst_int, q_int(0), qp_int(0));

  tff_s : for i in 1 to 3 generate
    tff_inst : tff port map('1', qp_int(i-1), rst_int, q_int(i), qp_int(i));
  end generate tff_s;

  q <= q_int;
  
end decade_struct;
