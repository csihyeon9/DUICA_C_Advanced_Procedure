//문제 1: 키보드로 양수를 입력받아서 9의 보수를 출력하시오
#include <stdio.h>

int main(void) {
    int number, digit, complement9 = 0, place = 1;

    printf("양수 입력:");
    scanf("%d", &number);

    while (number > 0) {
        digit = number % 10;
        complement9 += (9 - digit) * place;
        number /= 10;
        place *= 10;
    }

    printf("9의 보수: %d\n", complement9);
}





