#include "sqrtSimple.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void bubbleSort(vector<long> &arr, long begin, long end) {
    for (long i = end; i > begin; i--) {
        for (long j = begin; j < i; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void sqrtSortBubble(vector<long> &arr, long n) {
    long raiz = sqrt(n);
    long begin = 0;
    long end;
    long groupsTam;

    if(n%raiz == 0) {
        groupsTam = raiz;
    } else {
        groupsTam = raiz+1;
    }

    vector<long> groups(groupsTam, raiz), aux, result;
    vector<long> index(groupsTam, 0);

    while(begin < n){
        if(begin+raiz >= n) {
            end = n-1;
            groups.back() = n%raiz;
        } else {
            end = begin + raiz - 1;
        }
        bubbleSort(arr, begin, end);
        index[begin / raiz] = end;
        begin += raiz;
        aux.push_back(arr[end]);
    }
    //trabalhar com o aux

    while(!aux.empty()){
        //maior elemento do aux é inserido no result e apagado de aux
        auto max = max_element(aux.begin(),aux.end());
        long maxIndex = distance(aux.begin(), max);
        result.insert(result.begin(), *max);
        aux.erase(max);

        //move o indice do maior um para tras e puxa o proximo valor do vetor para o aux
        long position = maxIndex * raiz;
        if (index[maxIndex] > position) {
            index[maxIndex]--;
            aux.insert(aux.begin() + maxIndex, arr[index[maxIndex]]);
        }
    }
    arr = result;
}

