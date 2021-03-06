#include <iostream>
#include"fibonacci.h"
#include"MultistageGraph.h"
#include"FloydWarshallAlgo.h"
#include"Knapsack.h"
#include"OptimalBST.h"
#include"MatrixChainM.h"
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
        cout << "[4] - Matrix Chain Multiplication\n";
        cout << "[5] - 0/1 Knapsack Problem\n";
        cout << "[6] - Optimal Binary Search tree\n";
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
        else if (ch == 4) {
            int n,d;
            cout << "Enter the number of Matrices : ";
            cin >> n;
            n += 1;
            vector<int>D;
            cout << "Enter the dimentions : ";
            for (int i = 0; i < n; i++)
            {
                cout << "Enter d" << i << " : ";
                cin >> d;
                D.emplace_back(d);
            } 

            MatrixChainM(D, n);

        }
        else if (ch == 5) {
            int n,val,W;
            cout << "\nEnter the number of objects : ";
            cin >> n;
            
            vector<int>pi, wi; //pi-profit wi-weight
            pi.push_back(0); wi.push_back(0);

            for (int i = 1; i <= n; i++) {
                cout << "Enter wi (weight) for item " << i << " : ";
                cin >> val;
                wi.push_back(val);
                cout<< "Enter pi (profit) for item " << i << " : ";
                cin >> val;
                pi.push_back(val);

            }

            cout << "\nEnter the Knapsack Capacity : ";
            cin >> W;

            vector<vector<int>>V(n+1, vector<int>(W+1, 0)); //Table

            knapsack(V, pi, wi,W,n);
        }
        else if (ch == 6) {
            int n,val;
            cout << "Enter the number of keys for Binary search Tree : ";
            cin >> n;

            vector<int>keys, pi, qi;
            
            keys.push_back(0);
            pi.push_back(0);

            cout << "Enter Keys \n";
            for (int i = 1; i <= n; i++) {
                cout << "Enter Key " << i << " : ";
                cin >> val;
                keys.push_back(val);
            }

            cout << "Enter Successfull Probablities \n";
            for (int i = 1; i <= n; i++) {
                cout << "Enter P" << i << " : ";
                cin >> val;
                pi.push_back(val);
            }

            cout << "Enter Unsuccessfull Probablities \n";
            for (int i = 0; i <= n; i++) {
                cout << "Enter q" << i << " : ";
                cin >> val;
                qi.push_back(val);
            }


            OptimalBST(keys, pi, qi,n);

        }
        else if (ch == 0) {
            cout << "Thanks\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    } while (ch != 0);
}
