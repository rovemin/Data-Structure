/* 구조체의 선언과 구조체 변수의 생성 */

#include <stdio.h>
#include <string.h>

struct studentTag {		//학생 구조체 선언
	char name[10];		//학생의 이름을 저장할 문자 배열
	int age;			//학생의 나이를 저장할 정수 변수
	double gpa;			//평균 평점을 저장할 실수 변수
};

void main() {
	struct studentTag s1;	//학생 1명 생성
	strcpy(s1.name, "kim");	//s1 학생의 이름 저장
	s1.age = 20;			//s1 학생의 나이 저장
	s1.gpa = 4.3;			//s1 학생의 평균 평점 저장
	printf("%s, %d, %.2f \n", s1.name, s1.age, s1.gpa);
}