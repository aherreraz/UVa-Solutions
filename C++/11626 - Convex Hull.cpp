#include <bits/stdc++.h>
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
	Point () {}
	Point (double px, double py) : x(px), y(py) {}
};
Point operator - (const Point &a, const Point &b)
{
	return Point (a.x - b.x, a.y - b.y);
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
bool cmp (Point p1, Point p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
vector<Point> convexHull (vector<Point> P)
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

int main ()
{
	int t, n;
	vector<Point> v;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		v.clear();
		for (int i = 0; i < n; i++)
		{
			Point aux;
			char s[5];
			scanf("%lf %lf %s", &aux.x, &aux.y, &s);
			if (s[0] == 'Y') v.push_back(aux);
		}
		vector<Point> hull = convexHull(v);
		int m = hull.size();
		printf("%d\n", m);
		for (int i = 0; i < m; i++)
			printf("%.0lf %.0lf\n", hull[i].x, hull[i].y);
	}
}
