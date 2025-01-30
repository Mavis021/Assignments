library ieee;
use ieee.std_logic_1164.all;

entity counter_tb is
end counter_tb;

architecture tb of counter_tb is
  component counter
    generic (n : integer);
    port (clk, rst : in std_logic;
          q : out std_logic_vector(3 downto 0));
  end component;

  signal clk, rst : std_logic := '0';
  signal q : std_logic_vector(3 downto 0);
  constant Period : time := 1000 ns;

begin
  counter_inst : counter generic map(4) port map (clk, rst, q);
  
  clock_process: process
  begin
    for i in 1 to 50 loop
      clk <= not clk;
      wait for Period/2;
    end loop;
    wait;
  end process clock_process;
  
  rst <= '1', '0' after 2*Period;
end tb;
