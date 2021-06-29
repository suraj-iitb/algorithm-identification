#include<iostream>

#define SWAP(a,b) {int tmp = a;a = b;b = tmp;}

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    int ans = 0;
    for(int i=0;i<n;i++)cin >> A[i];
    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj])minj=j;
        }
        if(i!=minj){SWAP(A[i],A[minj]);ans++;}
    }
    cout << A[0];
    for(int i=1;i<n;i++)cout << " " << A[i];
    cout << endl;
    cout << ans << endl;
    return 0;
}
