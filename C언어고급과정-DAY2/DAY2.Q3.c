//문제 3: 키보드로 양수를 입력받아서 16진수로 변환해서 출력하시오

#include <stdio.h>

int main(void) {
    unsigned int number;

    printf("양수를 입력: ");
    scanf("%u", &number);

    printf("16진수로 변환: %X\n", number);

    return 0;
}