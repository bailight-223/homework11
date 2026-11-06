//202610411204
//杨百川
//基础题3：历史数据简易滑动窗口（结构体封装数组 + 下标回绕）
#include <stdio.h>

struct Window {
    int buffer[3]; // 保存最近 3 个数据
    int count;     // 累计采集次数
};

// 推入一个新数据，返回更新后的结构体
struct Window push_data(struct Window win, int val) {
    win.buffer[win.count % 3] = val;
    win.count = win.count + 1;
    return win;
}

// 计算当前保存数据的整数平均值
int get_average(struct Window win) {
    int i;
    int sum = 0;
    int num;

    if (win.count < 3) {
        num = win.count;
    } else {
        num = 3;
    }

    for (i = 0; i < num; i++) {
        sum = sum + win.buffer[i];
    }

    return sum / num;
}

int main() {
    int m, i, val;
    struct Window win;

    win.buffer[0] = 0;
    win.buffer[1] = 0;
    win.buffer[2] = 0;
    win.count = 0;

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        win = push_data(win, val);

        if (i > 0) {
            printf(" ");
        }
        printf("%d", get_average(win));
    }
    printf("\n");

    return 0;
}
