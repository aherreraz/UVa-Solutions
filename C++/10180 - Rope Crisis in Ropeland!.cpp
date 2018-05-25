#include <bits/stdc++.h>
#define EPS 1e-15
using namespace std;
typedef long double ld;
struct Point
{
	double x, y;
	Point() {}
	Point(double px, double py) : x(px), y(py) {}
};
struct Circle
{
	Point c;
	double r;
	Circle() {}
	Circle(Point pc, double nr) : c(pc), r(nr) {}
	Circle(double ncx, double ncy, double nr) : c(ncx, ncy), r(nr) {}
};
int comparar (double a, double b)
{
	if (a - b > EPS) return 1;
	if (b - a > EPS) return -1;
	return 0;
}
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
Point operator * (const Point &a, const double &s)
{
	return Point(a.x * s, a.y * s);
}
double operator * (const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}
Point project (const Point &a, const Point &b)
{
	return b * ((a * b) / (b * b));
}
double distanciaPuntoSegmento (const Point &a, const Point &b, const Point &c)
{
	int prod1 = (c - b) * (b - a);
	if (prod1 >= 0)
		return sqrt ((b - c) * (b - c));
	int prod2 = (c - a) * (a - b);
	if (prod2 >= 0)
		return sqrt ((a - c) * (a - c));
	return ~(a + project(c - a, b - a) - c);
}
void interseccionCircunferecia(Circle a, Circle b, Point *p1, Point *p2)
{
	double D = ~(a.c - b.c);
	double A = (a.r * a.r - b.r * b.r + D * D) / (2 * D);
	double H = sqrt(a.r * a.r - A * A);
	Point pAux = a.c + (b.c - a.c) * (A / D);
	*p1 = Point(pAux.x + (b.c.y - a.c.y) * (H / D), pAux.y - (b.c.x - a.c.x) * (H / D));
	*p2 = Point(pAux.x - (b.c.y - a.c.y) * (H / D), pAux.y + (b.c.x - a.c.x) * (H / D));
}
double safeAcos(double a)
{
	return acos(max(min(a, 1.0), -1.0));
}
double anguloPuntoEntreVectores(const Point &a, const Point &b)
{
	return safeAcos( (a * b) / (~a * ~b) );
}
double calcRope(Point a, Point tanA, Point b, Point tanB, Circle c)
{
	double arc = anguloPuntoEntreVectores(tanA - c.c, tanB - c.c) * c.r;
	double res = ~(tanA - a) + ~(tanB - b) + arc;
	return res;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		Point a, b;
		Circle c(0.0, 0.0, 0.0);
		scanf("%lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.r);
		double dist = distanciaPuntoSegmento (a, b, c.c);
		if (comparar(dist, c.r) >= 0)
		{
			printf("%.3lf\n", ~(b - a));
		}
		else
		{
			Circle aC((a + c.c) * 0.5, ~(c.c - a) * 0.5), bC((b + c.c) * 0.5, ~(c.c - b) * 0.5);
			Point p1, p2, p3, p4;
			if (comparar (~(a - c.c), c.r) == 0)
				p1 = p2 = a;
			else
				interseccionCircunferecia(aC, c, &p1, &p2);
			if (comparar (~(b - c.c), c.r) == 0)
				p3 = p4 = b;
			else
				interseccionCircunferecia(bC, c, &p3, &p4);
			double m1 = min (calcRope(a, p1, b, p3, c), calcRope(a, p1, b, p4, c));
			double m2 = min (calcRope(a, p2, b, p3, c), calcRope(a, p2, b, p4, c));
			printf("%.3lf\n", min(m1, m2));
		}
	}
}