#include <iostream>
using namespace std;

int N;
void print(int *array){
    for(int i = 0; i < N; i++){
        if(i != N-1) cout << array[i] << " ";
        else cout << array[i] << endl;
    }
}

void insertion_sort(int *array){
    print(array);
    for(int i = 1; i < N; i++){
        int key = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        
        array[j+1] = key;
        print(array);
    }
}

int main(void){
    // Your code here!
    
    cin >> N;
    int arr[N];
    for(int i =0;  i < N; i++) cin >> arr[i];
    
    insertion_sort(arr);
}


