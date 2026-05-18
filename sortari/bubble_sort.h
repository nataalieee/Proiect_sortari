//
// Created by natal on 10.04.2026.
//

#ifndef PROIECT_SORTARI_BUBBLE_SORT_H
#define PROIECT_SORTARI_BUBBLE_SORT_H

#endif //PROIECT_SORTARI_BUBBLE_SORT_H
#include <vector>
void bubble_sort(std::vector<int>&v) {
    bool swapped;
    for (int i=0;i<v.size()-1; i++) {
        swapped = false;
        for (int j=0; j<v.size()-i-1; j++) {
            if (v[j]>v[j+1]) {
                std::swap(v[j], v[j+1]);
                swapped=true;
            }
        }

        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

void customsort(std::vector<int>&v) {
    bubble_sort(v);
}