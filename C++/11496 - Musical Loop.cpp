#include <bits/stdc++.h>
int n;
int v[10010];
int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		bool up = v[n - 1] < v[0];
		int res = 0;
		for (int i = 0; i < n; i++)
			if ((up && v[i] > v[(i + 1) % n]) || (!up && v[i] < v[(i + 1) % n]))
				up = !up, res++;
		printf("%d\n", res);
	}
}