#include <stdio.h>
#include <stdlib.h>  // atoi 함수 사용을 위한 라이브러리

// 문자열을 정수로 변환하는 함수
int stringToInt(const char* str) {
    return atoi(str);  // atoi 함수를 사용하여 문자열을 정수로 변환
}

int main(void) {
    char numStr[10];  // 길이가 10 미만인 숫자 문자열을 저장할 배열 선언
    printf("숫자로 구성된 문자열을 입력: ");
    scanf("%s", numStr);  // 사용자로부터 문자열 입력을 받아 numStr 배열에 저장
    
    // 함수 호출하여 문자열을 정수로 변환
    int number = stringToInt(numStr);
    
    // 변환된 정수를 출력
    printf("변환된 정수: %d\n", number);
    
}
