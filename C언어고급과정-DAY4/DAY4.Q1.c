#include <stdio.h>    // 표준 입출력 라이브러리
#include <stdlib.h>   // 문자열 변환 함수 포함
/*stdlib.h의 사용 이유:
표준 라이브러리로 다양한 유틸리티 함수들을 포함하고 있습니다.
특히 strtoll 함수는 문자열을 특정 기수(여기서는 2진수)로 변환할 때 사용됩니다. 이 함수가 포함된 라이브러리가 stdlib.h입니다.
*/

int main(void) {
    char binaryStr[100];    // 길이가 100 미만인 2진수 문자열을 저장할 배열 선언
    printf("0과 1로 구성된 문자열을 입력: ");
    scanf("%s", binaryStr);    // 사용자로부터 문자열 입력을 받아 binaryStr 배열에 저장
    
    // 2진수를 10진수 정수로 변환
    long long decimal = strtoll(binaryStr, NULL, 2);
    
    /*strtoll 함수:
    strtoll은 문자열을 long long 타입의 정수로 변환하는 함수
    프로토타입: 
    long long int strtoll
    (const char *nptr 변환할 문자열의 포인터,
    char **endptr변환이 끝난 위치의 포인터,
    int base진법);
    */
    
    // 10진수 정수를 16진수로 변환하여 대문자로 출력
    printf("16진수로 변환된 값: %llX\n", decimal);
    
    /*
    ll: long long 타입을 나타냅니다.
    X: 정수를 16진수 대문자로 출력합니다.
    */
    
}