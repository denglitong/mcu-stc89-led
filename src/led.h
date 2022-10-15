//
// Created by Litong Deng on 2022/10/4.
//

#ifndef CMC_STC89_LED_H
#define CMC_STC89_LED_H

_Noreturn void flash_single_led();

_Noreturn void flash_serial_leds();

void turn_on_led_master_switch();

void turn_on_all_leds();

void turn_off_all_leds();

void turn_on_single_led(unsigned char i);

void turn_off_single_led(unsigned char i);

void switch_single_led(unsigned char i);

#endif // CMC_STC89_LED_H
