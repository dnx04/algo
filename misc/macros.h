// #pragma GCC optimize("Ofast,unroll-loops")       // unroll long, simple loops
// #pragma GCC target("avx2,fma")                   // vectorizing code
// #pragma GCC target("lzcnt,popcnt,abm,bmi,bmi2")  // for fast bitset operation

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;  // ordered_set, gp_hash_table
// using namespace __gnu_cxx; // rope

// for templates to work
#define all(s) s.begin(), s.end()
#define sz(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<i32, i32>;
using vi = vector<i32>;

// fast map
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {  // customize hash function for gp_hash_table
  int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> table;

/* ordered set
    find_by_order(k): returns an iterator to the k-th element (0-based)
    order_of_key(k): returns the number of elements in the set that are strictly less than k
*/
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*  rope
    rope <int> cur = v.substr(l, r - l + 1);
    v.erase(l, r - l + 1);
    v.insert(v.mutable_begin(), cur);
*/