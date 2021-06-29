#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 998244353;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T = string, class U = char>int character_count(T text, U character){ int ans = 0; for(U i: text){ ans += (i == character); } return ans; }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd_calc(T a, T b){ if(b){ return gcd_calc(b, a % b); }else{ return a; }}
template<class T> T gcd(T a, T b){ if(a < b) swap(a, b); return gcd_calc(a, b); }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }
inline int at(int x, int k){ return (x >> k) & 1; }
random_device rnd;

struct tropical{ // minimum tropical
    lint num;
    bool is_infty;
    
    tropical(lint num, bool is_infty = false): num(num), is_infty(is_infty){}

    static tropical infty(){
        return tropical(0, true);
    }
    
    lint get(){
        if((*this).is_infty){
            return LONG_LONG_MAX;
        }else{
            return num;
        }
    }
    
    tropical operator +(tropical B){
        if((*this).is_infty){
            return B;
        }else if(B.is_infty){
            return (*this);
        }else{
            return tropical(min((*this).num, B.num));
        }
    }
    
    tropical operator *(tropical B){
        if((*this).is_infty || B.is_infty){
            return infty();
        }else{
            return tropical((*this).num + B.num);
        }
    }
    
    tropical& operator +=(tropical B){
        (*this) = (*this) + B;
        return (*this);
    }
    
    tropical& operator *=(tropical B){
        (*this) = (*this) * B;
        return (*this);
    }
    
    template<class T> tropical& operator =(T B){
        (*this) = tropical(B);
        return (*this);
    }
    
    friend ostream& operator<<(ostream& os, tropical &A){
        if(A.is_infty){
            os << "INF";
        }else{
            os << A.num;
        }
        return os;
    }
    
    void output(string infty_text){
        if((*this).is_infty){
            cout << infty_text;
        }else{
            cout << (*this).num;
        }
    }
};

struct tropical_matrix{
    vector<vector<tropical>> data;
    
    size_t size(){
        return data.size();
    }
    
    inline vector<tropical>& operator[](int k){
        return data[k];
    }
    
    static tropical_matrix E(size_t n){
        tropical_matrix ret(n);
        for(int i = 0; i < n; i++){
            ret[i][i] = 0;
        }
        return ret;
    }
    
    tropical_matrix(size_t n){
        data.resize(n);
        for(int i = 0; i < n; i++){
            data[i].resize(n, tropical::infty());
        }
    }
    
    tropical_matrix& operator +=(tropical_matrix B){
        size_t n = size();
        assert(n == B.size());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }
    
    tropical_matrix& operator *=(tropical_matrix B){
        size_t n = size();
        assert(n == B.size());
        tropical_matrix ans(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    ans[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        data.swap(ans.data);
        return (*this);
    }
    
    tropical_matrix& operator ^=(lint k){
        tropical_matrix ans = E(size());
        while(k > 0){
            if(k & 1) ans *= (*this);
            (*this) *= (*this);
            k >>= 1;
        }
        data.swap(ans.data);
        return (*this);
    }
    
    tropical_matrix operator+(tropical_matrix B){
        return (tropical_matrix(*this) += B);
    }
    
    tropical_matrix operator*(tropical_matrix B){
        return (tropical_matrix(*this) *= B);
    }
    
    tropical_matrix operator^(lint k){
        return (tropical_matrix(*this) ^= k);
    }
    
    friend ostream& operator <<(ostream &os, tropical_matrix A){
        size_t n = A.size();
        for(int i = 0; i < n; i++){
            os << "[";
            for(int j = 0; j < n; j++){
                os << A[i][j] << (j + 1 == n ? "]\n" : " ");
            }
        }
        return os;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    tropical_matrix graph = tropical_matrix::E(V);
    for(int i = 0; i < E; i++){
        int s, t;
        lint d;
        cin >> s >> t >> d;
        graph[s][t] = d;
    }
    graph ^= V;
    for(int i = 0; i < V; i++){
        if(graph[i][i].get() < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            graph[i][j].output("INF");
            cout << (j + 1 == V ? "\n" : " ");
        }
    }
}

