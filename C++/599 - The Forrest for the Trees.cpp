#include <bits/stdc++.h>
using namespace std;
int t;
char in[100];
char a, b;
int pset[26];
int setSize[26];
set<int> usedSets;
void initSet()
{
	for(int i = 0; i < 26; i++)
		pset[i] = i, setSize[i] = 1;
}
int findSet(int i)
{
	return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
	if (!isSameSet(i, j))
	{
		setSize[findSet(j)] += setSize[findSet(i)];
		pset[findSet(i)] = findSet(j);
	}
}
vector<string> split(char *input, char *tokens)
{
	vector<string> res;
	char *p;
	p = strtok(input, tokens);
	while(p != NULL)
	{
		res.push_back(p);
		p = strtok(NULL, tokens);
	}
	return res;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		initSet(), usedSets.clear();
		while (scanf("%s", &in) == 1 && in[0] != '*')
			sscanf(in, "(%c,%c)", &a, &b), unionSet(a - 'A', b - 'A');
		scanf("%s", &in);
		vector<string> v = split(in, ",");
		int n = v.size();
		int nTrees = 0, nAcorns = 0;
		for (int i = 0; i < n; i++)
		{
			int k = v[i][0] - 'A';
			if (setSize[findSet(k)] == 1)
				nAcorns++;
			else if (usedSets.find(pset[k]) == usedSets.end())
				nTrees++, usedSets.insert(pset[k]);
		}
		printf("There are %d tree(s) and %d acorn(s).\n", nTrees, nAcorns);
	}
}