#include <bits/stdc++.h>
using namespace std;
int t, r, c, a, b, m, res;
int f[26];
string s;
int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %d %d %d", &r, &c, &a, &b);
		memset(f, 0, sizeof f);
		for (int i = 0; i < r; i++)
		{
			cin >> s;
			for (int j = 0; j < c; j++)
				f[s[j] - 'A']++;
		}
		m = f[0], res = 0;
		for (int i = 1; i < 26; i++)
			m = max(m, f[i]);
		for (int i = 0; i < 26; i++)
			m == f[i] ? res += a * f[i] : res += b * f[i];
		printf("Case %d: %d\n", z, res);
	}
}