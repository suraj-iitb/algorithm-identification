#include<iostream>
using namespace std;

int main(){
    int N,A[100];
    cin >> N;
    for(int i=0;i<N;i++)cin >> A[i];
    int ct=0;
 

    for(int i=0;i<N;i++){
        int min = i;
        for(int j=i+1;j<N;j++){
            if(A[j]<A[min])min=j;
        }
        if(i != min){
            int a=A[i];
            A[i]=A[min];
            A[min]=a;
            ct++;
        }
       

    }

    for(int b=0;b<N;b++){
        if(b== N-1)cout << A[b] << endl;
        else cout << A[b] << " " ;
    }

    cout << ct << endl;
    return 0;
}
