#include<stdio.h>
#include<string.h>

int n, q,s[100000], t,  c=0;

int main(void){
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d",&s[i]);

    scanf("%d",&q);
    for(int i=0 ; i<q ; i++){
        scanf("%d",&t);
        for(int j=0 ; j<n ; j++){
            if(t == s[j]){
                c++;
                break;
            }
        }
    }

    printf("%d\n", c);

    return 0;
}
