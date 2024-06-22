//문제1: 2개의 정수를 입력받아서 앞의 수에서 뒤의 수를 뺸 결과를 반복해서 출력(음수면 종료)
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d %d ", a, b);
    while (1) {
        int result = a - b;
        if (result < 0) {
            break;
        }
        printf("%d ", result);
        a = b;
        b = result;
    }
}


