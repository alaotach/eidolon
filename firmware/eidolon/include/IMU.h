#include <MPU6050_light.h>
#include "Config.h"
#include "I2c.h"

class IMU {
public:
    static bool init();
    static void update();
    static float getAccelX();
    static float getAccelY();
    static float getAccelZ();
    static float getGyroX();
    static float getGyroY();
    static float getGyroZ();
    static float getAngleX();
    static float getAngleY();
    static float getAngleZ();
    static void deinit();
    static void calibrate();
private:
    static MPU6050* mpu;
    static bool initialized;
    static float lastAngleX;
    static float lastAngleY;
    static float lastAngleZ;
};