#include <stdio.h>

// 비트의 개수를 세는 함수
int countBits(int number, int flag) {
    int count = 0;
    
    if (flag == 1) {
        // 1인 비트의 개수 세기
        while (number) {
            count += number & 1;
            number >>= 1;
        }
    } else if (flag == 0) {
        // 0인 비트의 개수 세기
        int totalBits = sizeof(number) * 8;  // 총 비트 수 (예: 32비트)
        while (number) {
            if ((number & 1) == 0) {
                count++;
            }
            number >>= 1;
        }
        count += totalBits - (sizeof(number) * 8 - __builtin_clz(number) - count); // 남은 0 비트 추가
    }
    
    return count;
}

int main(void) {
    int number, flag;
    
    // 사용자로부터 양수와 구분자 입력받기
    printf("양수를 입력하세요: ");
    scanf("%d", &number);

    printf("구분자를 입력하세요 (0 또는 1): ");
    scanf("%d", &flag);

    // 구분자가 0 또는 1인지 확인
    if (flag != 0 && flag != 1) {
        printf("유효하지 않은 구분자입니다. 0 또는 1을 입력하세요.\n");
        return 1;
    }

    // 비트의 개수 세기
    int result = countBits(number, flag);

    // 결과 출력
    if (flag == 1) {
        printf("값에서 1인 비트의 개수: %d\n", result);
    } else {
        printf("값에서 0인 비트의 개수: %d\n", result);
    }
}
