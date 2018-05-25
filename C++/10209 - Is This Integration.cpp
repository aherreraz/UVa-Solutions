#include <bits/stdc++.h>
#define PI (2*acos(0.0))
int main()
{	
	double r, a, x, y, z;
	while (scanf("%lf", &r) == 1)
	{
		a = r * r;
		z = a * (4.0 - 2.0 * PI / 3.0 - sqrt(3.0));
		x = a * (4.0 - PI) - 2.0 * z;
		y = a - x - z;
		printf("%.3lf %.3lf %.3lf\n", y, x, z);
	}
}
