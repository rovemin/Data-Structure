/* 구조체의 선언과 구조체 변수의 생성(typedef 사용) */

#include <stdio.h>
#include <string.h>

typedef struct studentTag {		//학생 구조체 선언
	char name[10];		//학생의 이름을 저장할 문자 배열
	int age;			//학생의 나이를 저장할 정수 변수
	double gpa;			//평균 평점을 저장할 실수 변수
} student;

void main() {
	student s1 = {"김이화", 20, 4.3}; //s1 학생 생성, 초기화
    student s2 = {"최이화", 21, 3.7}; //s2 학생 생성, 초기화
    printf("%s, %d, %.2f \n", s1.name, s1.age, s1.gpa);
    printf("%s, %d, %.2f \n", s2.name, s2.age, s2.gpa);
}