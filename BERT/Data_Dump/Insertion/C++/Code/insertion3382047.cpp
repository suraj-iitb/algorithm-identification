#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int N;
    int A[1010];
    cin >> N ;
    for(int k=0;k<N;k++){
        cin >> A[k];
    }
    int v,j;
    for(int i=0;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int k=0;k<N;k++){
            if(k==N-1) cout << A[k] << endl;
            else if(k!=N-1) cout << A[k] << " ";
        }
    }
}








