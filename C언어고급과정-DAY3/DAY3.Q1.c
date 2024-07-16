#include <stdio.h>

void convertToBase(int number, int base) {
    char digits[] = "0123456789ABCDEFGHIJ";
    char result[64];
    int index = 0;

    while (number > 0) {
        result[index++] = digits[number % base];
        number /= base;
    }

    // 변환된 숫자를 역순으로 출력
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main(void) {
    int number, base;

    printf("10진수 양수 입력: ");
    scanf("%d", &number);

    printf("변환할 진법 입력 (2-20): ");
    scanf("%d", &base);

    // 유효하지 않은 진법 검사
    if (base < 2 || base > 20) {
        printf("유효하지 않은 진법. 2-20 사이의 값을 입력하시오.\n");
        return 1;
    }

    printf("%d를 %d진법으로 변환한 결과: ", number, base);
    convertToBase(number, base);

}
