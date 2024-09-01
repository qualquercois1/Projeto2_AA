#include "sqrtHeap.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void sqrtSortHeap(vector<long> &arr, long n) {
    long raiz = sqrt(n);
    long begin = 0, end;

    long groupTam = max(raiz, (n + raiz - 1) / raiz);
    vector<long> result(n), groups(groupTam, raiz);
    groups.back() = n % raiz;

    vector<vector<long>> aux(groupTam);

    while (begin < n) {
        end = min(begin + raiz, n);
        vector<long> block(arr.begin() + begin, arr.begin() + end);

        make_heap(block.begin(), block.end());
        aux[begin / raiz] = block;

        begin += raiz;
    }

    vector<pair<long, long>> aux2;

    for (long i = 0; i < groupTam; ++i) {
        if (!aux[i].empty()) {
            aux2.push_back({aux[i].front(), i});
            pop_heap(aux[i].begin(), aux[i].end());
            aux[i].pop_back();
        }
    }

    make_heap(aux2.begin(), aux2.end());

    long i = n-1;
    while (!aux2.empty()) {
        result[i--] = aux2.front().first;

        long groupIndex = aux2.front().second;
        pop_heap(aux2.begin(), aux2.end());
        aux2.pop_back();

        if (!aux[groupIndex].empty()) {
            aux2.push_back({aux[groupIndex].front(), groupIndex});
            pop_heap(aux[groupIndex].begin(), aux[groupIndex].end());
            aux[groupIndex].pop_back();
            push_heap(aux2.begin(), aux2.end());
        }
    }

    arr = result;
}

