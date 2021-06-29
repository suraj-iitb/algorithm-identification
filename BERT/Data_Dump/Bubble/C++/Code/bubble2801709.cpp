#include<cstdio>
#include<limits>
using namespace std;
void bubbleSort(int A[],int N){
    int flag=1;
    int cnt=0;
    while(flag){
        flag=0;
        for(int j=(N-1);j>=1;j--){
            if(A[j]<A[j-1]){
                int tmp;
                tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag=1;
                cnt++;
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("%d%c",A[i],i==(N-1)?'\n':' ');
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
    bubbleSort(A,num);
    return 0;
}
