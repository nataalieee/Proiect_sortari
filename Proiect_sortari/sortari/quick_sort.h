//
// Created by natal on 18.05.2026.
//

#ifndef PROIECT_SORTARI_QUICK_SORT_H
#define PROIECT_SORTARI_QUICK_SORT_H

#include <vector>
#include <random>
#include <chrono>
#include <memory>
#include <cstdint>

std::mt19937 get_rng() {
    std::seed_seq seq {
        (uint64_t) std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) (uintptr_t) std::unique_ptr<char>(new char).get()
    };
    return std::mt19937(seq);
}


auto rng = get_rng();
int partition(std::vector<int>&A, std::vector<int>&B, int st, int dr) {
    std::uniform_int_distribution<int>v(st, dr);
    int pivot = v(rng), le = st - 1, ri = dr + 1;
    for(int i = st; i <= dr; i++) {
        B[i] = A[i];
    }
    int idx = ri;
    for(int i = st; i <= dr; i++) {
        if(B[pivot] > B[i]) {
            le++; A[le] = B[i];
        }
        else {
            ri--; A[ri] = B[i];
            if(B[pivot] == A[ri]) idx = ri;
        }
    }

    std::swap(A[ri], A[idx]);
    return ri;
}
void quicksort(std::vector<int>&A, std::vector<int>&B, int st, int dr) {
    if(st < dr)
    {
        int piv = partition(A, B, st, dr);
        int idx1 = piv - 1;
        int idx2 = piv + 1;
        while(A[idx1] == A[piv] && idx1 > st) idx1--;
        while(A[idx2] == A[piv] && idx2 < dr) idx2++;
        quicksort(A, B, st, idx1);
        quicksort(A, B, idx2, dr);
    }
}
void customsort(std::vector<int> &v)
{
    std::vector<int> aux(v.size());
    quicksort(v,aux,0,v.size()-1);
}

#endif //PROIECT_SORTARI_QUICK_SORT_H