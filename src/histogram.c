#include "histogram.h"

void histogram_render() {
    
    for (uint8_t i=0; i<BALL_SLOTS_NUM; i++) {
        histogram_render_bar((ball_accumulator[i]*HIST_BAR_MAX_SIZE)/ball_accumulator_max, BALL_ABSOLUTE_X_OFFSET+BALL_POS_INCREMENT*2*i, HIST_INITIAL_Y);
    }
}

void histogram_render_bar(uint8_t size, uint8_t x, uint8_t y) {
    for (uint8_t i=0; i<size; i++) {
        ssd1306_set_pixel(ssd, x, y+i, true);
    }
}