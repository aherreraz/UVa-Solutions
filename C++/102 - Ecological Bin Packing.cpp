#include <bits/stdc++.h>
using namespace std;

int v[9], r[6];
int main()
{
	while (scanf("%d", &v[0]) == 1)
	{
		for (int i = 1; i < 9; i++)
			scanf("%d", &v[i]);
		int sum = 0;
		for (int i = 0; i < 9; i++)
			sum += v[i];
		r[0] = sum - (v[0] + v[5] + v[7]);
		r[1] = sum - (v[0] + v[4] + v[8]);
		r[2] = sum - (v[2] + v[3] + v[7]);
		r[3] = sum - (v[2] + v[4] + v[6]);
		r[4] = sum - (v[1] + v[3] + v[8]);
		r[5] = sum - (v[1] + v[5] + v[6]);
		int minR = r[0];
		int pos = 0;
		for (int i = 0; i < 6; i++)
			if (r[i] < minR)
				pos = i, minR = r[i];
		switch(pos)
		{
			case 0:
				printf("BCG %d\n", minR);
				break;
			case 1:
				printf("BGC %d\n", minR);
				break;
			case 2:
				printf("CBG %d\n", minR);
				break;
			case 3:
				printf("CGB %d\n", minR);
				break;
			case 4:
				printf("GBC %d\n", minR);
				break;
			case 5:
				printf("GCB %d\n", minR);
				break;
		}
	}
}