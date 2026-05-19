#ifndef PROIECT_SORTARI_PATIENCE_SORT_H
#define PROIECT_SORTARI_PATIENCE_SORT_H
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

void patience_sort(std::vector<int>&v) {
    std::vector<std::vector<int>>subseq;
    for(int i = 0; i < v.size(); i++) {

        int st = 0, dr = (int)subseq.size() - 1;
        int best = -1;
        while(st <= dr) {
            int mid = (st + dr) / 2;
            if(subseq[mid][(int)subseq[mid].size() - 1] < v[i]) {
                best = mid;
                dr = mid - 1;
            }
            else { st = mid + 1; }
        }
        if(best == -1) {
            std::vector<int> v1 = {v[i]};
            subseq.push_back(v1);
        }
        else {
            subseq[best].push_back(v[i]);
        }
    }

    std::priority_queue<std::pair<int, int>>pq;
    for(int i = 0; i < subseq.size(); i++) {
        pq.push({subseq[i].back(), i});
        subseq[i].pop_back();
    }
    std::vector<int>sorted;
    while(!pq.empty()) {
        auto [val, poz] = pq.top();
        pq.pop();
        sorted.push_back(val);
        if(!subseq[poz].empty()) {
            pq.push({subseq[poz].back(), poz});
            subseq[poz].pop_back();
        }
    }
    std::reverse(sorted.begin(), sorted.end());
    v = sorted;
}

void customsort(std::vector<int>& v) {
    patience_sort(v);
}
#endif