#include <stdio.h> //표준 입출력 라이브러리 사용.

#define MAX 160 
//계산 결과를 저장하기 위한 배열의 크기 정의.

// 팩토리얼 함수
void factorial(int n) {
    int result[MAX] = {1}; // 0! = 1
    int result_size = 1; // 현재 결과의 자리 수
    int carry, prod;

    for (int i = 2; i <= n; i++) {
        carry = 0;
        for (int j = 0; j < result_size; j++) {
            prod = result[j] * i + carry;
            result[j] = prod % 10; // 현재 자리의 값 저장
            carry = prod / 10; // 자리 올림 값 저장
        }
        while (carry) {
            result[result_size++] = carry % 10;
            carry /= 10;
        }
    }

    printf("%d! = ", n);
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

/*
변수 설명:
result[MAX]: 팩토리얼 결과를 저장하는 배열.
result_size: 배열의 유효 자리 수.
carry: 자리 올림 값 저장.
prod: 중간 계산 값 저장.

계산 과정:
각 숫자 i에 대해, 현재 result 배열의 각 자리와 i를 곱해 prod를 계산.
prod의 일의 자리 값을 result에 저장하고, 나머지는 carry에 저장.
자리 올림(carry)이 존재할 경우, result 배열에 추가.
*/


int main(void) {
    int n;
    printf("0 ~ 100 입력: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        printf("0 ~ 100을 입력하시오\n");
    } else {
        factorial(n);
    }
}
/*
사용자로부터 0에서 100 사이의 숫자를 입력받음.
입력값이 유효하면 factorial 함수를 호출하여 결과를 계산하고 출력.
*/

/*
핵심:
큰 숫자 처리: 배열을 사용하여 큰 숫자의 계산과 출력을 가능하게 합니다.
자리 올림 처리: 각 자리의 계산 후 자리 올림을 처리하여 정확한 결과를 얻습니다.
유효성 검사: 사용자 입력을 검증하여 범위 외의 입력에 대해 적절한 메시지를 출력합니다.

결론:
이 프로그램은 큰 숫자의 팩토리얼을 계산하는 데 적합하며, 특히 숫자가 커질수록 일반적인 데이터 타입으로는 처리할 수 없는 경우 유용합니다.
팩토리얼 계산의 기본 원리와 자리 올림 처리의 중요성을 이해하는 데 도움을 줍니다.
*/
//수정 !!
#include <stdio.h>

#define MAX 160

void factorial(int n) {
    int result[MAX] = {1};
    int result_size = 1;
    int carry, prod;

    for (int i = 2; i <= n; i++) {
        carry = 0;
        for (int j = 0; j < result_size || carry; j++) {
            if (j == result_size) {
                result_size++;
            }
            prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }
    }
    
/*
변경 사항:
통합된 for 루프: for 루프 조건을 j < result_size || carry로 수정하여 
자리 올림이 있을 때까지 루프가 지속.

배열 크기 증가: 
if (j == result_size) 조건을 추가하여 새로운 자리가 필요할 경우 result_size를 증가시키고,
이로 인해 carry가 배열의 범위를 초과하여도 처리. 이제 carry 처리가 for 루프 내에서 직접 이루어지며, 
자리 올림과 계산이 통합되었다.
*/

/*    while (carry) {
        result[result_size++] = carry % 10;
        carry /= 10;
    }
*/

    printf("%d! = ", n);
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("0 ~ 100 입력: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        printf("0 ~ 100을 입력하시오\n");
    } else {
        factorial(n);
    }
}
