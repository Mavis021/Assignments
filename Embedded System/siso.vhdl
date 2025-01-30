library ieee;
use ieee.std_logic_1164.all;

entity siso is
  generic (n : integer := 4);
  
  port(din, clk, rst : in std_logic;
       dout : out std_logic);
end siso;

architecture siso_struct of siso is
  component dff
    port(d, clk, rst : in std_logic;
         q, qp : out std_logic);
  end component;

  signal q_int : std_logic_vector(n-2 downto 0);

begin
  dff1 : dff port map(din, clk, rst, q_int(0));
  dff_s : for i in 1 to n-2 generate
    dff_inst : dff port map(q_int(i-1), clk, rst, q_int(i));
  end generate dff_s;
  dff_n : dff port map(q_int(n-2), clk, rst, dout);
end siso_struct;
