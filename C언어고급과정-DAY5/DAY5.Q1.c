#include <stdio.h>

#define MAX 160

// 곱셈 함수
void multiply(int result[], int *result_size, int num) {
    int carry = 0; // 자리 올림
    for (int i = 0; i < *result_size; i++) {
        int prod = result[i] * num + carry;
        result[i] = prod % 10; // 현재 자리의 값 저장
        carry = prod / 10; // 자리 올림 값 저장
    }
    while (carry) {
        result[(*result_size)++] = carry % 10;
        carry /= 10;
    }
}

// 팩토리얼 함수
void factorial(int n) {
    int result[MAX] = {1}; // 0! = 1
    int result_size = 1; // 현재 결과의 자리 수

    for (int i = 2; i <= n; i++) {
        multiply(result, &result_size, i);
    }

    printf("%d! = ", n);
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number (0-100): ");
    scanf("%d", &n);
    if (n < 0 || n > 100) {
        printf("Please enter a number between 0 and 100.\n");
    } else {
        factorial(n);
    }
    return 0;
}
