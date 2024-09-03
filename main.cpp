#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random> // Biblioteca para geração de números aleatórios
#include "sqrtSimple.h"
#include "sqrtHeap.h"

using namespace std;
using namespace std::chrono;

void printVector(const vector<long> &arr) {
    for(long val : arr) {
        cout << val << ", ";
    }
    cout << endl;
}

// Função para gerar um vetor aleatório
void generateRandomVector(vector<long> &v, long minValue = -100000, long maxValue = 100000) {
    random_device rd; // Gera uma semente baseada no clock do sistema
    mt19937 gen(rd()); // Inicializa o gerador de números aleatórios
    uniform_int_distribution<long> dis(minValue, maxValue); // Define o intervalo dos números aleatórios

    for (auto &val : v) {
        val = dis(gen); // Preenche o vetor com números aleatórios
    }
}

int main() {
    long arrSize = pow(10, 7); // Tamanho do vetor
    vector<long> v(arrSize);
    long n = arrSize;
    long double tempoMedioBubble=0;
    long double tempoMedioHeap=0;


    for(int i = 0; i < 1; i++) {
        generateRandomVector(v);
        // Cria cópias do vetor para que ambos os algoritmos sejam testados com os mesmos dados
        vector<long> vCopy1 = v;
        vector<long> vCopy2 = v;

        auto startBubble = steady_clock::now();
        sqrtSortBubble(vCopy1, n);
        auto endBubble = steady_clock::now();
        long double timeBubble = duration_cast<nanoseconds>(endBubble - startBubble).count();

        auto startHeap = steady_clock::now();
        sqrtSortHeap(vCopy2, n);
        auto endHeap = steady_clock::now();
        long double timeHeap = duration_cast<nanoseconds>(endHeap - startHeap).count();

        tempoMedioBubble+=timeBubble;
        tempoMedioHeap+=timeHeap;
    }
    tempoMedioBubble/=1;
    tempoMedioHeap/=1;
    cout << "Tempo Medio Bubble: " << tempoMedioBubble << " nanosegundos (" << tempoMedioBubble/1e9 << " segundos)" << endl;
    cout << "Tempo Medio Heap: " << tempoMedioHeap << " nanosegundos (" << tempoMedioHeap/1e9 << " segundos)" << endl;
    cout << endl;
    return 0;
}
