#include <bits/stdc++.h>
#define EPS 1e-7
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
};
struct Circle
{
	Point c;
	double r;
	Circle() {}
	Circle(Point pc, double nr) : c(pc), r(nr) {}
	Circle(double ncx, double ncy, double nr) : c(ncx, ncy), r(nr) {}
};
struct Segment
{
	Point p0, p1;
	Segment() {}
	Segment(Point pa, Point pb) : p0(pa), p1(pb) {}
	Segment(double p0x, double p0y, double p1x, double p1y) : p0(p0x, p0y) , p1(p1x, p1y) {}
};
double operator ~ (const Point &a)
{
	return hypot(a.x, a.y);
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
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
Point interseccionLineas(const Segment &a, const Segment &b, bool *paralelas, bool *mismaLinea)
{
	double num1 = (b.p1 - b.p0) ^ (a.p0 - b.p0);
	double num2 = (a.p1 - a.p0) ^ (a.p0 - b.p0);
	double deno = (a.p1 - a.p0) ^ (b.p1 - b.p0);

	if (comparar(deno, 0.0) == 0)
	{
		*paralelas = true;
		*mismaLinea = comparar(num1, 0.0) == 0 && comparar(num2, 0.0) == 0;
		return Point(0.0, 0.0);
	}
	else
	{
		*paralelas = false;
		*mismaLinea = false;
		double k = num1 / deno;
		return Point(a.p0 + (a.p1 - a.p0) * k);
	}
}
Circle circuloDesde3puntos(const Point &a, const Point &b, const Point &c)
{
	Point ab = b - a, cb = b - c;
	Point pm1 = a + ab * 0.5; // punto medio de ab
	Point pm2 = c + cb * 0.5; // punto medio de cb
	Point po1 = pm1 + Point(-ab.y, ab.x); // línea pm1-po1 perpendicular a ab
	Point po2 = pm2 + Point(-cb.y, cb.x); // línea pm2-po2 perpendicular a cb
	bool paralelas, mismaLinea;
	Circle res;
	res.c = interseccionLineas(Segment(pm1, po1), Segment(pm2, po2), &paralelas, &mismaLinea);
	res.r = ~(res.c - a); // distancia del centro a cualquier punto
	return res;
}
int main()
{
	Point p1, p2, p3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y) == 6)
	{
		Circle c = circuloDesde3puntos(p1, p2, p3);
		if( comparar( c.c.x , 0.0 ) < 0)
			printf("(x + %.3lf)^2 + ",-c.c.x);
		else
			if( comparar( c.c.x , 0.0 ) > 0)
				printf("(x - %.3lf)^2 + ",c.c.x);
			else
				printf("x^2 + ");

		if( comparar( c.c.y , 0.0 ) < 0)
			printf("(y + %.3lf)^2 = ",-c.c.y);
		else
			if( comparar( c.c.y , 0.0 ) > 0)
				printf("(y - %.3lf)^2 = ",c.c.y);
			else
				printf("y^2 = ");
		printf("%.3lf^2\nx^2 + y^2 ",c.r);

		double C, D, E;
		C = 2*c.c.x;
		D = 2*c.c.y;
		E = c.c.x * c.c.x + c.c.y * c.c.y - c.r * c.r;
		if( comparar( C , 0.0 ) < 0 )
			printf("+ %.3lfx ",fabs(C));
		else
			if( comparar( C , 0.0 ) > 0 )
				printf("- %.3lfx ",fabs(C));

		if( comparar( D , 0.0 ) < 0 )
			printf("+ %.3lfy ",fabs(D));
		else
			if( comparar( D , 0.0 ) > 0 )
				printf("- %.3lfy ",fabs(D));

		if( comparar( E , 0.0 ) < 0 )
			printf("- %.3lf = 0\n\n",fabs(E));
		else
			if( comparar( E , 0.0 ) > 0 )
				printf("+ %.3lf = 0\n\n",fabs(E));
			else
				printf("= 0\n\n");
	}
}
