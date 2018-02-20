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
	int id = -1;
	vector<reference_wrapper<Node>> connectedNodes;
};

Node wheels[4][10];

void buildGraph()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			wheels[i][j].connectedNodes.push_back(wheels[i][j + 1]);
			wheels[i][j].id = j;
		}
		wheels[i][9].connectedNodes.push_back(wheels[i][0]);
		wheels[i][9].id = 9;

		for (int j = 9; j > 0; j--)
		{
			wheels[i][j].connectedNodes.push_back(wheels[i][j - 1]);
		}
		wheels[i][0].connectedNodes.push_back(wheels[i][9]);
	}

}

void playWithWheels(string input, string output, vector<string> bannedConfigurations)
{
	int totalDistance = 0;

	int in = 0;
	int place = 1;
	for (int i = 0; i < 4; i++)
	{
		in += (input.at(i * 2) - '0') * place;
		place *= 10;
	}

	int out = 0;
	place = 1;
	for (int i = 0; i < 4; i++)
	{
		out += output.at(i * 2) - '0';
		place *= 10;
	}

	vector<int> bannedConfigs;
	for (string bannedConfig : bannedConfigurations)
	{
		bannedConfigs.push_back(stoi(bannedConfig));
	}

	for (int i = 0; i < 4; i++)
	{
		queue<int> queue;

		queue.push(in);

		while (!queue.empty())
		{
			Node parent = queue.front();
			queue.pop();

			if (parent.id == out[i])
			{
				totalDistance += parent.distance;
				break;
			}

			for (int j = 0; j < parent.connectedNodes.size(); j++)
			{
				Node& child = parent.connectedNodes.at(j);
				if (!child.visited)
				{
					child.distance = parent.distance + 1;
					child.visited = true;
					queue.push(child);
				}
			}
		}

	}
	cout << "Num Button Presses: " << totalDistance;
}

void clean()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			wheels[i][j].distance = 0;
			wheels[i][j].visited = false;
		}
	}
}

int main()
{
	buildGraph();

	int testCases;
	string g;
	getline(cin, g);
	testCases = g.at(0) - '0';

	while (testCases > 0)
	{
		string input, output;
		getline(cin, input);
		getline(cin, output);

		int badConfigs;
		getline(cin, g);
		badConfigs = g.at(0) - '0';
		vector<string> bannedConfigurations;

		while (badConfigs > 0)
		{
			string badConfig;
			getline(cin, badConfig);
			bannedConfigurations.push_back(badConfig);
			badConfigs--;
		}

		playWithWheels(input, output, bannedConfigurations);

		getline(cin, g); // discard blank line

		testCases--;

		clean();
	}
	return 0;
}