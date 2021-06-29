#include<iostream>
using namespace std;
int bubbleSort(int A[],int N){
int cnt=0,i,j,tmp;
for(i=0;i<N;i++){
for(j=N-1;j>0;j--){
if(A[j]<A[j-1]){
tmp=A[j];
A[j]=A[j-1];
A[j-1]=tmp;
cnt++;
}

}
}
for(i=0;i<N;i++){
if(i>0)cout<<" ";
cout<<A[i];
}
cout<<endl;
cout<<cnt<<endl;
}


int main(){
int N,i;
cin>>N;
int A[N];
for(i=0;i<N;i++)cin>>A[i];
bubbleSort(A,N);
return 0;
}
