#include <bits/stdc++.h>
#define SOL 33000480
using namespace std;
typedef pair<int, int> ii;

int auxX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int auxY[8] = {1, -1, -2, 2, 2, -2, 1, -1};
map<ii, int> dist;
map<ii, int>::iterator it;
ii bfs(ii start)
{
	queue<ii> q; q.push(start), dist[start] = 0;
	while (!q.empty())
	{
		ii v = q.front(); q.pop();
		if (dist[v] == 10)
			return ii (-1, -1);
		int x = 4 - (v.second % 5), y = 4 - (v.second / 5);
		for (int k = 0; k < 8; k++)
		{
			int nx = x + auxX[k];
			int ny = y + auxY[k];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
			{
				ii u;
				u.first = v.first;
				u.second = (4 - ny) * 5 + 4 - nx;
				if (u.first & (1 << u.second))
					u.first |= (1 << v.second);
				u.first &= ~(1 << u.second);
				it = dist.find(u);
				if (it == dist.end())
					q.push(u), dist[u] = dist[v] + 1;
				if (u.first == SOL && u.second == 12)
					return u;
			}
		}
	}
}
string in;
int main()
{
	int t;
	scanf("%d\n", &t);
	while (t--)
	{
		ii a = ii(0, 0);
		dist.clear();
		for (int i = 4; i >= 0; i--)
		{
			getline(cin, in);
			for (int j = 0; j < 5; j++)
				if (in[j] == ' ')
					a.second = i * 5 + (4 - j);
				else if (in[j] == '1')
					a.first |= (1 << (i * 5 + (4 - j)));
		}
		ii res = bfs(a);
		if (res == ii(-1, -1))
			printf("Unsolvable in less than 11 move(s).\n");
		else
			printf("Solvable in %d move(s).\n", dist[res]);
	}
}