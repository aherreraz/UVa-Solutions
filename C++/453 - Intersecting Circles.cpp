#include <bits/stdc++.h>
#define EPS 1e-4
int comparar(double d1, double d2)
{
	if(d2 - d1 > EPS)
		return -1;
	else
		if(d1 - d2 > EPS)
		return 1;
	return 0;
}
struct Point
{
	double x, y;
	Point() {}
	Point(double px, double py) : x(px) , y(py) {}
	bool operator < (const Point &b) const
	{
		if (fabs(x - b.x) > EPS)
			return x < b.x;
		return y < b.y;
	}
};
struct Circle
{
	Point c;
	double r;
	Circle() {}
	Circle(Point pc, double nr) : c(pc), r(nr) {}
	Circle(double ncx, double ncy, double nr) : c(ncx, ncy), r(nr) {}
};
double operator ~ (const Point &a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
Point operator + (const Point &a, const Point &b)
{
	return Point(a.x + b.x, a.y + b.y);
}
Point operator + (const Point &a, const double &s)
{
	return Point(a.x + s, a.y + s);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
Point operator * (const Point &a, const double &s)
{
	return Point(a.x * s, a.y * s);
}
int interseccionCircunferecia(Circle a, Circle b, Point *p1, Point *p2)
{
	double D = ~(a.c - b.c);
	if (comparar(D, a.r + b.r) > 0 || comparar(D, fabs(a.r - b.r)) < 0)
		return 0;
	
	if (comparar(D, 0.0) == 0 && comparar(a.r, b.r) == 0)
	{
		if (comparar(a.r, 0.0) == 0)
		{
			*p1 = *p2 = a.c;
			return 1;
		}
		return 3;
	}
	
	double A = (a.r * a.r - b.r * b.r + D * D) / (2 * D);
	double H = sqrt(fabs(a.r * a.r - A * A));
	Point pAux = a.c + (b.c - a.c) * (A / D);
	*p1 = Point(pAux.x + (b.c.y - a.c.y) * (H / D), pAux.y - (b.c.x - a.c.x) * (H / D));
	*p2 = Point(pAux.x - (b.c.y - a.c.y) * (H / D), pAux.y + (b.c.x - a.c.x) * (H / D));
	if (comparar (p1->x, p2->x) == 0 && comparar (p1->y, p2->y) == 0)
		return 1;
	return 2;
}
int main()
{
	Circle a, b;
	while (scanf("%lf %lf %lf %lf %lf %lf", &a.c.x, &a.c.y, &a.r, &b.c.x, &b.c.y, &b.r) == 6)
	{
		Point p0, p1;
		int res = interseccionCircunferecia(a, b, &p0, &p1);
		switch (res)
		{
		case 0:
			printf("NO INTERSECTION\n");
			break;
		case 1:
			printf("(%.3lf,%.3lf)\n", p0.x + EPS, p0.y + EPS);
			break;
		case 2:
			
			if (p0 < p1)
				printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n", p0.x + EPS, p0.y + EPS, p1.x + EPS, p1.y + EPS);
			else
				printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n", p1.x + EPS, p1.y + EPS, p0.x + EPS, p0.y + EPS);
			break;
		case 3:
			printf("THE CIRCLES ARE THE SAME\n");
			break;
		}
	}
}