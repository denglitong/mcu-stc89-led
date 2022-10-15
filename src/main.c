#include "led.h"

int main() {
  turn_on_led_master_switch();
  // flash_single_led();
  flash_serial_leds();
}
