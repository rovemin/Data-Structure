/* ����ü �������� Ȱ��1 */

#include <stdio.h>

typedef struct StudentInfo {
    char name[10];      //�̸�
    int korean;         //���� ����
    int english;       //���� ����
    int math;           //���� ����
    double average;     //���� ���
} student;

int main() {
    student kim = {"kim, ewha", 100, 90, 95, 95.0};
    student class[3] = {{"����ȭ", 90, 90, 90, 90.0},
        {"����ȭ", 100, 90, 95, 95.0}, {"Choi", 80, 90, 70, 80.0}};
    student* p1, * p2;

    p1 = &kim;      //�л� kim�� ����Ų��
    p2 = class;     //�б� 3�� �߿��� ù° �л��� ����Ų��

    printf("����ȭ�� ���� ���� = %d\n", kim.korean);    //������.���
    printf("����ȭ�� ���� ���� = %d\n", p1->korean);    //������->���

    printf("����ȭ�� ���� ���� = %d\n", p2[1].math);    //�������� �迭 ���ؽ� ǥ��.���
    printf("����ȭ�� ���� ���� = %d\n", (p2+2)->english);   //*(p2+2).english �� �ƴ�
    printf("����ȭ�� ���� ���� = %d\n", p2[2].english); //*(p2+2).english �� �ƴ�
    printf("����ȭ�� �̸��� ù ���� = %c\n", p1->name[0]);  //����� �迭 ���� ����
    printf("����ȭ�� �̸��� ù ���� = %c\n", p1[0].name[0]);    //����� �迭 ���� ����
    printf("����ȭ�� �̸��� �ι�° ���� = %c\n", (p2+2)->name[1]);  //�����ͷ� �迭 ���� ����
    
    return 0;
}