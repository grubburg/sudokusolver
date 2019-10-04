//
// Created by John Stephenson on 21/1/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sudokuhelper.h"


void print_help(){
    printf("Enter your sudoku as a series of space delimited row, using 0 to represent blank spaces.\n");
    printf("For example: \n");
    printf("0 0 0 0 0 0 0 1 2\n");
    printf("0 0 0 0 3 5 0 0 0\n");
    printf("0 0 0 6 0 0 0 7 0\n");
    printf("7 0 0 0 0 0 3 0 0\n");
    printf("0 0 0 4 0 0 8 0 0\n");
    printf("1 0 0 0 0 0 0 0 0\n");
    printf("0 0 0 1 2 0 0 0 0\n");
    printf("0 8 0 0 0 0 0 4 0\n");
    printf("0 5 0 0 0 0 6 0 0\n");
}

void read_board(boardtype *b){

    /* reads the board entered line by line into an array, performs sanity checks on the input,
     * then stores it in a 2 dimensional array.
     */

    int i, j;


    int row[DIMENSION + 1];

    b->freecount = 0;
    b->movecounter = 0;

    printf("Enter your sudoku:\n");

    for(i = 0; i < DIMENSION; i++) {

        scanf("%d %d %d %d %d %d %d %d %d", &row[0], &row[1], &row[2], &row[3], &row[4], &row[5], &row[6], &row[7],
              &row[8]);

        for(j = 0; j < DIMENSION; j++) {

            if((row[j]>9)||(row[j]<0)){
                printf("Critical input error!\n");
                exit(1);
            }

            b->m[j][i]=row[j];
            if(!row[j]) {
                b->freecount++;
            }
        }
    }

    if(b->freecount < 17){
        printf("Not a valid sudoku puzzle!\n");
        exit(1);
    }

    printf("Entered Board: \n");
    print_board(b);
}

void possible_values(int x, int y, boardtype *b, bool *possible){


    /* checks valid moves for a given tile */


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

int count_poss(int x, int y, boardtype *b){

    /* count the number of candidate moves for a given square */

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

void next_square(int *x, int *y, boardtype *b){

    /* choose the next square to fill based on which square has the fewest candidate moves
     *
     * If a square with 1 candidate move is found, it is automatically chosen
     *
     * If a square with 0 candidate moves is found, the current board is rejected as the
     * path to a complete solution and the function returns*/

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


void make_move(int a[], int k, boardtype *b){

    b->m[b->move[k].x][b->move[k].y]=a[k];
    b->freecount--;
}

void unmake_move(int k, boardtype *b){

    b->m[b->move[k].x][b->move[k].y]=0;
    b->freecount++;
}


bool is_a_solution(boardtype *b){

    /* validates the current board state as a solution by checking
     * the number of free squares remaining. If it is 0, a solution
     * has been achieved (in theory) */

    b->movecounter++;

    if(b->freecount==0){

        return true;
    }

    return false;
}

void process_solution(boardtype *b){

    if(b->ratemode){
        print_rating(b);
        exit(0);
    }

    else{
        printf("Found Solution!\n");
        print_board(b);
        exit(0);
    }
}

double rate_sudoku(boardtype *b){

    /* An attempt at a rating system
     *
     * takes the log of the numbe rof moves required to solve and trandforms it
     * to make it out of ten (roughly, rating can exceed 10/10)*/


    double rating;

    rating = 10 - 300/(float)(b->movecounter);

    return rating;

}

void print_rating(boardtype *b){

    printf("Sudoku difficulty rating: %lf /10\n", rate_sudoku(b));
    printf("Moves taken: %d\n", b->movecounter);
}

void print_board(boardtype *b){

    /* print a formatted board */


    int i,j;

    for(i=0;i<DIMENSION;i++){

        if((i%3)==0){
            printf("+---------+---------+---------+\n");
        }

        for (j=0;j<DIMENSION;j++){
            if((j%3)==0){
                printf("|");
            }
            printf(" %d ", b->m[j][i]);
        }
        printf("|\n");
    }
    printf("+---------+---------+---------+\n");
    printf("\n");

}
