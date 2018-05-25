#include <bits/stdc++.h>
typedef long double ld;

int main()
{
	int n, m, p, q;
	while (scanf("%d %d %d %d", &n, &m, &p, &q) == 4)
	{
		ld res = 1;
		
		m = (n - m < m)? n - m : m;
		q = (p - q < q)? p - q : q;
		while (m || q)
		{
			if (m)
				res *= 1.0 * n / m, n--, m--;
			if (q)
				res *= 1.0 * q / p, p--, q--;
		}
		printf("%.5llf\n", res);
	}
}
