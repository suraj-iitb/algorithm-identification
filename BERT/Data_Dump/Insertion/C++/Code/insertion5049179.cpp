#include<bits/stdc++.h>
using namespace std;

int main(){
    int card[100],n,box;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> card[i];
        cout << card[i];
        if(i!=n-1){
            cout << ' ';
        }
    }
        cout << endl;
    for(int i=1;i<n;i++){
        
        box = card[i];
        for(int j=i-1;j>=0;j--){
           if(card[j+1]<card[j]){
               card[j+1]=card[j];
               card[j]=box;
           }else{
               break;
           }
        }
        for(int j=0;j<n;j++){
            cout << card[j];
            if(j!=n-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
