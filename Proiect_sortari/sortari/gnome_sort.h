#ifndef PROIECT_SORTARI_GNOME_SORT_H
#define PROIECT_SORTARI_GNOME_SORT_H
#include <cstring>
#include <vector>
void gnome_sort(std::vector<int>&v) {
    int idx = 0;
    while(idx < v.size()) {
        if(idx == 0) idx++;
        else if(v[idx] >=  v[idx - 1]) idx++;
        else if(v[idx] < v[idx - 1]) {std::swap(v[idx], v[idx - 1]); idx--;}
    }
}
void customsort(std::vector<int>& v) {
    gnome_sort(v);
}
#endif
