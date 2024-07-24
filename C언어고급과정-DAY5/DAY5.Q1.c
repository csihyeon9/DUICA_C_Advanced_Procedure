#include <stdio.h>

/*
100이하의 정수값을 입력받아서 팩토리얼을 출력하시오. 
*/

#define MAX_DIGITS 160 // 충분히 큰 배열 크기

void multiply(int *result, int *result_size, int num) {
    int carry = 0;
    for (int i = 0; i < *result_size; i++) {
        int prod = result[i] * num + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        result[*result_size] = carry % 10;
        carry /= 10;
        (*result_size)++;
    }
}

void factorial(int n) {
    int result[MAX_DIGITS] = {1}; // 초기값 1
    int result_size = 1; // 초기 결과 크기

    for (int i = 2; i <= n; i++) {
        multiply(result, &result_size, i);
    }

    // 결과를 역순으로 출력
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("0~100 사이의 정수 입력력: ");
    scanf("%d", &num);

    factorial(num);
    return 0;
}
