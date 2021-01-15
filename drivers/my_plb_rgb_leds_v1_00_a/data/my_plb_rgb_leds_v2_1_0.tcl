##############################################################################
## Filename:          C:\Users\Blanzas\Desktop\PR5_SE/drivers/my_plb_rgb_leds_v1_00_a/data/my_plb_rgb_leds_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Tue Jan 28 01:46:16 2020 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "my_plb_rgb_leds" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
