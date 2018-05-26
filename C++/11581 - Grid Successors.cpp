#include <bits/stdc++.h>
using namespace std;
int t, n;
char in[5][5];
int f(int n)
{
	int r = 0;
	for (int i = 0; i < 9; i++)
	{
		int top = n & (1 << i << 3) ? 1 : 0;
		int left = (n & (1 << i << 1)) && i % 3 < 2 ? 1 : 0;
		int right = (n & (1 << i >> 1)) && i % 3 > 0 ? 1 : 0;
		int bot = n & (1 << i >> 3) ? 1 : 0;
		if (top ^ left ^ right ^ bot)
			r |= (1 << i);
	}
	return r;
}
int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		for (int i = 0; i < 3; i++)
			scanf("%s", &in[i]);
		n = 0;
		for (int i = 0; i < 9; i++)
			if (in[i / 3][i % 3] == '1')
				n |= (1 << (8 - i));
		int res = -1;
		while (n != 0)
			res++, n = f(n);
		printf("%d\n", res);
	}
}