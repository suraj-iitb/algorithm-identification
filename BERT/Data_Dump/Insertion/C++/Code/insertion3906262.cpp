//17D8101003D 田野平 晃樹 TanoMero417 C++
#include <iostream>

using namespace std;

void printArray(int n, int a[]){
    for(int i=0;i<n;i++){
        cout << a[i];

        if(i<n-1){
            cout << " ";
        }
    }
    cout << endl;
}


int main(){
    int n;
    int a[1000];

    cin >> n;

    for(int i=0; i<n;i++){
        cin >> a[i];
    }

    printArray(n,a);

    //メインループ
    for(int i=1; i<n; i++){
        int j;
        int tmp = a[i];

        for(j=i-1; j >= 0 && a[j] > tmp; j--){
            a[j+1] = a[j];
        }

        a[j+1] = tmp;

        printArray(n,a);
    }
    
    return 0;
}

/*実行結果
15 16
*/
