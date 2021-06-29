#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<class like_bool> inline void YES(like_bool condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class like_bool> inline void Yes(like_bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class like_bool> inline void POSS(like_bool condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class like_bool> inline void Poss(like_bool condition){ if(condition)cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class like_bool> inline void First(like_bool condition){ if(condition)cout << "First" << endl; else cout << "Second" << endl; }
template<class like_bool, class output> inline void negative(like_bool condition, output num){ if(condition)cout << -1 << endl; else cout << num << endl; }
int character_count(string text, char character){ int ans = 0; for(int i = 0; i < text.size(); i++){ ans += (text[i] == character); } return ans; }
long power(long base, long exponent, long module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ long root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position move_pattern[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++){ ans += to_string(*i) + " "; } ans.pop_back(); cout << ans << endl; }
long gcd(long a, long b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }}
#define mod long(1e9 + 7)
#define bitcount(n) __builtin_popcount(n)

int main(){
    int N;
    cin >> N;
    int nums[N];
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    for(int i = 1; i <= N; i++){
        sort(nums, nums + i);
        array_output(nums, nums + N);
    }
}


