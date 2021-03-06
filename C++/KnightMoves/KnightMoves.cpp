#include <string>
#include <iostream>
#include <vector>
#include <queue>

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

void clean()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].visited = false;
			board[i][j].distance = 0;
		}
	}
}

//ATTEMPT TO DO BFS RECURSIVELY

//int totalDistance = 0;
//void search(Node& source)
//{
//	source.visited = true;
//	totalDistance++;
//	for (int i = 0; i < source.connectedNodes.size(); i++)
//	{
//		Node& nextNode = source.connectedNodes.at(i).get();
//		if (!nextNode.visited)
//		{
//			nextNode.distance = totalDistance;
//			cout << "position: " << nextNode.x << nextNode.y << "||" << " distance: " << nextNode.distance << endl;
//			search(nextNode);
//		}
//	}
//}

void bfs(Node& source, Node& target)
{
	queue<Node> queue;
	queue.push(source); // Push the first node to the queue

	while (!queue.empty()) // While the node is not empty
	{
		Node parent = queue.front(); // Get the front of the queue
		queue.pop();				// Get rid of that element, as we are now searching it

		if (parent.x == target.x && parent.y == target.y) // Check for termination
		{
			return;
		}

		for (int i = 0; i < parent.connectedNodes.size(); i++) // For every child
		{
			Node& childNode = parent.connectedNodes.at(i).get();

			if (!childNode.visited) // Provided the child has not been visited:
			{
				childNode.distance = parent.distance + 1; // the child's distance will be the parent's + 1
				queue.push(childNode);					  // add the child to the list of elements to be searched
			}
		}
	}
}



int main()
{
	buildChessBoard();
	while (true)
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

		Node& sourceNode = board[sourceX][sourceY];
		Node& targetNode = board[targetX][targetY];

		targetNode.target = true;

		bfs(sourceNode, targetNode);

		cout << "Target distance: " << targetNode.distance << endl;

		clean();
	}
	return 0;
}
/*

Issues I ran into:

Apparently vectors cannot hold memory references to objects
--reference_wrapper is used to get around this

References are not reseatable in C++ (You can't have multiple references to a single memory location)
--the & operator is used to have two objects pointing to the same memory locatoin

In C++, a queue does not a return a value on pop
--you must first retrieve the front element, then pop it

You cannot return an array from a method

*/
