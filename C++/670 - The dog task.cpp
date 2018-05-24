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

int t, n, m;
vector<Point> V;
vector< vector<int> > g;
vector<bool> visit;
vector<int> match;
vector<int> R;
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
			R[v] = u;
			return 1;
		}
	}
	return 0;
}
int MCBM (int left)
{
	int res = 0;
	match.assign(n + m, -1);
	R.assign(n, -1);
	for (int i = 0; i < left; i++)
		visit.assign(left, 0), res += augmentingPath(i);
	return res;
}
bool isInRange(int i, int j)
{
	double dist1 = ~(V[i] - V[j + n]) + ~(V[i + 1] - V[j + n]);
	double dist2 = ~(V[i] - V[i + 1]);
	return comparar(dist1, 2 * dist2) <= 0;
		
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		g.assign(n + m, vector<int>());
		V.resize(n + m);
		for (int i = 0; i < n + m; i++)
			scanf("%lf %lf", &V[i].x, &V[i].y);
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < m; j++)
				if (isInRange(i, j))
					g[i].push_back(j + n);
		printf("%d\n", n + MCBM(n));
		for (int i = 0; i < n; i++)
		{
			if (i > 0) printf(" ");
			printf("%.0lf %.0lf", V[i].x, V[i].y);
			if (R[i] != -1)
				printf(" %.0lf %.0lf", V[R[i]].x, V[R[i]].y);
		}
		printf("\n");
		if (t) printf("\n");
	}
}