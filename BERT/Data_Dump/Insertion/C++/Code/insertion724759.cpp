#include <iostream>

using namespace std;

void swap(int *a,int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int main(){
    int n;
    int ns[100];

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ns[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(ns[i]<ns[j])swap(&ns[i],&ns[j]);
        }
        int init = 1;
        for(int k=0;k<n;k++){
            if(init)init =0;
            else cout << " ";
            cout << ns[k];
        }
        cout << endl;
    }
    return 0;
}
