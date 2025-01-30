library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bcd2_tb is
end bcd2_tb;

architecture tb of bcd2_tb is
  component bcd2
      port (clk, clr : in std_logic;
            q : out std_logic_vector(7 downto 0));
  end component;

  signal clk, clr : std_logic := '0';
  signal q : std_logic_vector(7 downto 0);
  signal SimEnded : boolean := false;
  
  constant Period : time := 1000 ns;

begin
  bcd2_inst : bcd2 port map (clk, clr, q);
  
  clock_process: process
  begin
    while not SimEnded loop
      clk <= not clk after Period/2;
      wait for Period;
    end loop;
    wait;
  end process clock_process;

  clr <= '1', '0' after 2*Period;
  
  stimulus_process: process
  begin
    wait for 250 * Period;
    SimEnded <= true;
    wait;
  end process stimulus_process;
end tb;
