#include<bits/stdc++.h>
using namespace std;
void insection_sort(int *A,int n){
    int i = 0;
    while(1){
        for(int j = 0 ; j < n ;){
            cout << *(A+j);
            ++j;
            if(j < n)cout << " ";
        }
        cout << endl;
        ++i;
        if(i >= n)break;
        int v = A[i],j = i;
        while(j > 0 && A[j-1] > v){
            A[j] = A[j-1];
            --j;
        }
        A[j] = v;
        
    }
}
int main(){
    int n ;
    cin >> n;
    int *A = new int[n];
    for(int i = 0 ; i < n ; ++i)cin >> A[i];
    insection_sort(A,n);
}
