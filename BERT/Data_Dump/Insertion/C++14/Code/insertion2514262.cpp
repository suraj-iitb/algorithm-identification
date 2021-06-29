#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <array>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int a[N];
    int i,j,k;
    
    for(i=0; i<N; i++) {
        cin >> a[i];
    }
    
    //display a[]
    for(k=0; k<N; k++) {
        if(k==0) cout << a[k];
        else cout << " " << a[k];
    }
    cout << endl;


    for(i=1; i<N; i++) {
        
        int key = a[i];
        for(j=i-1; j>=0 && a[j]>key; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = key; //j??????1?????????????¨???????????????????????????§
        
        //display a[]
        for(k=0; k<N; k++) {
            if(k==0) cout << a[k];
            else cout << " " << a[k];
        }
        cout << endl;
    }
    
    return 0;
}
