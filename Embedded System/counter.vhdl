library ieee;
use ieee.std_logic_1164.all;

entity counter is
  generic (n : integer := 4);
  
  port(clk, rst : in std_logic;
       q : out std_logic_vector(n-1 downto 0));
end counter;

architecture counter_struct of counter is
  component tff
    port(t, clk, rst : in std_logic;
         q, qp : out std_logic);
  end component;

  signal q_int, t_int : std_logic_vector(n-1 downto 0);

begin
  tff1 : tff port map('1', clk, rst, q_int(0));
  t_int(0) <= q_int(0);
  
  tff_s : for i in 1 to n-2 generate
    tff_inst : tff port map(t_int(i-1), clk, rst, q_int(i));
    t_int(i) <= t_int(i-1) and q_int(i);
  end generate tff_s;
  
  tff_n : tff port map(t_int(n-2), clk, rst, q_int(n-1));
  q <= q_int;
  
end counter_struct;
