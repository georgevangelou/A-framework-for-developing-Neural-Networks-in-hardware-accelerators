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

entity conv_layer2_conv_2_weights_V_2_1_rom is 
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


architecture rtl of conv_layer2_conv_2_weights_V_2_1_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "0000", 1 => "0001", 2 => "0000", 3 => "1101", 4 => "0000", 
    5 => "0010", 6 to 7=> "1111", 8 => "1110", 9 => "1111", 10 => "1110", 
    11 => "1111", 12 => "0011", 13 to 14=> "1111", 15 => "0001", 16 => "1101", 
    17 => "1111", 18 => "1110", 19 => "1100", 20 => "1101", 21 => "0011", 
    22 => "0001", 23 => "1111", 24 => "0000", 25 => "0001", 26 => "0011", 
    27 to 28=> "0000", 29 to 30=> "1111", 31 => "1101", 32 => "0011", 33 => "0010", 
    34 to 35=> "1101", 36 => "0001", 37 => "0010", 38 => "1101", 39 => "0010", 
    40 => "1110", 41 => "0000", 42 => "0011", 43 to 44=> "0001", 45 => "0011", 
    46 => "1110", 47 => "1111", 48 to 49=> "1110", 50 => "0001", 51 => "0000", 
    52 => "0001", 53 => "1110", 54 => "0001", 55 => "1100", 56 => "0010", 
    57 => "1111", 58 => "0100", 59 to 61=> "0001", 62 => "0010", 63 => "1111", 
    64 => "0010", 65 => "0001", 66 to 67=> "1111", 68 => "0001", 69 => "1111", 
    70 => "1101", 71 => "0011", 72 => "0001", 73 => "0010", 74 => "0000", 
    75 => "0001", 76 => "1101", 77 => "1110", 78 => "0001", 79 to 81=> "0010", 
    82 => "0000", 83 => "1111", 84 => "0000", 85 => "1110", 86 => "1101", 
    87 => "1111", 88 => "0000", 89 => "1111", 90 => "0000", 91 => "0001", 
    92 => "1101", 93 => "1110", 94 => "0010", 95 => "1101" );

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

entity conv_layer2_conv_2_weights_V_2_1 is
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

architecture arch of conv_layer2_conv_2_weights_V_2_1 is
    component conv_layer2_conv_2_weights_V_2_1_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    conv_layer2_conv_2_weights_V_2_1_rom_U :  component conv_layer2_conv_2_weights_V_2_1_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


