int	row_visible(int grid[4][4], int row, int reverse)
{
	int	max;			// tallest building seen so far
	int	count;			// how many buildings we can see
	int	j;			// which column we're looking at
	int	step;			// which direction we're moving (+1 or -1)

	max = 0;			// nothing seen yet
	count = 0;			// nothing counted yet
	j = 3 * reverse;		// start at the left end (0) or right end (3)
	step = 1 - 2 * reverse;	// +1 = move right, -1 = move left
	while (j >= 0 && j < 4)	// keep going until we walk off the row
	{
		if (grid[row][j] > max)	// this building is taller than every one before it
		{
			max = grid[row][j];	// it's now the tallest we've seen
			count++;		// so we can see it : count it
		}
		j += step;		// move to the next building in this row
	}
	return (count);			// how many buildings were visible from this side
}

int	col_visible(int grid[4][4], int col, int reverse)
{
	int	max;			// tallest building seen so far
	int	count;			// how many buildings we can see
	int	i;			// which row we're looking at
	int	step;			// which direction we're moving (+1 or -1)

	max = 0;			// nothing seen yet
	count = 0;			// nothing counted yet
	i = 3 * reverse;		// start at the top (0) or bottom (3)
	step = 1 - 2 * reverse;	// +1 = move down, -1 = move up
	while (i >= 0 && i < 4)	// keep going until we walk off the column
	{
		if (grid[i][col] > max)	// this building is taller than every one before it
		{
			max = grid[i][col];	// it's now the tallest we've seen
			count++;		// so we can see it : count it
		}
		i += step;		// move to the next building in this column
	}
	return (count);			// how many buildings were visible from this side
}

int	rows_ok(int grid[4][4], int clues[4][4])
{
	int	i;			// which row we're checking
	int	r;			// how many buildings are visible from the left
	int	c;			// how many buildings are visible from the right

	i = 0;				// start at row 0
	while (i < 4)			// check every row
	{
		r = row_visible(grid, i, 0);		// count what's visible from the left
		c = row_visible(grid, i, 1);		// count what's visible from the right
		if (r != clues[2][i] || c != clues[3][i])	// doesn't match the clue given for this row
			return (0);			// this grid is wrong
		i++;				// move to the next row
	}
	return (1);				// every row matched its clues
}

int	cols_ok(int grid[4][4], int clues[4][4])
{
	int	i;			// which column we're checking
	int	r;			// how many buildings are visible from the top
	int	c;			// how many buildings are visible from the bottom

	i = 0;				// start at column 0
	while (i < 4)			// check every column
	{
		r = col_visible(grid, i, 0);		// count what's visible from the top
		c = col_visible(grid, i, 1);		// count what's visible from the bottom
		if (r != clues[0][i] || c != clues[1][i])	// doesn't match the clue given for this column
			return (0);			// this grid is wrong
		i++;				// move to the next column
	}
	return (1);				// every column matched its clues
}

int	check_clues(int grid[4][4], int clues[4][4])
{
	if (rows_ok(grid, clues) == 0)		// do all the row clues match?
		return (0);			// no : grid is invalid
	if (cols_ok(grid, clues) == 0)		// do all the column clues match?
		return (0);			// no : grid is invalid
	return (1);				// everything matches : this is a real solution
}
