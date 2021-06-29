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
const int INF=1LL<<55LL;

int cnt;
void merge(int *A,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=INF;
    R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]) A[k]=L[i++];
        else A[k]=R[j++];
    }
}


void mergesort(int *A,int left,int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        merge(A,left,mid,right);
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0); //この2行はより速度を向上させる
    int n;
    cin >> n;
    int S[n];
    for(int i=0;i<n;i++) cin>>S[i];
    cnt=0;
    mergesort(S,0,n);
    for(int i=0;i<n;i++) cout<<S[i]<<" \n"[i==n-1];
    cout<<cnt<<endl;
    return 0;
}

