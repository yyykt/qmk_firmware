#include "lily58.h"
#include <stdio.h>
#include QMK_KEYBOARD_H


uint16_t cnt = 0;
void count(void) {
  ++cnt;
}

uint16_t get_count(void) {
  return cnt;
}

const char *read_hikari(void) {
  const uint16_t anime[] = {0, 1, 0, 2};
  static char frames[][3*5+1] = {
    {
      32, 149, 150, 151, 32,
      32, 181, 182, 183, 32,
      32, 213, 214, 215, 32, 
      0
    },
    {
      32, 152, 153, 154, 32,
      32, 184, 185, 186, 32,
      32, 216, 217, 218, 32, 
      0
    }, 
    {
      32, 155, 156, 157, 32,
      32, 187, 188, 189, 32,
      32, 219, 220, 221, 32, 
      0
    }, 
  };
  return frames[anime[cnt % 4]];
}


char wpm_str[5];
const char *read_wpm(void) {
  snprintf(wpm_str, sizeof(wpm_str), "%4d", get_current_wpm());
  return wpm_str;
}