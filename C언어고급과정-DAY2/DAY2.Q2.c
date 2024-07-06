//문제 2: 문자를 입력( 부호 없는 문자형으로 처리)받아서 1비트씩 오른쪽 로테이션
//        시키면서 8회 반복하여 2진수로 출력하시오. 오른쪽 로테이션은 오른쪽으로
//        1비트 이동( >> 연산)하면 오른쪽에 잇는 비트가 제거되는데, 이 비트를
//        왼쪽의 최상위 비트에 채워 넣는 작업이다

#include <stdio.h>

// 함수 선언
void printBinary(unsigned char value);          // 2진수로 변환하여 출력하는 함수
unsigned char rotateRight(unsigned char value); // 오른쪽으로 1비트씩 로테이션하는 함수

int main(void) {
    unsigned char ch; // 입력된 문자를 저장할 변수

    // 사용자에게 문자 입력을 요청
    printf("문자 입력: ");
    scanf("%c", &ch); // 한 문자를 입력받아 ch에 저장

    // 입력받은 문자를 8회 반복하여 오른쪽으로 1비트씩 로테이션하면서 출력
    for (int i = 0; i < 8; i++) {
        printBinary(ch); // 현재 문자를 2진수로 출력
        ch = rotateRight(ch); // 문자를 오른쪽으로 1비트씩 로테이션
    }
}

// 입력된 값을 2진수로 변환하여 출력하는 함수
void printBinary(unsigned char value) {
    for (int i = 7; i >= 0; i--) { // 8비트를 역순으로 순회
        printf("%d", (value >> i) & 1); // 각 비트를 추출하여 출력
    }
    printf("\n"); // 줄바꿈
}

// 입력된 값의 비트를 오른쪽으로 1회 이동시키는 함수
unsigned char rotateRight(unsigned char value) {
    return (value >> 1) | (value << 7); // 오른쪽으로 1비트 이동 후, 최상위 비트를 최하위 비트로 이동
}
