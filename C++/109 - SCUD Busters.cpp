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
	Point () {}
	Point (double px, double py) : x(px), y(py) {}
};
double operator ~ (const Point &a)
{
	return sqrt (a.x * a.x + a.y * a.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point (a.x - b.x, a.y - b.y);
}
double operator * (const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}
double operator ^ (const Point &a, const Point &b)
{
	return a.x * b.y - b.x * a.y;
}
bool cmp (Point p1, Point p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
vector<Point> convexHull (vector<Point> P)
{
	int n = (int)P.size(), k = 0;
	vector<Point> H(2 * n);
	sort(P.begin(), P.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		while (k >= 2 && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) < 0)
			k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1;  i >= 0; i--)
	{
		while (k >= t && comparar((P[i] - H[k - 1]) ^ (H[k - 2] - H[k - 1]), 0) < 0)
			k--;
		H[k++] = P[i];
	}
	H.resize(k);
	//H.pop_back();
	return H;
}
double anguloPuntoEntreVectores(const Point &a, const Point &b)
{
	return safeAcos((a * b) / (~a * ~b));
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
	return comparar(sum, 2 * PI) == 0;
}
// Halla el área de un polígono
double areaPolygon(vector<Point> P)
{
	double res = 0;
	int n = P.size();
	for (int i = 0; i < n; i++)
		res += (P[i]) ^ (P[(i + 1) % n]);
	return fabs(res) / 2.0;
}
int main()
{
	vector< vector<Point> > kingdoms;
	vector< bool > kingdomConEnergia;
	int n;
	while (scanf("%d",&n) && n != -1)
	{
		vector<Point> kingdom;
		for(int i = 0; i < n; i++)
		{
			Point a;
			scanf("%lf %lf", &a.x, &a.y);
			kingdom.push_back(a);
		}
		kingdoms.push_back(convexHull(kingdom));
	}
	int m = kingdoms.size();
	kingdomConEnergia.clear();
	kingdomConEnergia.resize(m,true);
	Point misil;
	while(scanf("%lf %lf", &misil.x, &misil.y) == 2)
	{
		for(int i = 0; i < m; i++)
		{
			if(inPolygon(kingdoms[i], misil))
				kingdomConEnergia[i] = false;
		}
	}
	double areaSinEnergia = 0;
	for (int i = 0; i < m; i++)
	{
		if(!kingdomConEnergia[i])
			areaSinEnergia += areaPolygon(kingdoms[i]);
	}
	printf("%.2lf\n", areaSinEnergia);
}
