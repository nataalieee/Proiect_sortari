#include <iostream>
#include <algorithm>
#include <assert.h>
#include "sortari/radix_sort.h"
int main() {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    int N; std::cin >> N;
    std::vector<int> v(N);
    for(auto &x : v) std::cin >> x;
    customsort(v);
    assert(std::ranges::is_sorted(v));
    return 0;
}

/*
    radix nu sorteaza
    merge ia segfault
    heap nu sorteaza



*/