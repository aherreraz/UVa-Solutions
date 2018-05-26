#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
int main()
{
	int T;
	scanf("%d", &T);
	for(int z = 1; z <= T; z++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("Case %d: ",z);
		if( (a >= b + c) || (b >= a + c) || (c >= a + b) || a <= 0 || b <= 0 || c <= 0 )
		{
			printf("Invalid\n");
			continue;
		}
		if(a == b && b == c)
		{
			printf("Equilateral\n");
			continue;
		}

		if( (a == b && c != b) || (a == c && b != a) || (c == b && a != b) )
		{
			printf("Isosceles\n");
			continue;
		}
		printf("Scalene\n");
	}
}
