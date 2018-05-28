#include <bits/stdc++.h>

int frec[1010][26];
int t;
char in[1010];
int diff[26];
int par[2];
bool valid()
{
	par[0] = par[1] = 0;
	for (int i = 0; i < 26; i++)
		par[diff[i] & 1]++;
	return par[1] <= 1;
}
int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%s", &in);
		int n = strlen(in);
		for (int i = 0; i < 26; i++)
			frec[0][i] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 26; j++)
				frec[i][j] = frec[i - 1][j];
			frec[i][in[i - 1] - 'a']++;
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
			{
				for (int k = 0; k < 26; k++)
					diff[k] = frec[j][k] - frec[i - 1][k];
				if (valid())
					res++;
			}
		printf("Case %d: %d\n", z, res);
	}
}