#include <bits/stdc++.h>
#define EPS 1e-07
#define PI (2*acos(0.0))
#define CIRCLE 1
#define POLYGON 2
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
int puntoDentroCirculo(const Point &p, const Circle &C)
{
	return comparar(C.r, ~(p - C.c));
}
int figuras[10];
Circle circulos[10];
vector<Point> poligonos[10];
char s[5];
int main()
{
	int n = 0, np = 1;
	Point a, b, c, p;
	while(scanf("%s", &s) && s[0] != '*')
	{
		switch (s[0])
		{
		case 'c':
			scanf("%lf %lf %lf", &circulos[n].c.x, &circulos[n].c.y, &circulos[n].r);
			figuras[n] = CIRCLE;
			break;
		case 't':
			scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
			poligonos[n].push_back(a);
			poligonos[n].push_back(b);
			poligonos[n].push_back(c);
			figuras[n] = POLYGON;
			break;
		case 'r':
			scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
			poligonos[n].push_back(a);
			poligonos[n].push_back(Point(a.x, b.y));
			poligonos[n].push_back(b);
			poligonos[n].push_back(Point(b.x, a.y));
			figuras[n] = POLYGON;
		}
		n++;
	}
	while (scanf("%lf %lf", &p.x, &p.y) == 2)
	{
		if(comparar(p.x,9999.9) == 0 && comparar(p.y,9999.9) == 0)
			break;
		int cont = 0;
		for (int i = 0; i < n; i++)
		{
			switch(figuras[i])
			{
			case CIRCLE:
				if (puntoDentroCirculo(p, circulos[i]) > 0)
					printf("Point %d is contained in figure %d\n", np, i + 1), cont++;
				break;
			case POLYGON:
				if (inPolygon(poligonos[i], p))
					printf("Point %d is contained in figure %d\n", np, i + 1), cont++;
			}
		}
		if(cont == 0) printf("Point %d is not contained in any figure\n", np);
		np++;
	}
}
