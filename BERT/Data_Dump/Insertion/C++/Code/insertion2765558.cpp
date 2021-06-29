#include <iostream>
using namespace std;

int n;
int num[100];

int main(){
    //freopen("D:\\zhouyu\\study\\codes\\InsertSort.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    int temp;
    for(int i=0; i<n; i++){
        temp = num[i];
        for(int j=i-1; j>=0; j--){
            if(num[j] > temp){
                num[j+1] = num[j];
                num[j] = temp;
            }
            else{
                break;
            }
        }
        for(int k=0; k<n; k++){
            if(k==n-1){
                cout << num[k];
            }
            else{
                cout << num[k] << " ";
            }
        }
        cout << endl;
    }
}
