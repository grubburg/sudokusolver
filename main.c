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
        scanf("%d %d %d %d %d %d %d %d", &(b->m[0][i]), &(b->m[0][i]), &(b->m[0][i]), &(b->m[0][i]),
              &(b->m[0][i]), &(b->m[0][i]), &(b->m[0][i]), &(b->m[0][i]));


    }
}



void printboard(boardtype *b){

    int i,j;
    for(i=0;i<DIMENSION+1;i++){
        for (j=0;j<DIMENSION;j++){
            
        }
    }

}



int main() {
    printf("Hello, World!\n");
    boardtype *b;

    readboard(b);
    return 0;
}