/*****************************************************************************
* Filename:          C:\Users\Blanzas\Desktop\PR6-entrega/drivers/my_lcd_v1_00_a/src/my_lcd_selftest.c
* Version:           1.00.a
* Description:       Contains a diagnostic self-test function for the my_lcd driver
* Date:              Tue Jan 28 23:24:38 2020 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "my_lcd.h"

/************************** Constant Definitions ***************************/


/************************** Variable Definitions ****************************/


/************************** Function Definitions ***************************/

/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the MY_LCD instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 *
 *
 *
 */

/*
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

void print_turnos(int turno){
	char c = turno + '0' ;
	  LCD_inicializa();
	  LCD_enviarCMD ( WRITE_CMD + 'T' );
	  LCD_enviarCMD ( WRITE_CMD + 'U' );
	  LCD_enviarCMD ( WRITE_CMD + 'R' );
	  LCD_enviarCMD ( WRITE_CMD + 'N' );
	  LCD_enviarCMD ( WRITE_CMD + 'O' );
	  LCD_enviarCMD ( WRITE_CMD + c );
	//  LCD_enviarCMD ( WRITE_CMD +  );
	  MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, 0x80000000);
}


XStatus MY_LCD_SelfTest()
{
  //int     Index;
  //Xuint32 baseaddr;
  //Xuint8  Reg8Value;
  //Xuint16 Reg16Value;
  //Xuint32 Reg32Value;
  */
  /*
   * Check and get the device address
   */
  /*
   * Base Address maybe 0. Up to developer to uncomment line below.
  XASSERT_NONVOID(baseaddr_p != XNULL);
   */
  //baseaddr = (Xuint32) baseaddr_p;
 //int Data;
 // Data =((2  & 0xff ) << (31 -7)) +  (( 2 & 0xff ) << (31 -15)) + (( 2 & 0xff ) << (31 -23)) + 1;
 // MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, 0x80000000);
 /* xil_printf("******************************\n\r");
  xil_printf("* User Peripheral Self Test\n\r");
  xil_printf("******************************\n\n\r");
  LCD_inicializa();
  xil_printf (" practica LCD\r\n");
  LCD_enviarCMD ( WRITE_CMD + 'P' );
  LCD_enviarCMD ( WRITE_CMD + 'O' );
  LCD_enviarCMD ( WRITE_CMD + 'L' );
  LCD_enviarCMD ( WRITE_CMD + 'A' );
  LCD_enviarCMD ( WRITE_CMD + ' ' );
  LCD_enviarCMD ( WRITE_CMD + 'M' );
  LCD_enviarCMD ( WRITE_CMD + 'U' );
  LCD_enviarCMD ( WRITE_CMD + 'N' );
  LCD_enviarCMD ( WRITE_CMD + 'D' );
  LCD_enviarCMD ( WRITE_CMD + 'O' );
  LCD_enviarCMD ( WRITE_CMD + '!' );
  LCD_enviarCMD ( WRITE_CMD + ' ' );
  LCD_enviarCMD ( WRITE_CMD + ':' );
  LCD_enviarCMD ( WRITE_CMD + ')' );
  LCD_enviarCMD ( SECOND_ROW ); // cambio fila
  LCD_enviarCMD ( WRITE_CMD + 'a' );
  LCD_enviarCMD ( WRITE_CMD + 'b' );
  LCD_enviarCMD ( WRITE_CMD + 'c' );
  LCD_enviarCMD ( WRITE_CMD + 'd' );
  LCD_enviarCMD ( WRITE_CMD + 'e' );
  LCD_enviarCMD ( WRITE_CMD + 'f' );
  LCD_enviarCMD ( WRITE_CMD + 'g' );
  LCD_enviarCMD ( WRITE_CMD + ' ' );
  LCD_enviarCMD ( WRITE_CMD + ' ' );
  LCD_enviarCMD ( WRITE_CMD + '0' );
  LCD_enviarCMD ( WRITE_CMD + '1' );
  LCD_enviarCMD ( WRITE_CMD + '2' );
  LCD_enviarCMD ( WRITE_CMD + '3' );
  LCD_enviarCMD ( WRITE_CMD + '4' );
  LCD_enviarCMD ( WRITE_CMD + '5' );
  LCD_enviarCMD ( WRITE_CMD + '6' );
  //MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0,Data);
  //MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, 0X7FFF0000);
  MY_LCD_mWriteToFIFO (BASE_ADDRESS_LCD, 0, 0x80000000);

  return 0;

  return XST_SUCCESS;
}*/
