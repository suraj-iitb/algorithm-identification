#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10100
#define SMAX 50200

int linear_search(int a, int b[],int n);
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
        if(linear_search(T[i],S,n[0])){count++;}
    }
    printf("%d\n",count);


    return 0;
    
}

int linear_search(int a, int b[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a == b[i]){return 1;}
        
    }
    return  0;
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
