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
    int k;
    for(k = 0; k < N - 1; k++){
        cout << elements[k] << " " ;
    }
    cout << elements[k] << endl;
    
    int key;
    for(i = 1; i < N ; i++){
        key = elements[i];
        int j;
        for(j = i - 1; j >= 0; j--){
            if(elements[j] > key){
                elements[j+1] = elements[j];

            }else{
                break;
            }
        }
        elements[j+1] = key;
        
        for(k = 0; k < N - 1; k++){
            cout << elements[k] << " " ;
        }
        cout << elements[k] << endl;
    }
    return 0;
}

