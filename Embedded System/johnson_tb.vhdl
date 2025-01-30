library ieee;
use ieee.std_logic_1164.all;

entity johnson_tb is
end johnson_tb;

architecture tb of johnson_tb is
  component johnson
    generic (n : integer);
    port (clk, rst : in std_logic;
          q : out std_logic_vector(3 downto 0));
  end component;

  signal clk, rst : std_logic := '0';
  signal q : std_logic_vector(3 downto 0);
  constant Period : time := 1000 ns;

begin
  johnson_inst : johnson generic map(4) port map (clk, rst, q);
  
  clock_process: process
  begin
    for i in 1 to 50 loop
      clk <= not clk after Period/2;
      wait for Period;
    end loop;
    wait;
  end process clock_process;
  
  rst <= '1', '0' after 2*Period;
end tb;
