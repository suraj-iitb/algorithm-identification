#include <iostream>
using namespace std;

int bubbleSort(int A[],int n){
    bool flag(true);
    int ans(0);
    while(flag){
        flag = false;
        for(int i=n-1;i>=1;i--){
            if(A[i]<A[i-1]){
                swap(A[i],A[i-1]);
                ans++;
                flag = true;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    int x = bubbleSort(A,n);
    for(int i=0;i<n;i++){
        if(i+1==n){
            cout << A[i] << endl;
        }else
            cout << A[i] << " ";
    }
    cout << x << endl;
    
    return 0;
}
