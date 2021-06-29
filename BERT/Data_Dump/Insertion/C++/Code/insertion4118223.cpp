/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

#define N 100

void insertionSort(int a[], int n)
{
    for(int i=1,j=0; i<n; i++)
    {   
        int v;
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v)
        {
                a[j+1]=a[j];
                j--;
        }
        a[j+1]=v;
        for(int k=0; k<n; k++)
        {    
            std::cout<<a[k];
            if(k<n-1)
                std::cout<<' ';
        }
        std::cout<<std::endl;
        
    }
}

int main()
{
    int n, a[N], i=0;
    std::cin>>n;
    while(i<n)
    {
        std::cin>>a[i];
        i++;
    }
    
    for(int k=0; k<n; k++)
    {        
        std::cout<<a[k];
        if(k<n-1)
                std::cout<<' ';
    }
    std::cout<<std::endl;
   
   insertionSort(a, n);
    

    return 0;
}

