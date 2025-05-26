#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_system.h"
#include "esp32/rom/ets_sys.h"  

#define NUM_POTS      5
#define MAX_VOLTAGE   3300.0   =
#define MAX_DEGREE    300.0
#define DEFAULT_VREF  1100     
#define SAMPLES       16       

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"  // Suppress warnings for legacy API

// ADC1 channels mapped to GPIOs
const adc1_channel_t pot_channels[NUM_POTS] = {
    ADC1_CHANNEL_0,  // GPIO36
    ADC1_CHANNEL_3,  // GPIO39
    ADC1_CHANNEL_6,  // GPIO34
    ADC1_CHANNEL_7,  // GPIO35
    ADC1_CHANNEL_4   // GPIO32 (replacing invalid CHANNEL_8)
};

esp_adc_cal_characteristics_t adc_chars;

void init_adc() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    for (int i = 0; i < NUM_POTS; i++) {
        adc1_config_channel_atten(pot_channels[i], ADC_ATTEN_DB_11);
    }

    // Calibrate ADC
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11,
                             ADC_WIDTH_BIT_12, DEFAULT_VREF, &adc_chars);
}

// Average multiple ADC readings for smoother result
uint32_t get_average_voltage(adc1_channel_t channel, int samples) {
    uint32_t total = 0;
    for (int i = 0; i < samples; i++) {
        int raw = adc1_get_raw(channel);
        total += esp_adc_cal_raw_to_voltage(raw, &adc_chars);
        ets_delay_us(100);  
    }
    return total / samples;
}

void read_and_print_pot_values() {
    uint32_t voltage[NUM_POTS];
    float percent[NUM_POTS], degrees[NUM_POTS];

    for (int i = 0; i < NUM_POTS; i++) {
        voltage[i] = get_average_voltage(pot_channels[i], SAMPLES);
        percent[i] = (voltage[i] / MAX_VOLTAGE) * 100.0f;
        degrees[i] = (voltage[i] / MAX_VOLTAGE) * MAX_DEGREE;
    }

    printf("\nAccurate Potentiometer Readings:\n");
    for (int i = 0; i < NUM_POTS; i++) {
        printf("p%d = (%4lumV, %6.2f%%, %6.2f°)\n", i + 1, (unsigned long)voltage[i], percent[i], degrees[i]);
    }
    printf("----------------------------\n");
}

void app_main(void) {


    printf("Boot successful. Initializing ADC...\n");
    init_adc();

    while (1) {
        read_and_print_pot_values();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }




    
}