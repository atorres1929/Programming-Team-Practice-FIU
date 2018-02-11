#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Node
{
public:
	int distance = 0;
	bool visited = false;
	bool target = false;
	int x, y;
	vector<reference_wrapper<Node>> connectedNodes;
};

int deltaX, deltaY;
bool isValid(int position, int x, int y)
{

	if (position % 8 == 1)
	{
		deltaX = 2;
		deltaY = 1;
	}
	else if (position % 8 == 2)
	{
		deltaX = 2;
		deltaY = -1;
	}
	else if (position % 8 == 3)
	{
		deltaX = -2;
		deltaY = 1;
	}
	else if (position % 8 == 4)
	{
		deltaX = -2;
		deltaY = -1;
	}
	else if (position % 8 == 5)
	{
		deltaX = 1;
		deltaY = 2;
	}
	else if (position % 8 == 6)
	{
		deltaX = 1;
		deltaY = -2;
	}
	else if (position % 8 == 7)
	{
		deltaX = -1;
		deltaY = 2;
	}
	else if (position % 8 == 0)
	{
		deltaX = -1;
		deltaY = -2;
	}

	if (deltaX + x < 8 && deltaY + y < 8 &&
		deltaX + x >= 0 && deltaY + y >= 0)
	{
		return true;
	}
	return false;
}


//TODO change the way that visited works (it isn't working properly)
int totalDistance = 1;
void search(Node& source)
{
	source.visited = true;
	for (int i = 0; i < source.connectedNodes.size(); i++)
	{
		Node& nextNode = source.connectedNodes.at(i).get();

		if (nextNode.target)
		{
			nextNode.distance = totalDistance;
			cout << "position: " << nextNode.x << nextNode.y << endl;
			cout << "distance: " << nextNode.distance << endl;
			return;
		}
		else if (!nextNode.visited)
		{
			nextNode.distance = totalDistance;
			totalDistance++;
		}
		else
		{
			return; //this node has been searched
		}
		cout << nextNode.x << nextNode.y << endl;
		search(nextNode);
	}
}

Node board[8][8];
void buildChessBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].x = i;
			board[i][j].y = j;

			//checking all possible positions from coordinates i,j
			for (int p = 0; p < 8; p++)
			{
				if (isValid(p, i, j))
				{
					board[i][j].connectedNodes.push_back(board[i + deltaX][j + deltaY]);
				}
			}
		}
	}
}

int main()
{
	string a;
	string b;

	char letters[] = { 'a','b','c','d','e','f','g','h' };

	cin >> a >> b;

	int sourceX, sourceY;
	int targetX, targetY;

	for (int i = 0; i < 8; i++)
	{
		if (letters[i] == a.at(0))
		{
			sourceX = i;
		}
		if (letters[i] == b.at(0))
		{
			targetX = i;
		}
	}

	sourceY = a.at(1) - '0' - 1;
	targetY = b.at(1) - '0' - 1;

	cout << sourceX << sourceY << " ";
	cout << targetX << targetY << endl;

	buildChessBoard();

	Node& sourceNode = board[sourceX][sourceY];
	Node& targetNode = board[targetX][targetY];

	targetNode.target = true;
	search(sourceNode);

	return 0;
}
/*

Issues I ran into:

Apparently vectors cannot hold memory references to objects
--reference_wrapper is used to get around this

References are not reseatable in C++ (You can't have multiple references to a single memory location)
--the & operator is used to have two objects pointing to the same memory locatoin

You cannot return an array from a method

*/
