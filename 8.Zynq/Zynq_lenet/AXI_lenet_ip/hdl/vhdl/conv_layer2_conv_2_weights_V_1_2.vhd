-- ==============================================================
-- File generated on Tue Jun 02 21:19:38 EEST 2020
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity conv_layer2_conv_2_weights_V_1_2_rom is 
    generic(
             DWIDTH     : integer := 4; 
             AWIDTH     : integer := 7; 
             MEM_SIZE    : integer := 96
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of conv_layer2_conv_2_weights_V_1_2_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "1111", 1 to 2=> "1110", 3 => "0000", 4 => "1111", 5 => "0010", 
    6 => "0000", 7 => "1111", 8 => "0001", 9 => "1111", 10 => "1110", 
    11 => "1011", 12 => "0001", 13 => "1110", 14 => "0100", 15 => "1111", 
    16 => "0010", 17 => "1101", 18 => "0000", 19 => "0001", 20 => "0000", 
    21 => "1100", 22 => "0001", 23 => "1101", 24 => "1100", 25 => "1110", 
    26 => "0010", 27 => "0000", 28 => "1111", 29 => "0010", 30 => "1101", 
    31 => "0010", 32 => "0001", 33 => "1111", 34 => "0001", 35 => "1111", 
    36 to 39=> "0000", 40 => "0010", 41 => "0011", 42 => "0001", 43 => "1111", 
    44 => "0100", 45 => "1111", 46 => "0001", 47 => "0011", 48 => "1111", 
    49 => "1100", 50 => "1111", 51 => "1110", 52 to 53=> "0000", 54 to 55=> "0010", 
    56 => "0011", 57 => "1111", 58 => "1101", 59 => "1111", 60 => "0000", 
    61 => "0001", 62 => "0011", 63 => "0010", 64 => "0001", 65 to 67=> "1101", 
    68 => "0010", 69 => "1111", 70 => "0010", 71 to 72=> "1101", 73 => "1111", 
    74 => "0011", 75 => "0001", 76 => "1101", 77 => "1110", 78 => "0010", 
    79 to 81=> "0000", 82 => "1111", 83 => "0001", 84 to 85=> "0010", 86 => "1110", 
    87 => "1101", 88 to 89=> "0010", 90 => "1101", 91 to 92=> "0000", 93 => "1110", 
    94 => "1111", 95 => "1101" );

attribute syn_rom_style : string;
attribute syn_rom_style of mem : signal is "select_rom";
attribute ROM_STYLE : string;
attribute ROM_STYLE of mem : signal is "distributed";

begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity conv_layer2_conv_2_weights_V_1_2 is
    generic (
        DataWidth : INTEGER := 4;
        AddressRange : INTEGER := 96;
        AddressWidth : INTEGER := 7);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of conv_layer2_conv_2_weights_V_1_2 is
    component conv_layer2_conv_2_weights_V_1_2_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_1_2_rom_U :  component conv_layer2_conv_2_weights_V_1_2_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


