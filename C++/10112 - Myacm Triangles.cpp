#include <bits/stdc++.h>
#define EPS 1e-7
#define PI (2*acos(0.0))
using namespace std;
int comparar(double a, double b)
{
	if(b - a > EPS)	return -1;
	if(a - b > EPS)	return 1;
	return 0;
}
double safeAcos(double a)
{
	return acos(max(min(a, 1.0), -1.0));
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
double areaTriangle (Point a, Point b, Point c)
{
	return 0.5 * fabs( (b - a) ^ (c - a) );
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
bool inPolygonBorder(vector<Point> P, Point a)
{
	int n = P.size();
	for (int i = 0; i < n; i++)
		if (comparar(~(P[i] - a) + ~(P[(i + 1) % n] - a), ~(P[(i + 1) % n] - P[i])) == 0)
			return true;
	return false;
}
int main()
{
	int n;
	char s[5];
	vector<Point> v;
	while (scanf("%d", &n) == 1 && n)
	{
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%s %lf %lf", &s, &v[i].x, &v[i].y);
		
		double maxA = 0.0;
		for (int i = 0; i < n - 2; i++)
			for (int j = i + 1; j < n - 1; j++)
				for (int k = j + 1; k < n; k++)
				{
					bool cumple = true;
					vector<Point> aux;
					aux.clear();
					aux.push_back(v[i]);
					aux.push_back(v[j]);
					aux.push_back(v[k]);
					for (int p = 0; p < n && cumple; p++)
					{
						if (p == i || p == j || p == k)
							continue;
						if (inPolygon(aux, v[p]) || inPolygonBorder(aux, v[p]))
							cumple = false;
					}
					if (cumple)
					{
						double area = areaTriangle (v[i], v[j], v[k]);
						if (comparar (area, maxA) > 0)
							maxA = area, sprintf(s,"%c%c%c", i + 'A', j + 'A', k + 'A');
					}
				}
		printf("%s\n", s);
	}
}