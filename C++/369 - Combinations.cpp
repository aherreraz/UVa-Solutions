#include <bits/stdc++.h>
int main()
{
	int n,m,N,M;
	while (scanf ("%d %d", &n, &m) == 2 && n && m)
	{
		double res = 1.0;
		N = n, M = m;
		M = (N - M < M)? N - M : M;
		while(M != 0)
			res *= 1.0 * N / M, N--, M--;
		printf("%d things taken %d at a time is %.0lf exactly.\n", n, m, res);
	}
}
