#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int number[n];

    for(int i=0;i<n;i++){
        cin >> number[i];
        cout << number[i];
        if(i<n-1)cout << " ";
        else cout << endl;
    }

    for(int i=1;i<n;i++){
        int sub = number[i];
        int j = i-1;

        while(j >= 0 && number[j]>sub){
            number[j+1]=number[j];
            j--;
        }

        number[j+1] = sub;

        for(int k=0;k<n;k++){
            cout << number[k];
            if(k<n-1)cout << " ";
            else cout << endl;
        }

    }


}
