/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */

#include <stdio.h>
#include<stdlib.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "teclado.h"
#include "my_lcd.h"
//#include "my_lcd_selftest.h"
#include "my_plb_rgb_leds.h"


//#define int TAM_ARRAY = 4;



typedef int Array[4];


#define BASE_ADDRESS_LCD 0XC5000000
#define CLEAR_DISPLAY_CMD 0x00000001
#define RETURN_HOME_CMD 0x00000002
#define WRITE_CMD 0x00000200
#define FIRST_ROW 0x00000080
#define SECOND_ROW 0x000000C0

void LCD_enviarCMD(Xuint32 cmd) {
	while (MY_LCD_mWriteFIFOFull ( BASE_ADDRESS_LCD)) {
	}// Comprobamos que la FIFO no est� llena
	MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, cmd ); // Escribimos el comando en la FIFO
}

void LCD_inicializa () {
MY_LCD_mResetWriteFIFO ( BASE_ADDRESS_LCD );
LCD_enviarCMD ( CLEAR_DISPLAY_CMD );
LCD_enviarCMD ( RETURN_HOME_CMD ); // moverse al comienzo de la pantalla LCD
LCD_enviarCMD ( WRITE_CMD ); // primera escritura
}

void print_fin_partida(int turno){
	  LCD_inicializa();
	if (turno == 10){
		  LCD_enviarCMD ( WRITE_CMD + 'L' );
		  LCD_enviarCMD ( WRITE_CMD + 'O' );
		  LCD_enviarCMD ( WRITE_CMD + 'S' );
		  LCD_enviarCMD ( WRITE_CMD + 'E' );
		  LCD_enviarCMD ( WRITE_CMD + '!' );

	}
	else{
		  LCD_enviarCMD ( WRITE_CMD + 'W' );
		  LCD_enviarCMD ( WRITE_CMD + 'I' );
		  LCD_enviarCMD ( WRITE_CMD + 'N' );
		  LCD_enviarCMD ( WRITE_CMD + '!' );
		  LCD_enviarCMD ( WRITE_CMD + '!' );
	}
	  LCD_enviarCMD ( WRITE_CMD );
	  LCD_enviarCMD ( 0x80000000);

}
void print_turnos(int turno){
		// Xuint32 c = '0' + turno + WRITE_CMD  ;
	  char c = '0' + turno;
	  LCD_inicializa();
	  LCD_enviarCMD ( WRITE_CMD + 'T' );
	  LCD_enviarCMD ( WRITE_CMD + 'U' );
	  LCD_enviarCMD ( WRITE_CMD + 'R' );
	  LCD_enviarCMD ( WRITE_CMD + 'N' );
	  LCD_enviarCMD ( WRITE_CMD + 'O' );
	  LCD_enviarCMD ( WRITE_CMD + ' ' );
	  LCD_enviarCMD ( WRITE_CMD + c );
	  LCD_enviarCMD ( WRITE_CMD );
	  LCD_enviarCMD ( 0x80000000);//1 en el bit 31 para activar el banner
	 // MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, c );

	 // MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, 0x80000000);
}

int pintar(int x) {
	switch (x) {
	case 1:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//B
		break;
	case 2:

		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
		/*case -1342177280 : x=3;
		 break;*/
	case 4:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 5:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 10);//B
		break;
	case 6:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 102);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 204);//B
		break;
	case 7:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 102);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,51);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 8:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 9:

		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,10);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//B
		break;
	case 10:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 11:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,50);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 12:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,10);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 13:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,255);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//B
		break;
	case 14:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,255);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 15:
		MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,255);//G
		MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//B
		break;
	default:
		x = 0;
		break;
	}
}

int numerar(Xuint32 reg) {
	int x;
	switch (reg) {
	case -1073741824:
		x = 1;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//B
		break;
	case -1342177280:
		x = 2;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
		/*case -1342177280 : x=3;
		 break;*/
	case -805306368:
		x = 4;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case -1879048192:
		x = 5;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 10);//B
		break;
	case -2147483648:
		x = 6;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 102);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 204);//B
		break;
	case -536870912:
		x = 7;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 102);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,51);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 1610612736:
		x = 8;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 1342177280:
		x = 9;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,10);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//B
		break;
	case -268435456:
		x = 10;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,0);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 536870912:
		x = 11;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,50);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 268435456:
		x = 12;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 50);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,10);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case 1073741824:
		x = 13;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,255);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//B
		break;
	case 1879048192:
		x = 14;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,255);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//B
		break;
	case -1610612736:
		x = 15;
		//MY_PLB_RGB_LEDS_mWriteSlaveReg0(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 0);//R
		//MY_PLB_RGB_LEDS_mWriteSlaveReg1(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET,255);//G
		//MY_PLB_RGB_LEDS_mWriteSlaveReg2(XPAR_MY_PLB_RGB_LEDS_0_BASEADDR, MY_PLB_RGB_LEDS_SLV_REG0_OFFSET, 255);//B
		break;
	default:
		x = 0;
		break;
	}
	pintar(x);
	return x;
}

