#pragma once
#include<vector>
using namespace std;
int fib(vector<int>& F, int n) {
    if (n <= 1) {
        return n;
    }
    else {
        if (F[n] == -1) {
            F[n - 2] = fib(F, n - 2);
            F[n - 1] = fib(F, n - 1);
            F[n] = F[n - 2] + F[n - 1];
        }
        else {
            return F[n];
        }
    }
}