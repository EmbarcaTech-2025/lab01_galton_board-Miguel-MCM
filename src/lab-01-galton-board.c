#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Biblioteca para uso do SSD1306, display OLED.
#include "include/ssd1306.h"

#include "ball.h"
#include "histogram.h"

// Definições para uso de comunicação I2C com os pinos do display OLED.
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define I2C_FREQ (400*1000)
#define I2C_ADDR ssd1306_i2c_port

uint8_t ssd[ssd1306_buffer_length];
struct render_area frame_area;

void setup_ssd1306();

void loop(Ball *balls);

#define NUMBER_BALLS 8
#define DELAY 500 // us
#define NEW_BALL_TICKS ((BALL_END_Y*2)/NUMBER_BALLS)

int main() {
    stdio_init_all();
    setup_ssd1306();

    Ball balls[NUMBER_BALLS];
    for (int i=0; i<NUMBER_BALLS; i++) {
        balls[i].state = Stt_NONE;
    }

    // initilize each ball after the correct number of ticks
    for (uint tick=0; tick<NUMBER_BALLS*NEW_BALL_TICKS; tick++) {
        if (!(tick%NEW_BALL_TICKS)) {
            ball_reset(&(balls[tick/NEW_BALL_TICKS]));
        }
        loop(balls);
    }

    while (true) {
        loop(balls);
    }
}

void loop(Ball *balls) {
    ssd1306_clear(ssd);
    for (int i=0; i<NUMBER_BALLS; i++) {
        ball_render(&(balls[i]));
        ball_update(&(balls[i]));
    }
    histogram_render();
    sdd1306_draw_uint(ssd, ball_total, ssd1306_width-8, 0, 3);
    render_on_display(ssd, &frame_area);
    sleep_us(DELAY);
}

void setup_ssd1306() {
    i2c_init(I2C_PORT, I2C_FREQ);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    frame_area.start_column = 0;
    frame_area.end_column = ssd1306_width-1;
    frame_area.start_page = 0;
    frame_area.end_page = ssd1306_n_pages-1;

    calculate_render_area_buffer_length(&frame_area);
    ssd1306_clear(ssd);
    render_on_display(ssd, &frame_area);

}
