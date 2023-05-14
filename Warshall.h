#pragma once
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printPath(int i, int j, const vector<vector<int>>& next, vector<char> cos) {
    if (next[i][j] == -1) {
        cout << "No path exists" << endl;
        return;
    }

    cout << "Path: " << cos[i];
    while (i != j) {
        i = next[i][j];
        cout << " -> " << cos[i];
    }
    cout << endl;
}

vector<char> make_cosmetic(int n) {
    vector<char> cos;
    cos.clear();
    if (n > 26) {
        cout << "\nSize cannot be more than 26\nReturning empty vecotr\n";
        return cos;
    }

    cos.resize(n);
    for (int i = 0; i < n; i++){
        cos[i] = ('A' + i);
    }
    return cos;
}