#include <bits/stdc++.h>
#define EPS 1e-7
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
struct Segment
{
	Point p0, p1;
	Segment() {}
	Segment(Point pa, Point pb) : p0(pa), p1(pb) {}
	Segment(double p0x, double p0y, double p1x, double p1y) : p0(p0x, p0y) , p1(p1x, p1y) {}
};
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
bool puntoEnSegmento(const Segment &a, const Point &b)
{
	return comparar(b.x, min(a.p0.x, a.p1.x)) >= 0 && comparar(b.y, min(a.p0.y, a.p1.y)) >= 0 && comparar(b.x, max(a.p0.x, a.p1.x)) <= 0 && comparar(b.y, max(a.p0.y, a.p1.y)) <= 0;
}
bool verificarInterseccionSegmentos(const Segment &a, const Segment &b)
{
	double num1 = (b.p1 - b.p0) ^ (a.p0 - b.p0);
	double num2 = (a.p1 - a.p0) ^ (a.p0 - b.p0);
	double deno = (a.p1 - a.p0) ^ (b.p1 - b.p0);

	if (comparar(deno, 0.0) == 0)
	{
		if (comparar(num1, 0.0) == 0 && comparar(num2, 0.0) == 0)
			return puntoEnSegmento(a, b.p0) || puntoEnSegmento(a, b.p1) || puntoEnSegmento(b, a.p0) || puntoEnSegmento(b, a.p1);
		return false;
	}

	double k1 = num1 / deno;
	double k2 = num2 / deno;

	if (comparar(k1, 0.0) >= 0 && comparar(k1, 1.0) <= 0 && comparar(k2, 0.0) >= 0 && comparar(k2, 1.0) <= 0)
		return true;
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	Point pL1, pL2, p1, p2, p3, p4;
	while (T--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &pL1.x, &pL1.y, &pL2.x, &pL2.y, &p1.x, &p1.y, &p4.x, &p4.y);
		p2.x = p4.x;
		p2.y = p1.y;
		p3.x = p1.x;
		p3.y = p4.y;
		bool b1, b2, b3, b4, b5, b6;
		b1 = verificarInterseccionSegmentos(Segment(pL1, pL2), Segment(p1, p2));
		b2 = verificarInterseccionSegmentos(Segment(pL1, pL2), Segment(p2, p4));
		b3 = verificarInterseccionSegmentos(Segment(pL1, pL2), Segment(p3, p4));
		b4 = verificarInterseccionSegmentos(Segment(pL1, pL2), Segment(p1, p3));
		b5 = comparar(pL1.x, min(p1.x, p4.x)) >= 0 && comparar(pL1.y, min(p1.y, p4.y)) >= 0 && comparar(pL1.x, max(p1.x, p4.x)) <= 0 && comparar(pL1.y, max(p1.y, p4.y)) <= 0;
		b5 = comparar(pL2.x, min(p1.x, p4.x)) >= 0 && comparar(pL2.y, min(p1.y, p4.y)) >= 0 && comparar(pL2.x, max(p1.x, p4.x)) <= 0 && comparar(pL2.y, max(p1.y, p4.y)) <= 0;
		if ( b1 || b2 || b3 || b4 || b5 || b6 )
			printf("T\n");
		else
			printf("F\n");
	}
}
