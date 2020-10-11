a[100],v,j,n;p(){for(v=0;v<n;printf("%d%s",a[v++],v-n+1?" ":"\n"));}main(i){for(scanf("%d",&n);j<n;scanf("%d",a+j++));for(p();i<n;a[j+1]=v,p())for(j=i-1,v=a[i++];a[j]>v;a[j+1]=a[j--]);exit(0);}
