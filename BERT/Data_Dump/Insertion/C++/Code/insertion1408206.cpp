//
//  main.cpp
//  ajo
//
//  Created by Hashimoto Ryo on 2015/06/20.
//  Copyright (c) 2015??´ Hashimoto Ryo. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

void out(int a[],int n){
    for(int i; i < n - 1;i++){
        cout << a[i]<< " ";
    }
    cout << a[n-1] << endl;
}


int main(){
    
    int a[MAX];
    int n;
    
    
    cin >> n;//?????????????????????
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    out(a,n);
    
    for(int i = 1;i < n;i++){
        int j = i - 1;
        int v = a[i];
        
        while(v < a[j] && j >= 0){
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = v;
        out(a, n);
    }
    
    return 0;
}
