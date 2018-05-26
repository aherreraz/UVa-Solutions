#include <bits/stdc++.h>
#define MAX 110
int g, n, r, rp, aux;
int points[MAX][MAX]; // points[scoring system][pilot]
int race[MAX][MAX]; // race[race][position] = pilot
int main()
{
	while (scanf("%d %d", &g, &n) == 2 && (g || n))
	{
		for (int i = 0; i < g; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &aux), race[i][aux - 1] = j;
		scanf("%d", &r);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < n; j++)
				points[i][j] = 0;
		for (int i = 0; i < r; i++)
		{
			scanf("%d", &rp);
			for (int j = 0; j < rp; j++)
			{
				scanf("%d", &aux);
				for (int k = 0; k < g; k++)
					points[i][race[k][j]] += aux;
			}
		}
		for (int i = 0; i < r; i++)
		{
			int maxPoints = -1;
			for (int j = 0; j < n; j++)
				if (points[i][j] > maxPoints)
					maxPoints = points[i][j];
			int cont = 0;
			for (int j = 0; j < n; j++)
				if (points[i][j] == maxPoints)
					cont++ == 0 ? printf("%d", j + 1) : printf(" %d", j + 1);
			printf("\n");
		}
	}
}