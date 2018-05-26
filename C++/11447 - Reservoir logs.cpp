#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;
int comparar(double a, double b)
{
	if(b - a > EPS)	return -1;
	if(a - b > EPS)	return 1;
	return 0;
}
struct Point
{
	double x, y;
	Point() {}
	Point(double px, double py) : x(px) , y(py) {}
};
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
double areaPolygon(vector<Point> P)
{
	double res = 0;
	int n = P.size();
	for (int i = 0; i < n; i++)
		res += (P[i]) ^ (P[(i + 1) % n]);
	return fabs(res) / 2.0;
}
int main()
{
	int t, n;
	double w, perc, wSpent, wFalling, totalVolume, currVolume;
	vector<Point> v;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		scanf("%lf %lf %lf %lf", &w, &perc, &wSpent, &wFalling);
		totalVolume = areaPolygon(v) * w;
		currVolume = totalVolume * perc / 100.0;
		currVolume -= wSpent;
		if(comparar(currVolume, 0.0) < 0)
			printf("Lack of water. "), currVolume = 0.0;
		currVolume += wFalling;
		if(comparar(currVolume, totalVolume) > 0)
			printf("Excess of water. "), currVolume = totalVolume;
		printf("Final percentage: %d%%\n", (int)floor (currVolume / totalVolume * 100.0) );
	}
}
