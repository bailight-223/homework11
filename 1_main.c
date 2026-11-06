//202610411204
//杨百川
//基础题1：电竞战队选手榜（结构体数组 + 冒泡排序）
#include <stdio.h>

struct Player {
    char name[16];
    int score;
};

// 冒泡排序：按积分从高到低，分数相同不交换（保持原顺序）
void sort_players(struct Player arr[], int n) {
    int i, j;
    struct Player temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j].score < arr[j + 1].score) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Player arr[10];
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d", arr[i].name, &arr[i].score);
    }

    sort_players(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d %s %d\n", i + 1, arr[i].name, arr[i].score);
    }

    return 0;
}
