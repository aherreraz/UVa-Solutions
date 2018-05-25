#include <bits/stdc++.h>
#define EPS 1e-7
#define INF 2e8
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

	bool operator < (const Point &b) const
	{
		if (fabs(x - b.x) > EPS)
			return x < b.x;
		return y < b.y;
	}
};
double operator ~ (const Point &a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y);
}
double closestPair(vector<Point> v)
{
	// Ordenamos los puntos
	int n = v.size();
	sort (v.begin(), v.end());
	// Guardamos los puntos que están a distancia res del sweep line
	// setX: Puntos ordenados por x
	// setY: Puntos ordenados por y
	set<Point> setX, setY;
	set<Point>::iterator it, itX, itY, lb, ub;
	double res = INF;
	for (int i = 0; i < n; i++)
	{
		// Eliminamos los puntos cuya coordenada x está a más distancia que res
		for (it = setX.begin(); it != setX.end(); itX = it++, setX.erase(itX))
			if (comparar(v[i].x - it->x, res) > 0)
				setY.erase(setY.lower_bound(Point(it->y, it->x)));
			else
				break;
		// Consideramos los puntos cuya coordenada "y" se encuentra entre [Y-res, Y+res]
		lb = setY.lower_bound(Point(v[i].y - res, -INF));
		ub = setY.upper_bound(Point(v[i].y + res, INF));
		// Actualizamos la respuesta
		while (lb != ub)
			res = min (res, ~(v[i] - Point(lb->y, lb->x))), lb++;
		// Agregamos el punto a los sets
		setX.insert (v[i]);
		setY.insert (Point(v[i].y, v[i].x));
	}
	return res;
}
int main()
{
	int n;
	vector<Point> v;
	while (scanf("%d", &n) == 1 && n)
	{
		v.clear(), v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y);
		double res = closestPair(v);
		if (comparar (res, 10000.0) < 0)
			printf("%.4lf\n", res);
		else
			printf("INFINITY\n");
	}
}