#include <bits/stdc++.h>
using namespace std;
char input[30];
char input2[30];

int main()
{
	int posI, fuelI;
	double pos, lastpos, fuelConsumption, leakConsumption, maxFuel, currFuel;
	while (scanf("%d %s %s %d", &posI, &input, &input2, &fuelI) == 4)
	{
		if (posI == 0 && fuelI == 0)
			return 0;
		lastpos = posI;
		fuelConsumption = fuelI / 100.0;
		leakConsumption = 0;
		maxFuel = currFuel = 0;
		while (scanf("%lf %s", &pos, &input) == 2)
		{
			currFuel += ((pos - lastpos) * (fuelConsumption + leakConsumption));
			if (strcmp(input, "Fuel") == 0)
				scanf("%s %lf", &input2, &fuelConsumption), fuelConsumption /= 100.0;
			else if (strcmp(input, "Leak") == 0)
				leakConsumption += 1.0;
			else if (strcmp(input, "Mechanic") == 0)
				leakConsumption = 0.0;
			else if (strcmp(input, "Gas") == 0)
			{
				scanf("%s", &input2);
				maxFuel = max (currFuel, maxFuel);
				currFuel = 0.0;
			}
			else if (strcmp(input, "Goal") == 0)
			{
				maxFuel = max (currFuel, maxFuel);
				currFuel = 0.0;
				break;
			}
			lastpos = pos;
		}
		printf("%.3lf\n", maxFuel);
	}
}