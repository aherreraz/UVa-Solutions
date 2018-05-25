#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> perm;
int main()
{
	while (getline(cin, s))
	{
		int n = s.length();
		perm.assign(21, "");
		perm[10] = s;
		string prev(s);
		for (int i = 1; i <= 10; i++)
			prev_permutation(prev.begin(), prev.end()), perm[10 - i] = prev;
		string next(s);
		for (int i = 1; i <= 10; i++)
			next_permutation(next.begin(), next.end()), perm[10 + i] = next;
		
		int m = -1, p = -1;
		for (int i = 0; i < 21; i++)
		{
			int aux = abs(perm[i][1] - perm[i][0]);
			for (int j = 2; j < n; j++)
				aux = min(aux, abs(perm[i][j] - perm[i][j - 1]));
			if (aux > m)
				m = aux, p = i;
		}
		printf("%s%d\n", perm[p].c_str(), m);
	}
}