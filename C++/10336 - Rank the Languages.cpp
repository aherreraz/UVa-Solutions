#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> ic;

int t, n, m;
vector<string> M;
vector< vector<bool> > visited;
int aux_x[4] = {1, -1, 0, 0};
int aux_y[4] = {0, 0, 1, -1};
int frec[26];
vector<ic> v;

void dfs_visit(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + aux_x[i];
		int ny = y + aux_y[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			if (!visited[nx][ny] && M[x][y] == M[nx][ny])
				dfs_visit(nx, ny);
	}
}
void dfs()
{
	memset(frec, 0, sizeof frec);
	visited.assign(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j])
				frec[M[i][j] - 'a']++, dfs_visit(i, j);
}
int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %d\n", &n, &m);
		M.resize(n), v.clear();
		for (int i = 0; i < n; i++)
			getline(cin, M[i]);
		dfs();
		printf("World #%d\n", z);
		for (int i = 0; i < 26; i++)
			if (frec[i] > 0)
				v.push_back(ic(-frec[i], i + 'a'));
		sort(v.begin(), v.end());
		int k = v.size();
		for (int i = 0; i < k; i++)
			printf("%c: %d\n", v[i].second, -v[i].first);
	}
}
