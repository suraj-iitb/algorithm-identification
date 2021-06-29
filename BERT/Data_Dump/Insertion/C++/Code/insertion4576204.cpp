#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans[N];
    for(int i = 0; i< N;i++){
        cin >> ans[i];
      	cout << ans[i];
      	if(i!= N-1){
          cout << " ";
        }
    }
  	cout << endl;
    for(int i = 1; i < N;i++){
        int a = ans[i];
        int j = i-1;
        while(j >= 0 && ans[j]>a){
            ans[j+1] = ans[j];
            j--;
        }
        ans[j+1] = a;
        for(int k = 0; k <N;k++){
            cout << ans[k];
            if(k!= N-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}
