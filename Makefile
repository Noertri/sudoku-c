target_dir := $(PREFIX)/tmp

sudoku_solver: $(PWD)/libsudoku.c $(PWD)/sudoku_solver.c
	clang $(PWD)/libsudoku.c $(PWD)/sudoku_solver.c -o $(target_dir)/sudoku_solver

run: sudoku_solver
	$(target_dir)/sudoku_solver
