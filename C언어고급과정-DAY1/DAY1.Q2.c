//문제2: 양의 정수 1개를 입력받아서 다음과 같이 분할해서 출력하시오
//예) 입력 : 1245
//    출력 : 4 34 234 1234
#include <stdio.h>

int main(void){
    int number;
    
    printf("Input: ");
    scanf("%d", &number);

    printf("OutPut: ");
    int divi = 1;
    while (divi <= number) {
        int divided = number % (divi * 10);
        printf("%d ", divided);
        divi *= 10;
    }
}
