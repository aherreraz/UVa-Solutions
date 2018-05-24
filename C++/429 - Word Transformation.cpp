#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > g;
map<string, int> mapa;
map<string, int>::iterator it, it2;
vector<int> dist;
int n, t;
string in, s, s2;
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
	scanf("%d\n\n", &t);
	while (t--)
	{
		mapa.clear(); n = 0;
		
		while (getline(cin, in) && in.compare("*") != 0)
			mapa[in] = n++;
		//printf("%d\n", n);
		g.assign(n, vector<int>());
		for (it = mapa.begin(); it != mapa.end(); it++)
		{
			//printf("%s\n", it->first.c_str());
			for (it2 = mapa.begin(); it2 != mapa.end(); it2++)
			{
				int diff = 0;
				int s1 = it->first.length();
				int s2 = it2->first.length();
				if (s1 != s2)
					continue;
				for (int i = 0; i < s1; i++)
				{
					if (it->first[i] != it2->first[i])
						diff++;
				}
				if (diff == 1)
					//printf("%s %s\n", it->first.c_str(), it2->first.c_str()),
					g[it->second].push_back(it2->second), g[it2->second].push_back(it->second);
			}
		}
		while (getline(cin, in) && in.length() != 0)
		{
			char cad1[15], cad2[15];
			sscanf(in.c_str(), "%s %s", &cad1, &cad2);
			s = string(cad1), s2 = string(cad2);
			int a = mapa[s], b = mapa[s2];
			dist.assign(n, -1);
			bfs_visit(a);
			printf("%s %s %d\n", s.c_str(), s2.c_str(), dist[b]);
		}
		if (t) printf("\n");
	}
}