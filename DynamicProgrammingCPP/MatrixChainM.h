#pragma once
void MatrixChainM(vector<int>& D, int n) {
	vector<vector<int>>Cost(n, vector<int>(n, 0));
	vector<vector<int>>K(n, vector<int>(n, 0));
	int j, min,c;

	for (int d = 1; d < n - 1; d++) {			//d-difference
		for (int i = 1; i < n - d; i++) {		//n-d as the difference increases the number of loops for i decreases
			j = i + d;
			min = 32767;
			for (int k = i; k < j; k++) {
				c = Cost[i][k] + Cost[k + 1][j] + D[i - 1] * D[k] * D[j];

				if (c < min) {
					min = c;
					K[i][j] = k;
				}
			}
			Cost[i][j] = min;
		}
	}

	cout << "\nTotal Multiplication cost : "<<Cost[1][n - 1]<<"\n";
}