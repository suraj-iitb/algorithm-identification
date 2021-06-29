#include <iostream>
#include <string>

int main(){

    int n;
    int *array;
    int key;
    std::string str;

   // std::cout << "Input the length of the array: ";
    std::cin >> n;

  //  std::cout << "Input the array: ";

    array = new int[n];

    for(int i = 0; i < n; i++)
        std::cin >> array[i];
    
    //show the array before sorting
    for(int k = 0; k < n-1; k++)
            std::cout << array[k] << " ";
    std::cout << array[n-1] << std::endl;

    for(int i = 1, j; i < n; i++){
        key = array[i];
        //insert Array[i] into the sorted sequence A[0,...,j-1] 
        j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
        //show the intersection of sorting
        for(int k = 0; k < n-1; k++)
            std::cout << array[k] << " ";
        std::cout << array[n-1] << std::endl;
    }

    delete[] array;
    return 0;
}
