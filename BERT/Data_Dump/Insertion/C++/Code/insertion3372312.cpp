#include <iostream>

using namespace std;

int main(){
    int num;
    int array[1024];

    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> array[i];
    }
    for(int k = 0; k < num; k++){
        cout << array[k];
        if(k != num - 1) cout << " ";
    }
    cout << endl;

    for(int i = 1; i < num; i++){
        int key = array[i];
        if(array[i - 1] > key){
            int j = i;
            do {
                array[j] = array[j - 1];
                j--;
            } while(j > 0 && array[j - 1] > key);
            array[j] = key;
        }
        for(int k = 0; k < num; k++){
            cout << array[k];
            if(k != num - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

