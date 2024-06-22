//문제3: 양의 정수를 입력받아서 각 디지트를 출력하시오
// 예) 입력 : 1234
//     출력 : 1 2 3 4
#include <stdio.h>

int main(void){
    int number, digit, divi, currentDigit;

    printf("입력: ");
    scanf("%d", &number);

    printf("출력: ");

    // 자릿수 초기 설정
    divi = 1;
    while (number / divi >= 10) {
        divi *= 10;
    }

    // 각 자릿수 분리 출력
    while (divi > 0) {
        currentDigit = (number / divi) % 10;
        printf("%d ", currentDigit);
        divi /= 10;
    }
}
