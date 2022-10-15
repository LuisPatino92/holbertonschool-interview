/**
 * impr_malla - Sand pile grid printer
 * @grid: Grid
 *
 * Return: No Return
 */
void impr_malla(int grid[3][3])
{
	int i, j, l = 3;

	for (i = 0; i < l; i++)
	{
		for (j = 0; j < l; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * g_s - Sum of two sandpiles
 * @grid1: Pile 1
 * @grid2: Pile 2
 *
 * Return: No Return
 */
void g_s(int grid1[3][3], int grid2[3][3])
{
	int i, j, l = 3;

	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * stability_checker - Checks if stable
 * @grid: Grid to check
 *
 * Return: No Return
 */
int stability_checker(int grid[3][3])
{
	int i, j, l = 3;

	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			if (grid[i][j] > l)
				return (0);

	return (1);
}

/**
 * toppling - Distributes sand grains
 * @grid: Grid to process
 *
 * Return: No Return
 */
void toppling(int grid[3][3])
{
	int i, j, limit = 3, wall = 2;

	int grid_tmp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			if (grid[i][j] > limit)
			{
				(i - 1) >= 0 ? grid_tmp[i - 1][j]++ : 0;

				(i + 1) <= wall ? grid_tmp[i + 1][j]++ : 0;

				(j - 1) >= 0 ? grid_tmp[i][j - 1]++ : 0;

				(j + 1) <= wall ? grid_tmp[i][j + 1]++ : 0;

				grid[i][j] -= 4;
			}
		}
	}

	g_s(grid, grid_tmp);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Pile 1
 * @grid2: Pile 2
 *
 * Return: No Return
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	g_s(grid1, grid2);
	while (!stability_checker(grid1))
	{
		printf("=\n");
		impr_malla(grid1);
		toppling(grid1);
	}
}