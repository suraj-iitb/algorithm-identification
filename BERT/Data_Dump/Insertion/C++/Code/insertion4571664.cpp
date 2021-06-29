#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
#include<queue>
#include<map>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int k=0;k<n;k++){
        if(k > 0) cout << " ";
        cout << a[k];
    }
    cout << endl;

    for(int i=1;i<n;i++){
        int tmp = a[i];
        int j = i-1;
        while(j>=0 && a[j] > tmp){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = tmp;
        
        for(int k=0;k<n;k++){
            if(k > 0) cout << " ";
            cout << a[k];
        }
        cout << endl;
    }
}
