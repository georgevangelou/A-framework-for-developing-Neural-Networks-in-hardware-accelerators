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

entity conv_layer2_conv_2_weights_V_0_0_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_0_0_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "1011", 1 => "1110", 2 => "0011", 3 => "0000", 4 => "1110", 
    5 => "1011", 6 => "1110", 7 => "0010", 8 => "0011", 9 => "0000", 
    10 => "0001", 11 => "0010", 12 => "0000", 13 => "0010", 14 to 15=> "0001", 
    16 => "1110", 17 => "1101", 18 => "0011", 19 => "0001", 20 => "1110", 
    21 => "1111", 22 => "0010", 23 => "0001", 24 => "1101", 25 => "1111", 
    26 => "1011", 27 => "1111", 28 to 29=> "0001", 30 => "0000", 31 => "0001", 
    32 => "1111", 33 => "1110", 34 => "1111", 35 => "0010", 36 => "1101", 
    37 => "0000", 38 => "1111", 39 => "0000", 40 => "1101", 41 => "1110", 
    42 => "0001", 43 => "1100", 44 => "1111", 45 => "1101", 46 => "1110", 
    47 to 48=> "0000", 49 => "1111", 50 => "0011", 51 to 54=> "0000", 55 => "1110", 
    56 => "1100", 57 => "1111", 58 => "0001", 59 => "1110", 60 => "1011", 
    61 => "1111", 62 => "1110", 63 => "1100", 64 => "0010", 65 => "1111", 
    66 to 67=> "0000", 68 => "0001", 69 => "0000", 70 => "1111", 71 => "0010", 
    72 => "1111", 73 => "0000", 74 => "1110", 75 => "1111", 76 => "0010", 
    77 => "0000", 78 => "0010", 79 => "1101", 80 => "1111", 81 => "0000", 
    82 => "1111", 83 => "0001", 84 => "0000", 85 => "0001", 86 => "0010", 
    87 => "1101", 88 to 89=> "0010", 90 => "1110", 91 => "0010", 92 => "1111", 
    93 => "0000", 94 => "1111", 95 => "0010" );

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

entity conv_layer2_conv_2_weights_V_0_0 is
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

architecture arch of conv_layer2_conv_2_weights_V_0_0 is
    component conv_layer2_conv_2_weights_V_0_0_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_0_0_rom_U :  component conv_layer2_conv_2_weights_V_0_0_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


