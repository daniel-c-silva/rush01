#include <unistd.h>			// needed for write()

void	print_grid(int grid[4][4])
{
	int		i;		// which row we're printing
	int		j;		// which column we're printing
	char	c;		// the character version of the current number

	i = 0;				// start at the first row
	while (i < 4)			// print all 4 rows
	{
		j = 0;			// start at the first column of this row
		while (j < 4)		// print all 4 numbers in this row
		{
			c = '0' + grid[i][j];	// turn the number (1-4) into its printable character
			write(1, &c, 1);	// print that character
			if (j < 3)		// if it's not the last number in the row
				write(1, " ", 1);	// print a space after it
			j++;			// move to the next column
		}
		write(1, "\n", 1);		// end the row with a new line
		i++;				// move to the next row
	}
}
