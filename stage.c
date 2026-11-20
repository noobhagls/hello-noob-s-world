#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 生成[min, max]范围内的随机整数 */
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main(void) {
    int type;      /* 题型：0加 1减 2乘 3除 */
    int num1;      /* 第一个运算数 */
    int num2;      /* 第二个运算数 */

    /* 设置随机种子，使每次运行结果不同 */
    srand((unsigned)time(NULL));

    /* 随机生成题型 */
    type = randRange(0, 3);

    switch (type) {
        case 0: /* 加法：10-99 */
            num1 = randRange(10, 99);
            num2 = randRange(10, 99);
            printf("========== 智能口算训练系统 ==========\n");
            printf("本次题目：%d + %d = ?\n", num1, num2);
            break;

        case 1: /* 减法：10-99，保证结果非负 */
            num1 = randRange(10, 99);
            num2 = randRange(10, 99);
            if (num1 < num2) {
                int temp = num1;
                num1 = num2;
                num2 = temp;
            }
            printf("========== 智能口算训练系统 ==========\n");
            printf("本次题目：%d - %d = ?\n", num1, num2);
            break;

        case 2: /* 乘法：1-9，乘法口诀表范围 */
            num1 = randRange(1, 9);
            num2 = randRange(1, 9);
            printf("========== 智能口算训练系统 ==========\n");
            printf("本次题目：%d × %d = ?\n", num1, num2);
            break;

        case 3: /* 除法：除数1-9，被除数1-81，保证整除 */
            num2 = randRange(1, 9);          /* 除数 */
            num1 = num2 * randRange(1, 9);   /* 被除数 */
            printf("========== 智能口算训练系统 ==========\n");
            printf("本次题目：%d ÷ %d = ?\n", num1, num2);
            break;
    }

    return 0;
}
