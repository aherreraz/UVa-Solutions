#include <bits/stdc++.h>
#define EPS 1e-7
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

int n, m, t, s;
double S;
vector<Point> V;
vector<int> match;
vector<bool> visit;
vector< vector<int> > g;

int augmentingPath (int v)
{
	if (visit[v])
		return 0;
	visit[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int u = g[v][i];
		if (match[u] == -1 || augmentingPath(match[u]))
		{
			match[u] = v;
			return 1;
		}
	}
	return 0;
}
int MCBM (int left)
{
	int res = 0;
	match.assign(n + m, -1);
	for (int i = 0; i < left; i++)
		visit.assign(left, 0), res += augmentingPath(i);
	return res;
}
int main()
{
	while (scanf("%d %d %d %d", &n, &m, &t, &s) == 4)
	{
		S = (s * t);
		V.resize(n + m);
		g.assign(n + m, vector<int>());
		for (int i = 0; i < n + m; i++)
			scanf("%lf %lf", &V[i].x, &V[i].y);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (comparar(~(V[i] - V[n + j]), S) <= 0)
					g[i].push_back(j + n);
		printf("%d\n", n - MCBM(n));
	}
}