#include <iostream>
using namespace std;
#define Max_num 100

void insertionsort(int array[],int number){
    int temp;
    int j;
    for(int i = 0;i < number;i++){
        if(i == number - 1){
            cout << array[i] << endl;
            break;
        }
        cout << array[i] << " ";
    }
    for(int i = 1;i < number;i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
        for(int t = 0;t < number;t++){
            if(t == number - 1){
                cout << array[t] << endl;
                break;
            }
            cout << array[t] << " ";
        }
    }
}

int main(){
    int num;
    int origin[Max_num];
    cin >> num;
    for(int i = 0;i < num;i++) cin >> origin[i];
    insertionsort(origin,num);
    return 0;
}
