
#include<iostream>
using namespace std;

int bSort(int A[], int n){
    int s = 0;
    bool flag = 1;
    for( int i = 0;flag; i++){
        flag = 0;
        for( int j = n-1; j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag=1;
                s++;
            }
        }
    }
    return s;
}

int main(){
    int A[100],n,s;
    cin>>n;
    for(int i = 0;i<n;i++)cin>>A[i];
    s = bSort(A,n);
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout << A[i];
        
    }
    cout << endl;
    cout << s << endl;
    return 0;
}
