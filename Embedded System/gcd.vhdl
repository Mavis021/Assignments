library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity gcd is
  port(start, clk, clr : in std_logic;
       x, y : in unsigned(3 downto 0);
       d : out unsigned(3 downto 0));
end gcd;

architecture bhv of gcd is

  TYPE state is (idle, init, check, update_x, update_y, get);
  signal ps : state := idle;
  signal ns : state;
  
begin
  p1 : process(clk, clr)
  begin
    if(clr = '1') then
      ps <= idle;
    elsif (clk'event and clk = '1') then
      ps <= ns;
    end if;
  end process;

  p2 : process(x, y, ps, start)
    variable xt, yt : unsigned(3 downto 0);
  begin
    case ps is
      when idle =>
        if(start ='0') then
          ns <= idle;
        else
          ns <= init;
        end if;
      when init =>
        xt := x;
        yt := y;
        ns <= check;
      when check =>
        if(xt > yt) then
          ns <= update_x;
        elsif (Xt < yt) then
          ns <= update_y;
        else
          ns <= get;
        end if;
      when get =>
        d <= xt;
        ns <= idle;
      when update_x =>
        xt := xt - yt;
        ns <= check;
      when update_y =>
        yt := yt - xt;
        ns <= check;
    end case;
  end process;
end bhv;
