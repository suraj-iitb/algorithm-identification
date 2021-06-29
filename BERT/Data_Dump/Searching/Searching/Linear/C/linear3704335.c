#include <stdio.h>
#define MAX_LENGTH 100000
int main() {
    int s[MAX_LENGTH]={0};
    int t[MAX_LENGTH]={0};
    int n, m, counter=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){scanf("%d", &s[i]);}
    scanf("%d", &m);
    for(int i=0;i<m;i++){scanf("%d", &t[i]);}
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j]==t[i])
            {
                counter++;
                break;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}

