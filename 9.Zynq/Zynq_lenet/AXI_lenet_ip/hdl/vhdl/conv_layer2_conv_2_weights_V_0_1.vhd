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

entity conv_layer2_conv_2_weights_V_0_1_rom is 
    generic(
             DWIDTH     : integer := 3; 
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


architecture rtl of conv_layer2_conv_2_weights_V_0_1_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "111", 1 => "100", 2 => "111", 3 => "101", 4 => "010", 5 => "110", 
    6 => "001", 7 => "101", 8 => "011", 9 => "110", 10 => "111", 11 => "000", 
    12 => "001", 13 => "010", 14 => "110", 15 => "010", 16 => "000", 17 => "001", 
    18 => "011", 19 => "000", 20 to 22=> "001", 23 => "010", 24 => "000", 25 => "111", 
    26 => "100", 27 => "000", 28 => "111", 29 => "010", 30 => "111", 31 => "000", 
    32 => "111", 33 => "110", 34 => "111", 35 => "000", 36 => "110", 37 => "000", 
    38 => "001", 39 => "111", 40 => "110", 41 to 42=> "001", 43 => "101", 44 => "100", 
    45 => "111", 46 => "100", 47 => "101", 48 => "011", 49 => "101", 50 => "001", 
    51 to 52=> "010", 53 => "111", 54 => "000", 55 to 56=> "110", 57 => "000", 58 => "101", 
    59 to 60=> "000", 61 => "110", 62 to 64=> "010", 65 => "100", 66 => "010", 67 => "000", 
    68 => "001", 69 => "011", 70 => "000", 71 => "111", 72 => "000", 73 => "101", 
    74 to 76=> "000", 77 to 78=> "111", 79 to 80=> "110", 81 => "011", 82 => "110", 83 => "011", 
    84 => "110", 85 => "111", 86 => "000", 87 to 88=> "001", 89 => "111", 90 => "010", 
    91 => "000", 92 to 93=> "010", 94 => "000", 95 => "001" );

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

entity conv_layer2_conv_2_weights_V_0_1 is
    generic (
        DataWidth : INTEGER := 3;
        AddressRange : INTEGER := 96;
        AddressWidth : INTEGER := 7);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of conv_layer2_conv_2_weights_V_0_1 is
    component conv_layer2_conv_2_weights_V_0_1_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_0_1_rom_U :  component conv_layer2_conv_2_weights_V_0_1_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


