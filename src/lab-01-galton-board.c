#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Biblioteca para uso do SSD1306, display OLED.
#include "include/ssd1306.h"

#include "ball.h"

// Definições para uso de comunicação I2C com os pinos do display OLED.
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define I2C_FREQ (400*1000)
#define I2C_ADDR ssd1306_i2c_port

uint8_t ssd[ssd1306_buffer_length];
struct render_area frame_area;

void setup_ssd1306();

int main()
{
    stdio_init_all();
    setup_ssd1306();

    Ball ball;
    ball_reset(&ball);
    while (true) {
        ssd1306_clear(ssd);
        ball_render(&ball);
        ball_update(&ball);
        render_on_display(ssd, &frame_area);
        sleep_ms(5);
    }
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