void test() {
	Xuint32 baseaddr;
	// Xuint8  Reg8Value;
	// Xuint16 Reg16Value;
	Xuint32 Reg32Value;
	Xuint32 TeclaOld;
	int num;

	xil_printf("---Test para el keypad---\n\r");
	baseaddr = XPAR_TECLADO_0_BASEADDR;

	xil_printf(" Pulse una tecla cualquiera \n\r");
	Reg32Value = TECLADO_mReadReg(baseaddr, 0);
	// num = numerar(Reg32Value);
	xil_printf("   Se ha leido %d del registro 0 del teclado \n\r", Reg32Value);
	//xil_printf("   Se ha leido %d del registro 0 del tecladoo \n\r", num);
	TECLADO_mWriteReg(baseaddr, 0,0);
	TeclaOld = Reg32Value;
	while (1) {
		if (Reg32Value != TeclaOld) {
			num = numerar(Reg32Value);
			//xil_printf("    Se ha leido %d del registro 0 del teclado \n\r", Reg32Value);
			xil_printf("   Se ha leido %d del registro 0 del tecladoo \n\r",num);
		}
		//TeclaOld=Reg32Value;
		Reg32Value = TECLADO_mReadReg (baseaddr, 0);
		TECLADO_mWriteReg(baseaddr, 0,0); /* Se escribe un 0 en el registro del teclado para borrar la �ltima tecla le�da */
	}
}

void espera(){
	int i;
	for(i=0;i < 1250000;i++){

	}

}

void reset(Array correc){
	int i;
	for(i=0;i < 4;i++){
		 correc[i] = 16;
	}
}


//3 G 1 B 2 R
int corregir2(Array sol, int resp){
	int i;
	int correc = 2;
	for(i=0; i < 4;i++){
		if(resp == sol[i]){
			correc = 1;
		}
	}
	return correc;
}

int corregir(Array sol, Array resp, Array correc){
	int i;
	int fin = 1;
	for(i=0; i < 4;i++){
		if(resp[i] == sol[i])
			correc[i] = 4;
		else{
		 correc[i] = corregir2(sol, resp[i]);
		 fin = 0;
		}
	}
	return fin;
}

void genera_sol(){}
void mostrar_sol(Array correc){
	int i;

	for(i=0; i < 4;i++){
		pintar(correc[i]);
		espera();
		pintar(8);
		espera();
	}
}

void secuencia_usuario(Array resp){
	Xuint32 baseaddr;
	// Xuint8  Reg8Value;
	// Xuint16 Reg16Value;
	Xuint32 Reg32Value;
	Xuint32 TeclaOld;
	int salir =0;
	int num;
	int i = 0;

	//xil_printf("---Test para el keypad---\n\r");
	baseaddr = XPAR_TECLADO_0_BASEADDR;

	//xil_printf(" Pulse una tecla cualquiera \n\r");
	Reg32Value = TECLADO_mReadReg(baseaddr, 0);
	// num = numerar(Reg32Value);
	//xil_printf("   Se ha leido %d del registro 0 del teclado \n\r", Reg32Value);
	//xil_printf("   Se ha leido %d del registro 0 del tecladoo \n\r", num);
	TECLADO_mWriteReg(baseaddr, 0,0);
	TeclaOld = Reg32Value;
	while (salir == 0 ) {
		if (Reg32Value != TeclaOld) {
			num = numerar(Reg32Value);
			//xil_printf("    Se ha leido %d del registro 0 del teclado \n\r", Reg32Value);
			xil_printf("   Se ha leido %d del registro 0 del tecladoo, va a resp[%d] \n\r",num, i);
			resp[i] = num;
			i++;
			if(i==4){
				salir=1;
			}
		}
		//TeclaOld=Reg32Value;
		Reg32Value = TECLADO_mReadReg (baseaddr, 0);
		TECLADO_mWriteReg(baseaddr, 0,0); /* Se escribe un 0 en el registro del teclado para borrar la �ltima tecla le�da */
	}
}

int main() {
	//Xuint8  i = 0;
	int /*mode =0,*/fin=0,turnos=1;
	Array sol= {1,7,5,10};
	Array resp;
	Array correc={2,2,2,2};
	Xil_ICacheEnable();
	Xil_DCacheEnable();

	print("---Entering main---\n\r");

	/*{
		int status;

		print("\r\nRunning Bram Example() for xps_bram_if_cntlr_0...\r\n");

		status = BramExample(XPAR_XPS_BRAM_IF_CNTLR_0_DEVICE_ID);

		if (status == 0) {
			xil_printf("Bram Example PASSED.\r\n");
		} else {
			print("Bram Example FAILED.\r\n");
		}

	}*/
	//
	//MY_LCD_SelfTest();
	//test();




	/*if (mode == 1){
		genera_sol();
	}*/
	//mostrar_sol(correc);
	while(fin !=1 && turnos != 10){
		reset(resp);
		print_turnos(turnos);
		xil_printf("VAMOS A LEER DEL TECLADO .\r\n");
		secuencia_usuario(resp);
		xil_printf("LA SECUENCIA DEL USUARIO ES 1: %d  2: %d  3:%d  4:%d turno: %d .\r\n", resp[0], resp[1], resp[2], resp[3], turnos);
		fin = corregir(sol,resp,correc);
		xil_printf("La correccion es 1: %d  2: %d  3:%d  4:%d turno: %d .\r\n", correc[0], correc[1], correc[2], correc[3], turnos);
		espera();
		mostrar_sol(correc);

		turnos++;
	}

	print_fin_partida(turnos);
	espera();espera();espera();espera();


	print("---Exiting Mastermind  ---\n\r");

	Xil_DCacheDisable();
	Xil_ICacheDisable();

	return 0;
}

