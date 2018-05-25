#include <bits/stdc++.h>
using namespace std;
string aux;
int n;
vector<string> v;
bool comparar (string a, string b)
{
	return (a + b).compare(b + a) > 0;
}
int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> aux;
			v.push_back(aux);
		}
		sort(v.begin(), v.end(), comparar);
		for (int i = 0; i < n; i++)
			printf("%s", v[i].c_str());
		printf("\n");
	}
}