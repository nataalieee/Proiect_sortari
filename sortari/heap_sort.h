//
// Created by natal on 10.04.2026.
//
#include <vector>
#ifndef PROIECT_SORTARI_HEAP_SORT_H
#define PROIECT_SORTARI_HEAP_SORT_H

#endif //PROIECT_SORTARI_HEAP_SORT_H

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
void customsort(std::vector<int>&v) {
    heap_sort(v);
}