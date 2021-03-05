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

entity conv_layer2_conv_2_weights_V_1_0_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_1_0_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "1110", 1 to 3=> "0000", 4 => "1110", 5 => "1100", 6 => "0100", 
    7 => "1111", 8 => "0010", 9 => "0011", 10 to 11=> "0010", 12 => "0001", 
    13 => "0000", 14 => "0011", 15 => "0000", 16 => "1111", 17 => "1101", 
    18 => "0011", 19 => "1110", 20 to 22=> "1111", 23 => "1110", 24 to 25=> "0000", 
    26 to 27=> "1110", 28 => "1111", 29 => "0010", 30 => "0000", 31 => "1101", 
    32 to 33=> "0000", 34 => "1111", 35 => "0000", 36 => "1110", 37 to 39=> "0001", 
    40 to 41=> "1111", 42 to 43=> "0001", 44 => "1110", 45 => "0000", 46 => "0010", 
    47 => "1111", 48 => "0011", 49 to 50=> "0010", 51 => "0001", 52 => "1111", 
    53 => "0001", 54 => "0000", 55 => "0010", 56 => "0001", 57 => "1111", 
    58 => "1110", 59 to 60=> "0000", 61 => "0001", 62 to 63=> "0010", 64 to 65=> "0000", 
    66 => "1111", 67 => "1100", 68 => "0000", 69 => "1110", 70 => "0000", 
    71 => "0001", 72 => "1110", 73 => "1101", 74 => "0001", 75 => "1110", 
    76 => "0011", 77 => "1110", 78 => "0000", 79 => "0001", 80 => "1111", 
    81 => "1110", 82 => "0000", 83 => "1110", 84 => "1111", 85 => "0000", 
    86 to 88=> "1110", 89 => "0001", 90 => "0000", 91 => "1111", 92 => "0000", 
    93 => "1110", 94 => "0010", 95 => "0001" );

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

entity conv_layer2_conv_2_weights_V_1_0 is
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

architecture arch of conv_layer2_conv_2_weights_V_1_0 is
    component conv_layer2_conv_2_weights_V_1_0_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_1_0_rom_U :  component conv_layer2_conv_2_weights_V_1_0_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


