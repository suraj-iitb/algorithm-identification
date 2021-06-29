#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int N,A[100],flag,count=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    flag = 1;
    while(flag){
        flag = 0;
        for(int j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i!=N-1)  cout << " ";
    }
    cout << "\n" << count << "\n";
}
