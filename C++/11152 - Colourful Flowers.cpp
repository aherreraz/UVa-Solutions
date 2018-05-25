#include <bits/stdc++.h>
#define PI (2 * acos (0.0))

int main()
{
	double a, b, c;
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		double sp = (a + b + c) / 2.0;
		double A = sqrt (sp * (sp - a) * (sp - b) * (sp - c));
		double R = (a * b * c) / (4.0 * A);
		double r;
		if (sp != 0)
			r = A / sp;
		else
			r = 0;
		printf("%.4lf %.4lf %.4lf\n", PI * R * R - A, A - PI * r * r, PI * r * r);
	}
}
