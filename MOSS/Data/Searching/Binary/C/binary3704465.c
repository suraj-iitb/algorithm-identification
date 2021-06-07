#include <stdio.h>
#define MAXLENGTH 100000
int binarySearch(int arr[],int key,int size)
{
    int left=0;
    int right=size;
    while(left<right)
    {
        int middle = (left+right)/2;
        if(key==arr[middle])
            return middle;
        else if(arr[middle]>key)
            right = middle;
        else if(key>arr[middle])
            left=middle+1;
    }
    return -1;
}
int main() {
    int s[MAXLENGTH]={0};
    int t[MAXLENGTH]={0};
    int n, m,counter=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){scanf("%d", &s[i]);}
    scanf("%d", &m);
    for(int i=0;i<m;i++){scanf("%d", &t[i]);}
    for(int i=0;i<m;i++)
    {
        int mid = binarySearch(s, t[i], n);
        if(mid!=-1)
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}

