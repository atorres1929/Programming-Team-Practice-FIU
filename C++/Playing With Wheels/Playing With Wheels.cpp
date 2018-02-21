#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
	int distance;
	bool visited = false;
	int id = -1;
	vector<reference_wrapper<Node>> connectedNodes;
};

void playWithWheels(string input, string output, vector<string> bannedConfigurations)
{
	int totalDistance = 0;

	Node in;
	int place = 1;
	for (int i = 0; i < 4; i++)
	{
		in.id += (input.at(i * 2) - '0') * place;
		place *= 10;
	}

	Node out;
	place = 1;
	for (int i = 0; i < 4; i++)
	{
		out.id += output.at(i * 2) - '0';
		place *= 10;
	}

	vector<Node> bannedConfigs;
	for (string bannedConfig : bannedConfigurations)
	{
		Node node;
		node.id = stoi(bannedConfig);
		bannedConfigs.push_back(node);
	}

	queue<Node> queue;
	queue.push(in);

	while (!queue.empty())
	{
		Node parent = queue.front();
		queue.pop();

		if (parent.id == out.id)
		{
			totalDistance += parent.distance;
			break;
		}

		//All possible positions +1
		int place = 1;
		for (int i = 0; i < 4; i++)
		{
			int temp = parent.id + place;

			if (temp == 10000)
			{
				temp = 9990;
			}
			else if (temp == 10009)
			{
				temp = 9909;
			}
			else if (temp == 10090)
			{
				temp = 9099;
			}
			else if (temp == 10900)
			{
				temp = 999;
			}

			if (find(bannedConfigs.begin(), bannedConfigs.end(), temp) == bannedConfigs.end())
			{
				Node child;
				child.id = temp;
				child.connectedNodes.push_back(parent);
				parent.connectedNodes.push_back(child);
			}
			
			place *= 10;
		}

		//All possible positions -1
		int place = 1;
		for (int i = 0; i < 4; i++)
		{
			int temp = parent.id + place;

			if (find(bannedConfigs.begin(), bannedConfigs.end(), temp) == bannedConfigs.end())
			{
				Node child;
				child.id = temp;
				child.connectedNodes.push_back(parent);
				parent.connectedNodes.push_back(child);
			}

			place *= 10;
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
	cout << "Num Button Presses: " << totalDistance;
}

int main()
{

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