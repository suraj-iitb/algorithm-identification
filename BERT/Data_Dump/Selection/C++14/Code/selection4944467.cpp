#include <iostream>
using namespace std;

int selection_sort(int* a,int n){
    int count=0;
    for(int i=0;i<n;i++){
        int minv=i;
        for(int j=i;j<n;j++){
            if(a[minv]>a[j]){
                minv=j;
            }
        }
        if(i != minv){
            swap(a[i],a[minv]);
            count++;
        }
        
        
        
        
    }
    return count;
}

int main(){
    int N;
    cin>>N;
    int* A = new int [N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    int x = selection_sort(A,N);

    for(int i=0;i<N;i++){
        if(i!=0) {cout<<" ";}
        cout<<A[i];
    }
    cout<<'\n'<<x<<'\n';
    delete[] A;
}
