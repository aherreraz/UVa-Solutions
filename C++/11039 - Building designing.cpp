#include <bits/stdc++.h>
#define MAX 500010
using namespace std;
int t, n;
int v[MAX];
bool comparar(int a, int b)
{
	return abs(a) > abs(b);
}
bool canTake(int a, int cur)
{
	return (a > 0 && cur < 0) || (a < 0 && cur > 0);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		sort(v, v + n, comparar);
		int cur = v[0], res = 1;
		for (int i = 1; i < n; i++)
			if (canTake(v[i], cur))
				cur = v[i], res++;
		printf("%d\n", res);
	}
}