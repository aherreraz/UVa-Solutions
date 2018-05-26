#include <bits/stdc++.h>
using namespace std;
map<int, int> X, Y;
int n, m, q, auxX, auxY, x, y;
map<int, int>::iterator itX, itY, it1, it2, it3, it4, it5, it6;
int main()
{
	int caso = 1;
	while (scanf("%d %d %d", &n, &m, &q) == 3 && (n || m || q))
	{
		X.clear(); Y.clear();
		for (int i = 0; i < q; i++)
			scanf("%d %d", &auxX, &auxY), X[auxX]++, Y[auxY]++;
		scanf("%d %d", &x, &y);
		itX = X.end(), itY = Y.end();
		it1 = X.find(x - 1), it2 = X.find(x), it3 = X.find(x + 1);
		it4 = Y.find(y - 1), it5 = Y.find(y), it6 = Y.find(y + 1);
		if ((it1 == itX && it5 == itY && x > 0) || (it2 == itX && it4 == itY && y > 0) || (it2 == itX && it5 == itY) || (it2 == itX && it6 == itY && y < m - 1) || (it3 == itX && it5 == itY && x < n - 1))
			printf("Case %d: Escaped again! More 2D grid problems!\n", caso++);
		else
			printf("Case %d: Party time! Let's find a restaurant!\n", caso++);
	}
}