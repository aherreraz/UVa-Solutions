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
	int index;
	Point() {}
	Point(double px, double py) : x(px), y(py) {}
	Point(double px, double py, int idx) : x(px), y(py), index(idx) {}
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

int n;
vector<Point> v;
vector< vector<int> > g;
vector<int> visited;
int contImpar, contPar;

void createGraph()
{
	sort (v.begin(), v.end());
	set<Point> setX, setY;
	set<Point>::iterator it, itX, itY, lb, ub;
	double dist = 5.0;
	for (int i = 0; i < n; i++)
	{
		for (it = setX.begin(); it != setX.end(); itX = it++, setX.erase(itX))
			if (comparar(v[i].x - it->x, dist) > 0)
				setY.erase(setY.lower_bound(Point(it->y, it->x)));
			else
				break;
		lb = setY.lower_bound(Point(v[i].y - dist, -INF));
		ub = setY.upper_bound(Point(v[i].y + dist, INF));
		while (lb != ub)
		{
			double dAux = ~(v[i] - Point(lb->y, lb->x));
			if (comparar(dAux, dist) <= 0)
				g[v[i].index].push_back(lb->index), g[lb->index].push_back(v[i].index);
			lb++;
		}
		setX.insert (v[i]);
		setY.insert (Point(v[i].y, v[i].x, v[i].index));
	}
}
void dfs(int pos, int nivel)
{
	visited[pos] = 1;
	int sz = g[pos].size();
	for (int i = 0;i < sz; ++i)
		if (!visited[g[pos][i]])
			dfs(g[pos][i], nivel + 1);
	if (nivel % 2)
		contPar++;
	else
		contImpar++;
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		v.assign(n, Point());
		g.assign(n, vector<int>());
		visited.assign(n, 0);
		
		for(int i = 0; i < n; i++)
			scanf("%lf %lf", &v[i].x, &v[i].y), v[i].index = i;
		createGraph();
		int total = 0;
		for(int i = 0; i < n; i++)
			if(!visited[i])
				contImpar = 0, contPar = 0,	dfs(i, 0), total += max(contImpar, contPar);
		printf("%d\n", n - total);
	}
}
