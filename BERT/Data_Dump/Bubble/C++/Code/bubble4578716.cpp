#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans[N];
    for(int i = 0; i< N;i++){
        cin >> ans[i];
    }
    int flag = 1;
    int i = 0;
    int count = 0;
    while(flag){
      flag = 0;
        for(int j = N-1; j>= i+1;j--){
            int temp=0;
            if(ans[j] < ans[j-1]){
                temp = ans[j-1];
                ans[j-1] = ans[j];
                ans[j] = temp;
                flag = 1;
                count++;
            }
        }
      i++;
    }
    for(int i = 0; i< N;i++){
        cout << ans[i];
        if(i != N-1)cout << " ";
    }
    cout << endl;
    cout <<count << endl;
}
