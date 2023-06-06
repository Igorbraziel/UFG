    #include <stdio.h>
     
    int main(){
        int v[5000], n, i;
        scanf("%d", &n);
        for(i=0;i<n;i++){
            scanf("%d", &v[i]);
        }
        for(i=n-1;i>=0;i--){
            printf("%d ", v[i]);
        }
        printf("\n");
        return 0;
    }