#pragma once

void display(vector<vector<int>>& A, int v) {
	cout << "\n";
	for (int i = 1; i < v; i++) {
		for (int j = 1; j < v; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}
void shortestPath(vector<vector<int>>& A, int v) {
	for (int k = 1; k < v; k++) {
		for (int i = 1; i < v; i++) {
			for (int j = 1; j < v; j++) {
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}
	display(A, v);
}