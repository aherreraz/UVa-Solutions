#include <bits/stdc++.h>
#define PI (2*acos(0.0))
#define EPS 1e-7
using namespace std;

struct point
{
   double x, y; 
};
double area (vector<point> P)
{
	double result = 0, x1, y1, x2, y2;
	int sz = P.size();
	for (int i = 0; i < sz; i++)
	{
		x1 = P[i].x;
		x2 = P[(i + 1) % sz].x;
		y1 = P[i].y;
		y2 = P[(i + 1) % sz].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}
int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}
int border(vector<point> P)
{
	int sz = (int)P.size(), b = 0;
	for(int i = 0; i < sz; i++)
	{
		int j = (i + 1) % sz;
		b += abs(gcd((int)P[i].x - (int)P[j].x, (int)P[i].y - (int)P[j].y));
	}
	return b;
}
double puntosInterior(vector<point> P)
{
	return area(P) - (border(P) / 2.0) + 1.0;
}

int main()
{
	int n;
	while(scanf("%d", &n) && n != 0)
	{
		vector<point> P;
		P.clear();
		P.resize(n);
		for(int i = 0; i < n ;i++)
			scanf("%lf %lf", &P[i].x, &P[i].y);
		printf("%.0lf\n", puntosInterior(P));
	}
}
