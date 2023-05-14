#include "Warshall.h"

const int INF = numeric_limits<int>::max() / 2;
// The time complexity of the algorithm is O(n^3) - three nested loops
// The memory complexity of the algorithm is O(n ^ 2) - need to store 2 n^n matrixes



int main() {
    int n = 4;
    vector<char> cosmetic = make_cosmetic(n);

    vector<vector<int>> distance = {
    //   A    B    C    D       
        {0,   3,   INF, 7},    // A
        {8,   0,   2,   INF},  // B
        {5,   INF, 0,   1},    // C
        {2,   INF, INF, 0}     // D
    };

    vector<vector<int>> next(n, vector<int>(n, -1));

    // Initialize next matrix
    cout << "The next Matrix: ";
    for (int i = 0; i < n; i++) {
        cout << '\n';
        for (int j = 0; j < n; j++) {
            if (i != j && distance[i][j] != INF) {
                next[i][j] = j;
                cout << j << " ";
            }
        }
    }
    cout << '\n';

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Print shortest path distances
    cout << "Shortest path distances:" << '\n';
    cout << "  ";
    for (char c : cosmetic) { cout << c << " "; }
    cout << '\n';

    for (int i = 0; i < n; i++) {
        cout << cosmetic[i] << " ";
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == INF)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "Shortest path from vertex 0 to vertex 3:" << '\n';
    printPath(0, 3, next, cosmetic);

    return 0;
}
