//입력, 출력 파일 이름을 입력받아서 행 단위로 라인 번호를 붙여서 출력 파일에 저장하시오
#include <stdio.h>

int main(void){
    char inputFileName[100];
    char outputFileName[100];
    char buffer[1024];
    int lineNumber = 1;

    printf("입력 파일 이름을 입력하세요: ");
    scanf("%s", inputFileName);
    printf("출력 파일 이름을 입력하세요: ");
    scanf("%s", outputFileName);

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    while(fgets(buffer, 256, inputFile) != NULL){
        fprintf(outputFile, "%d: %s", lineNumber, buffer);
        lineNumber++;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("%s\n", outputFileName);
}
