#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;
int comparar(double a, double b)
{
	if(b - a > EPS) return -1;
	if(a - b > EPS)	return 1;
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
	return sqrt(a.x * a.x + a.y * a.y);
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
double perimeterPolygon (vector<Point> P)
{
	int n = P.size();
	double res = 0;
	for (int i = 1; i < n; i++)
		res += ~(P[i] - P[i - 1]);
	return res;
}
vector<Point> getPoints (vector<Point> v, double d)
{
	vector<Point> res;
	res.push_back(v[0]);
	int n = v.size(), m = 1;
	Point desp(0.0, 0.0);
	double currDist = 0.0;
	for (int i = 1; i < n; i++)
	{
		double dist = ~(v[i] - v[i - 1]);
		if (comparar (dist, d - currDist) < 0)
			desp = desp + (v[i] - v[i - 1]), currDist += dist;
		else
		{
			res.push_back(res[m++ - 1] + desp + ((v[i] - v[i - 1]) * ((d - currDist) / dist)));
			int k = 2;
			while (comparar (dist, d * k - currDist) >= 0)
				res.push_back(res[m++ - 1] + ((v[i] - v[i - 1]) * (d/ dist))), k++;
			desp = v[i] - res[m - 1];
			currDist = ~desp;
		}
	}
	return res;
}
int main()
{
	int t, n, nTrees;
	double perimeter, d;
	vector<Point> v;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %d", &n, &nTrees);
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		perimeter = perimeterPolygon(v);
		d = perimeter / (nTrees - 1.0);
		printf("Road #%d:\n", z);
		vector<Point> res = getPoints(v, d);
		int m = res.size();
		for (int i = 0; i < m; i++)
			printf("%.2lf %.2lf\n", res[i].x, res[i].y);
		printf("\n");
	}
}