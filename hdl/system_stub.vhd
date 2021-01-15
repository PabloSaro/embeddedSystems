-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    RX : in std_logic;
    TX : out std_logic;
    rst_plb : in std_logic;
    S_pin : out std_logic_vector(0 to 3);
    R : in std_logic_vector(0 to 3);
    red : out std_logic;
    blue : out std_logic;
    green : out std_logic;
    lcd_data_out : out std_logic_vector(7 downto 0);
    lcd_reset2 : out std_logic;
    lcd_reset : out std_logic;
    lcd_row_clk : out std_logic;
    lcd_row_serial : out std_logic;
    lcd_col_clk : out std_logic;
    lcd_col_serial : out std_logic;
    Clk_pin : in std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      RX : in std_logic;
      TX : out std_logic;
      rst_plb : in std_logic;
      S_pin : out std_logic_vector(0 to 3);
      R : in std_logic_vector(0 to 3);
      red : out std_logic;
      blue : out std_logic;
      green : out std_logic;
      lcd_data_out : out std_logic_vector(7 downto 0);
      lcd_reset2 : out std_logic;
      lcd_reset : out std_logic;
      lcd_row_clk : out std_logic;
      lcd_row_serial : out std_logic;
      lcd_col_clk : out std_logic;
      lcd_col_serial : out std_logic;
      Clk_pin : in std_logic
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      RX => RX,
      TX => TX,
      rst_plb => rst_plb,
      S_pin => S_pin,
      R => R,
      red => red,
      blue => blue,
      green => green,
      lcd_data_out => lcd_data_out,
      lcd_reset2 => lcd_reset2,
      lcd_reset => lcd_reset,
      lcd_row_clk => lcd_row_clk,
      lcd_row_serial => lcd_row_serial,
      lcd_col_clk => lcd_col_clk,
      lcd_col_serial => lcd_col_serial,
      Clk_pin => Clk_pin
    );

end architecture STRUCTURE;

