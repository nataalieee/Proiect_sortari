//
// Created by natal on 10.04.2026.
//

#ifndef PROIECT_SORTARI_RADIX_SORT_H
#define PROIECT_SORTARI_RADIX_SORT_H
#include <cstring>
#include <vector>


void radix_sort(std::vector<int>& arr) {
    std::vector<int> temp(arr.size());
    std::vector<int> cnt1(65536,0),cnt2(65536,0);
    bool skip1,skip2;
    skip1=skip2=false;
    for (auto elem : arr) {
        cnt1[elem&0xffff]++;
        cnt2[elem>>16&0xffff]++;
    }
    if (cnt1[0]==arr.size())skip1=true;
    if (cnt2[0]==arr.size())skip2=true;
    for (int i=1;i<=0xffff;i++) {
        cnt1[i]+=cnt1[i-1];
        cnt2[i]+=cnt2[i-1];
    }
    for (int i=0xffff;i>0;i--) {
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
    }
    cnt1[0]=cnt2[0]=0;
    if (!skip1) {
        for (auto elem : arr) {
            temp[cnt1[elem&0xffff]++]=elem;
        }
        arr.swap(temp);
    }
    if (!skip2) {
        for (auto elem : arr) {
            temp[cnt2[elem>>16&0xffff]++]=elem;
        }
        arr.swap(temp);
    }
}
void customsort(std::vector<int>& v) {
    radix_sort(v);
}
#endif //PROIECT_SORTARI_RADIX_SORT_H
