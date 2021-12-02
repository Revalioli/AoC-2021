package pkg is
  constant i_width : integer := 16;
end package;

-- ===[INPUT BLOCK]===

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE std.textio.ALL;
USE work.pkg.ALL;

ENTITY input_block IS
  PORT (clk : IN std_logic; int_input : OUT std_logic_vector(i_width-1 DOWNTO 0) := (OTHERS => 'Z' ));
END ENTITY;


architecture arch_input_block of input_block is
  file input_file : text OPEN read_mode IS "D:\Documents\Programmation\AdventOfVHDL\input_1.txt";
begin

  process (clk)
    variable line_read : line;
    variable int_read : integer;
  begin
    if(Rising_edge(clk)) then

      if endfile(input_file) then
        int_input <= (OTHERS => 'Z');
      else
        readline(input_file, line_read);
        read(line_read, int_read);

        int_input <= std_logic_vector( to_signed(int_read, i_width) );
      end if;

    end if;
  end process;

end;

-- ===[COMPARATOR]===

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

entity comparator is
  port(a : IN std_logic; b : IN std_logic; lt_pre : IN std_logic; gt : OUT std_logic; lt : OUT std_logic; eq : OUT std_logic);
end entity;

-- lt_pre : if '1', then the result can't be greater than (gt can't be '1')

architecture comparator_arch of comparator is
begin
  gt <= (a AND (not b)) AND (NOT lt_pre);
  lt <= ((not a) AND b) OR lt_pre;
  eq <= a XOR b;
end;

-- ===[COMPARATOR - ACCUMULATOR]===

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE work.pkg.ALL;

entity comp_accu is
  port(clk : IN std_logic;
        int_input : IN std_logic_vector(i_width-1 DOWNTO 0);
        result : INOUT integer := 0);
end entity;

architecture comp_accu_1 of comp_accu is

  signal gt_out : std_logic_vector(i_width-1 DOWNTO 0) := (OTHERS => 'Z');


  signal lt_out : std_logic_vector(i_width-1 DOWNTO 0) := (OTHERS => 'Z');
  signal eq_out : std_logic_vector(i_width-1 DOWNTO 0) := (OTHERS => 'Z');

  signal lt_init : std_logic := '0';

  signal previous_integer : std_logic_vector(i_width-1 DOWNTO 0) := (OTHERS => 'Z');

begin

  COMP_GEN : for i in 0 to i_width-1 generate

    MSB : if i = i_width-1 generate
      comp_msb : entity work.comparator(comparator_arch)
        PORT MAP(int_input(i), previous_integer(i), lt_init, gt_out(i), lt_out(i), eq_out(i));
    end generate MSB;

    other_bits : if i < i_width-1 generate
      comp_msb : entity work.comparator(comparator_arch)
        PORT MAP(int_input(i), previous_integer(i), lt_out(i+1), gt_out(i), lt_out(i), eq_out(i));
    end generate other_bits;

  end generate COMP_GEN;


  process (clk)
    variable temp : std_logic := '0';
  begin
    if(Rising_edge(clk)) then

      -- Counter
      temp := '0';
      for i in 0 to gt_out'length-1 loop
        temp := temp OR gt_out(i);
      end loop;

      if temp = '1' then
        result <= result + 1;
      end if;

      -- Integer storage
      previous_integer <= int_input;

    end if;
  end process;

end;


-- ===[Special barrel shifter (part 2)]===

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USe work.pkg.ALL;

entity barrel_shift is
  PORT (clk : IN std_logic;
        int_input : IN std_logic_vector(i_width-1 DOWNTO 0);
        out_sum : OUT std_logic_vector(i_width-1 DOWNTO 0));
end entity;

architecture barrel_shift_arch of barrel_shift is

  SIGNAL A, B, C : std_logic_vector(i_width-1 DOWNTO 0) := (OTHERS => 'Z');

begin

  process (clk)
  begin
    if(Rising_edge(clk)) then
      C <= B;
      B <= A;
      A <= int_input;
    end if;
  end process;

  process(A, B, C)
  begin
    out_sum <= std_logic_vector(to_unsigned(
        to_integer(unsigned(A)) + to_integer(unsigned(B)) + to_integer(unsigned(C))
    , i_width));
  end process;

end;


-- ===[BENCH]===

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE work.pkg.ALL;

entity bench is
end entity;

architecture archi_1 of bench is
  constant half_period : Time := 50 ns;
  signal clk : std_logic;

  signal int_input : std_logic_vector(i_width-1 DOWNTO 0);

  signal counter : integer;
begin

  process
  begin
    clk <= '1';
    wait for half_period;
    clk <= '0';
    wait for half_period;
  end process;

  input_b : entity work.input_block(arch_input_block)
    GENERIC MAP (width)
    PORT MAP (clk, int_input);

  comp_accu_b : entity work.comp_accu(comp_accu_1)
    PORT MAP (clk, int_input, counter);

end;

architecture archi_2 of bench is
  constant half_period : Time := 50 ns;
  signal clk : std_logic;

  signal int_input : std_logic_vector(i_width-1 DOWNTO 0);
  signal out_sum : std_logic_vector(i_width-1 DOWNTO 0);

  signal counter : integer;
begin

  process
  begin
    clk <= '1';
    wait for half_period;
    clk <= '0';
    wait for half_period;
  end process;

  input_b : entity work.input_block(arch_input_block)
    GENERIC MAP (width)
    PORT MAP (clk, int_input);

  shifter : entity work.barrel_shift(barrel_shift_arch)
    PORT MAP(clk, int_input, out_sum);

  comp_accu_b : entity work.comp_accu(comp_accu_1)
    PORT MAP (clk, out_sum, counter);

  -- Faut juste retirer 3 au résultat final pour pas tenir compte des cycles où les valeurs rentrent dans le barrel shifter

end;
