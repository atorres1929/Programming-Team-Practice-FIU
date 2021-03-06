// HeartOfCountry.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class City {
public:
	int id = -1;
	int troops = -1;
	int totalTroops = -1;
	bool defensible = true;
	bool visited = false;
	vector<reference_wrapper<City>> connectedCities;
};

void defend(vector<City> cities, int minTroops)
{
	queue<reference_wrapper<City>> queue;

	for (int i = 0; i < cities.size(); i++)
	{
		queue.push(cities.at(i));
	}

	while (!queue.empty())
	{

		City& parent = queue.front().get();
		queue.pop();

		parent.totalTroops = parent.troops;

		for (int i = 0; i < parent.connectedCities.size(); i++)
		{
			City& child = parent.connectedCities.at(i).get();
			parent.totalTroops += child.troops;

			if (parent.totalTroops < minTroops)
			{
				parent.defensible = false;
			}
		}
	}


	int totalTroops = 0;
	int totalDefensibleCities = 0;

	bool areBadCities = true;

	while (areBadCities)
	{
		areBadCities = false;
		for (City parentCity : cities)
		{
			if (parentCity.totalTroops < minTroops)
			{
				parentCity.defensible = false;
				if (!parentCity.defensible)
				{
					for (City connectedCity : parentCity.connectedCities)
					{
						connectedCity.totalTroops -= parentCity.troops;
					}
					areBadCities = true;
				}
			}
		}
	}

	for (City c : cities)
	{
		if (c.defensible)
		{
			totalTroops += c.troops;
			totalDefensibleCities++;
		}
	}

	cout << "Heart of Country: " << totalDefensibleCities << " Total Troops: " << totalTroops << endl;
}

int main()
{
	int towns = -1, minTroops = -1;
	cin >> towns >> minTroops;
	while (towns != 0 && minTroops != 0)
	{
		vector<City> cities;

		for (int i = 0; i < towns; i++) {
			City city;
			cities.push_back(city);
		}

		for (int i = 0; i < towns; i++)
		{
			int troops, highways;
			cin >> troops >> highways;
			cities.at(i).troops = troops;
			cities.at(i).id = i;
			for (int j = 0; j < highways; j++)
			{
				int highway;
				cin >> highway;
				cities.at(i).connectedCities.push_back(cities.at(highway));
			}
		}

		defend(cities, minTroops);

		cin >> towns >> minTroops;
	}

	return 0;
}

