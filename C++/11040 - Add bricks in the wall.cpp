#include <bits/stdc++.h>
#define MAX 9
int M[MAX][MAX];
int n;
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j <= i; j++)
				scanf("%d", &M[2 * i][2 * j]);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j <= i; j++)
				M[2 * i + 2][2 * j + 1] = (M[2 * i][2 * j] - M[2 * i + 2][2 * j] - M[2 * i + 2][2 * j + 2]) / 2;
		for (int i = 1; i < 5; i++)
			for (int j = 0; j < 2 * i; j++)
				M[2 * i - 1][j] = M[2 * i][j] + M[2 * i][j + 1];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j <= i; j++)
				j == 0 ? printf("%d", M[i][j]) : printf(" %d", M[i][j]);
			printf("\n");
		}
	}
}