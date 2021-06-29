#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

static const int MAX = 100;
int main(){
    int A[MAX], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 1; i < n; i++){
        int v = A[i];
        int j = i-1;
        for(int l = 0; l < n-1; l++){
            printf("%d ", A[l]);
        }
        printf("%d",A[n-1]);
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printf("\n");
    }
    for(int l = 0; l < n-1; l++){
            printf("%d ", A[l]);
    }
    printf("%d",A[n-1]);
    printf("\n");
    return 0;
}
