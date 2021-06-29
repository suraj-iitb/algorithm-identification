#include<bits/stdc++.h>
using namespace std;
const int MAX_NUM = 2000000;
int main(){
    int N;
    cin >> N;
    int elements[MAX_NUM];
    int i;
    for(i = 0; i < N; i++){
        cin >> elements[i];
    }
  
    int j;
    int count = 0;
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i+1; j--){
            if(elements[j] < elements[j-1]){
                int tmp = elements[j];
                elements[j] = elements[j-1];
                elements[j-1] = tmp;
                count++;
            }
        }
    }
    for(i = 0; i < N-1; i++){
        printf("%d ", elements[i]);
    }
    printf("%d\n", elements[i]);
    printf("%d\n", count);
    return 0;
}
