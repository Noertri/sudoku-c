#include<stdio.h>
#include "libsudoku.h"


int puzzle[9][9] = {
    {4, 0, 0,     0, 7, 0,     0, 0, 0},
    {0, 0, 5,     0, 0, 0,     0, 0, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 0},
    
    {9, 0, 0,     0, 0, 0,     0, 0, 7},
    {0, 0, 0,     0, 9, 0,     0, 2, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 0},
    
    {0, 0, 0,     0, 0, 0,     3, 0, 0},
    {5, 0, 0,     0, 1, 0,     0, 0, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 4}
};


// int solver(int (*puzzle_ptr)[9], int *count);


int main()
{
    printf("Sudoku: \n");
    print_puzzle(puzzle);
    printf("\nSolusi: \n");  
    int iter = 0;
    if (solver(puzzle, &iter) == 0) print_puzzle(puzzle);
    else printf("%d\n", solver(puzzle, &iter));
    printf("Jumlah iterasi = %d\n", iter);
    
    return 0;
}
