#include <stdio.h>
#include "SysY.h"

int main() {
    // 测试 getint
    printf("Testing getint:\n");
    int intValue = getint();
    printf("Input integer: %d\n", intValue);

    // 测试 getch
    printf("Testing getch:\n");
    int chValue = getch();
    printf("Input character ASCII: %d\n", chValue);

    // 测试 getfloat
    printf("Testing getfloat:\n");
    float floatValue = getfloat();
    printf("Input float: %f\n", floatValue);

    // 测试 getarray
    printf("Testing getarray:\n");
    int array[10];
    int arraySize = getarray(array);
    printf("Input array size: %d, contents: ", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 测试 getfarray
    printf("Testing getfarray:\n");
    float farray[10];
    int farraySize = getfarray(farray);
    printf("Input float array size: %d, contents: ", farraySize);
    for (int i = 0; i < farraySize; i++) {
        printf("%f ", farray[i]);
    }
    printf("\n");

    // 测试 putint
    printf("Testing putint:\n");
    putint(123);
    printf("\n");

    // 测试 putch
    printf("Testing putch:\n");
    putch('A');
    printf("\n");

    // 测试 putfloat
    printf("Testing putfloat:\n");
    putfloat(123.456);
    printf("\n");

    // 测试 putarray
    printf("Testing putarray:\n");
    putarray(arraySize, array);
    printf("\n");

    // 测试 putfarray
    printf("Testing putfarray:\n");
    putfarray(farraySize, farray);
    printf("\n");

    // 测试 putf
    printf("Testing putf:\n");
    putf("%d: %d(%c), %d(%c)", 2, 50, 50 + 48, 51, 51 + 48);
    printf("\n");

    // 测试 starttime 和 stoptime
    printf("Testing starttime and stoptime:\n");
    starttime();
    // 模拟一些计算
    for (int i = 0; i < 1000000; i++);
    stoptime();

    return 0;
}