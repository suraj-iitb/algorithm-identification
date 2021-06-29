#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>a(N);
    for(int i=0;i<N;i++){cin>>a[i];}
    int flag;
    int count=0;
    int k;
 // N 個の要素を含む 0-オリジンの配列 A
   flag = 1; // 逆の隣接要素が存在する
   while (flag){flag = 0;
     for (int j=N-1;j>= 1;j--){
       if( a[j] < a[j-1]){
         k=a[j];
         a[j]=a[j-1];
         a[j-1]=k;
         //A[j] と A[j-1] を交換
         flag = 1;
         count++;
           
       }
         
     }
         
     }
    for(int i=0;i<N;i++){
        if(i!=0)cout<<" ";
        cout<<a[i];
    }cout<<endl;
    cout<<count<<endl;
    
    
    return 0;
    
}
