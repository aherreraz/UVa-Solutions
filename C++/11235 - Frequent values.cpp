#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, q;
int t[2 * N];
int v[N];
int s[N];
int e[N];

void build()
{
	for (int i = n - 1; i > 0; i--)
		t[i] = max(t[i << 1], t[i << 1 | 1]);
}
int query(int l, int r)
{
	if (v[l] == v[r])
		return r - l + 1;
	
	int l2 = e[l] + 1, r2 = s[r] - 1;
	int res = max(l2 - l, r - r2);
	for (l2 += n, r2 += n; l2 <= r2; l2 >>= 1, r2 >>= 1)
	{
		if (  l2 & 1 ) res = max(res, t[l2++]);
		if (!(r2 & 1)) res = max(res, t[r2--]);
	}
	return res;
}
int main()
{
	while (scanf("%d", &n) == 1 && n != 0)
	{
		scanf("%d", &q);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		for (int i = 0; i < n;)
		{
			int j = i + 1;
			int cont = 1;
			while (v[i] == v[j])
			{
				cont++;
				j++;
			}
			for (int k = i; k < j; k++)
			{
				t[k + n] = cont;
				s[k] = i;
				e[k] = j - 1;
			}
			i = j;
		}
		build();
		for (int i = 0; i < q; i++)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", query(l - 1, r - 1));
		}
	}
}