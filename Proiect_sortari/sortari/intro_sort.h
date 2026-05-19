

#include <bits/stdc++.h>
#include <vector>
#include <random>
#include <chrono>
#include <memory>
#include <cstdint>

#ifndef PROIECT_SORTARI_INTRO_SORT_H
#define PROIECT_SORTARI_INTRO_SORT_H

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

void heapify_top_down(std::vector<int>& v, int poz, int size) {
    while (2*poz+1 < size) {
        int maxim = poz;
        if (v[2*poz+1] > v[maxim]) maxim = 2*poz+1;
        if (2*poz+2 < size && v[2*poz+2] > v[maxim]) maxim = 2*poz+2;
        if (maxim == poz) return;
        std::swap(v[poz], v[maxim]);
        poz = maxim;
    }
}

void heap_sort(std::vector<int>&v) {
    ///il facem max-heap
    for (int i=v.size()/2;i>=0;i--) {
        heapify_top_down(v,i,v.size());
    }

    ///mutam elementul maxim la final, pentru a ramane sortat crescator
    for (int i=v.size()-1;i>=0;i--) {
        std::swap(v[i],v[0]);
        ///pastram structura de max-heap
        heapify_top_down(v,0,i);
    }
}


void intro_sort(std::vector<int>&A, std::vector<int>&B, int st, int dr, int depth = 0) {
    if(dr - st + 1 <= 30) {
    for (int i= st + 1; i<=dr; i++) {
        int  j=i-1;
        int current=A[i];
        while (j>=st && A[j]>current) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=current;
    }
        return ;
    }

    if(depth >= 32) {
        std::vector<int>v; 
        for(int i = st; i <= dr; i++) {
            v.push_back(A[i]);
        }
        heap_sort(v);
        reverse(v.begin(), v.end());
        for(int i = st; i <= dr; i++) {
            A[i] = v.back();
            v.pop_back();
        }
        return ;
    }

    if(st < dr)
    {   

        int piv = partition(A, B, st, dr);
        int idx1 = piv - 1;
        int idx2 = piv + 1;
        while(A[idx1] == A[piv] && idx1 > st) idx1--;
        while(A[idx2] == A[piv] && idx2 < dr) idx2++;
        intro_sort(A, B, st, idx1, depth + 1);
        intro_sort(A, B, idx2, dr, depth + 1);
    }
}

void customsort(std::vector<int> &v)
{
    std::vector<int> aux(v.size());
    intro_sort(v,aux,0,v.size()-1);
}

#endif //PROIECT_SORTARI_QUICK_SORT_H