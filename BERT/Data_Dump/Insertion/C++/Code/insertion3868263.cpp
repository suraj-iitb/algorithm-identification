#include <bits/stdc++.h>
using namespace std;

void show(int A[],int N){
    for(int i = 0; i < N;i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

int main(){
    int N;
    cin >> N;
    int str[N];
    for(int i = 0; i < N; i++){
        cin >> str[i];
    }
    show(str,N);

    for(int i = 1; i < N; i++){
        int key = str[i];
        int j = i-1;
        while(j >= 0 && str[j] > key){
            str[j+1] = str[j];
            j--;
        }
        str[j+1] = key;
        show(str,N);
    }

        
        
}
