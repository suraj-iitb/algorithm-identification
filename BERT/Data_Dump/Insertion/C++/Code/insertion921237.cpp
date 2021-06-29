#include <cstdlib>
#include <iostream>

using namespace std;

void insertion_sort(int arr[], int length);
void print_array(int array[],int size);

int main() {
    
    
    int l=0,i=0;
    cin>>l;
    int array[l];
    while(cin>>array[i] && i < l-1)
    {
        
        cout<<array[i]<<" ";
        i++;
    }
    cout<<array[l-1];
    
    cout<<endl;
    insertion_sort(array,l);
    
    return 0;
}

void insertion_sort(int arr[], int length) {
    int i, j ,tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
        print_array(arr,length);
    }
}

void print_array(int array[], int size){
    int j;
    for (j=0; j<size;j++)
        for (j=0; j<size;j++)
            if(j==size-1)
                cout <<array[j];
            else
            cout <<array[j]<<" ";
            
    
    cout << endl;
}
