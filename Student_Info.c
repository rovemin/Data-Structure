#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum level { freshman = 1, sophomore, junior, senior }; //�г�
struct student {        //�л� ������ ������ ����ü ���
    char name[20];      //�̸�
    enum level year;    //�г�
    int score;          //����
    struct student* next;   //�ٸ� �л��� ����ų ������
};
typedef struct student STUDENT; //�г��� ����

STUDENT * buildClass(STUDENT* list) {
    while (1) {
        STUDENT* s = (STUDENT*)malloc(sizeof(STUDENT));
        printf("�л� ���� (�̸� �г� ����): ");
        scanf("%s %d %d", s->name, &s->year, &s->score);
        if ((strcmp(s->name,"��") == 0) && (s->year == 0) && (s->score == 0))
            break;
        s->next = list;
        list = s;
    }
    return list;
    printf("\n");
}

void printClass(STUDENT* list) {
    printf("\n** �л� ����Ʈ ��� **\n");
    for (STUDENT* s = list; s != NULL; s = s->next)
        printf("%s : %d�г�, %d��\n", s->name, s->year, s->score);
    printf("\n");
}

void printStudent(STUDENT* list, char* p) {
    for (STUDENT* s = list; s != NULL; s = s->next)
        if(strcmp(s->name, p) == 0) {
            printf("%s : %d�г�, %d��\n", s->name, s->year, s->score);
            break;
        }
    printf("\n");
}

void findStudents(STUDENT* list, int low, int high) {
    printf("*** %d���� %d�� ������ �л� ���� ***\n", low, high);
    for (STUDENT* s = list; s != NULL; s = s->next) {
        if((low <= (s->score)) && ((s->score) <= high)) 
            printf("%s : %d�г�, %d��\n", s->name, s->year, s->score);
    }
    printf("\n");
}

void printFour(STUDENT* list) {
    printf("*** 4 �л����� �̸� ***\n");
    STUDENT* p = list;
    printf("%s\n", p->name);
    printf("%s\n", p->next->name);
    printf("%s\n", p->next->next->name);
    printf("%s\n", p->next->next->next->name);
}

int main() {
    STUDENT* list = NULL;
    list = buildClass(list);
    printClass(list);
    printStudent(list, "����ȭ");
    findStudents(list, 70, 80);
    printFour(list);
    return 0;
}
