library ieee;
use ieee.std_logic_1164.all;

entity tff is
  port(t, clk, rst : in std_logic;
       q, qp : out std_logic);
end tff;

architecture tff_struct of tff is
  component dff
    port(d, clk, rst : in std_logic;
         q, qp : out std_logic);
  end component;

  signal t1, t2, t3, t4, t5, t6 : std_logic;

begin
  t1 <= not t;    
  t3 <= t1 and t2;
  t5 <= t and t4;
  t6 <= t3 or t5;

  dff_inst : dff port map(d => t6, clk => clk, rst => rst, q => t2, qp => t4);

  q <= t2;
  qp <= t4;
end tff_struct;
