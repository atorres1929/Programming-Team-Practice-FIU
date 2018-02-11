#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	int testCases;
	cin >> testCases;
	string asdf;
	getline(cin, asdf);
	const int num_fingers = 10;
	const int num_notes = 200;
	bool fingers[num_notes][num_fingers] = { false, false };
	int fingers_counter[num_fingers] = { 0 };

	int c[] = { 2,3,4,7,8,9,10 };
	int d[] = { 2,3,4,7,8,9 };
	int e[] = { 2,3,4,7,8 };
	int f[] = { 2,3,4,7 };
	int g[] = { 2,3,4 };
	int a[] = { 2,3 };
	int b[] = { 2 };
	int C[] = { 3 };
	int D[] = { 1,2,3,4,7,8,9 };
	int E[] = { 1,2,3,4,7,8 };
	int F[] = { 1,2,3,4,7 };
	int G[] = { 1,2,3,4 };
	int A[] = { 1,2,3 };
	int B[] = { 1,2 };

	string input;
	while (testCases > 0)
	{
		getline(cin, input);

		//i can be used as the row counter
		for (int i = 0; i < input.size(); i++)
		{

			if (input.at(i) == 'c')
			{
				for (int j = 0; j < sizeof(c)/sizeof(int); j++)
				{
					fingers[i][c[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'd')
			{
				for (int j = 0; j < sizeof(d) / sizeof(int); j++)
				{
					fingers[i][d[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'e')
			{
				for (int j = 0; j < sizeof(e) / sizeof(int); j++)
				{
					fingers[i][e[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'f')
			{
				for (int j = 0; j < sizeof(f) / sizeof(int); j++)
				{
					fingers[i][f[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'g')
			{
				for (int j = 0; j < sizeof(g) / sizeof(int); j++)
				{
					fingers[i][g[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'a')
			{
				for (int j = 0; j < sizeof(a) / sizeof(int); j++)
				{
					fingers[i][a[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'b')
			{
				for (int j = 0; j < sizeof(b) / sizeof(int); j++)
				{
					fingers[i][b[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'C')
			{
				for (int j = 0; j < sizeof(C) / sizeof(int); j++)
				{
					fingers[i][C[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'D')
			{
				for (int j = 0; j < sizeof(D) / sizeof(int); j++)
				{
					fingers[i][D[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'E')
			{
				for (int j = 0; j < sizeof(E) / sizeof(int); j++)
				{
					fingers[i][E[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'F')
			{
				for (int j = 0; j < sizeof(F) / sizeof(int); j++)
				{
					fingers[i][F[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'G')
			{
				for (int j = 0; j < sizeof(G) / sizeof(int); j++)
				{
					fingers[i][G[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'A')
			{
				for (int j = 0; j < sizeof(A) / sizeof(int); j++)
				{
					fingers[i][A[j] - 1] = true;
				}
			}
			else if (input.at(i) == 'B')
			{
				for (int j = 0; j < sizeof(B) / sizeof(int); j++)
				{
					fingers[i][B[j] - 1] = true;
				}
			}
		}
		for (int i = 0; i < num_notes; i++)
		{
			for (int j = 0; j < num_fingers; j++)
			{
				if ((i == 0 && fingers[i][j]) || (fingers[i][j] && !fingers[i-1][j])) 
				{
					fingers_counter[j]++;
				}
			}
		}

		//Printing out and reseting fingers counter
		for (int i = 0; i < num_fingers; i++)
		{
			cout << fingers_counter[i] << " ";
			fingers_counter[i] = 0;
		}

		//reseting fingers to be all false again
		for (int i = 0; i < num_notes; i++)
		{
			for (int j = 0; j < num_fingers; j++)
			{
				fingers[i][j] = false;
			}
		}
		cout << endl;
		testCases--;
	}
	return 0;
}