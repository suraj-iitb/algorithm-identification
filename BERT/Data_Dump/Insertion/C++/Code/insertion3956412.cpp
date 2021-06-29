
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int* arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<N;i++){
        int tmp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>tmp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
        for(int k=0;k<N;k++){
            if(k==N-1){
                printf("%d\n",arr[k]);
            }
            else{
                printf("%d ",arr[k]);
            }
        }
    }
    return 0;
}


