#include <bits/stdc++.h>
using namespace std;
int n, sz;
struct person
{
	string title, fn, ln, city, dpt, hp, wp, cb;
	bool operator < (person b)
	{
		return ln < b.ln;
	}
};
vector<person> v;
string dep, aux;
person pAux;
int main()
{
	scanf("%d\n", &n);
	v.clear();
	while (n--)
	{
		getline(cin, dep);
		while (getline(cin, aux) && !aux.empty())
		{
			stringstream ss(aux);
			getline(ss, pAux.title, ',');
			getline(ss, pAux.fn, ',');
			getline(ss, pAux.ln, ',');
			getline(ss, pAux.city, ',');
			getline(ss, pAux.hp, ',');
			getline(ss, pAux.wp, ',');
			getline(ss, pAux.cb);
			pAux.dpt = dep;
			v.push_back(pAux);
		}
	}
	sort(v.begin(), v.end());
	sz = v.size();
	for (int i = 0; i < sz; i++)
	{
		printf("----------------------------------------\n");
		printf("%s %s %s\n", v[i].title.c_str(), v[i].fn.c_str(), v[i].ln.c_str());
		printf("%s\n", v[i].city.c_str());
		printf("Department: %s\n", v[i].dpt.c_str());
		printf("Home Phone: %s\n", v[i].hp.c_str());
		printf("Work Phone: %s\n", v[i].wp.c_str());
		printf("Campus Box: %s\n", v[i].cb.c_str());
	}
}