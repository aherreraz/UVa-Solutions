#include <bits/stdc++.h>
#define MAX 20
#define THRESH 1.01 

int p[MAX][MAX][MAX];
double M[MAX][MAX][MAX];
int n;

void printPath(int i, int j, int s)
{
	if (p[i][j][s] == -1)
		printf("%d %d", i + 1, j + 1);
	else
	{
		printPath(i, p[i][j][s], s - 1);
		printf(" %d", j + 1);
	}
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		memset(p, -1, sizeof(p));
		memset(M, 0.0, sizeof(M));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i == j)
					M[i][j][0] = 1.0;
				else
					scanf("%lf", &M[i][j][0]);
		bool solved = false;
		for (int s = 1; s < n && !solved; s++)
		{
			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (M[i][k][s - 1] * M[k][j][0] > M[i][j][s])
						{
							M[i][j][s] = M[i][k][s - 1] * M[k][j][0];
							p[i][j][s] = k;
						}
			for (int i = 0; i < n && !solved; i++)
				if (M[i][i][s] >= THRESH)
				{
					printPath(i, i, s);
					printf("\n");
					solved = true;
				}
		}
		if (!solved)
			printf("no arbitrage sequence exists\n");
			
	}
}