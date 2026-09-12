#include <unistd.h>

void	ft_error(void);						//prints "Error\n"
int		parse_clues(char *s, int clues[4][4]);			// fills clues[4][4] from a string, returns 1/0 1 if parsed 0 if it did not 1 BY PARSING WE MEAN CHARACTER TO NUMBER!!!!!!
int		solve(int grid[4][4], int clues[4][4], int pos);	// solver, returns 1 if solved
void	print_grid(int grid[4][4]);					// with the values it got, prints the finished grid

int	main(int argc, char *argv[])
{
	int	clues[4][4];					// will hold the 16 parsed clues (top then bottom then left then right)
	int	grid[4][4];					// will hold the solved skyscraper grid 
	int	found;						// if solve found a working grid it is 1 if not 0.

	if (argc != 2)						// must be called as "./rush01 <clues>"
	{
		ft_error();					// wrong number of arguments : print error
		return (1);					// exit
	}
	if (parse_clues(argv[1], clues) != 1)			// try to parse the clue string; must return exactly 1
	{
		ft_error();					// malformed clues (bad chars, wrong count) : print error
		return (1);					// exit
	}
	found = solve(grid, clues, 0);				// run thesolver starting at cell 0 top left corner
	if (found)						// a valid grid satisfying all constraints was found
		print_grid(grid);				// print the solution
	else							// no grid satisfies the given clues
		ft_error();					// print "Error" instead
	return (0);						// program always exits 0 here regardless of found/not found
}

// Writes the literal string "Error\n" (6 bytes) directly to stdout.
void	ft_error(void)
{
	write(1, "Error\n", 6);
}
