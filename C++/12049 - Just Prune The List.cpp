#include <bits/stdc++.h>
using namespace std;

map<int, int> v1;
map<int, int> v2;
map<int, int>::iterator it1;
map<int, int>::iterator it2;

int main()
{
	int t, n1, n2, aux;
	scanf("%d", &t);
	while (t--)
	{
		v1.clear(); v2.clear();
		scanf("%d %d", &n1, &n2);
		for (int i = 0; i < n1; i++)
			scanf("%d", &aux), v1[aux]++;
		for (int i = 0; i < n2; i++)
			scanf("%d", &aux), v2[aux]++;
		int cont = 0;
		for (it1 = v1.begin(); it1 != v1.end(); it1++)
		{
			it2 = v2.find(it1->first);
			if (it2 == v2.end())
				cont += it1->second;
			else if (it1->second > it2->second)
				cont += it1->second - it2->second;
		}
		for (it2 = v2.begin(); it2 != v2.end(); it2++)
		{
			it1 = v1.find(it2->first);
			if (it1 == v1.end())
				cont += it2->second;
			else if (it2->second > it1->second)
				cont += it2->second - it1->second;
		}
		printf("%d\n", cont);
	}
}
