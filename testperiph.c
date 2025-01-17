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
#include "xparameters.h"
#include "xil_cache.h"
#include "uartlite_header.h"
#include "xbasic_types.h"
#include "xgpio.h"
/*#include "gpio_header.h"
*/
#define LEDs_HW_BASEaddress (0x81420000)
int main() 
{

	XGpio Gpio_LEDs; /* The driver instance for GPIO Device configured as Salida */
	XGpio GpioSwitches;  /* The driver instance for GPIO Device configured as Entrada */
	u32 DataRead;
	Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Test para switches y leds---\n\r");



			// Configuración de la GPIO para los LEDs de la placa extendida
			XGpio_Initialize(&Gpio_LEDs, XPAR_LEDS_DEVICE_ID); /*Obtiene el puntero a la estructura */
			XGpio_SetDataDirection(&Gpio_LEDs, 1, 0x0); /*Coloca la dirección de salida */

			// Configuración de la GPIO para los Switches
			XGpio_Initialize(&GpioSwitches, XPAR_SWITCHES_DEVICE_ID); /*Obtiene el puntero a la estructura */
			XGpio_SetDataDirection(&GpioSwitches, 1, 0xFF); /*Coloca la dirección de entrada */


			/*
				* Lee el estado de los switches y entra en un buche mientras la configuración no sea 0F
			*/
				 DataRead = XGpio_DiscreteRead(&GpioSwitches, XPAR_SWITCHES_DEVICE_ID);
			while (DataRead!=0x0F){
			// Escribir el dato leido en los LEDs de la placa extendida
			XGpio_DiscreteWrite(&Gpio_LEDs, 1, DataRead);
			/*
					* Lee de nuevo el estado de los switches
			*/
			DataRead = XGpio_DiscreteRead(&GpioSwitches, XPAR_SWITCHES_DEVICE_ID);}


			// Rotación 10 veces de 1 LED
			int delay = 0, i=0;
			Xuint32 bit = 0;

			while (i<160){
				// Escribe en los leds
				XGpio_DiscreteWrite(&Gpio_LEDs, 1, 1<<bit);
				// retardo. Se escriben puntos en la pantalla
				for (delay=0; delay<50; delay++){print(".");}
				bit = (bit + 1) % 4;
				i=i +1;
			}


{			u32  Data;
/*para escribir una dato cualquiera (por ejemplo 5) hacemos*/
			Data=0x00000005;
			XGpio_DiscreteWrite(&Gpio_LEDs, 1, DataRead);

			/* Otra forma de escribir en los leds. Accedemos directamente a la dirección donde se encuentran*/
			Xuint32 baseaddr;
			baseaddr=LEDs_HW_BASEaddress; /*Este valor lo definimos como una cte que tomamos del EDK*/
			Data=0x00000003;

			(*(volatile u32 *)baseaddr)= Data;
			}
   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}



