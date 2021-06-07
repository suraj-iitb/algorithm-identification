#include <stdio.h>

int main(){
    int n,q,flag,counter;
    
    scanf("%d ",&n);
    int s[n];
    for(int i=0;i<n;i++)scanf("%d ",&s[i]);
    
    scanf("%d ",&q);
    int t[q];
    for(int i=0;i<q;i++)scanf("%d ",&t[i]);
    
    //forループを用いた線形探索
    counter=0;
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(t[i]==s[j]){
                counter++;
                break;
            }
        }
    }
    
    
    /*番兵を用いた線形探索
    for(int i=0;i<q;i++){
        
    }
    */
    printf("%d\n",counter);
    return 0;
}
