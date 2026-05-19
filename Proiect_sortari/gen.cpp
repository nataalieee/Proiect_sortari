#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 get_rng() {
	seed_seq seq {
		(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
			chrono::high_resolution_clock::now().time_since_epoch()).count(),
		(uint64_t) __builtin_ia32_rdtsc(),
		(uint64_t) (uintptr_t) unique_ptr<char>(new char).get()
	};
	return mt19937(seq);
}

auto rng = get_rng();

struct Operation {
    int t, x;
};


vector <int> N_c_K(int N, int K) {
    if(K > N || K < 0) {
        return vector<int>();
    }

    vector <int> ret(N);
    iota(ret.begin(), ret.end(), 0);
    shuffle(ret.begin(), ret.end(), rng);
    ret.resize(K);
    sort(ret.begin(), ret.end());

    return ret;
}

vector <int> S_as_N(int S, int N) {
    vector <int> ret;
    if(N == 0) {
        return vector<int>();
    }
    vector <int> c = N_c_K(N + S - 1, N - 1);
    c.insert(c.begin(), -1);
    c.push_back(N + S - 1);
    
    
    for(int i = 1; i < c.size(); i++) {
        ret.push_back(c[i] - c[i - 1] - 1);
    }
    return ret;
}

int prim(int x) {
    if(x == 1 || x == 0) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
        
    }
    return true;
}


int32_t main(int32_t argc, char *argv[]) {
    // cin.tie(0); cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int N = atoi(argv[1]);
    int seed = atoi(argv[2]);
    uniform_int_distribution<int>A(1, (1LL << 29));
    cout << N << "\n";
    vector<int>B(N);
    for(int i = 0; i < N; i++) {
        B[i] = A(rng);
    }
    
    if(seed == 1) {
        for(int i = 0; i < N; i++) {
            B[i] %= 100;
        }
    }
    if(seed == 2) {
        sort(B.begin(), B.end());
        reverse(B.begin(), B.end());
    }
    if(seed == 3) {
        int bucket_size = 400;
        for(int i = 0; i < B.size(); i += bucket_size) {
            int le = i;
            int ri = min(i + bucket_size, (int) B.size());
               if(le > ri) continue;
            sort(B.begin() + le, B.begin() + ri);
            reverse(B.begin() + le, B.begin() + ri);
        }
    }

    if(seed == 4) {
        for(int i = 0; i < B.size(); i++) B[i] %= 10;
    }

    if(seed == 6) {
        uniform_int_distribution<int> A1(500000000, 1000000000);
        for(int i = 0; i < B.size(); i++) B[i] = A1(rng); 
    }

    if(seed == 7) {
        sort(B.begin(), B.begin() + B.size() / 2);
        sort(B.begin() + B.size() / 2, B.end());
        reverse(B.begin() + B.size() / 2, B.end());
    }

    if(seed == 8) {
        vector<int>v1, v2;
        for(int i = 0; i < N / 2; i++) {
            v1.push_back(i);
        }
        for(int i = N / 2; i < N; i++) {
            v2.push_back(i);
        }
        reverse(v2.begin(), v2.end());
        reverse(v1.begin(), v1.end());

        for(int i = 0; i < B.size(); i++) {
            if(!v2.empty()) {
                B[i] = v2.back();
                v2.pop_back();
            }
            else {
                B[i] = v1.back();
                v1.pop_back();
            }
        }
    }

    if(seed == 9) {
        uniform_int_distribution<int>bin(0, 1);
        vector<int>v1, v2;
        for(int i = 0; i < B.size() / 2; i++) {
            v1.push_back(B[i]);
        }
        for(int i = B.size() / 2; i < N; i++) {
            v2.push_back(B[i]);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());

        for(int i = 0; i < B.size(); i++) {
            bool bn = bin(rng);
            if(bn == 0 && !v1.empty()) {
                B[i] = v1.back();
                v1.pop_back();
            }
            else {
                if(!v2.empty()) {
                    B[i] = v2.back();
                    v2.pop_back();
                }
                else {
                    B[i] = v1.back();
                    v1.pop_back();
                }
            }
        }
    }

    for(auto i : B) cout << i << ' ';
}   

/*



*/
