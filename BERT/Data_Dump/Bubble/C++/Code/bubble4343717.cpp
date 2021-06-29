#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cctype>

using namespace std;
// for loop
#define F(i, L, R) for(int i = L; i < R; i++)
#define FE(i, L, R) for(int i = L; i <= R; i++)
// for (reversed)
#define FR(i, L, R) for(int i = L; i > R; i--)
#define FRE(i, L, R) for(int i = L; i >= R; i--)

// data types
#define ul unsigned long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned shoft

// vectors
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define ALL(c) (c).begin(),(c).end()
#define last(vec) vec.size()-1
#define lastEle(vec) vec[last(vec)]
#define pb push_back
#define InputV(a, n) F(i,0,n){long l; cin >> l; a.pb(l);}

// debug
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i==R?'\n':' ')
#define printAF(a, L) printA(a, 0, L-1)
#define printV(a) printA(a, 0, a.size()-1)

// utils
#define char2int(c) (c-'0')
#define bit(x, i) (x&(1<<i))
#define space ' '
#define PI 3.14159265358979323

int main() {
    int n;
    cin >> n;
    vl data;
    InputV(data, n);
    int times = 0;
    F(i, 0, n){
        FRE(j, n-1, i+1){
            if(data[j] < data[j-1]){
                swap(data[j], data[j-1]);
                times++;
            }

        }
    }
    printV(data);
    cout << times << endl;
}

