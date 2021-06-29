#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int INF = 1000000007;

int cnt=0;
vector<int> A(600000);

void merge(int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1),R(n2+1);

    for(int i=0;i<n1;i++) L[i] = A[left+i];
    for(int i=0;i<n2;i++) R[i] = A[mid+i];
    L[n1] = INF;
    R[n2] = INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void mergesort(int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergesort(left,mid);
        mergesort(mid,right);
        merge(left,mid,right);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];

    mergesort(0,n);
    cout << A[0];
    for(int i=1;i<n;i++) cout << ' ' << A[i];
    cout << endl;
    cout << cnt << endl;
}
