#include<bits/stdc++.h>
using namespace std;
const int MAX_NUM = 2000000;

int main(){
    int N;
    cin >> N;

    int numbers[MAX_NUM];
    int i;
    for(i = 0 ;  i< N; i++){
        cin >> numbers[i];
    }
    int count = 0;
    for(i = 0; i < N-1; i++){
        int tmp = i;
        int j;
        for(j = i+1; j <N;j++){
            if(numbers[j]<numbers[tmp]){
                tmp = j;
            }
        }
        if(tmp != i ){
            swap(numbers[tmp], numbers[i]);
            count++;
        }
        
    }
    for(i = 0 ; i<N-1; i++){
        cout << numbers[i] << " ";
    }
    cout << numbers[i] << endl;
    cout << count << endl;

    return 0;
}

