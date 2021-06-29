#include <iostream>
using namespace std;
int bubble_sort(int* a,int n){
    int x=1;
    int count=0;
    while(x){
        x=0;
        for(int i=n-1;i>=0;i--){
            if(a[i-1]>a[i]){
                swap(a[i-1],a[i]);
                x=1;
                count+=1;
            }
        }
    }
    return count;
}
int main(){
    int N,x;
    cin>>N;
    int* A = new int[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    x = bubble_sort(A,N);
    for(int i=0;i<N;i++){
        if(i!=0){cout<<" ";}
        cout<<A[i];
    }
    cout<<'\n';
    cout<<x<<'\n';
    delete[] A;
}
