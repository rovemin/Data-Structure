/* ����ü�� ����� ����ü ������ ���� */

#include <stdio.h>
#include <string.h>

struct studentTag {		//�л� ����ü ����
	char name[10];		//�л��� �̸��� ������ ���� �迭
	int age;			//�л��� ���̸� ������ ���� ����
	double gpa;			//��� ������ ������ �Ǽ� ����
};

void main() {
	struct studentTag s1;	//�л� 1�� ����
	strcpy(s1.name, "kim");	//s1 �л��� �̸� ����
	s1.age = 20;			//s1 �л��� ���� ����
	s1.gpa = 4.3;			//s1 �л��� ��� ���� ����
	printf("%s, %d, %.2f \n", s1.name, s1.age, s1.gpa);
}