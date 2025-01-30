library ieee;
use ieee.std_logic_1164.all;

entity johnson is
  generic (n : integer := 4);
  
  port(clk, rst : in std_logic;
       q : out std_logic_vector(n-1 downto 0));
end johnson;

architecture johnson_struct of johnson is
  component dff
    port(d, clk, rst : in std_logic;
         q, qp : out std_logic);
  end component;

  signal q_int, qp_int : std_logic_vector(n-1 downto 0);

begin
  dff1 : dff port map(qp_int(n-1), clk, rst, q_int(0), qp_int(0));
  
  dff_s : for i in 1 to n-2 generate
    dff_inst : dff port map(q_int(i-1), clk, rst, q_int(i), qp_int(i));
  end generate dff_s;
  
  dff_n : dff port map(q_int(n-2), clk, rst, q_int(n-1), qp_int(n-1));
  q <= q_int;
end johnson_struct;
