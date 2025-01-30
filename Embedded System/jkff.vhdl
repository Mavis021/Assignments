library ieee;
use ieee.std_logic_1164.all;

entity jkff is
  port(j, k, clk, rst : in std_logic;
       q, qp : out std_logic);
end jkff;

architecture jkff_struct of jkff is
  component dff
    port(d, clk, rst : in std_logic;
         q, qp : out std_logic);
  end component;

  signal t1, t2, t3, t4, t5, t6 : std_logic;

begin
  dff_inst : dff port map(d => t6, clk => clk, rst => rst, q => t2, qp => t4);

  t1 <= not k;
  t3 <= t1 and t2;
  t5 <= j and t4;
  t6 <= t3 or t5;

  q <= t2;
  qp <= t4;
end jkff_struct;
