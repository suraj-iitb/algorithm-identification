/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author champon
 */

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define se cout << "test ok" << endl;
#define sp << " " <<
#define enl "\n"
using namespace std;
using ll=long long;
using ld=long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vlll = vector<vector<vector<ll>>>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
ll mod = ll(1e9)+7;
ll inf = ll(1e18);
void bl(bool b, ostream& out=cout){ out << (b ? "Yes" : "No") << endl; }
void bl2(bool b, ostream& out=cout){ out << (b ? "YES" : "NO") << endl; }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){a=b; return true;} return false; }
template<typename T> inline bool chmin(T &a, T b){ if(a>b){a=b; return true;} return false; }
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

#ifndef INCLUDE_DEBUG_HPP
#define INCLUDE_DEBUG_HPP

#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace dbg {
    using ll = long long;

    class Debug {
    public:
        Debug(){}
        template<typename T>
        void vd(vector<T> vec);
        template<typename T>
        void vd2(vector<vector<T>> vec);
        template<typename T>
        void ad(T *arr, ll n);
        template<typename T, size_t N>
        void ad2(T (&arr)[N], ll n);
        template<typename T>
        void md(T mp);
    };

    template<typename T>
    void Debug::vd(vector<T> vec) {
        for (auto vv : vec) cout << vv << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::vd2(vector<vector<T>> vec) {
        for (auto vv : vec) {
            for (auto vvv : vv) cout << vvv << " ";
            cout << endl;
        }
    }

    template<typename T>
    void Debug::ad(T *arr, ll n) {
        for (int i = 0; i <= n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T, size_t N>
    void Debug::ad2(T (&arr)[N], ll n) {
        for (int i = 0; i <= N; i++) for (int j = 0; j <= n; j++) cout << arr[i][j] << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::md(T mp) {
        cout << "key : value" << endl;
        for (auto const &m : mp) cout << m.first << " : " << m.second << endl;
        cout << endl;
    }

}

#endif //INCLUDE_DEBUG_HPP

using dbg::Debug;
Debug debug;

class a {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, e;
	    in >> n >> e;
        vll dist(n, vl(n, inf));
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

	    ll s, t, d;
	    for(int i=0; i<e; i++){
	        in >> s >> t >> d;
	        dist[s][t] = d;
	    }

	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
                    if(dist[i][k] == inf || dist[k][j] == inf) continue;
                    chmin(dist[i][j], dist[i][k] + dist[k][j]);

                    if(dist[i][i] < 0) {
                        out << "NEGATIVE CYCLE" << enl;
                        return;
                    }
	            }
	        }
	    }

	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            ll res = dist[i][j];
	            if(j) out << " ";
	            if(res == inf) out << "INF";
	            else out << res;
	        }
	        out << enl;
	    }
	}
};


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	a solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}

