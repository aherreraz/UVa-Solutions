#include <bits/stdc++.h>
const int N = 100005;
int n, q;
int t[2 * N];
int multiply(int a, int b)
{
	int c = a * b;
	if (c < 0) return -1;
	if (c > 0) return 1;
	return 0;
}
void build()
{
	for (int i = n - 1; i > 0; i--)
		t[i] = multiply(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value)
{
	for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = multiply(t[p], t[p ^ 1]);
}
int query(int l, int r)
{
	int res = 1;
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
	{
		if (  l&1 ) res = multiply(res, t[l++]);
		if (!(r&1)) res = multiply(res, t[r--]);
	}
	return res;
}
void print(int a)
{
	if (a > 0) printf("+");
	else if (a < 0) printf("-");
	else printf("0");
}
int main()
{
	while (scanf("%d %d", &n, &q) == 2)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &t[n + i]);
		
		build();
		char c[1];
		int a, b;
		for (int i = 0; i < q; i++)
		{
			scanf("%s %d %d", &c, &a, &b);
			switch (c[0])
			{
			case 'C':
				modify(a - 1, b);
				break;
			case 'P':
				int res = query(a - 1, b - 1);
				print(res);
				break;
			}
		}
		printf("\n");
	}
}