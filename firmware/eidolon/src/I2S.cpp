#include "I2S.h"

void I2S::init() {
    initMic();
    initSpeaker();
}
void I2S::deinit() {
    i2s_driver_uninstall(I2S_NUM_0);
}

void I2S::initMic() {
    i2s_config_t mic = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = 16000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
        .communication_format = I2S_COMM_FORMAT_I2S_MSB,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 4,
        .dma_buf_len = 1024,
        .use_apll = false,
        .tx_desc_auto_clear = false
    };
    i2s_pin_config_t micPins = {
        .bck_io_num = I2S_SCK,
        .ws_io_num = I2S_WS,
        .data_out_num = -1,
        .data_in_num = I2S_SD
    };
    i2s_driver_install(I2S_NUM_0, &mic, 0, nullptr);
    i2s_set_pin(I2S_NUM_0, &micPins);
}

void I2S::initSpeaker() {
    i2s_config_t speaker = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate = 16000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
        .communication_format = I2S_COMM_FORMAT_I2S_MSB,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 4,
        .dma_buf_len = 1024,
        .use_apll = false,
        .tx_desc_auto_clear = false
    };
    i2s_pin_config_t speakerPins = {
        .bck_io_num = I2S_SCK,
        .ws_io_num = I2S_WS,
        .data_out_num = I2S_DIN,
        .data_in_num = -1
    };
    i2s_driver_install(I2S_NUM_0, &speaker, 0, nullptr);
    i2s_set_pin(I2S_NUM_0, &speakerPins);
}

esp_err_t I2S::read(uint32_t* buffer, size_t size, size_t* bytesRead) {
    return i2s_read(I2S_NUM_0, buffer, size * sizeof(uint32_t), bytesRead, portMAX_DELAY);
}

esp_err_t I2S::write(uint32_t* buffer, size_t size, size_t* bytesWritten) {
    return i2s_write(I2S_NUM_0, buffer, size * sizeof(uint32_t), bytesWritten, portMAX_DELAY);
}