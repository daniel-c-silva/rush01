// Parses the cmdl clue string into the 4x4 clues array.

// Expects exactly 16 digits (each '1 to 4), separated by EXACTLY 1 space.

// Layout produced: clues[0][0..3] = top clues, clues[1][0..3] = bottom clues,
//                  clues[2][0..3] = left clues, clues[3][0..3] = right clues.
// Returns 1 on success (exactly 16 valid digits found), 0 on any error.
int	parse_clues(char *s, int clues[4][4])
{
	int	i;						// current read position inside the string s
	int	n;						// how many valid clue digits parsed so far (0..16)

	i = 0;						// start reading from the beginning of the string
	n = 0;						// no clues collected yet
	while (1)						// loop forever; we break or return from inside
	{
		while (s[i] == ' ' && s[i + 1] != ' ')		// if theres a space skip but ONLY if the next character is not also a space!
			i++;					// advance to the next number
		if (s[i] == '\0')				// reached the end of the string
			break ;					// stop the loop normally (may or may not have 16 yet)
		if (s[i] < '1' || s[i] > '4')			// character is not a digit between '1' and '4'
			return (0);				// invalid character : parsing fails immediately RETURN 0 so we can print the error message
		if (n >= 16)					// we've already stored 16 clues but there's more data
			return (0);				// too many values : parsing fails RETURN 0 so we can print the error message
		clues[n / 4][n % 4] = s[i] + '0';		// convert ascii digit to int, store row-major 4 per group
		n++;						// one more clue successfully stored
		i++;						// move past this character to look for the next one
	}
	return (n == 16);					// success only if we ended with exactly 16 clues
}
