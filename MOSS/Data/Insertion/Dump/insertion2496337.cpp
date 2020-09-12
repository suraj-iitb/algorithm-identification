#include <iostream>
using namespace std;
int main(void){
    int n;
    int i, j;
    int v;
    int array[105];

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> array[i];
    }
    for(j = 0; j < n-1; j++){
        cout << array[j] << " ";
    }
    cout << array[n-1] << endl;

    //?????\?????????
    for(i = 1; i < n; i++){
        v = array[i];
        for(j = i - 1; j >= 0; j--){
            if(v >= array[j]){
                array[j+1] = v;
                break;
            }else{
                array[j+1] = array[j];
                if(j == 0){
                    array[0] = v;
                    break;
                }
            }
        }
        for(j = 0; j < n-1; j++){
            cout << array[j] << " ";
        }    
        cout << array[n-1] << endl;
    }
    return 0;
}
