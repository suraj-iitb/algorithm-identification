#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *a, int ax);

void ins_sort(int *a, int ax)
{
    int i;

    for(i=1;i<ax;i++) {
        print(a,ax);
        int key = a[i];
        int j;

        for(j=i-1;j>=0;j--) {
            if(key >= a[j]) {
                break;
            }
            else {
                a[j+1] = a[j];
            }
        }
        a[j+1] = key;
    }
    print(a,ax);
    return;
}

void print(int *a, int ax)
{
    int i;

    for(i=0;i<ax-1;i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[i]);

    return;
}

void read(int n, int *a)
{
    int i;
    char str[1000];
    char tmp[] = " \n";

    fgets(str, sizeof(str), stdin);
    a[0] = atoi(strtok(str, tmp));
    for(i=1;i<n;i++) {
        a[i] = atoi(strtok(NULL, tmp));
    }

    return;
}

int main(void)
{
    int n;
    int a[1000];
    scanf("%d%*c", &n);

    read(n,a);

    ins_sort(a,n);

    return 0;
}
