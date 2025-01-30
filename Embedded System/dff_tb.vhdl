library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity dff_tb is
end dff_tb;

architecture tb of dff_tb is
    component dff
        port (d, clk, rst : in std_logic;
              q, qp : out std_logic);
    end component;

    signal d, rst, q, qp : std_logic;
    signal clk : std_logic := '0';
    signal SimEnded : boolean := false;

    constant Period : time := 1000 ns;

begin
    dut : dff port map (d, clk, rst, q, qp);

    clock_process: process
    begin
        while not SimEnded loop
            clk <= not clk after Period/2;
            wait for Period;
        end loop;
        wait;
    end process clock_process;

    d <= '1', '0' after 3*Period, '1' after 5*Period, '0' after 10*Period;
    rst <= '1', '0' after Period;

    stimulus_process: process
    begin
        wait for 100 * Period;
        SimEnded <= true;
        wait;
    end process stimulus_process;
end tb;
