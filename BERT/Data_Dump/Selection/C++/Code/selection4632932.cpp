#include<iostream>
using namespace std;

int main(){
    int n, minj, a;
    int times = 0;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < n; i++){
        minj = i;
        for(int j = i; j < n; j++){
            if(num[j] < num[minj]){
                minj = j;
            }
        }
        a = num[minj];
        num[minj] = num[i];
        num[i] = a;
        if(i != minj) times++;
    }
    cout << num[0];
    for(int i = 1; i < n; i++){
        cout << " " << num[i];
    }
    cout << endl;
    cout << times << endl;
    return 0;
    
}
