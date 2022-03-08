/* 구조체 포인터의 활용1 */

#include <stdio.h>

typedef struct StudentInfo {
    char name[10];      //이름
    int korean;         //국어 점수
    int english;       //영어 점수
    int math;           //수학 점수
    double average;     //과목 평균
} student;

int main() {
    student kim = {"kim, ewha", 100, 90, 95, 95.0};
    student class[3] = {{"박이화", 90, 90, 90, 90.0},
        {"송이화", 100, 90, 95, 95.0}, {"Choi", 80, 90, 70, 80.0}};
    student* p1, * p2;

    p1 = &kim;      //학생 kim을 가리킨다
    p2 = class;     //학급 3명 중에서 첫째 학생을 가리킨다

    printf("김이화의 국어 점수 = %d\n", kim.korean);    //변수명.멤버
    printf("김이화의 국어 점수 = %d\n", p1->korean);    //포인터->멤버

    printf("송이화의 수학 점수 = %d\n", p2[1].math);    //포인터의 배열 인텍스 표현.멤버
    printf("최이화의 영어 점수 = %d\n", (p2+2)->english);   //*(p2+2).english 가 아님
    printf("최이화의 영어 점수 = %d\n", p2[2].english); //*(p2+2).english 가 아님
    printf("김이화의 이름의 첫 글자 = %c\n", p1->name[0]);  //멤버의 배열 원소 접근
    printf("김이화의 이름의 첫 글자 = %c\n", p1[0].name[0]);    //멤버의 배열 원소 접근
    printf("최이화의 이름의 두번째 글자 = %c\n", (p2+2)->name[1]);  //포인터로 배열 원소 접근
    
    return 0;
}