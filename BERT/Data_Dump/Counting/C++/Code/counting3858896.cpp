#include<stdio.h>
#include<vector>
using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    vector<int> v1,v2;
    v1.resize(n+1);
    v2.resize(n+1);
    int C[10001] = {0};
    for(int i =0; i<n; i++){
        int a;
        scanf("%d", &a);
        v1[i+1] = a;
        C[v1[i+1]]++;
    }
    
    for(int i=1; i<=10001; i++) C[i] = C[i] + C[i-1];

    for(int j=1; j<=n; j++){
        v2[C[v1[j]]] = v1[j];
        C[v1[j]]--;
    }

    for(int i=1; i<=n; i++){
        if(i>1) printf(" ");
        printf("%d", v2[i]);
    }
    printf("\n");

    return 0;

}
