#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

void read_board(boardtype *b);
void print_board(boardtype *b);
void possible_values(int x, int y, boardtype *b, bool *possible);
void check_vert(int x, boardtype *b, bool *possible);
void check_horz(int y, boardtype *b, bool *possible);
void check_square(int x, int y, boardtype *b, bool *possible);
void backtrack(int a[], int k, boardtype *board);
void construct_candidates(int k, boardtype *b, int c[], int *ncandidates);
void next_square(int *x, int *y, boardtype *b);
void make_move(int a[], int k, boardtype *b);
void unmake_move(int k, boardtype *b);
bool is_a_solution(boardtype *b);
void process_solution(boardtype *b);
int count_poss(int x, int y, boardtype *b);


void backtrack(int a[], int k, boardtype *board){

    int c[DIMENSION];
    int ncandidates;
    int i;


    if(is_a_solution(board)){
        process_solution(board);

    }
    else{

        k = k+1;
        construct_candidates(k, board, c, &ncandidates);

        for(i=0;i<ncandidates;i++){
            a[k]=c[i];
            make_move(a,k,board);
            backtrack(a,k,board);
            unmake_move(k,board);
            if(board->freecount==0){
                return;

            }
        }
    }
}


void make_move(int a[], int k, boardtype *b){

    b->m[b->move[k].x][b->move[k].y]=a[k];
    b->freecount--;

}

void unmake_move(int k, boardtype *b){

    b->m[b->move[k].x][b->move[k].y]=0;
    b->freecount++;
}


bool is_a_solution(boardtype *b){

    if(b->freecount==0){

        return true;
    }

    return false;
}

void process_solution(boardtype *b){
    printf("Found Solution!\n");
    print_board(b);
    exit(0);

}


void construct_candidates(int k, boardtype *b, int *c, int *ncandidates){

    int x,y,i;

    bool possible[DIMENSION+1];

    next_square(&x,&y,b);

    b->move[k].x=x;
    b->move[k].y=y;

    *ncandidates = 0;

    if((x<0)&&(y<0)){

        return;
    }



    possible_values(x,y,b,possible);

    for(i=0;i<DIMENSION+1;i++){

        if(possible[i]){

            c[*ncandidates]=i;
            *ncandidates = *ncandidates + 1;
        }

    }


}

void next_square(int *x, int *y, boardtype *b){



    int i, j;
    int count;
    int min_count=9;

    *x=-1;
    *y=-1;


    for(i=0;i<DIMENSION;i++){

        for(j=0;j<DIMENSION;j++){

            if(b->m[i][j]==0) {
                count = count_poss(i,j,b);


                if (count == 0) {
                    *x = -1;
                    *y = -1;
                    return;
                }

                if (count == 1) {
                    *x = i;
                    *y = j;

                }

                else if ((count < min_count) && (count > 0)) {

                    *x = i;
                    *y = j;
                    min_count = count;

                }
            }
        }
    }
}


int count_poss(int x, int y, boardtype *b){

    int count = 0;
    bool possible[DIMENSION + 1];

    int i;
    for(i=0;i<DIMENSION+1;i++){
        possible[i] = true;
    }

    check_vert(x, b, possible);
    check_horz(y, b, possible);
    check_square(x, y, b, possible);

    for(i=1;i<DIMENSION+1;i++){

        if(possible[i]){
            count = count + 1;
        }
    }
    return count;
}




void possible_values(int x, int y, boardtype *b, bool *possible){

    int i;
    for(i=0;i<DIMENSION+1;i++){
        possible[i] = true;
    }

    check_vert(x, b, possible);
    check_horz(y, b, possible);
    check_square(x, y, b, possible);

}

void check_vert(int x, boardtype *b, bool *possible){

    int i;

    for(i=0;i<DIMENSION;i++){

        possible[b->m[x][i]]=false;
    }
}

void check_horz(int y, boardtype *b, bool *possible){

    int i;

    for(i=0;i<DIMENSION;i++){
        possible[b->m[i][y]]=false;
    }
}

void check_square(int x, int y, boardtype *b, bool *possible){

    int i, j;

    int xind = (x/3)*3;
    int yind = (y/3)*3;


    for(i=xind;i<(xind+3);i++){
        for(j=yind;j<(yind+3);j++){
            possible[b->m[i][j]]=false;
        }
    }
}


void read_board(boardtype *b){

    int i, j;


    int row[DIMENSION + 1];

    b->freecount = 0;

    for(i = 0; i < DIMENSION; i++) {

        scanf("%d %d %d %d %d %d %d %d %d", &row[0], &row[1], &row[2], &row[3], &row[4], &row[5], &row[6], &row[7],
              &row[8]);

        for(j = 0; j < DIMENSION; j++) {

            b->m[j][i]=row[j];
            if(!row[j]) {
                b->freecount++;
            }
        }
    }
}


void print_board(boardtype *b){

    int i,j;

    printf("\n");

    for(i=0;i<DIMENSION;i++){
        for (j=0;j<DIMENSION;j++){
            printf("%d ", b->m[j][i]);


        }
        printf("\n");


    }
    printf("\n");
}


int main() {

    boardtype *b;

    int k=0;
    int *a;

    a = (int *)malloc(NCELLS*sizeof(int));

    read_board(b);
    backtrack(a,k,b);
    print_board(b);
    return 0;
}