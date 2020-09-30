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

entity conv_layer2_conv_2_weights_V_1_1_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_1_1_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 1=> "0000", 2 => "0001", 3 => "1101", 4 => "0010", 5 => "1111", 
    6 => "1101", 7 => "0011", 8 => "1100", 9 => "0000", 10 => "1111", 
    11 => "1110", 12 => "0010", 13 => "0000", 14 to 15=> "0001", 16 => "0010", 
    17 to 19=> "1111", 20 => "1101", 21 => "0010", 22 to 24=> "1111", 25 => "0001", 
    26 to 27=> "1110", 28 => "0000", 29 => "0010", 30 => "1111", 31 => "1110", 
    32 => "0000", 33 to 34=> "0010", 35 to 36=> "0001", 37 => "1110", 38 => "1111", 
    39 to 40=> "0001", 41 => "0011", 42 => "1110", 43 => "0001", 44 => "0010", 
    45 => "0011", 46 => "1111", 47 => "0001", 48 => "1110", 49 => "1111", 
    50 => "0001", 51 => "0000", 52 => "0001", 53 => "1111", 54 to 56=> "0001", 
    57 to 58=> "1111", 59 => "0001", 60 to 61=> "0000", 62 => "0100", 63 to 65=> "1111", 
    66 => "1101", 67 => "1110", 68 => "0011", 69 => "0010", 70 => "0011", 
    71 => "0010", 72 => "1101", 73 to 74=> "0011", 75 => "1101", 76 => "1111", 
    77 => "0001", 78 => "0011", 79 => "0000", 80 => "1110", 81 => "0000", 
    82 => "0001", 83 => "0000", 84 => "1110", 85 => "0010", 86 => "0000", 
    87 => "0001", 88 => "0000", 89 => "1110", 90 => "0001", 91 => "0011", 
    92 to 93=> "0001", 94 => "1100", 95 => "0001" );

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

entity conv_layer2_conv_2_weights_V_1_1 is
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

architecture arch of conv_layer2_conv_2_weights_V_1_1 is
    component conv_layer2_conv_2_weights_V_1_1_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_1_1_rom_U :  component conv_layer2_conv_2_weights_V_1_1_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


