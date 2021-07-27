//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

void wdt_c_handler(){
  clearScreen(COLOR_WHITE);
}

void main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  switch_init();
  lcd_init();
  buzzer_init();
  buzzer_set_period(0);
  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
