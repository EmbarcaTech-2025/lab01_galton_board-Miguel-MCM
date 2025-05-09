#ifndef BALL_H
#define BALL_H
#include "ssd1306.h"

#define BALL_POS_INCREMENT 2

#define BALL_INITIAL_Y 0
#define BALL_END_Y (16)
#define BALL_SLOTS_NUM (BALL_END_Y)

#define BALL_ABSOLUTE_X_OFFSET (ssd1306_width/2-BALL_SLOTS_NUM*BALL_POS_INCREMENT)

#define BALL_INITIAL_X (BALL_SLOTS_NUM)

#define FAVOR_RIGHT 1

typedef enum BallState {
    Stt_FALL,
    Stt_COLLISION,
    Stt_END,
    Stt_NONE
} BallState;

typedef uint8_t ball_pos_t;

typedef struct Ball {
    ball_pos_t x, y;
    BallState state;
} Ball;

void ball_render(Ball *b);
void ball_update(Ball *b);
void ball_reset(Ball *b);

bool random_decision();

extern uint8_t ssd[ssd1306_buffer_length];

extern uint16_t ball_accumulator[BALL_SLOTS_NUM];
extern uint ball_total;
extern uint16_t ball_accumulator_max;

#endif