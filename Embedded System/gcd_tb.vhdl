library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity gcd_tb is
end gcd_tb;

architecture df of gcd_tb is
  component gcd
    port(start, clk, clr : in std_logic;
         x, y : in unsigned(3 downto 0);
         d : out unsigned(3 downto 0));
  end component;

  signal start, clk, clr : std_logic := '0';
  signal x, y : unsigned(3 downto 0);
  signal SimEnded : boolean := false;
  
  constant Period : time := 1000 ns;
begin
  gcd_inst : gcd port map(start, clk, clr, x, y);
  
  clock_process: process
  begin
    while not SimEnded loop
      clk <= not clk after Period/2;
      wait for Period;
    end loop;
    wait;
  end process clock_process;
  
  clr <= '1', '0' after 2*Period;
  start <= '0', '1' after 5*Period;
  x <= to_unsigned(5, x'length);
  y <= to_unsigned(10, x'length);
  
  stimulus_process: process
  begin
    wait for 50 * Period;
    SimEnded <= true;
    wait;
  end process stimulus_process;
end df;
