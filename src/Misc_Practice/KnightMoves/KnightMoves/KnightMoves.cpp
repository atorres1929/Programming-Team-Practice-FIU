#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int searchCount = 0;
vector<array<int, 2>> visitedPositions;
vector<array<int, 2>> bannedPositions;

bool isValid(int horizontal, int vertical, int currentPosition[2])
{
	for (int i = 0; i < bannedPositions.size(); i++)
	{
		array<int, 2> bannedPosition = bannedPositions.at(i);
		if (bannedPosition.at(0) == currentPosition[0] + horizontal && 
			bannedPosition.at(1) == currentPosition[1] + vertical)
		{
			return false;
		}
	}

	if (currentPosition[0] + horizontal < 8 && currentPosition[1] + vertical < 8 &&
		currentPosition[0] + horizontal >= 0 && currentPosition[1] + vertical >= 0)
	{
		return true;
	}
	return false;
}

void search(int source[2], int target[2])
{
	
	if (source[0] == target[0] && source[1] == target[1])
	{
		cout << source[0] << source[1] << endl;
		cout << visitedPositions.size();
		return;
	}
	
	visitedPositions.push_back({ source[0], source[1] });

	for (int i = 0; i < visitedPositions.size(); i++)
	{
		array<int, 2> 
	}

	if (isValid(3, 1, source) && searchCount % 8 == 1)
	{
		int nextPosition[2] = { source[0] + 3, source[1] + 1 };
		search(nextPosition, target);
	}
	else if (isValid(3, -1, source) && searchCount % 8 == 2)
	{
		int nextPosition[2] = { source[0] + 3, source[1] - 1 };
		search(nextPosition, target);
	}
	else if (isValid(-3, 1, source) && searchCount % 8 == 3)
	{
		int nextPosition[2] = { source[0] - 3, source[1] + 1 };
		search(nextPosition, target);
	}
	else if (isValid(-3, -1, source) && searchCount % 8 == 4)
	{
		int nextPosition[2] = { source[0] - 3, source[1] - 1 };
		search(nextPosition, target);
	}
	else if (isValid(1, 3, source) && searchCount % 8 == 5)
	{
		int nextPosition[2] = { source[0] + 1, source[1] + 3 };
		search(nextPosition, target);
	}
	else if (isValid(1, -3, source) && searchCount % 8 == 6)
	{
		int nextPosition[2] = { source[0] + 1, source[1] - 3 };
		search(nextPosition, target);
	}
	else if (isValid(-1, 3, source) && searchCount % 8 == 7)
	{
		int nextPosition[2] = { source[0] - 1, source[1] + 3 };
		search(nextPosition, target);
	}
	else if (isValid(-1, -3, source) && searchCount % 8 == 0)
	{
		int nextPosition[2] = { source[0] - 1, source[1] - 3 };
		search(nextPosition, target);
	}
	else
	{
		searchCount++;
		visitedPositions.pop_back();
		search(source, target);
	}
}

int main()
{
	string a;
	string b;

	char letters[] = { 'a','b','c','d','e','f','g','h' };

	cin >> a >> b;

	int source[2];
	int target[2];

	for (int i = 0; i < 8; i++)
	{
		if (letters[i] == a.at(0))
		{
			source[0] = i;
		}
		if (letters[i] == b.at(0))
		{
			target[0] = i;
		}
	}

	source[1] = a.at(1) - '0' - 1;
	target[1] = b.at(1) - '0' - 1;
	
	cout << source[0] << source[1] << " ";
	cout << target[0] << target[1] << endl;

	search(source, target);

	return 0;
}
