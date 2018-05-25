#include <bits/stdc++.h>
#define EPS 1e-7
#define PI (2*acos(0.0))
using namespace std;
int comparar(double a, double b)
{
	if (a - b > EPS) return 1;
	if (b - a > EPS) return -1;
	return 0;
}
struct Point
{
	double x, y;
	Point () {}
	Point (double px, double py) : x(px), y(py) {}
};
Point operator + (const Point &a, const Point &b)
{
	return Point (a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point (a.x - b.x, a.y - b.y);
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
	H.pop_back();
	return H;
}
// Devuelve un vector de strings con la cadena "input" separada por los "tokens" indiciados
vector<string> split(char *input, char *tokens)
{
	vector<string> res;
	char *p;
	p = strtok(input, tokens);
	while(p != NULL)
	{
		res.push_back(p);
		p = strtok(NULL, tokens);
	}
	return res;
}
string in;
char cIn[1000000];
vector<string> s;
vector<Point> v, hull;
int main()
{
	while (getline(cin, in))
	{
		strcpy (cIn, in.c_str());
		s = split(cIn, " ");
		int n = s.size();
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i++)
			sscanf(s[i].c_str(), "(%lf,%lf)", &v[i].x, &v[i].y);
		hull = convexHull(v);
		int m = hull.size();
		for (int i = 0; i < m; i++)
			printf("(%g,%g) ", hull[i].x, hull[i].y);
		printf("(%g,%g)\n", hull[0].x, hull[0].y);
	}
}