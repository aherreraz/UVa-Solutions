#include <bits/stdc++.h>
using namespace std;
struct team
{
	string name;
	int wins, ties, loss;
	int goalScore, goalAgainst;
	team(string s) : name(s), wins(0), ties(0), loss(0), goalScore(0), goalAgainst(0) {}
	void inc(bool w, bool t, bool l, int gs, int ga)
	{
		if (w) wins++;
		if (t) ties++;
		if (l) loss++;
		goalScore += gs, goalAgainst += ga;
	}
};
int t, n, m;
string in;
vector<team> v;
map<string, int> mapa;
bool comparar(team a, team b)
{
	if (3 * a.wins + a.ties != 3 * b.wins + b.ties)
		return 3 * a.wins + a.ties > 3 * b.wins + b.ties;
	else if (a.wins != b.wins)
		return a.wins > b.wins;
	else if (a.goalScore - a.goalAgainst != b.goalScore - b.goalAgainst)
		return a.goalScore - a.goalAgainst > b.goalScore - b.goalAgainst;
	else if (a.goalScore != b.goalScore)
		return a.goalScore > b.goalScore;
	else if (a.wins + a.ties + a.loss != b.wins + b.ties + b.loss)
		return a.wins + a.ties + a.loss < b.wins + b.ties + b.loss;
	else
	{
		string na(a.name), nb(b.name);
		int ta = na.length(), tb = nb.length();
		for (int i = 0; i < ta; i++) na[i] = tolower(na[i]);
		for (int i = 0; i < tb; i++) nb[i] = tolower(nb[i]);
		return lexicographical_compare(na.begin(), na.end(), nb.begin(), nb.end());
	}
}
int main()
{
	scanf("%d\n", &t);
	while (t--)
	{
		mapa.clear();
		getline(cin, in);
		scanf("%d\n", &n);
		printf("%s\n", in.c_str());
		v.resize(n, team(""));
		for (int i = 0; i < n; i++)
			getline(cin, in), v[i] = team(in), mapa[in] = i;
		scanf("%d\n", &m);
		for (int i = 0; i < m; i++)
		{
			getline(cin, in);
			stringstream ss(in);
			char aux;
			string t1, t2;
			int n1, n2;
			getline(ss, t1, '#');
			ss >> n1 >> aux >> n2 >> aux;
			getline(ss, t2);
			v[mapa[t1]].inc(n1 > n2, n1 == n2, n1 < n2, n1, n2);
			v[mapa[t2]].inc(n2 > n1, n2 == n1, n2 < n1, n2, n1);
		}
		sort(v.begin(), v.end(), comparar);
		for (int i = 0; i < n; i++)
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, v[i].name.c_str(), 3 * v[i].wins + v[i].ties, v[i].wins + v[i].ties + v[i].loss, v[i].wins, v[i].ties, v[i].loss, v[i].goalScore - v[i].goalAgainst, v[i].goalScore, v[i].goalAgainst);
		if (t > 0) printf("\n");
	}
}