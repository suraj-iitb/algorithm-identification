#include<cstdio>

using namespace std;

void trace(int a[],int N){
    int i;
    for(i=0;i<N;++i){
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void insertSort(int* addr, int N){
    int j,i,v;
    for(i=1;i<N;++i){
        v=addr[i];
        j=i-1;
        while(j>=0 && addr[j]>v){
            addr[j+1]=addr[j];
            --j;
        }
        addr[j+1]=v;
        trace(addr,N);
    }
    return;
}


int main(void){
    int N,i,j;
    int addr[100];
    scanf("%d",&N);
    for(i=0;i<N;++i){
        scanf("%d",addr+i);
    }
    trace(addr,N);
    insertSort(addr,N);
    return 0;
}
