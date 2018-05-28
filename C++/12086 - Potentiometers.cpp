#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
int t[2 * N];
int suma(int a, int b)
{
	return a + b;
}
void build()
{
	for (int i = n - 1; i > 0; i--)
		t[i] = suma(t[i<<1], t[i<<1|1]);
}
void modify(int i, int val)
{
	for (t[i += n] = val; i >>= 1;)
		t[i] = suma(t[i<<1], t[i<<1|1]);
}
int query(int l, int r)
{
	int res = 0;
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
	{
		if (  l&1 ) res = suma(res, t[l++]);
		if (!(r&1)) res = suma(res, t[r--]);
	}
	return res;
}
int main()
{
	int caso = 1;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		if (caso > 1)
			printf("\n");
		for (int i = 0; i < n; i++)
			scanf("%d", &t[i + n]);
		build();
		char c[5];
		int a, b;
		printf("Case %d:\n", caso++);
		while (scanf("%s", c) == 1)
		{
			if (strcmp(c, "END") == 0)
				break;
			scanf("%d %d", &a, &b);
			switch(c[0])
			{
			
			case 'S':
				modify(a - 1, b);
				break;
			case 'M':
				printf("%d\n", query(a - 1, b - 1));
				break;
			}
		}
	}
}