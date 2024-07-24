#include <stdio.h> //팩토리얼의 크기와 관련없이 계산할 수 있게 제작해보기
#define MAX_DIGITS 160

void multiply(int *result, int *result_size, int num)
void factorial(int n)

int main(void) {
    int num;
    printf("0~100 사이의 정수 입력: ");
    scanf("%d", &num);

    factorial(num);
}

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
    int result[MAX_DIGITS] = {1};
    int result_size = 1;

    for (int i = 2; i <= n; i++) {
        multiply(result, &result_size, i);
    }
    
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}
