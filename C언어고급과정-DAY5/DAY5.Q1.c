#include <stdio.h>

#define MAX 160

// 팩토리얼 함수
void factorial(int n) {
    int result[MAX] = {1}; // 0! = 1
    int result_size = 1; // 현재 결과의 자리 수
    int carry, prod;

    for (int i = 2; i <= n; i++) {
        carry = 0;
        for (int j = 0; j < result_size; j++) {
            prod = result[j] * i + carry;
            result[j] = prod % 10; // 현재 자리의 값 저장
            carry = prod / 10; // 자리 올림 값 저장
        }
        while (carry) {
            result[result_size++] = carry % 10;
            carry /= 10;
        }
    }

    printf("%d! = ", n);
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("0 ~ 100 입력: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        printf("0 ~ 100을 입력하시오\n");
    } else {
        factorial(n);
    }
    return 0;
}
