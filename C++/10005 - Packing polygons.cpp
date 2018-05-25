#include <bits/stdc++.h>
#define EPS 1e-7

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
	return hypot(a.x, a.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
Point operator + (const Point &a, const Point &b)
{
	return Point(a.x + b.x, a.y + b.y);
}
Point operator * (const Point &a, const double &s)
{
	return Point(a.x * s, a.y * s);
}
int puntoDentroCirculo(const Point &p, const Circle &C)
{
	return comparar(C.r, ~(p - C.c));
}
int interseccionCircunferecia(Circle a, Circle b, Point *p1, Point *p2)
{
	double D = ~(a.c - b.c);
	if (comparar(D, a.r + b.r) > 0 || comparar(D, fabs(a.r - b.r)) < 0)
		return 0;
	if (comparar(D, a.r + b.r) == 0)
	{
		*p1 = *p2 = a.c + ((b.c - a.c) * (a.r / D));
		return 1;
	}

	double A = (a.r * a.r - b.r * b.r + D * D) / (2 * D);
	double H = sqrt(a.r * a.r - A * A);
	Point pAux = a.c + (b.c - a.c) * (A / D);
	*p1 = Point(pAux.x + (b.c.y - a.c.y) * (H / D), pAux.y - (b.c.x - a.c.x) * (H / D));
	*p2 = Point(pAux.x - (b.c.y - a.c.y) * (H / D), pAux.y + (b.c.x - a.c.x) * (H / D));
	return 2;
}

Point v[110];
int main()
{
	int n;
	double R;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		scanf("%lf", &R);
		bool cumplen = (n == 1);
				
		for (int i = 0; i < n && !cumplen; i++)
		{
			for (int j = i + 1; j < n && !cumplen; j++)
			{
				Circle a (v[i], R);
				Circle b (v[j], R);
				Circle c1, c2;
				c1.r = c2.r = R;
				int inter = interseccionCircunferecia (a, b, &c1.c, &c2.c);
				bool cumpleC1 = true, cumpleC2 = true;
				for (int k = 0; k < n && cumpleC1; k++)
				{
					if (puntoDentroCirculo(v[k], c1) < 0)
						cumpleC1 = false;
				}
				for (int k = 0; k < n && cumpleC2; k++)
				{
					if (puntoDentroCirculo(v[k], c2) < 0)
						cumpleC2 = false;
				}
				if (cumpleC1 || cumpleC2)
					cumplen = true;
			}
		}
		if (cumplen)
			printf("The polygon can be packed in the circle.\n");
		else
			printf("There is no way of packing that polygon.\n");
	}
}
