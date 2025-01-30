library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity bcd_tb is
end bcd_tb;

architecture tb of bcd_tb is
  component bcd
      port (clk, en, ld : in std_logic;
            d : in std_logic_vector(3 downto 0);
            q : out std_logic_vector(3 downto 0));
  end component;

  signal clk, ld : std_logic := '0';
  signal d, q : std_logic_vector(3 downto 0);
  signal SimEnded : boolean := false;
  
  constant Period : time := 1000 ns;

begin
  bcd_inst : bcd port map (clk, '1', ld , d, q);
  
  clock_process: process
  begin
    while not SimEnded loop
      clk <= not clk after Period/2;
      wait for Period;
    end loop;
    wait;
  end process clock_process;

  d <= "0000";
  ld <= '1', '0' after 2*Period;
  
  stimulus_process: process
  begin
    wait for 50 * Period;
    SimEnded <= true;
    wait;
  end process stimulus_process;
end tb;
