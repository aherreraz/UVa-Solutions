#include <bits/stdc++.h>
using namespace std;
string in;
int v[10];
int main()
{
	int caso = 1;
	while (getline(std::cin, in))
	{
		int n = sscanf(in.c_str(), "%d %d %d %d %d %d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6], &v[7], &v[8], &v[9]);
		int minN = v[0];
		for (int i = 1; i < n; i++)
			minN = min(minN, v[i]);
		int res = -1;
		for (int t = minN * 2; t <= 3600 && res == -1; t++)
		{
			bool cumple = true;
			for (int i = 0; i < n && cumple; i++)
			{
				if ((t % (2 * v[i])) >= v[i] - 5)
					cumple = false;
			}
			if (cumple)
				res = t;
		}
		if (res != -1)
			printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", caso++, res / 60, res % 60);
		else
			printf("Set %d is unable to synch after one hour.\n", caso++);
	}
}