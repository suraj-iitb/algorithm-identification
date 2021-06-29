//(・ω・)
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, atoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;
int selectionSort(vector<int> &a,int n){
    int count=0;
    for(int i=0; i<n-1; i++){
        int minj=i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]) minj=j;
        }
        swap(a[i],a[minj]);
        if(i!=minj) count++;
    }
    return count;
}
int main(){
    int n,ans;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    ans=selectionSort(a,n);
    for(int i=0; i<n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
    cout << ans << endl;
}

