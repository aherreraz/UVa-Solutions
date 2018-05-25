#include <bits/stdc++.h>
#define EPS 1e-07
#define INF 1e15
using namespace std;
int comparar (double a, double b)
{
	if (b - a > EPS) return -1;
	if (a - b > EPS) return 1;
	return 0;
}

struct Point
{
	double x, y;
	Point() {}
	Point(double px, double py) : x(px) , y(py) {}
};

double operator ~ (const Point &a)
{
	return hypot(a.x, a.y);
}
Point operator + (const Point &a, const Point &b)
{
	return Point(a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
Point operator * (const Point &a, const double &s)
{
	return Point(a.x * s, a.y * s);
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}

bool cmp(Point p1, Point p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
vector<Point> convexHull(vector<Point> P)
{
	int n = (int)P.size(), k = 0;
	vector<Point> H(2 * n);
	sort(P.begin(), P.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		while (k >= 2 && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) < 0)
			k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--)
	{
		while (k >= t && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) < 0)
			k--;
		H[k++] = P[i];
	}
	H.resize(k);
	H.pop_back();
	return H;
}

double distanciaPuntoLinea (Point a, Point b, Point c)
{
	return fabs( ((b - a) ^ (c - a)) / ~(b - a) );
}
vector<Point> v;
vector<Point> hull;
Point center;
int nHull;

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int z = 1; z <= t; z++)
	{
		int n;
		scanf("%d", &n);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		
		if (n <= 2)
		{
			printf("Case #%d: 0.000\n", z);
			continue;
		}
		hull = convexHull(v);
		center = Point(0.0, 0.0);
		for (int i = 0; i < n; i++)
			center = center + v[i];
		center = center * (1.0 / n);
		//printf("center: %.3lf\n", center);
		nHull = hull.size();
		//for (int i = 0; i < hull[]
		double d = INF;
		for (int i = 0; i < nHull; i++)
		{
			double aux = distanciaPuntoLinea(hull[i % n], hull[(i + 1) % n], center);
			d = min(d, aux);
		}
		
		printf("Case #%d: %.3lf\n", z, d);
	}
}