#include <bits/stdc++.h>
#define EPS 1e-7
#define PI (2*acos(0.0))
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
Point operator + (const Point &a, const Point &b)
{
	return Point (a.x + b.x, a.y + b.y);
}
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
double areaPolygon(vector<Point> P)
{
	double res = 0;
	int n = P.size();
	for (int i = 0; i < n; i++)
		res += (P[i]) ^ (P[(i + 1) % n]);
	return fabs(res) / 2.0;
}
double gradosARadianes(double theta)
{
	return theta * (PI / 180.0);
}
Point rotarAntiHorario(const Point &p, double theta)
{
	double rad = gradosARadianes(theta);
	return Point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}
int main()
{
	int t, n;
	double w, h, theta, area, hullArea;
	Point p;
	scanf("%d", &t);
	vector<Point> v;
	while (t--)
	{
		scanf("%d", &n);
		v.clear();
		v.resize(4 * n);
		area = 0.0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf %lf %lf", &p.x, &p.y, &w, &h, &theta);
			v[4 * i] = p + rotarAntiHorario(Point(w / 2.0, h / 2.0), -theta);
			v[4 * i + 1] = p + rotarAntiHorario(Point(w / 2.0, -h / 2.0), -theta);
			v[4 * i + 2] = p + rotarAntiHorario(Point(-w / 2.0, h / 2.0), -theta);
			v[4 * i + 3] = p + rotarAntiHorario(Point(-w / 2.0, -h / 2.0), -theta);
			area += w * h;
		}
		vector<Point> hull = convexHull(v);
		hullArea = areaPolygon(hull);
		printf("%.1lf %%\n", area / hullArea * 100.0);
	}
}