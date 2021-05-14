#include <iostream>
#include"fibonacci.h"
#include"MultistageGraph.h"
#include"FloydWarshallAlgo.h"
#include<vector>
using namespace std;

vector<int>F;


int main()
{
    cout << "Problems Solution using Dynamic Programming\n";
    int ch;
    do {
        cout << "\nEnter the problem, you want to solve\n";
        cout << "[1] - Fibonnacci using memorization method\n";
        cout << "[2] - Shortest Path in Multistage graph\n";
        cout << "[3] - Floyd Warshall Algorithm\n";
        cout << "[0] - Quit";

        cout << "\nEnter your choice : ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter the number whose fibonnacci value, you want to obtain : ";
            int n;
            cin >> n;
            for (int i = 0; i <= n; i++)F.push_back(-1);
            cout << "The value is : " << fib(F, n);
        }
        else if (ch == 2) {
            int G[13][13] = { {0,0,0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,9,7,3,2,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,4,2,1,0,0,0,0},
                              {0,0,0,0,0,0,2,7,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,11,0,0,0,0},
                              {0,0,0,0,0,0,0,11,8,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,6,5,0,0},
                              {0,0,0,0,0,0,0,0,0,4,3,0,0},
                              {0,0,0,0,0,0,0,0,0,0,5,6,0},
                              {0,0,0,0,0,0,0,0,0,0,0,0,4},
                              {0,0,0,0,0,0,0,0,0,0,0,0,2},
                              {0,0,0,0,0,0,0,0,0,0,0,0,5},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0}
            };

            MultiStageGraph(G);
        }
        else if (ch == 3) {
            cout << "Enter the number of vertices in the graph : ";
            int v, ele;
            cin >> v;
            cout << "Enter the distance b/w the pairs of vertices (if any , else input -1 if the distance is infinity)\n";
            cout << "(Enter 0 for self loop edge)\n";
            v += 1;
            vector<vector<int>>A(v, vector<int>(v, 0));
            for (int i = 1; i < v; i++) {
                for (int j = 1; j < v; j++) {
                    cout << "Enter [" << i << "," << j << " ] : ";
                    cin >> ele;
                    if (ele != -1) {
                        A[i][j] = ele;
                    }
                    else {
                        A[i][j] = 30000;
                    }
                }
            }
            shortestPath(A, v);
        }
        else if (ch == 0) {
            cout << "Thanks\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    } while (ch != 0);
}
