library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity dff is
  port (d, clk, rst: in std_logic;
        q : out std_logic;
        qp : out std_logic);
end dff;

architecture dff_struct of dff is
  component nand_gate
    port(i1, i2 : in std_logic;
         o : out std_logic);
  end component;

  signal t5, t3, t4, t1 : std_logic;
  signal t6, t2, t8, t7, t9, t10, not_rst : std_logic;

begin
  not_rst <= not rst;
  nand6 : nand_gate port map (t4, t2, t1);
  nand1 : nand_gate port map (clk, t1, t2);
  nand2 : nand_gate port map (clk, t2, t7);
  nand3 : nand_gate port map (t7, t7, t8);
  nand4 : nand_gate port map (t8, t4, t3);
  nand5 : nand_gate port map (t3, d, t4);
  nand7 : nand_gate port map (t2, t6, t5);
  nand8 : nand_gate port map (t3, t5, t9);
  nand9 : nand_gate port map (t9, t9, t10);
  nand10 : nand_gate port map (t10, not_rst, t6);
  q <= '0' when rst = '1' else t5;
  qp <= t6;

end dff_struct;
