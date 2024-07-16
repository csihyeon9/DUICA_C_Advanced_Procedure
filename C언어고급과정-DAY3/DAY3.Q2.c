#include <stdio.h>

// 암호화 함수
void encrypt(char* text, char* key, char* result) {
    int i = 0, j = 0;
    
    while (text[i] != '\0') {
        // 키의 각 문자를 숫자로 변환하여 사용
        int shift = key[j] - '0'; // '0' ~ '9' 문자를 숫자로 변환
        result[i] = ((text[i] - 'A' + shift) % 26) + 'A'; 
        i++;
        j++;
        
        // 키의 끝에 도달하면 처음으로 돌아감
        if (key[j] == '\0') {
            j = 0;
        }
    }
    result[i] = '\0'; // 결과 문자열의 끝에 널 문자 추가
}

int main(void) {
    char text[100], key[100], result[100];

    // 사용자로부터 문자열과 키 입력 받기
    printf("문자열을 입력하세요 (대문자): ");
    scanf("%99s", text); // 99자까지 입력 받기, 버퍼 오버플로우 방지

    printf("키를 입력하세요 ('0' ~ '9'로 구성된 문자열): ");
    scanf("%99s", key); // 99자까지 입력 받기, 버퍼 오버플로우 방지

    // 대문자로만 이루어졌는지 검사 (선택적으로 추가할 수 있음)
    int isValid = 1;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] < 'A' || text[i] > 'Z') {
            isValid = 0;
            break;
        }
    }
    if (!isValid) {
        printf("오류: 입력된 문자열은 대문자로만 구성되어야 합니다.\n");
        return 1;
    }

    // 암호화 함수 호출
    encrypt(text, key, result);
    // 암호화된 결과 출력
    printf("암호화된 결과: %s\n", result);
}
