#include<cstdio>
#include<algorithm>
using namespace std;

void selectionSort(int A[],int N){
    int cnt=0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            swap(A[i],A[minj]);
            cnt++;
        }
    }
    for(int i=0;i<N;i++){
        printf("%d%c",A[i],i==N-1?'\n':' ');
    }
    printf("%d\n",cnt);
}

int main(){
    int num;
    scanf("%d",&num);
    int A[num];
    for(int i=0;i<num;i++){
        scanf(" %d",&A[i]);
    }
    selectionSort(A,num);
    return 0;
}
