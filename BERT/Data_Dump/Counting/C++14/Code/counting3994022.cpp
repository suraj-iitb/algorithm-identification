#include <bits/stdc++.h>
using namespace std;
#define MAX 2000006

void CountingSort(int *arr,int n)
{
    int output[n+1];
    int mn = *min_element(arr,arr+n);
    int mx = *max_element(arr,arr+n);
    int cnt[mx-mn+5];

    memset(cnt,0,sizeof cnt);

    for(int i=0; i<n; i++)
    {
        cnt[arr[i]-mn]++;
    }
    for(int i=1; i<(mx-mn+2); i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[cnt[arr[i]-mn]-1] = arr[i];
        cnt[arr[i]-mn]--;
    }
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

int arr[MAX];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) scanf("%d", &arr[i]);
    CountingSort(arr, n);
    for(int i = 0 ; i < n; i++)
    {
        if(i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
