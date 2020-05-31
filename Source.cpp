#include <stdio.h>
#define M 5
#define N 6

int max(int a, int b)
{
	return a > b ? a : b;
}

void display(int c[M][N])
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d\t", c[i][j]);
		printf("\n");
	}
}

int robot_coin_collect(int a[M][N])
{
	int i = 1, j = 1, c[M][N];

	c[0][0] = a[0][0];
	while (i < M && a[i][0] != -1)
	{
		c[i][0] = c[i - 1][0] + a[i][0];
		i = i + 1;
	}
	for (; i < M; i++)
		c[i][0] = -6;
	while (j < N && a[0][j] != -1)
	{
		c[0][j] = c[0][j - 1] + a[0][j];
		j = j + 1;
	}
	for (; j < N; j++)
		c[0][j] = -6;

	printf("\n\n");

	for (i = 1; i < M; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (a[i][j] != -1)
				c[i][j] = max(c[i - 1][j], c[i][j - 1]) + a[i][j];
			else
				c[i][j] = -6;
		}
	}
	return c[M - 1][N - 1];
}

int main(void)
{
	int mat[5][6] =
	{
		{ 0, 0, 0, 6 },
		{ 1, 3, 0, 0 },
		{ 2, 0, 0, 0 },
		{ 0, 7, 2, 4 },
		{ 0, 0, 6, 0 }
	};
	printf("%d", robot_coin_collect(mat));
	return 0;
}