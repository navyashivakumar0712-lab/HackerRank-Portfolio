#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> seqList(n);
    int lastAnswer = 0;
    vector<int> result;

    for (auto query : queries) {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1) {
            seqList[index].push_back(y);
        }
        else if (type == 2) {
            int value = seqList[index][y % seqList[index].size()];
            lastAnswer = value;
            result.push_back(lastAnswer);
        }
    }

    return result;
}
