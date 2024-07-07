//문제 3: 키보드로 양수를 입력받아서 16진수로 변환해서 출력하시오

#include <stdio.h>

int main(void) {
    unsigned int number;
    int shift, digit;
    char hexDigits[] = "0123456789ABCDEF";

    // 양수 입력 받기
    printf("양수를 입력하세요: ");
    scanf("%u", &number);

    // 16진수로 변환하여 출력
    printf("입력한 양수의 16진수 표현: ");

    int started = 0;  // 시작 여부 확인을 위한 변수
    for (shift = 28; shift >= 0; shift -= 4) {
        digit = (number >> shift) & 0xF;  // 해당 자리의 16진수 값을 추출
        if (digit != 0 || started) {
            // printf를 사용하여 한 자리 16진수 문자를 출력
            printf("%c", hexDigits[digit]);
            started = 1;  // 출력 시작
        }
    }

    // number가 0인 경우 특별 처리
    if (!started) {
        printf("%c", '0');
    }

    printf("\n");
    return 0;
}
