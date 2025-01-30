library ieee;
use ieee.std_logic_1164.all;

entity siso_tb is
end siso_tb;

architecture tb of siso_tb is
  component siso
    generic (n : integer);
    port (din, clk, rst : in std_logic;
          dout : out std_logic);
  end component;

  signal din, rst, clk, dout : std_logic := '0';
  constant Period : time := 1000 ns;

begin
  siso_inst : siso generic map(4) port map (din, clk, rst, dout);
  
  clock_process: process
  begin
    for i in 1 to 50 loop
      clk <= not clk;
      wait for Period/2;
    end loop;
    wait;
  end process clock_process;
  
  din <= '0', '1' after 2*Period, '0' after 3*Period, '1' after 4*Period, '0' after 5*Period, '1' after 6*Period, '0' after 7*Period, '1' after 8*Period;
  rst <= '1', '0' after Period;
end tb;
