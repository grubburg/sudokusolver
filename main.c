#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudokuhelper.h"

void backtrack(int a[], int k, boardtype *board);
void construct_candidates(int k, boardtype *b, int c[], int *ncandidates);


void construct_candidates(int k, boardtype *b, int c[], int *ncandidates){

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

int main() {

    boardtype *b;

    int k=0;
    int *a;

    a = (int *)malloc(NCELLS*sizeof(int));

    read_board(b);

    printf("Input:\n");
    print_board(b);

    backtrack(a,k,b);

    return 0;
}