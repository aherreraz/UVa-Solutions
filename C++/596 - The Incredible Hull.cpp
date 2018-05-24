#include <bits/stdc++.h>
#define EPS 1e-7
#define PI (2*acos(0.0))
using namespace std;
typedef pair<double, double> dd;
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
	return p1.x > p2.x || (p1.x == p2.x && p1.y < p2.y);
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
int n, caso = 0;
string in;
char cIn[1000];
vector<string> s;
set<dd> usados;
vector<Point> v, hull, pAux;
Point aux;
char hullName[1000];
void printHull()
{
	printf("%s convex hull:\n", hullName + 2);
	hull = convexHull(v);
	int m = hull.size();
	for (int i = 0; i < m; i++)
		printf(" (%.0lf,%.0lf)", hull[i].x, hull[i].y);
	printf("\n");
}
int main()
{
	while (getline(cin, in))
	{
		strcpy (cIn, in.c_str());
		if (cIn[0] == 'S')
		{
			if (caso++ > 0)
				printHull();
			v.clear();
			usados.clear();
			strcpy (hullName, cIn);
		}
		else if (cIn[0] == 'P')
		{
			s = split(cIn, " ");
			sscanf(s[1].c_str(), "%d", &n);
			for (int i = 2; i < 2 * n + 2; i++)
				if (i & 1)
				{
					sscanf(s[i].c_str(), "%lf", &aux.y);
					if (usados.find(dd(aux.x, aux.y)) == usados.end())
						v.push_back(aux), usados.insert(dd(aux.x, aux.y));
				}
				else
					sscanf(s[i].c_str(), "%lf", &aux.x);
		}
		else if (strcmp(cIn, "END") == 0)
		{
			printHull();
			usados.clear();
			v.clear();
		}
	}
}