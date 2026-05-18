//
// Created by natal on 10.04.2026.
//

#ifndef PROIECT_SORTARI_INSERTION_SORT_H
#define PROIECT_SORTARI_INSERTION_SORT_H

#endif //PROIECT_SORTARI_INSERTION_SORT_H
#include <vector>
void insertion_sort(std::vector<int>&v) {
    for (int i=1; i<v.size(); i++) {
        int  j=i-1;
        int current=v[i];
        while (j>=0 && v[j]>current) {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=current;
    }
}
void customsort(std::vector<int>&v) {
    insertion_sort(v);
}