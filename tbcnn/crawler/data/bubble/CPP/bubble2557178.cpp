#include<iostream>
using namespace std;

int A[100],n;

int bubbleSort(int A[], int n){
    int s=0;
    int flag;
    flag = 1;
    while(flag){
        flag = 0;
        for(int j=n-1; j>=1; j--){
            if(A[j]<A[j-1]){
                s++;
                swap(A[j],A[j-1]);
                flag = 1;
            }
        }
    }
    
    return s;
}

int main(){
    cin >> n;
    int ans;
    
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    
    ans = bubbleSort(A,n);
    
    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << ans << endl;
    
    return 0;
}
