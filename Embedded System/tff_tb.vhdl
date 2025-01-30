library ieee;
use ieee.std_logic_1164.all;

entity tff_tb is
end tff_tb;

architecture tb of tff_tb is
    component tff
        port (t, clk, rst : in std_logic;
              q, qp : out std_logic);
    end component;

    signal t, rst, clk, q, qp : std_logic := '0';
    constant Period : time := 1000 ns;

begin
    tff_inst : tff port map (t, clk, rst, q, qp);

    clock_process: process
    begin
        for i in 1 to 50 loop
            clk <= not clk;
            wait for Period;
        end loop;
        wait;
    end process clock_process;

    t <= '1', '0' after 4*Period, '1' after 8*Period, '0' after 10*Period, '1' after 20*Period;
    rst <= '1', '0' after 2*Period;
end tb;
