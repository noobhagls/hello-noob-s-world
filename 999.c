#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // 设置随机种子，只调用一次，保证每次运行题目不同
    srand(time(NULL));

    int num1, num2; // 两个运算数
    int op;         // 运算符：0加法，1减法，2乘法，3除法

    // 随机生成运算符：0、1、2、3
    op = rand() % 4;

    printf("========== 智能口算训练系统 ==========\n");

    switch(op)
    {
        case 0: // 加法：10~99，无其他约束
            num1 = rand() % 90 + 10;  // 10~99
            num2 = rand() % 90 + 10;
            printf("本次题目：%d + %d = ?\n", num1, num2);
            break;

        case 1: // 减法：10~99，num1 >= num2，结果非负
            num1 = rand() % 90 + 10;  // 被减数10~99
            num2 = rand() % (num1 - 10 + 1) + 10; // 减数范围10~num1
            printf("本次题目：%d - %d = ?\n", num1, num2);
            break;

        case 2: // 乘法：1~9，乘法口诀表
            num1 = rand() % 9 + 1; // 1~9
            num2 = rand() % 9 + 1;
            printf("本次题目：%d * %d = ?\n", num1, num2);
            break;

        case 3: // 除法：被除数1~81，除数1~9，整除，除数≠0
            num2 = rand() % 9 + 1;        // 除数 1~9
            num1 = num2 * (rand() % 9 +1);// 被除数是除数倍数，1~81
            printf("本次题目：%d ÷ %d = ?\n", num1, num2);
            break;
    }

    return 0;
}
