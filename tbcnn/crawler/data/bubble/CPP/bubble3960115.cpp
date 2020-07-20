#include<iostream>
#include<cstdio>

using namespace std;
int bubbleSort(int,int*);
void show(int,int*,int);

int main(void){
    int n,sw;
    int const MAX=100;
    int num[MAX];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    sw = bubbleSort(n,num);
    show(n,num,sw);
    return 0;
}

int bubbleSort(int n, int* addr){
    int sw=0;
    for(int i=0;i<n-1;++i){
        for(int j=n-1;j>=i+1;--j){
            if(addr[j]<addr[j-1]){
                swap(addr[j],addr[j-1]);
                ++sw;
            }
        }
    }
    return sw;
}

void show(int n, int* addr, int sw){
    for(int i=0;i<n;++i){
        if(i) printf(" ");
        printf("%d",addr[i]);
    }
    printf("\n");
    printf("%d\n",sw);
}
