#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
//1番目から順に配列の中で最も小さい数字と入れ替えていく
void selectionSort(int A[],int N){
    int count = 0;
    
    for(int i=0;i<N;i++){
        int minj=i;
        int cou = 0;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
                cou =1;
            }
        }
        int a =A[i];
        A[i]=A[minj];
        A[minj]=a;
        if(cou==1)count+=1;
    }
    for(int k=0;k<N;k++){
        if(k==N-1)cout<<A[k]<<endl;
        else cout<<A[k]<<" ";
    }
    cout<<count<<endl;
}


int main(){
    
    int N;
    cin>>N;
    int A[N];
    

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    selectionSort(A,N);
    
    

}
