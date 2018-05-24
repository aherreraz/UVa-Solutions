#include <bits/stdc++.h>
#define EPS 1e-7
#define PI (2*acos(0.0))
using namespace std;
int comparar(double a, double b)
{
	if(b - a > EPS) return -1;
	if(a - b > EPS) return 1;
	return 0;
}
double safeAcos(double a)
{
	return acos(max(min(a, 1.0), -1.0));
}
struct Point
{
	double x, y;
	Point () {}
	Point (double px, double py) : x(px), y(py) {}
};
double operator ~ (const Point &a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
double operator * (const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
double anguloPuntoEntreVectores(const Point &a, const Point &b)
{
	return safeAcos( (a * b) / (~a * ~b) );
}
bool inPolygon(vector<Point> P, Point a)
{
	double sum = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++)
	if (comparar((P[i] - a) ^ (P[(i + 1) % n] - a), 0) > 0)
		sum += anguloPuntoEntreVectores(P[i] - a, P[(i + 1) % n] - a);
	else
		sum -= anguloPuntoEntreVectores(P[i] - a, P[(i + 1) % n] - a);
	return comparar(fabs(sum), 2 * PI) == 0;
}
int main()
{
	int n, caso = 1;
	vector<Point> v;
	Point a;
	while (scanf("%d", &n) && n != 0)
	{
		v.clear(); v.resize(n);
		for(int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		scanf("%lf %lf", &a.x, &a.y);
		inPolygon(v, a) ? printf("T\n") : printf("F\n");
	}
}