//
// Created by John Stephenson on 21/1/19.
//

#ifndef SUDOKUSOLVER_SUDOKUHELPER_H
#define SUDOKUSOLVER_SUDOKUHELPER_H

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
void next_square(int *x, int *y, boardtype *b);
void make_move(int a[], int k, boardtype *b);
void unmake_move(int k, boardtype *b);
bool is_a_solution(boardtype *b);
void process_solution(boardtype *b);
int count_poss(int x, int y, boardtype *b);


#endif //SUDOKUSOLVER_SUDOKUHELPER_H
