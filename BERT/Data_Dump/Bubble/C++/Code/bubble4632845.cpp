#include<iostream>
using namespace std;

int main(){
    int n, a;
    int times = 0;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    
    int flag = 1;
    while(flag == 1){
        flag = 0;
        for(int j = n-1; j > 0; j--){
            if(num[j] < num[j-1]){
                a = num[j];
                num[j] = num[j-1];
                num[j-1] = a;
                times++;
                flag = 1;
            }
        }
    }
    cout << num[0];
    for(int i = 1; i < n; i++){
        cout << " " << num[i];
    }
    cout << endl;
    cout << times << endl;
    
    return 0;
}
