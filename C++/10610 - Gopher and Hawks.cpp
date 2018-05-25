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
int s, t, n;
double S;
string in;
Point aux;
vector<Point> v;
vector< vector<int> > g;
vector<int> dist;
void bfs_visit(int start)
{
	queue<int> q; q.push(start), dist[start] = 0;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			if (dist[u] == -1)
				dist[u] = dist[v] + 1, q.push(u);
		}
	}
}
int main()
{	
	while (scanf("%d %d\n", &s, &t) == 2 && (s & t))
	{
		n = 0; v.clear(); S = 60.0 * s * t;
		while (getline(cin, in) && in.length() > 0)
			sscanf(in.c_str(), "%lf %lf", &aux.x, &aux.y), v.push_back(aux), n++;
		
		g.assign(n, vector<int>());
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (comparar(~(v[i] - v[j]), S) < 0)
					g[i].push_back(j), g[j].push_back(i);
		dist.assign(n, -1);
		bfs_visit (0);
		if (dist[1] == -1)
			printf("No.\n");
		else
			printf("Yes, visiting %d other holes.\n",  dist[1] - 1);
	}
}