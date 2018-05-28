#include <bits/stdc++.h>
using namespace std;

int ask(int n)
{
	int res = 1;
	while (n != 1)
	{
		if (n % 2)
			n = 3 * n + 1;
		else
			n /= 2;
		res++;
	}
	return res;
}

int main()
{
	int l,r;
	while (scanf("%d %d", &l, &r) == 2)
	{
		int l1 = l, r1 = r, maxR = 0;
		if (l1 > r1)
			swap(l1, r1);		
		for (int i = l1; i <= r1; i++)
			maxR = max(ask(i), maxR);
		printf("%d %d %d\n", l, r, maxR);
	}
}
