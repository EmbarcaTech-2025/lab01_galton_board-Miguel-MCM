#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "ball.h"
#include "ssd1306.h"

#define HIST_INITIAL_Y (BALL_END_Y*BALL_POS_INCREMENT+1)
#define HIST_BAR_MAX_SIZE (ssd1306_height - HIST_INITIAL_Y)

void histogram_render();

void histogram_render_bar(uint8_t size, uint8_t x, uint8_t y);

#endif