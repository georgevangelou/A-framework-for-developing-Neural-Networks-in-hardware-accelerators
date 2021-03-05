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

entity conv_layer2_conv_2_weights_V_0_2_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_0_2_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 2=> "0001", 3 to 4=> "1111", 5 => "0010", 6 => "1111", 7 => "0001", 
    8 => "0100", 9 => "0001", 10 => "1110", 11 => "0000", 12 => "1101", 
    13 => "1111", 14 => "0010", 15 => "0001", 16 => "1101", 17 => "1111", 
    18 to 19=> "0001", 20 => "1100", 21 => "1110", 22 => "0000", 23 => "0010", 
    24 => "1100", 25 to 27=> "0000", 28 to 29=> "0011", 30 => "0001", 31 => "0010", 
    32 => "1100", 33 => "0001", 34 => "0000", 35 => "0011", 36 => "0000", 
    37 => "1110", 38 => "1111", 39 to 40=> "0000", 41 => "0001", 42 => "0011", 
    43 => "1101", 44 => "1100", 45 => "1110", 46 => "1100", 47 => "0001", 
    48 => "0010", 49 => "1111", 50 to 51=> "0000", 52 => "0001", 53 => "1110", 
    54 => "0001", 55 => "1110", 56 => "0001", 57 => "1111", 58 => "1110", 
    59 => "0010", 60 => "0000", 61 => "1110", 62 to 64=> "0010", 65 => "1101", 
    66 => "1100", 67 => "1101", 68 => "1110", 69 => "0000", 70 => "0001", 
    71 to 72=> "0000", 73 => "0001", 74 to 75=> "0011", 76 => "1111", 77 => "1110", 
    78 => "0010", 79 => "1111", 80 => "0000", 81 => "0001", 82 => "0000", 
    83 to 84=> "0001", 85 => "1111", 86 => "0010", 87 to 89=> "0001", 90 => "1101", 
    91 => "0001", 92 => "1101", 93 to 94=> "1100", 95 => "0001" );

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

entity conv_layer2_conv_2_weights_V_0_2 is
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

architecture arch of conv_layer2_conv_2_weights_V_0_2 is
    component conv_layer2_conv_2_weights_V_0_2_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_0_2_rom_U :  component conv_layer2_conv_2_weights_V_0_2_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


