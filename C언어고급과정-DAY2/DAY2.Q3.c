#include <stdio.h>

int main(void) {
    unsigned int number;  // 입력받을 양수를 저장할 변수
    int shift, digit;     // 비트 시프트 연산과 16진수 자릿수를 저장할 변수
    char hexDigits[] = "0123456789ABCDEF";  // 16진수 문자를 저장한 배열

    // 양수 입력 받기
    printf("양수 입력: ");
    scanf("%u", &number);

    // 16진수로 변환하여 출력
    printf("입력한 양수의 16진수 표현: ");

    int started = 0;  // 16진수 변환의 시작 여부를 확인하기 위한 변수

    // 32비트 정수를 16진수 문자열로 변환하기 위한 반복문
    for (shift = 28; shift >= 0; shift -= 4) {
        digit = (number >> shift) & 0xF;  // 해당 자리의 16진수 값을 추출
        if (digit != 0 || started) {
            // 16진수 문자 출력
            printf("%c", hexDigits[digit]);
            started = 1;  // 출력이 시작되었음을 표시
        }
    }

    // 변환된 결과가 '0'인 경우 처리
    if (!started) {
        printf("%c", '0');
    }

    printf("\n");  // 줄바꿈 출력
}
