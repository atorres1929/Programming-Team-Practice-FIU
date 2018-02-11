#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int searchCount = 0;
vector<array<int, 2>> visitedPositions;
vector<array<int, 2>> bannedPositions;

array<int, 2> searchPosition(int position)
{
	if (position % 8 == 1)
	{
		return { 3,1 };
	}
	else if (position % 8 == 2)
	{
		return { 3, -1 };
	}
	else if (position % 8 == 3)
	{
		return { -3, 1 };
	}
	else if (position % 8 == 4)
	{
		return { -3, -1 };
	}
	else if (position % 8 == 5)
	{
		return { 1, 3 };
	}
	else if (position % 8 == 6)
	{
		return { 1, -3 };
	}
	else if (position % 8 == 7)
	{
		return { -1, 3 };
	}
	else if (position % 8 == 0)
	{
		return { -1, -3 };
	}
	else
	{
		throw new invalid_argument("Unexpected value: " + position);
	}
}

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
	
	//Check if the target has been reached
	if (source[0] == target[0] && source[1] == target[1])
	{
		cout << source[0] << source[1] << endl;
		cout << visitedPositions.size();
		return;
	}

	//Check to see that the visited position has not been visited twice
	for (int i = 0; i < visitedPositions.size(); i++)
	{
		array<int, 2> visitedPosition = visitedPositions.at(i);
		if (source[0] == visitedPosition.at(0) && source[1] == visitedPosition.at(1))
		{
			visitedPositions.erase(visitedPositions.begin() + i);
		}
	}

	//add the current position to the list of visited positions
	visitedPositions.push_back({ source[0], source[1] });

	
	/*
		 
	*/
	array<int, 2> searchValues = searchPosition(searchCount);

	if (isValid(searchValues.at(0), searchValues.at(1), source))
	{
		int nextPosition[2] = { source[0] + searchValues.at(0), source[1] + searchValues.at(1) };
		search(nextPosition, target);
	}
	else
	{
		//if the move currently searched for was not found, then change the move being searched for
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
