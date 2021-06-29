#include<bits/stdc++.h>
using namespace std;
int main(){
    int flag = 1,N,count = 0;
    cin >> N;
    vector<int> list(N);
    for(int i = 0; i < N; i++)
{
    cin >> list[i];
}
    while(flag){
        flag = 0;
        for(int i = N - 1; i > 0; i--){
            if(list[i] < list[i - 1]){
                int b = list[i];
                int c = list[i - 1];
               list[i - 1] = b;
               list[i] = c;
                    flag = 1;  
            count++;     }
        
        }
    }
    for(int i = 0; i < N; i++){
        if(i < N - 1)
        cout << list[i] << " ";
        if(i  == N - 1)
        cout << list[i];
    }
    cout << endl;
    cout << count << endl;
}
