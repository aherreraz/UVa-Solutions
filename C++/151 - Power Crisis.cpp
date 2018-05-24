#include <bits/stdc++.h>

int survivor (int n, int k)
{
	int i, s;
	for (s = 0, i = 1; i <= n; i++) s = (s + k) % i;
	return s + 1;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		int k = 1, s = 0;
		do
		{
			s = survivor(n - 1, k++);
		} while (s != 12);
		printf("%d\n", k - 1);
	}
}