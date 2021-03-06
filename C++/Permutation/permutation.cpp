// Saturday_18_2_6.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


long factorial(long N)
{
	if (N > 0)
		return N * factorial(N - 1);
	return 1;
}

int main()
{	
	int curr;
	long dataSets;
	cin >> dataSets;
	while (dataSets >= 0) {

		int numPermutations = 0;
		long N, v;

		cin >> curr >> N >> v;

		vector<int> values;
		for (int i = 1; i <= N; i++) {
			values.push_back(i);
		}

		while (next_permutation(values.begin(), values.end())) {

			int count = 0;
			for (int i = 0; i < N - 1; i++) {
				if (values.at(i) > values.at(i + 1)) {
					count++;
					if (count > v) {
						break;
					}
				}
			}

			if (count == v) {
				numPermutations++;
			}
		}
		cout << curr << " " << numPermutations;
		dataSets--;
	}
	cin >> curr;
	return 0;
}
