#include <bits/stdc++.h>
#define EPS 1e-7
#define INF 1e8
int comparar(double a, double b)
{
	if (a - b > EPS) return 1;
	if (b - a > EPS) return -1;
	return 0;
}
int main()
{
	double v, v0;
	while (scanf("%lf %lf", &v, &v0) == 2)
	{
		if (comparar(v0, 0.0) == 0 && comparar(v, 0.0) == 0)
			return 0;
		int n = 1, r, nr = 0;
		double maxL = -INF;
		while (comparar(v / n - v0, 0.0) > 0)
		{
			if (comparar(sqrt(v / n - v0) * n, maxL) > 0)
				maxL = sqrt(v / n - v0) * n, r = n, nr = 1;
			else if (comparar(sqrt(v / n - v0) * n, maxL) == 0)
				nr++;
			n++;
		}
		if (nr == 1)
			printf("%d\n", r);
		else
			printf("0\n");
	}
}