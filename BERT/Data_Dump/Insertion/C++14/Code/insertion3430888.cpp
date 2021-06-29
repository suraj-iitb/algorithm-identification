//
// Created by xfr on 2019/3/16.
//
#include <iostream>
using namespace std;

void output(int num[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d", num[i]);
        if(i == (n-1))
        {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
    }
    output(num, n);
    for(int i=1; i<n; i++)
    {

        int temp = num[i];
        int j = i - 1;
        while(j>=0 && temp < num[j])
        {
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = temp;
        output(num, n);
    }
}

