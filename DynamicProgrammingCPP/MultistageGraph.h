#pragma once
#include<iostream>
using namespace std;
void MultiStageGraph(int G[][13]) {
	int cost[13], d[13], min = 32767;
	int n = 12, stages = 4;
	int path[13]{ 0 };

	cost[n] = 0; d[n] = 12;
	for (int i = n - 1; i >= 1; i--) {
		min = 32767;
		for (int j = i + 1; j < 13; j++) {
			if (G[i][j] != 0 && G[i][j] + cost[j] < min) {
				min = G[i][j] + cost[j];
				d[i] = j;
			}
			cost[i] = min;
		}
	}

	path[1] = 1; int k = 1;
	while (k != n) {
		path[d[k]] = 1;
		k = d[k];
	}

	for (int i = 0; i < n; i++) {
		if (path[i] == 1) {
			cout << i << " --> ";
		}
	}
	cout << n << "\n";
}

/* Analysis : Space : O(n)
			  Time  : O(n2)
*/