#include <bits/stdc++.h>
#define INF 9999
using namespace std;
int t, n;
string in;
char cIn[100000];
vector<int> res;
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
		scanf("%d\n", &n);
		int minN = INF;
		for (int i = 0; i < n; i++)
		{
			getline(cin, in);
			strcpy(cIn, in.c_str());
			vector<string> v = split(cIn, " ");
			int m = v.size();
			if (m < minN)
				res.clear(), res.push_back(i + 1), minN = m;
			else if (m == minN)
				res.push_back(i + 1);
		}
		int sz = res.size();
		for (int i = 0; i < sz; i++)
			if (i == 0)
				printf("%d", res[i]);
			else
				printf(" %d", res[i]);
		printf("\n");
	}
}