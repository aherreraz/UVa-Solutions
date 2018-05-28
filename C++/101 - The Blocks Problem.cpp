#include <bits/stdc++.h>
using namespace std;

char input[40];
char cA[10];
char cB[10];
int a,b;
vector< vector<int> > v;
vector<int> auxA;
vector<int> auxB;

int main()
{
	int n;
	scanf("%d\n", &n);
	v.clear();
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[i].resize(1, i);
	while (gets(input) && strcmp(input,"quit") != 0)
	{
		sscanf(input, "%s %d %s %d", &cA, &a, &cB, &b);
		if(a == b)
			continue;
		int iA, jA, iB, jB;
		for (int i = 0; i < n; i++)
		{
			int m = v[i].size();
			for (int j = 0; j < m; j++)
			{
				if (v[i][j] == a)
					iA = i, jA = j;
				if (v[i][j] == b)
					iB = i, jB = j;
			}
		}
		if(iA == iB)
			continue;
		if (strcmp(cA, "move") == 0 && strcmp(cB, "onto") == 0)
		{
			auxA.clear();
			auxB.clear();
			for (int j = 0; j < jA; j++)
				auxA.push_back(v[iA][j]);

			for (int j = 0;j <= jB; j++)
				auxB.push_back(v[iB][j]);

			auxB.push_back(v[iA][jA]);
			int mA = v[iA].size();
			int mB = v[iB].size();
			for (int j = jA + 1; j < mA; j++)
				v[v[iA][j]].push_back(v[iA][j]);
			for(int j=jB+1;j<mB;j++)
				v[v[iB][j]].push_back(v[iB][j]);
			v[iA] = auxA;
			v[iB] = auxB;
		}
		else if (strcmp(cA, "move") == 0 && strcmp(cB, "over") == 0)
		{
			auxA.clear();
			for (int j = 0; j < jA; j++)
				auxA.push_back(v[iA][j]);
			int mA = v[iA].size();
			for(int j = jA + 1; j < mA; j++)
				v[v[iA][j]].push_back(v[iA][j]);
			v[iA] = auxA;
			v[iB].push_back(a);
		}
		else if (strcmp(cA, "pile") == 0 && strcmp(cB, "onto") == 0)
		{
			auxA.clear();
			auxB.clear();
			for (int j = 0; j < jA; j++)
				auxA.push_back(v[iA][j]);
			for (int j = 0;j <= jB; j++)
				auxB.push_back(v[iB][j]);
			int mA = v[iA].size();
			int mB = v[iB].size();
			for (int j = jA; j < mA; j++)
				auxB.push_back(v[iA][j]);
			for (int j = jB + 1; j < mB; j++)
				v[v[iB][j]].push_back(v[iB][j]);
			v[iA] = auxA;
			v[iB] = auxB;
		}
		else if (strcmp(cA, "pile") == 0 && strcmp(cB, "over") == 0)
		{
			auxA.clear();
			for (int j = 0; j < jA; j++)
				auxA.push_back(v[iA][j]);
			int mA = v[iA].size();
			for (int j = jA; j < mA; j++)
				v[iB].push_back(v[iA][j]);
			v[iA]=auxA;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int M = v[i].size();
		printf("%d:",i);
		for (int j = 0; j < M; j++)
			printf(" %d",v[i][j]);
		printf("\n");
	}
}