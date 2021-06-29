int main()
{
    int s[100001], t[50001];
    int n,q;
    int i,j;
    int count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &s[i]);

    scanf("%d", &q);
    for (i = 0; i < q; i++) scanf("%d", &t[i]);
    
    for (i = 0; i < q; i++){ //compare t to s
        int left = 0;
        int right = n;
        while (left < right){
            int mid = (left + right)/2;
            if (t[i] == s[mid]){    //found
                count++;
                break;
            }
            if (t[i] > s[mid]){    //right
                left = mid + 1;
            }
            else if(t[i] < s[mid]){   //left
                right = mid;
            }
        }
    }
    printf("%d\n", count);
}
