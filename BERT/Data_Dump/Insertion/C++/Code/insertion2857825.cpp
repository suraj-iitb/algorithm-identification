#include<iostream>
using namespace std;

int main(){
    int n, j, v = 0;
    cin >>n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >>num[i];
        if(i != 0)cout << " ";
        cout << num[i];
    }
    cout << endl;
    for(int i = 1; i < sizeof(num)/sizeof(int); i++){
        v = num[i];
        j = i - 1;
        while(j >= 0 && num[j] > v){
            num[j + 1] = num[j];
            j--;

        }
        num[j + 1] = v;
        for(int k = 0; k < sizeof(num)/sizeof(int); k++){
            if(k != 0)cout << " ";
            cout << num[k];
        }
        cout << endl;
    }

}
