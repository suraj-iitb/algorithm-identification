#include<iostream>
#include<cstdio>

using namespace std;
int selectedSort(int,int*);
void show(int,int*,int);

int main(void){
    int n,sw;
    int const MAX=100;
    int num[MAX];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    sw = selectedSort(n,num);
    show(n,num,sw);
    return 0;
}

int selectedSort(int n, int* addr){
    int min,sw=0;
    for(int i=0;i<n;++i){
        min=i;
        for(int j=i;j<n;++j){
            if(addr[j]<addr[min]){
                min=j;
            }
        }
        if(i!=min){
            swap(addr[i],addr[min]);
            ++sw;
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
