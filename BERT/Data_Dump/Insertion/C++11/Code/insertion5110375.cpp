#include<iostream>

using namespace std;

class Sort{
    public:
    void insertionSort(int *array,int n){
        int value,index;
        for (int i = 0; i < n; i++){
            value = array[i];
            index = i-1;
            while(index >= 0 && array[index] > value){
                array[index+1] = array[index];
                index--;
            }
            array[index+1] = value;
            
            for (int i = 0; i < n; i++){
                if(i!=0) cout << " ";
                cout << array[i];
            }
            cout << endl;
        }  
    }
};


int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++){cin >> array[i];}
    
    Sort sort = Sort();
    sort.insertionSort(array,n);
    
}
