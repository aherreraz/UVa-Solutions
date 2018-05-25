#include <bits/stdc++.h>
using namespace std;
struct carMaker
{
	int minP, maxP;
	string name;
	carMaker() {}
	carMaker(int m) : minP(m), maxP(m) {}
};
bool comparar(carMaker a, carMaker b)
{
	return a.minP < b.minP || (a.minP == b.minP && a.maxP < b.maxP);
}
int t, n, m, aux;
vector<carMaker> v;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].name >> v[i].minP >> v[i].maxP;
		sort(v.begin(), v.end(), comparar);
		/*for (int i = 0; i < n; i++)
			printf("%d %d %s\n", v[i].minP, v[i].maxP, v[i].name.c_str());*/
		scanf("%d", &m);
		
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &aux);
			int r, c = 0;
			for (int j = 0; j < n; j++)
				if (aux >= v[j].minP && aux <= v[j].maxP)
					c++, r = j;
			if (c == 1)
				printf("%s\n", v[r].name.c_str());
			else
				printf("UNDETERMINED\n");
		}	
		if (t) printf("\n");
	}
}