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

entity conv_layer2_conv_2_weights_V_2_0_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_2_0_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "1111", 1 => "1101", 2 to 4=> "0000", 5 => "1101", 6 => "0011", 
    7 => "1111", 8 => "1110", 9 => "0011", 10 => "1100", 11 => "1011", 
    12 to 13=> "0000", 14 => "0011", 15 => "0001", 16 => "0000", 17 => "0001", 
    18 => "1110", 19 => "1111", 20 to 21=> "1110", 22 => "0000", 23 to 24=> "1111", 
    25 => "1101", 26 => "0010", 27 => "1110", 28 => "0001", 29 to 31=> "0000", 
    32 => "0100", 33 => "0010", 34 => "0000", 35 => "1111", 36 => "0001", 
    37 => "1110", 38 => "0100", 39 => "1110", 40 to 41=> "1111", 42 => "0001", 
    43 => "0010", 44 to 45=> "0000", 46 => "1101", 47 => "1110", 48 => "0011", 
    49 => "0010", 50 => "1111", 51 => "0000", 52 to 53=> "1111", 54 => "0000", 
    55 => "1111", 56 => "1110", 57 => "0010", 58 => "0011", 59 to 60=> "0010", 
    61 => "0011", 62 => "1110", 63 to 66=> "0001", 67 => "1101", 68 => "0001", 
    69 to 71=> "0000", 72 => "1111", 73 => "1101", 74 to 77=> "0010", 78 => "0001", 
    79 to 80=> "0010", 81 to 82=> "0001", 83 => "1101", 84 => "1111", 85 => "1110", 
    86 => "1101", 87 => "1110", 88 => "0000", 89 => "1101", 90 => "0001", 
    91 => "1101", 92 => "0001", 93 => "1101", 94 => "1110", 95 => "0010" );

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

entity conv_layer2_conv_2_weights_V_2_0 is
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

architecture arch of conv_layer2_conv_2_weights_V_2_0 is
    component conv_layer2_conv_2_weights_V_2_0_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_2_0_rom_U :  component conv_layer2_conv_2_weights_V_2_0_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


