#include<stdio.h>


int puzzle[9][9] = {
    {4, 0, 0,     0, 7, 0,     0, 0, 0},
    {0, 0, 5,     0, 0, 0,     0, 0, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 0},
    
    {9, 0, 0,     0, 0, 0,     0, 0, 0},
    {0, 0, 0,     0, 5, 0,     0, 0, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 0},
    
    {0, 0, 0,     0, 0, 0,     0, 0, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 0},
    {0, 0, 0,     0, 0, 0,     0, 0, 0}
};


int is_valid(int (*puzzle_ptr)[9], int row, int col, int target)
{
    // cek baris
    for (int i = 0; i < 9; i++)
    {
        if (puzzle_ptr[row][i] == target) return 0;
    }
    
    // cek kolom
    for (int i = 0; i < 9; i++)
    {
        if (puzzle_ptr[i][col] == target) return 0;
    }
    
    // cek sub puzzle 3x3
    int iStart    = (row/3)*3;
    int jStart    = (col/3)*3;
    
    for (int i = iStart; i < iStart+3; i++) {
        for (int j = jStart; j < jStart+3; j++) {
            if (puzzle_ptr[i][j] == target) return 0;
        }
    }
    
    return 1;
}


int solver(int (*puzzle_ptr)[9], int *count);


void print_puzzle(int (*puzzle_ptr)[9]) {
    printf("\n");
   
   for (int i = 0; i < 9; i++) {
       
       if (i%3 == 0 && i != 0) printf("\n");
       printf("\t");
       
       for (int j = 0; j < 9; j++) {
            if (j%3 == 0 && j != 0) printf("\t");
            
            printf("%d ", puzzle_ptr[i][j]);
            
            // else if (j == 5) printf("\t");
            if (j == 8) printf("\n");
        }
        
        // else if (i == 5) printf("\n");
        if (i == 8) printf("\n");
    }
}


int main()
{   
    int iter = 0;
    if (solver(puzzle, &iter) == 0) print_puzzle(puzzle);
    else printf("%d\n", solver(puzzle, &iter));
    printf("Jumlah iterasi = %d\n", iter);
    
    return 0;
}


int solver(int (*puzzle_ptr)[9], int *count)
{
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (puzzle_ptr[r][c] == 0) {
                for (int k = 1; k < 10; k++) {
                    if (is_valid(puzzle_ptr, r, c, k) == 1) {
                        puzzle_ptr[r][c] = k;
                    
                        if (solver(puzzle_ptr, count) == 0) {
                            (*count)++;
                            return 0;
                        } else {
                            (*count)++;
                            puzzle_ptr[r][c] = 0;
                        }
                    }
                }
                return -1;
            }
        }
    }
    
    return 0;
}