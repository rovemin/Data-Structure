/* �迭 �ε����� ������ */

 #include <stdio.h>

 int main() {
     int A[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

     printf("(1) A[i][j] ���� \n");
     for (int i=0; i<3; i++) {
         for (int j=0; j<4; j++)
            printf("%3d", A[i][j]);
        printf("\n");
     }

     printf("\n(2) *(*(A+i)+j) ���� \n");
     for (int i=0; i<3; i++) {
         for (int j=0; j<4; j++)
            printf("%3d", *(*(A+i)+j));
        printf("\n");
     }

     printf("\n(3) *(A[i]+j) ���� \n");
     for (int i=0; i<3; i++) {
         for (int j=0; j<4; j++)
            printf("%3d", *(A[i]+j));
        printf("\n");
     }
     
     return 0;
 }
