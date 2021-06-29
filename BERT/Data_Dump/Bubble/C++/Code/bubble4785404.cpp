#include<bits/stdc++.h>
using namespace std;
int A[110];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];
    int cnt=0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=N-1;j>0;j--)
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                flag=true;
                cnt++;
            }
    }
    for(int i=0;i<N;i++)cout<<A[i]<<(i==N-1?'\n':' ');
    cout<<cnt<<endl;
}
