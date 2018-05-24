#include <bits/stdc++.h>
//#define PI (2.0 * acos (0.0))
#define PI 3.141592653589793
#define RAD 6378
using namespace std;
typedef long double ld;
typedef pair<double, double> dd;
typedef long long ll;
map<string, dd> mapa;
char input[50], input2[50];

double greatCircleDistance (dd p, dd q, double rad)
{
	double res = cos (p.first) * cos (p.second) * cos (q.first) * cos (q.second) +
			     cos (p.first) * sin (p.second) * cos (q.first) * sin (q.second) +
				 sin (p.first) * sin (q.first);
	res = max (min (res, 1.0), -1.0); // limit acos()
	return acos (res) * rad;
}
int main()
{
	while (scanf("%s", &input) == 1)
	{
		if (strcmp(input, "#") == 0)
			break;
		
		double lat, lon;
		scanf("%lf %lf", &lat, &lon);
		mapa[string(input)] = dd(lat * PI / 180, lon * PI / 180);
	}
	while (scanf("%s %s", &input, &input2) == 2)
	{
		if (strcmp(input, "#") == 0 && strcmp(input2, "#") == 0)
			break;
		
		string s1(input), s2(input2);
		if (mapa.find(s1) == mapa.end() || mapa.find(s2) == mapa.end())
			printf("%s - %s\nUnknown\n", input, input2);
		else
			printf("%s - %s\n%.0lf km\n", input, input2, greatCircleDistance (mapa[s1], mapa[s2], RAD));
	}
}