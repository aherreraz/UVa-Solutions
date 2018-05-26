#include <bits/stdc++.h>
#define MAX 51
using namespace std;
typedef long long ll;

string in;
char cIn[110];
vector<string> s;
ll C[MAX][MAX];
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
void init()
{
	memset(C, 0, sizeof C);
	for (int i = 0; i < MAX; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
}
void print (string a, string b, ll n, ll k)
{
	ll c = C[n][k], e1 = n - k, e2 = k;
	if (c > 1) printf("%lld*", c);
	if (e1 == 1) printf("%s", a.c_str());
	else if (e1 > 1) printf("%s^%lld", a.c_str(), e1);
	if (e1 > 0 && e2 > 0) printf("*");
	if (e2 == 1) printf("%s", b.c_str());
	else if (e2 > 1) printf("%s^%lld", b.c_str(), e2);
}
int main()
{
	ll t, n;
	scanf("%lld\n", &t);
	init ();
	for (ll z = 1; z <= t; z++)
	{
		getline (cin, in);
		strcpy (cIn, in.c_str());
		s = split(cIn, "(+)^");
		sscanf(s[2].c_str(), "%lld", &n);
		printf("Case %lld: ", z);
		for (ll i = 0; i <= n; i++)
		{
			if (i > 0)
				printf("+"), print(s[0], s[1], n, i);
			else
				print(s[0], s[1], n, i);
		}
		printf("\n");
	}
}