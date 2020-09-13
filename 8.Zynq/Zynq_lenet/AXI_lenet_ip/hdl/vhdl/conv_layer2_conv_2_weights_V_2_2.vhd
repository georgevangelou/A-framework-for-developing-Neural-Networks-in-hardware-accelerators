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

entity conv_layer2_conv_2_weights_V_2_2_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_2_2_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "0000", 1 => "0001", 2 => "1111", 3 => "0001", 4 => "1110", 
    5 => "0010", 6 => "0001", 7 => "1101", 8 to 9=> "1110", 10 to 11=> "0000", 
    12 => "1111", 13 => "0001", 14 to 17=> "0000", 18 => "1101", 19 to 21=> "0000", 
    22 => "1111", 23 => "0000", 24 => "0010", 25 => "1110", 26 => "0010", 
    27 => "0001", 28 => "0000", 29 => "1110", 30 => "0000", 31 => "1110", 
    32 => "0000", 33 to 34=> "0001", 35 => "0010", 36 => "1111", 37 => "0010", 
    38 => "1101", 39 to 40=> "0000", 41 => "1111", 42 => "0001", 43 to 47=> "0000", 
    48 => "1111", 49 => "1110", 50 => "0001", 51 => "1111", 52 => "1101", 
    53 => "0011", 54 => "0001", 55 => "1101", 56 => "1110", 57 => "0000", 
    58 => "1111", 59 to 61=> "1110", 62 => "0010", 63 => "0001", 64 to 65=> "1110", 
    66 => "1111", 67 => "1100", 68 => "0000", 69 => "1111", 70 => "0011", 
    71 => "1101", 72 => "1011", 73 => "0000", 74 => "1111", 75 => "1110", 
    76 => "0000", 77 to 78=> "1111", 79 => "1110", 80 => "0000", 81 => "0001", 
    82 => "0010", 83 => "1111", 84 => "0010", 85 => "1101", 86 => "1110", 
    87 => "0001", 88 => "1110", 89 => "1101", 90 => "1111", 91 => "1100", 
    92 => "1110", 93 to 95=> "0000" );

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

entity conv_layer2_conv_2_weights_V_2_2 is
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

architecture arch of conv_layer2_conv_2_weights_V_2_2 is
    component conv_layer2_conv_2_weights_V_2_2_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_2_2_rom_U :  component conv_layer2_conv_2_weights_V_2_2_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


