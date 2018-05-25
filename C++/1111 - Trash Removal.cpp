#include <bits/stdc++.h>
#define INF 200000000
#define EPS 1e-7
using namespace std;

int comparar(double a, double b)
{
	if (a - b > EPS) return 1;
	if (b - a > EPS) return -1;
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
	return sqrt (a.x * a.x + a.y * a.y);
}
Point operator + (const Point &a, const Point &b)
{
	return Point(a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
double distanciaPuntoLinea(Point a, Point b, Point c)
{
	return fabs( ((b - a) ^ (c - a)) / ~(b - a) );
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
	for (int i = n - 2, t = k + 1;  i >= 0; i--)
	{
		while (k >= t && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) < 0)
		k--;
		H[k++] = P[i];
	}
	H.resize(k);
	H.pop_back();
	return H;
}
vector<Point> v;
vector<Point> hull;

int main()
{
	int n, caso = 1;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		
		hull = convexHull(v);
		int n2 = hull.size();
		double res = INF;
		for (int i = 0; i < n2; i++)
		{
			Point a = hull[i % n2];
			Point b = hull[(i + 1) % n2];
			Point vec = a - b;
			double maxN = -INF;
			for (int j = 0; j < n2; j++)
			{
				double aux = distanciaPuntoLinea(hull[j], hull[j] + vec, a);
				maxN = aux > maxN ? aux : maxN;
			}
			res = maxN < res ? maxN : res;
		}
		printf("Case %d: %.2lf\n", caso++, res + 0.005);
	}
}