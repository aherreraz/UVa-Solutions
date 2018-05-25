#include <bits/stdc++.h>
#define MAX 110
int n, N;
char m[MAX][MAX], M[MAX][MAX];
bool comparar(int si, int sj, int ei, int ej, int SI, int SJ, bool r)
{
	int szI = SI + n, szJ = SJ + n;
	for (int I = SI, i = si; I < szI; I++, si < ei ? i++ : i--)
		for (int J = SJ, j = sj; J < szJ; J++, sj < ej ? j++ : j--)
		{
		if ((r && m[j][i] != M[I][J]) || (!r && m[i][j] != M[I][J]))
				return false;
		}
	return true;
}
int main()
{
	while (scanf("%d %d", &N, &n) == 2 && (n || N))
	{
		for (int i = 0; i < N; i++)
			scanf("%s", &M[i]);
		for (int i = 0; i < n; i++)
			scanf("%s", &m[i]);
		int r0, r90, r180, r270;
		r0 = r90 = r180 = r270 = 0;
		for (int i = 0; i <= N - n; i++)
			for (int j = 0; j <= N - n; j++)
			{
				if (comparar(0, 0, n, n, i, j, 0))
					r0++;
				if (comparar(0, n - 1, n, 0, i, j, 1))
					r90++;
				if (comparar(n - 1, n - 1, 0, 0, i, j, 0))
					r180++;
				if (comparar(n - 1, 0, 0, n, i, j, 1))
					r270++;
			}
		printf("%d %d %d %d\n", r0, r90, r180, r270);
	}
}