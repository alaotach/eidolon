#include "IMU.h"

MPU6050* IMU::mpu = nullptr;

bool IMU::initialized = false;
float IMU::lastAngleX = 0.0f;
float IMU::lastAngleY = 0.0f;
float IMU::lastAngleZ = 0.0f;

bool IMU::init() {
    mpu = new MPU6050(I2c::getWire());

    return true;
}

void IMU::update() {
    if (!initialized) {
        return;
    }
    mpu->update();
    lastAngleX = mpu->getAngleX();
    lastAngleY = mpu->getAngleY();
    lastAngleZ = mpu->getAngleZ();
}

float IMU::getAccelX() {
    if (!initialized) {
        return 0.0f;
    }
    return mpu->getAccX();
}

float IMU::getAccelY() {
    if (!initialized) {
        return 0.0f;
    }
    return mpu->getAccY();
}

float IMU::getAccelZ() {
    if (!initialized) {
        return 0.0f;
    }
    return mpu->getAccZ();
}

float IMU::getGyroX() {
    if (!initialized) {
        return 0.0f;
    }
    return mpu->getGyroX();
}

float IMU::getGyroY() {
    if (!initialized) {
        return 0.0f;
    }
    return mpu->getGyroY();
}

float IMU::getGyroZ() {
    if (!initialized) {
        return 0.0f;
    }
    return mpu->getGyroZ();
}

float IMU::getAngleX() {
    if (!initialized) {
        return 0.0f;
    }
    return lastAngleX;
}

float IMU::getAngleY() {
    if (!initialized) {
        return 0.0f;
    }
    return lastAngleY;
}

float IMU::getAngleZ() {
    if (!initialized) {
        return 0.0f;
    }
    return lastAngleZ;
}

void IMU::deinit() {
    if (mpu) {
        delete mpu;
        mpu = nullptr;
    }
    initialized = false;
}

void IMU::calibrate() {
    if (!initialized) {
        return;
    }
    mpu->calcOffsets();
}