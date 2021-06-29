#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX  1000005
#define SMAX 3000200

int binary_search(int a, int b[],int n);
void input(int a[]);

int main(void)
{
    int count=0;
    int n[1];
    int q[1];
    int S[MAX];
    int T[MAX];
    input(n);
    input(S);    
    input(q);
    input(T);
    for(int i=0;i<q[0];i++)
    {
        if(binary_search(T[i],S,n[0])){count++;}
    }
    printf("%d\n",count);


    return 0;
    
}

int binary_search(int a, int b[],int n)
{
    int left=0;
    int right=n;
    int mid;
    while(left<right)
    {
        mid = (left+right)/2;
        if(b[mid]==a)
        {
            return 1;
        }
        else if(a<b[mid])
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }
    return 0;
}
void input(int a[])
{
    char str[SMAX];
    int x;
    int j=0;
    fgets(str,SMAX,stdin);
    int i=0;
    while(str[i]>=' ')
    {
        while(isspace(str[i])){i++;}
        if(isdigit(str[i]))
        {
            x=0;
            while(isdigit(str[i]))
            {
                x=10*x+(str[i]-'0');
                i++;
            }
            a[j]=x;
            j++;
        }
        else
        {
            i++;
        }
    }
}
