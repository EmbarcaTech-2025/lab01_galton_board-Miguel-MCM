#include "ball.h"
#include "pico/rand.h"
#include <stdio.h>


uint16_t ball_accumulator[BALL_SLOTS_NUM] = {0};
uint ball_total = 0;
uint16_t ball_accumulator_max = 0;

void ball_render(Ball *b) {
    if (b->state == Stt_NONE)
        return;
    ssd1306_set_pixel(ssd, b->x*BALL_POS_INCREMENT+BALL_ABSOLUTE_X_OFFSET, b->y*BALL_POS_INCREMENT, true);
}

void ball_update(Ball *b) {
    switch (b->state) {
    case Stt_FALL:
        b->y += 1;
        if (b->y >= BALL_END_Y) {
            b->state = Stt_END;
        } else {
            b->state = Stt_COLLISION;
        }
        break;
    case Stt_COLLISION:
        if  (random_decision()) {
            b->x += 1;
        } else {
            b->x -= 1;
        }
        b->state = Stt_FALL;
        break;
    case Stt_END:
        ball_accumulator[b->x/2]++;
        if (ball_accumulator_max < ball_accumulator[b->x/2])
            ball_accumulator_max = ball_accumulator[b->x/2];
        ball_total++;
        ball_reset(b);
        break;
    default:
        break;
    }
}

void ball_reset(Ball *b) {
    b->x = BALL_INITIAL_X;
    b->y = BALL_INITIAL_Y;
    b->state = Stt_FALL;
}

bool random_decision() {
    static uint32_t random_number;
    static uint8_t mask = 32;

    if (mask == 32) {
        random_number = get_rand_32();
        mask = 0;
    }

    #ifndef FAVOR_RIGHT
    return (random_number & (1 << mask++)) != 0;
    #else
    bool descision = (random_number & (3 << mask)) != 0;
    mask += 2;
    return descision;
    #endif
}