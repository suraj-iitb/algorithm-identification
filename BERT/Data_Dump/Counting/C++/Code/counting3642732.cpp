#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define int long long
#define k 10001

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0); //この2行はより速度を向上させる
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    vector<int> C(k);
    for(int i=0;i<k;i++) C[i]=0;
    for(int j=0;j<n;j++) C[A[j]]++;
    for(int i=1;i<k;i++) C[i]=C[i]+C[i-1];
    for(int j=n-1; j>=0; j--){
        B[C[A[j]]-1]=A[j];
        C[A[j]]--;
    }
    for(int i=0;i<n;i++) cout << B[i] << " \n"[i==n-1];
    return 0;
}

