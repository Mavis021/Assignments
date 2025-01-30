library ieee;
use ieee.std_logic_1164.all;

entity dff is
  port(d, clk, rst : in std_logic;
       q : out std_logic := '0';
       qp : out std_logic := '1');
end dff;

architecture dff_bhv of dff is
begin
  p1 : process(clk, rst)
  begin
    if(rst = '1') then
      q <= '0';
      qp <= '1';
    elsif(clk'event and clk = '1') then
      q <= d;
      qp <= not d;
    end if;
  end process;
end dff_bhv;
