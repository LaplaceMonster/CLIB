#include <stdio.h>
#include "myLib.h"
#include <stdlib.h>
int main()
{
    int result1 = add(3, 4);       // 调用库函数
    int result2 = subtract(10, 5); // 调用库函数

    printf("Add result: %d\n", result1);
    printf("Subtract result: %d\n", result2);
    system("pause");  // 在 Windows 上暂停程序，等待用户输入
    return 0;
}