#include <iostream>
#include "sortari/quick_sort.h"
int main() {
    std::vector<int> v={2,4,1,2,5,3,2};
    customsort(v);
    for (auto i : v) {std::cout<<i<<" ";}
    return 0;
}