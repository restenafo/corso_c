#include <stdio.h>
#include <unistd.h>

#define GRID_ROWS 20
#define GRID_COLS 20
#define GRID_AREA (GRID_ROWS*GRID_COLS)
#define ALIVE '*'
#define DEAD '.'


/* Translate the specified x,y coordinates into the index of a linear array
   This function implements wrapping, so both negative and positive coordinates
   that are out of the grid will wrap around
*/
int cell_to_index(int x, int y) {
	if (x >= GRID_COLS) x = x % GRID_COLS;
	if (y >= GRID_ROWS) y = y % GRID_ROWS;
	if (x < 0) x = GRID_COLS + (x % GRID_COLS);
	if (y < 0) y = GRID_ROWS + (y % GRID_ROWS);
	return y*GRID_COLS+x;
//    if (x < 0) {
//        x = (-x) % GRID_COLS;
//        x = GRID_COLS - x;
//    }
//    if (y < 0) {
//        y = (-y) % GRID_ROWS;
//        y = GRID_ROWS - y;
//    }
//    if (x >= GRID_COLS) x = x % GRID_COLS;
//    if (y >= GRID_ROWS) y = y % GRID_ROWS;
//
//    return y*GRID_COLS+x;
}

/* The function sets the cell at x,y with the specified value */
void set_cell(char *grid, int x, int y, int state) {
	grid[cell_to_index(x,y)] = state;
}

/* THe function get the value of the cell at x,y */
char get_cell(char *grid, int x , int y) {
	return grid[cell_to_index(x,y)];
}

void set_grid(char *grid, char state) {
        for (int i = 0; i < GRID_COLS; i++) {
                for (int j=0; j < GRID_ROWS; j++) {
                        set_cell(grid, i, j, state);
                }
                printf("\n");
        }
}

void print_grid(char *grid) {
	printf("\x1b[H\x1b[2J\x1b[3J");
	for (int y = 0; y < GRID_ROWS; y++) {
		for (int x = 0; x < GRID_COLS; x++) {
			printf("%c ",get_cell(grid, x, y));
		}
		printf("\n");
	}
}

int calculate_neighbours(char *grid, int x, int y) {
//	printf("\nCalcolo relativo alla cella %d,%d\n", x,y);
	int neighbours_count=0;
	for (int ry = -1 ; ry <= 1; ry++) {
		for (int rx = -1; rx <= 1; rx++) {
			if (rx == 0 && ry == 0) continue;
			if (get_cell(grid, x+rx, y+ry) == ALIVE) neighbours_count++;
//			printf("La cella %d,%d è nello stato %c\n", x+rx, y+ry, get_cell(grid, x+rx,y+ry ));
		}
	}
//	printf("\n");
	return neighbours_count;
}

void calculate_new_state(char *old_grid, char *new_grid) {
        for (int y = 0 ; y < GRID_ROWS; y++) {
                for (int x = 0; x < GRID_COLS; x++) {
                        int number_of_living_neighbours = calculate_neighbours(old_grid, x, y);
			int new_state = DEAD;
			if (get_cell(old_grid,x,y) == ALIVE ) {
				if (number_of_living_neighbours == 2 || number_of_living_neighbours == 3) {
					new_state = ALIVE ;
				}
			}
			else {
				if (number_of_living_neighbours == 3 ) {
					new_state= ALIVE;
				}
			}
		set_cell(new_grid,x,y,new_state);
                }
        }
//    for (int y = 0; y < GRID_ROWS; y++) {
//        for (int x = 0; x < GRID_COLS; x++) {
//            int n_alive = calculate_neighbours(old_grid,x,y);
//            int new_state = DEAD;
//            if (get_cell(old_grid,x,y) == ALIVE) {
//                if (n_alive == 2 || n_alive == 3)
//                    new_state = ALIVE;
//            } else {
//                if (n_alive == 3)
//                    new_state = ALIVE;
//            }
//            set_cell(new_grid,x,y,new_state);
//        }
//    }
}

int main(void) {
	char old_grid[GRID_AREA];
	char new_grid[GRID_AREA];
	set_grid(old_grid, DEAD);
	set_grid(new_grid, DEAD);
	set_cell(old_grid, 19, 20, ALIVE);
        set_cell(old_grid, 20, 20, ALIVE);
        set_cell(old_grid, 21, 20, ALIVE);
	set_cell(old_grid,21,19,ALIVE);
	set_cell(old_grid,20,18,ALIVE);
//       set_cell(old_grid,40,20,ALIVE);
//        set_cell(old_grid,41,20,ALIVE);
//        set_cell(old_grid,42,20,ALIVE);
//        set_cell(old_grid,42,21,ALIVE);
	while(1) {
	print_grid(old_grid);
	calculate_new_state(old_grid, new_grid);
	print_grid(new_grid);
	usleep(100000);
        calculate_new_state(new_grid, old_grid);
	usleep(100000);
	}
//	printf("La cella 39,20 ha %d vicini\n", calculate_neighbours(old_grid, 39,20));
//        printf("La cella 40,20 ha %d vicini\n", calculate_neighbours(old_grid, 40,20));
//        printf("La cella 41,20 ha %d vicini\n", calculate_neighbours(old_grid, 41,20));
//        printf("La cella 42,20 ha %d vicini\n", calculate_neighbours(old_grid, 42,20));
//        printf("La cella 42,21 ha %d vicini\n", calculate_neighbours(old_grid, 42,21));
//	printf("TEST :%d", (-1)%5);
	return 0;
}
