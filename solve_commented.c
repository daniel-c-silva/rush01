int	check_clues(int grid[4][4], int clues[4][4]);		// prototype: validates visibility clues on a full grid

int	can_place(int grid[4][4], int row, int col, int num)
{
	int	j;					
	int	i;				

	j = 0;						
	while (j < col)		
	{
		if (grid[row][j] == num)			// same number already used earlier in this row
			return (0);				// conflict : can't place num here exit with 0
		j++;						// check next column to the right
	}
	i = 0;						
	while (i < row)				
	{
		if (grid[i][col] == num)			// same number already used earlier in this column
			return (0);				// conflict : can't place num here exit with 0
		i++;						// check next row down
	}
	return (1);						// no conflicts found in row-so-far or column-so-far
}

// Recursive backtracking solver. "pos" is the current cell index (0..15)
// in order (row = pos/4, col = pos%4). Tries each number 1-4
// in turn, and recurses to the next cell if it's a legal placement.
int	solve(int grid[4][4], int clues[4][4], int pos)
{
	int	col;			// which column we're filling right now
	int	row;			// which row we're filling right now
	int	num;			// the number we're currently trying (1, 2, 3, or 4)

	if (pos == 16)			// if we've filled all 16 boxes
		return (check_clues(grid, clues));	// check if the finished grid matches the clues
	row = pos / 4;			// figure out which row box #pos is in
	col = pos % 4;			// figure out which column box #pos is in
	num = 1;			// start by trying the number 1
	while (num <= 4)		// try 1, then 2, then 3, then 4
	{
		if (can_place(grid, row, col, num))	// is this number allowed here?
		{
			grid[row][col] = num;		// yes : write it in the box
			if (solve(grid, clues, pos + 1))	// try to fill the rest of the boxes
				return (1);			// it worked all the way through : done, success!
			grid[row][col] = 0;			// it didn't work out later : erase this guess
		}
		num++;			// try the next number instead
	}
	return (0);			// none of 1-4 worked in this box : tell whoever called us to try something else
}
