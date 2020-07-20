#include <cstdio>
#include <iostream>
#define MAX 100
using namespace std;
int N;
int a[MAX];
int cnt=0;
void bs(int *a,int n){
    bool flag=true;
    while(flag){
        flag=false;
        for(int j=N-1;j>0;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=true; 
                cnt++;
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    bs(a,N);
    printf("%d",a[0]);
    for(int i=1;i<N;i++){
        printf(" %d",a[i]);
    }
    printf("\n%d\n",cnt);
}
