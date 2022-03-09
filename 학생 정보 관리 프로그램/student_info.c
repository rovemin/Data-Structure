#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum level { freshman = 1, sophomore, junior, senior }; //학년
struct student {        //학생 정보를 저장할 구조체 모양
    char name[20];      //이름
    enum level year;    //학년
    int score;          //점수
    struct student* next;   //다른 학생을 가리킬 포인터
};
typedef struct student STUDENT; //닉네임 정의

STUDENT * buildClass(STUDENT* list) {
    while (1) {
        STUDENT* s = (STUDENT*)malloc(sizeof(STUDENT));
        printf("학생 정보 (이름 학년 점수): ");
        scanf("%s %d %d", s->name, &s->year, &s->score);
        if ((strcmp(s->name,"끝") == 0) && (s->year == 0) && (s->score == 0))
            break;
        s->next = list;
        list = s;
    }
    return list;
    printf("\n");
}

void printClass(STUDENT* list) {
    printf("\n** 학생 리스트 출력 **\n");
    for (STUDENT* s = list; s != NULL; s = s->next)
        printf("%s : %d학년, %d점\n", s->name, s->year, s->score);
    printf("\n");
}

void printStudent(STUDENT* list, char* p) {
    for (STUDENT* s = list; s != NULL; s = s->next)
        if(strcmp(s->name, p) == 0) {
            printf("%s : %d학년, %d점\n", s->name, s->year, s->score);
            break;
        }
    printf("\n");
}

void findStudents(STUDENT* list, int low, int high) {
    printf("*** %d점과 %d점 사이의 학생 정보 ***\n", low, high);
    for (STUDENT* s = list; s != NULL; s = s->next) {
        if((low <= (s->score)) && ((s->score) <= high)) 
            printf("%s : %d학년, %d점\n", s->name, s->year, s->score);
    }
    printf("\n");
}

void printFour(STUDENT* list) {
    printf("*** 4 학생들의 이름 ***\n");
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
    printStudent(list, "윤이화");
    findStudents(list, 70, 80);
    printFour(list);
    return 0;
}
