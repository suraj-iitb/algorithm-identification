#include<cstdio>
using namespace std;
int insertionSort(int A[],int N){
    int v,j;
    for(int i=1;i<=N-1;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
        for(int i=0;i<N;i++){
            if(i != (N-1)){
                printf("%d ",A[i]);
            }else{
                printf("%d\n",A[i]);
            }
        }
    }
    return 0;

}
int main(){
    int num;
    scanf("%d",&num);
    int A[num];
    for(int i=0;i<num;i++){
        scanf(" %d",&A[i]);
    }
    for(int i=0;i<num;i++){
            if(i != (num-1)){
                printf("%d ",A[i]);
            }else{
                printf("%d\n",A[i]);
            }
        }
    insertionSort(A,num);
    return 0;
}
