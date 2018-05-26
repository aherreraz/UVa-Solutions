#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<string> M;
int auxX[4] = {-1, 0, 0, 1};
int auxY[4] = {0, -1, 1, 0};
char R[20];
int main()
{
	scanf("%d", &t);
	memset(R, 0, sizeof R);
	R[1] = 'A', R[2] = 'B', R[4] = 'C', R[8] = 'D', R[16] = 'E';
	for (int z = 1; z <= t; z++)
	{
		scanf("%d\n", &n);
		M.resize(n);
		for (int i = 0; i < n; i++)
			getline(cin, M[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (M[i][j] != '.')
					continue;
				int m = ~0;
				for (int k = 0; k < 4; k++)
				{
					int ni = i + auxX[k];
					int nj = j + auxY[k];
					if (ni >= 0 && nj >= 0 && ni < n && nj < n && M[ni][nj] != '.')
						m &= ~(1 << (M[ni][nj] - 'A'));
				}
				M[i][j] = R[m & ~(m - 1)];
			}
		printf("Case %d:\n", z);
		for (int i = 0; i < n; i++)
			printf("%s\n", M[i].c_str());
	}
}