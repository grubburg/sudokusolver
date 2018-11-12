#include <stdio.h>


#define DIMENSION 9
#define NCELLS DIMENSION*DIMENSION


typedef struct{

    int x,y;

} point;



typedef struct {

    int m[DIMENSION + 1][DIMENSION + 1];
    int freecount;
    point move[NCELLS + 1];

}boardtype;

void readboard (boardtype *b);




void readboard(boardtype *b){

    int i, j;

    for(i=0;i<DIMENSION;i++){
        scanf("%d %d %d %d %d %d %d %d %d", &(b->m[0][i]), &(b->m[1][i]), &(b->m[2][i]), &(b->m[3][i]),
              &(b->m[4][i]), &(b->m[5][i]), &(b->m[6][i]), &(b->m[7][i]), &(b->m[8][i]));


    }
}



void printboard(boardtype *b){

    int i,j;
    for(i=0;i<DIMENSION;i++){
        for (j=0;j<DIMENSION;j++){
            printf("%d ", b->m[j][i]);


        }
        printf("\n");
    }

}



int main() {
    printf("Hello, World!\n");
    boardtype *b;

    readboard(b);
    printboard(b);
    return 0;
}