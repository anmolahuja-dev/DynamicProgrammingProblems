#pragma once
void OptimalBST(vector<int>& keys, vector<int>& pi, vector<int>& qi, int n) {
    vector<vector<int>>W(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>>C(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>>r(n + 1, vector<int>(n + 1, 0));
    int min,c,j;

    int p = 0;
    while (p<=n)
    {
        W[p][p] = qi[p];
        C[p][p] = 0;
        r[p][p] = 0;
        p++;
    }

    for (int d = 1; d <= n; d++) {
        for (int i = 0; i <= n - d; i++) {
            j = i + d;
            min = 32767;
            W[i][j] = W[i][j - 1] + pi[j] + qi[j];
            for (int k = i + 1; k <= j; k++) {
                c = C[i][k - 1] + C[k][j];
                if (c < min) {
                    min = c;
                    r[i][j] = k;
                }
            }
            C[i][j] = min + W[i][j];
        }
    }
       
    cout << "Cost of Optimal Binary Search tree is : "<<C[0][n]<<"\n";
}