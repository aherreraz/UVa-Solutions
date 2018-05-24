#include <bits/stdc++.h>
typedef long double ld;

int main ()
{
	int n, k;
	while (scanf ("%d %d", &n, &k) == 2)
	{
		if (n == 0 && k == 0)
			return 0;
		ld res = 1.0;
		k = (n - k < k)? n - k : k;
		while (k)
			res *= 1.0 * n / k, n--, k--;
		printf("%.0llf\n", res);
	}
}