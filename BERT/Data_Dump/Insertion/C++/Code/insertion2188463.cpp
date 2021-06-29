//
//  ALDS.cpp
//  aoj
//
//  Created by shiro kobayashi on 2017/02/15.
//  Copyright ?? 2017??´ shiro kobayashi. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void insertionSort(int a[], int n);
void print_array(int a[], int n);

int main()
{
    int N, A[100];
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    insertionSort(A, N);
    return 0;
}

void insertionSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        
        while( j >= 0 && a[j] > v )
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        
        print_array(a, n);
    }
}

void print_array(int a[], int n)
{
    for(int i = 0; i < n ; i++)
    {
        cout << a[i];
        if( i == (n - 1))
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}
