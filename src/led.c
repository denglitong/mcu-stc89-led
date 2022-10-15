//
// Created by Litong Deng on 2022/10/4.
//

#include "led.h"

#include <8051.h>

#include "common.h"

_Noreturn void flash_single_led() {
  LED_SINGLE = P0_0;
  while (1) {
    // 高电平 - 低电平 点亮 LED_SINGLE
    LED_SINGLE = 0;
    delay_ms(200);
    // 高电平 - 高电平 熄灭 LED_SINGLE
    LED_SINGLE = 1;
    delay_ms(300);
  }
}

_Noreturn void flash_serial_leds() {
  short i = 0;
  while (1) {
    for (i = 0; i < 2; ++i) {
      turn_on_all_leds();
      delay_ms(200);
      turn_off_all_leds();
      delay_ms(300);
    }
    for (i = 0; i < LED_SIZE; ++i) {
      // turn on the i-th led from low-high
      turn_on_single_led(i);
      delay_ms(100);
      turn_off_all_leds();
      delay_ms(100);
    }
    for (i = LED_SIZE - 1; i >= 0; --i) {
      // turn on the i-th led from high-low
      turn_on_single_led(i);
      delay_ms(100);
      turn_off_all_leds();
      delay_ms(100);
    }
  }
}

// 教学板子 LED_SINGLE 总开关
void turn_on_led_master_switch() {
  enable_u3_74hc138();
  // 110 LEDS6 为低电平，三极管导通，LED 总开关打开
  ADDR_2 = 1;
  ADDR_1 = 1;
  ADDR_0 = 0;
}

void turn_on_all_leds() { LED_LINE = 0x00; }

void turn_off_all_leds() { LED_LINE = 0xff; }

void turn_on_single_led(unsigned char i) {
  // turn on the i-th led from low-high
  LED_LINE &= ~(0x01 << i);
}

void turn_off_single_led(unsigned char i) {
  // turn off the i-th led from low-high
  LED_LINE |= 0x01 << i;
}

void switch_single_led(unsigned char i) {
  // switch the i-th led from low-high
  LED_LINE ^= 0x01 << i;
}
