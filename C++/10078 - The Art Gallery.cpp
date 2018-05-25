#include <bits/stdc++.h>
#define EPS 1e-7
#define PI (2*acos(0.0))

using namespace std;

int comparar(double a, double b)
{
	if(b - a > EPS)
		return -1;
	if(a - b > EPS)
		return 1;
	return 0;
}
struct Point
{
	double x, y;
	Point() {}
	Point(double px, double py) : x(px) , y(py) {}
};
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}

bool isConvex(vector<Point> P)
{
	int n = (int)P.size();
	if (n < 3) return false;
	int dir = comparar((P[2] - P[1]) ^ (P[0] - P[1]), 0);
	for (int i = 0; i < n; i++)
		if ( comparar((P[(i + 2) % n] - P[(i + 1) % n]) ^ (P[i] - P[(i + 1) % n]), 0) != dir)
			return false;
	return true;
}

int main()
{
	int n, caso = 1;
	while (scanf("%d", &n) && n != 0)
	{
		vector<Point> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);

		if(isConvex(v))
			printf("No\n");
		else
			printf("Yes\n");
	}
}
