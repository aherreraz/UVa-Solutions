#include <bits/stdc++.h>
#define PI (2*acos(0.0))
#define EPS 1e-7
using namespace std;
int comparar(double a, double b)
{
	if (a - b > EPS) return 1;
	if (b - a > EPS) return -1;
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
	Point(double px, double py) : x(px), y(py) {}
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
bool cmp(Point p1, Point p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
vector<Point> convexHull(vector<Point> P)
{
	int n = (int)P.size(), k = 0;
	vector<Point> H(2 * n);
	sort(P.begin(), P.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		while (k >= 2 && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) <= 0)
			k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--)
	{
		while (k >= t && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) <= 0)
			k--;
		H[k++] = P[i];
	}
	H.resize(k);
	H.pop_back();
	return H;
}
double anguloPuntoEntreVectores(const Point &a, const Point &b)
{
	return safeAcos((a * b) / (~a * ~b));
}
// Determina si un punto "a" se encuentra estrictamente dentro de un polígono "P"
bool inPolygon(vector<Point> P, Point a)
{
	double sum = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++)
	if (comparar((P[i] - a) ^ (P[(i + 1) % n] - a), 0) > 0)
		sum += anguloPuntoEntreVectores(P[i] - a, P[(i + 1) % n] - a);
	else
		sum -= anguloPuntoEntreVectores(P[i] - a, P[(i + 1) % n] - a);
	return comparar(sum, 2 * PI) == 0;
}
// Determina si un punto "a" se encuentra en el borde de un polígono "P"
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
	int c, r, o, caso = 1;
	bool enoughCops, enoughRobbers;
	vector<Point> cops;
	vector<Point> robbers;
	while (scanf("%d %d %d", &c, &r, &o) == 3 && (c | r | o))
	{
		cops.clear(); cops.resize(c);
		robbers.clear(); robbers.resize(r);
		enoughCops = (c >= 3);
		enoughRobbers = (r >= 3);
		for (int i = 0; i < c; i++)
			scanf("%lf %lf", &cops[i].x, &cops[i].y);
		for (int i = 0; i < r; i++)
			scanf("%lf %lf", &robbers[i].x, &robbers[i].y);
		if (enoughCops) cops = convexHull(cops);
		if (enoughRobbers) robbers = convexHull(robbers);
		printf("Data set %d:\n", caso++);
		for (int i = 0; i < o; i++)
		{
			Point p;
			scanf("%lf %lf", &p.x, &p.y);
			if (enoughCops && (inPolygon(cops, p) || inPolygonBorder(cops, p)))
				printf("     Citizen at (%.0lf,%.0lf) is safe.\n", p.x, p.y);
			else if (enoughRobbers && (inPolygon(robbers, p) || inPolygonBorder(robbers, p)))
				printf("     Citizen at (%.0lf,%.0lf) is robbed.\n", p.x, p.y);
			else
				printf("     Citizen at (%.0lf,%.0lf) is neither.\n", p.x, p.y);
		}
		printf("\n");
	}
}