#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int t, n, m;
int M[10][100];
int v[10];
set<ii> s;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &M[i][j]);
		bool cumple = true;
		s.clear();
		for (int i = 0; i < m && cumple; i++)
		{
			int k = 0;
			for (int j = 0; j < n; j++)
				if (M[j][i])
					v[k++] = j;
			if (k != 2)
				cumple = false;
			else if (s.find(ii(v[0], v[1])) == s.end())
				s.insert(ii(v[0], v[1]));
			else
				cumple = false;			
		}
		if (cumple)
			printf("Yes\n");
		else
			printf("No\n");
	}
}