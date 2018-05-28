#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> M;
vector< vector<int> > idFilas, idColumnas, g;
vector<int> match;
vector<bool> visit;

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
	match.assign(m, -1);
	for (int i = 0; i < left; i++)
		visit.assign(left, 0), res += augmentingPath(i);
	return res;
}
int main()
{
    while (scanf("%d\n", &n) == 1)
    {
        M.resize(n);
        idFilas.assign(n, vector<int>(n, -1));
        idColumnas.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            getline(cin, M[i]);
        // Filas
        int l = -1;
        for (int i = 0; i < n; i++)
        {
            bool up = 1;
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == '.')
                    idFilas[i][j] = up ? ++l : l, up = 0;
                else
                    up = 1;
            }
        }
        // Columnas
        int r = l;
        for (int i = 0; i < n; i++)
        {
            bool up = 1;
            for (int j = 0; j < n; j++)
            {
                if (M[j][i] == '.')
                    idColumnas[j][i] = up ? ++r : r, up = 0;
                else
                    up = 1;
            }
        }
        m = r + 1;
        g.assign(m, vector<int>());
        // Aristas
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (idFilas[i][j] >= 0 && idColumnas[i][j] >= 0)
                    g[idFilas[i][j]].push_back(idColumnas[i][j]);
        printf("%d\n", MCBM(l + 1));
    }
}