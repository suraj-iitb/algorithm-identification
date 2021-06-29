#include <cstdio>
#include <iostream>
#define MAX 100
using namespace std;
int N;
int a[MAX];
int cnt=0;
void ss(int *a,int n){
    int minj;
    for(int i=0;i<N;i++){
        minj=i;
        for(int j=i;j<N;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        swap(a[i],a[minj]);
        if(minj!=i){
            cnt++;
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    ss(a,N);
    printf("%d",a[0]);
    for(int i=1;i<N;i++){
        printf(" %d",a[i]);
    }
    printf("\n%d\n",cnt);
}
