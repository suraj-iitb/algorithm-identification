//
//  main.cpp
//  Select
//
//  Created by ptyuan on 2018/10/17.
//  Copyright © 2018 YY. All rights reserved.
//

#include <iostream>
using namespace std;
int globacount = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    globacount++;
}



void selectionSort(int *array, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&array[min], &array[i]);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int n = 0;
    cin >> n;
    int array[100];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    selectionSort(array, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << array[i];
        
    }
    cout << endl << globacount << endl;
    
    
    return 0;
}

