#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;
int main(){

    int n,a;
    vector<int>v(1,0); //要素数10 全てのがず0
    cin >> n;
    
    while(n--){
        cin >> a;
        v.push_back(a);//add的な意味
    }
    
    for(int j=1; j<v.size();j++){
        int key = v[j]; //j  = 1~size
        int i = j - 1;//一つ左
        
        while(i > 0 && v[i] > key){
            v[i+1] = v[i]; //左隣のほうが大きかった場合、左隣に現在の値を代入する
            i--;
        }
        v[i+1] = key;//whileから抜け出した場合、keyを代入する
        
        for(int j=1 ;j<v.size() ;j++){
            cout << (j==1?"":" ") << v[j];
        }
        cout << endl;
    }
}



