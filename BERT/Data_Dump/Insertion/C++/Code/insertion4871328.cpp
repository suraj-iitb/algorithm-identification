#include<iostream>
#include<cstdio>
using namespace std;

int n, a[100];

void print(){
    int i;
    for(i=0; i<n-1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);
}

int main(int argc, char *argv[]){
    scanf("%d", &n);
    int key, i, j;
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    print();
    for(i=1; i<n; i++){
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        print();
    }
    return 0;
}
