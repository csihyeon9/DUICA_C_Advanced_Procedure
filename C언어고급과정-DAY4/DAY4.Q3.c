#include <stdio.h> 
//이 문제는 팰린드롬 알고리즘으로 보인다
/*
팰린드롬 알고리즘이란?

회문(Palindrome)은 똑바로 읽어도 거꾸로 읽어도 같은 문자열을 의미한다.
ex. 기러기, 토마토, 스위스, 인도인, 별똥별 …

*/

int stringLength(const char* str);
int longestPalindrome(const char* str);


int main(void) {
    /*
    문자열을 입력받아 str 배열에 저장합니다.
    longestPalindrome 함수를 호출하여 입력된 문자열에서 가장 긴 
    팰린드롬 부분 문자열의 길이를 계산합니다. 그후, 결과를 출력합니다.
    */
    char str[100];
    printf("문자열을 입력: ");
    scanf("%s", str);

    int result = longestPalindrome(str);
    printf("가장 긴 팰린드롬 부분 문자열의 길이: %d\n", result);

    return 0;
}

// 문자열의 길이를 계산하는 함수
/*
문자열의 길이를 계산하여 반환합니다.
while 루프를 사용하여 문자열 끝('\0')에 도달할 때까지 문자의 개수를 셉니다.
*/
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 가장 긴 팰린드롬 부분 문자열의 길이를 찾는 함수
int longestPalindrome(const char* str) {
    int n = stringLength(str);
    if (n == 0) return 0;

    int dp[100][100] = {0}; // dp 테이블 초기화
    int maxLength = 1; // 팰린드롬의 최소 길이는 1

    /*
    dp[i][j]는 str[i]부터 str[j]까지의 부분 문자열이 팰린드롬인지 여부를 나타냅니다.
    모든 길이 1인 부분 문자열은 팰린드롬이므로 dp[i][i]를 1로 설정합니다.
    maxLength를 1로 초기화합니다.
    */


    // 길이 1인 모든 부분 문자열은 팰린드롬
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // 길이 2인 부분 문자열 체크
    /*
    길이 2인 부분 문자열이 팰린드롬인지 확인하고, 팰린드롬이면 dp[i][i + 1]을 1로 
    설정하고 maxLength를 2로 갱신합니다.
    */
    
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            maxLength = 2;
        }
    }

    // 길이 3 이상인 부분 문자열 체크
    /*
    길이 3 이상인 부분 문자열의 경우, 양 끝 문자가 같고 내부 부분 문자열(dp[i + 1][j - 1])이 
    팰린드롬이면 해당 부분 문자열도 팰린드롬입니다.
    이 경우 dp[i][j]를 1로 설정하고, 현재 부분 문자열의 길이가 maxLength보다 크면 maxLength를 갱신합니다.
    */
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;

            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }

    return maxLength; //최종 결과 반환
}