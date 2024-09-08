#include <stdio.h>
#include <stdarg.h>
#include <time.h>

// I/O 函数实现
int getint() {
    int value;
    scanf("%d", &value);
    return value;
}

int getch() {
    char ch;
    scanf(" %c", &ch);
    return (int)ch; // 返回字符的ASCII码值
}

float getfloat() {
    float value;
    scanf("%f", &value);
    return value;
}

int getarray(int array[]) {
    int n, i;
    scanf("%d", &n); // 读取输入的整数个数
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]); // 读取后续的整数并存入数组
    }
    return n; // 返回输入的整数个数
}

int getfarray(float array[]) {
    int n, i;
    scanf("%d", &n); // 读取输入的浮点数个数
    for (i = 0; i < n; i++) {
        scanf("%f", &array[i]); // 读取后续的浮点数并存入数组
    }
    return n; // 返回输入的浮点数个数
}

void putint(int value) {
    printf("%d", value);
}

void putch(int value) {
    if (value >= 0 && value <= 255) {
        putchar(value);
    }
}

void putfloat(float value) {
    printf("%f", value);
}

void putarray(int n, int array[]) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void putfarray(int n, float array[]) {
    for (int i = 0; i < n; i++) {
        printf("%f", array[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void putf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

// 计时函数实现
typedef struct {
    clock_t start;
    clock_t end;
} Timer;

static Timer timers[100]; // 假设最多有100个计时器
static int timer_count = 0;

void starttime() {
    if (timer_count < sizeof(timers) / sizeof(timers[0])) {
        timers[timer_count].start = clock();
        timer_count++;
    }
}

void stoptime() {
    if (timer_count > 0) {
        timers[timer_count - 1].end = clock();
        printf("Timer#%03d@%03d-%03d: %02ld-%02ld-%02ld-%04ldus\n",
               timer_count - 1,
               __LINE__ - 1,
               __LINE__,
               (timers[timer_count - 1].end - timers[timer_count - 1].start) / (CLOCKS_PER_SEC * 3600),
               (timers[timer_count - 1].end - timers[timer_count - 1].start) / (CLOCKS_PER_SEC * 60) % 60,
               (timers[timer_count - 1].end - timers[timer_count - 1].start) / CLOCKS_PER_SEC % 60,
               (timers[timer_count - 1].end - timers[timer_count - 1].start) % CLOCKS_PER_SEC,
               ((timers[timer_count - 1].end - timers[timer_count - 1].start) % CLOCKS_PER_SEC) * 1000000 / CLOCKS_PER_SEC);
        timer_count--;
    }
}