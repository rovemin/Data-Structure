/* ����ü�� ����� ����ü ������ ����(typedef ���) */

#include <stdio.h>
#include <string.h>

typedef struct studentTag {		//�л� ����ü ����
	char name[10];		//�л��� �̸��� ������ ���� �迭
	int age;			//�л��� ���̸� ������ ���� ����
	double gpa;			//��� ������ ������ �Ǽ� ����
} student;

void main() {
	student s1 = {"����ȭ", 20, 4.3}; //s1 �л� ����, �ʱ�ȭ
    student s2 = {"����ȭ", 21, 3.7}; //s2 �л� ����, �ʱ�ȭ
    printf("%s, %d, %.2f \n", s1.name, s1.age, s1.gpa);
    printf("%s, %d, %.2f \n", s2.name, s2.age, s2.gpa);
}