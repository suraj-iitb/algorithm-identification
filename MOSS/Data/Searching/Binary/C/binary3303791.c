  #include <stdio.h>

  int main(){
  int i,j,n,q,k=0;
  int right,left,mid;
  int s[100000];
  int t[50000];

   scanf("%d",&n);

        for(i = 0; i < n; i++){
          scanf("%d",&s[i]);
        }

        scanf("%d",&q);

        for(i = 0; i < q; i++){
          scanf("%d",&t[i]);
        }

        for(i=0; i<q; i++){
                left = 0;
                right = n;
            while(left < right){
            mid = (left + right)/2;
            if(t[i] == s[mid]){
                k=k+1;
                break;
            }
            else if(t[i] > s[mid]){
              left = mid+1;
            }
            else right = mid;
                     }
                }

            printf("%d\n",k);

            return 0;
        }

