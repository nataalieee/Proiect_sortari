//
// Created by natal on 10.04.2026.
//
#include <vector>
#include <string.h>
#ifndef PROIECT_SORTARI_MERGE_SORT_H
#define PROIECT_SORTARI_MERGE_SORT_H

#endif //PROIECT_SORTARI_MERGE_SORT_H
inline void merge(int *dest, int* source1,const int size1,int* source2,const int size2) {
    int temp[size1+size2];
    int i=0,j=0;
    while (i<size1 && j<size2) {
        if (source1[i] <= source2[j]) {
            temp[i+j] = source1[i];
            i++;
        }
        else {
            temp[i+j] = source2[j];
            j++;
        }
    }
    while (i<size1) {
        temp[i+j] = source1[i];
        i++;
    }
    while (j<size2) {
        temp[i+j] = source2[j];
        j++;
    }
    memcpy(dest,temp,(size1+size2)*sizeof(int));
}
void merge_sort(int *arr, int l, int r) {
    if (l==r) return;
    int mid = l + (r - l) / 2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr+l,arr+l,mid-l+1,arr+mid+1,r-mid);
}
void customsort(std::vector<int> &v)
{
    merge_sort(v.data(),0,v.size()-1);
}