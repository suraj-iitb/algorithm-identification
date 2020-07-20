#include<iostream>
using namespace std;

int main(){
    int n, temp, count = 0;
    cin >>n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >>num[i];
    }
    bool flg = 1;
    while(flg){
        flg = 0;
        for(int i = sizeof(num)/sizeof(int); i>0; i--){
            if(num[i] < num[i-1]){
                temp = num[i-1];
                num[i-1] = num[i];
                num[i] = temp;
                flg = 1;
                count++;
            }
        }
    }
    for(int i = 0; i < sizeof(num)/sizeof(int); i++){
        if(i != 0)cout << " ";
        cout << num[i];
    }
    cout << endl;
    cout << count << endl;
}
