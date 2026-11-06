//202610411204
//杨百川
//基础题2：设备传感器数据打包（结构体封装 + 函数按值返回）
#include <stdio.h>

struct Sensor {
    int temp;   // 温度
    int humi;   // 湿度
    int valid;  // 1 表示正常，0 表示异常
};

// 把温度和湿度打包成结构体，同时判断数据是否在合理范围内
struct Sensor pack_sensor(int t, int h) {
    struct Sensor s;

    s.temp = t;
    s.humi = h;

    if (t >= -20 && t <= 50 && h >= 0 && h <= 100) {
        s.valid = 1;
    } else {
        s.valid = 0;
    }

    return s;
}

int main() {
    int t, h;
    struct Sensor s;

    scanf("%d %d", &t, &h);

    s = pack_sensor(t, h);

    if (s.valid == 1) {
        printf("TEMP=%d HUMI=%d\n", s.temp, s.humi);
    } else {
        printf("ERROR: Out of Range\n");
    }

    return 0;
}
