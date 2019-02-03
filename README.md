#Sudoku Solver
A command line program to solve sudoku puzzles

##How to get it running

###Installation

1. Clone the repository:
```
git clone http://github.com/grubburg/sudokusolver.git
```
2. Enter the directory and run make:
```
cd sudokusolver
make
```
3. Run the program!
```
./sudoku
```


###How to use it:

Use the '-s' flag to enter solve mode, or the '-r' flag to enter rating mode.

```
./sudoku -s
Enter your sudoku:
0 0 0 0 0 0 0 1 2
0 0 0 0 3 5 0 0 0
0 0 0 6 0 0 0 7 0
7 0 0 0 0 0 3 0 0
0 0 0 4 0 0 8 0 0
1 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0
0 8 0 0 0 0 0 4 0
0 5 0 0 0 0 6 0 0
Johns-MacBook-Air:sudEntered Board:
+---------+---------+---------+
| 0  0  0 | 0  0  0 | 0  1  2 |
| 0  0  0 | 0  3  5 | 0  0  0 |
| 0  0  0 | 6  0  0 | 0  7  0 |
+---------+---------+---------+
| 7  0  0 | 0  0  0 | 3  0  0 |
| 0  0  0 | 4  0  0 | 8  0  0 |
| 1  0  0 | 0  0  0 | 0  0  0 |
+---------+---------+---------+
| 0  0  0 | 1  2  0 | 0  0  0 |
| 0  8  0 | 0  0  0 | 0  4  0 |
| 0  5  0 | 0  0  0 | 6  0  0 |
+---------+---------+---------+

Found Solution!
+---------+---------+---------+
| 6  7  3 | 8  9  4 | 5  1  2 |
| 9  1  2 | 7  3  5 | 4  8  6 |
| 8  4  5 | 6  1  2 | 9  7  3 |
+---------+---------+---------+
| 7  9  8 | 2  6  1 | 3  5  4 |
| 5  2  6 | 4  7  3 | 8  9  1 |
| 1  3  4 | 5  8  9 | 2  6  7 |
+---------+---------+---------+
| 4  6  9 | 1  2  8 | 7  3  5 |
| 2  8  7 | 3  5  6 | 1  4  9 |
| 3  5  1 | 9  4  7 | 6  2  8 |
+---------+---------+---------+
```



