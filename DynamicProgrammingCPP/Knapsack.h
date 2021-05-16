#pragma once
void knapsack(vector< vector<int >> &V, vector<int>& pi, vector<int>& wi, int W, int n) {
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				V[i][w] = 0;
			}
			else if (wi[i] <= w) {
				V[i][w] = max(V[i - 1][w], V[i - 1][w - wi[i]] + pi[i]);
			}
			else {
				V[i][w] = V[i - 1][w];
			}
		}
	}

	//Here we use DP
	cout << "\n\nThe Items that will be Added to the knapsack are : \n";
	cout << "Object   Amount\n";
	int i = n, j = W;
	while (i > 0 && j > 0) {
		if (V[i][j] == V[i - 1][j]) {
			cout << i << "    -    0 \n";
			i--;
		}
		else {
			cout << i << "    -    1 \n";
			j -= wi[i];
			i--;
		}
	}
}