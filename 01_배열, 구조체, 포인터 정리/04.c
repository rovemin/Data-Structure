/* ����ü�� �迭�� Ȱ�� */

#include <stdio.h>
#include <string.h>

typedef struct studentTag {		//�л� ����ü ����
	char name[10];		//�л��� �̸��� ������ ���� �迭
	int age;			//�л��� ���̸� ������ ���� ����
	double gpa;			//��� ������ ������ �Ǽ� ����
} student;

void main() {
	student s[2] = {{"����ȭ", 20, 4.3}, {"����ȭ", 21, 3.7}};
    for(int i=0; i<2; i++) 
        printf("%s, %d, %.2f \n", s[i].name, s[i].age, s[i].gpa);
}