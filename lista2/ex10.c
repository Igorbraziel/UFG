    #include <stdio.h>
     
    int main(){
            int l, c, cl, cc;
        scanf("%d", &l);
        scanf("%d", &c);
        for(cl=1;cl<=l;cl++){
            for(cc=1;cc<=c;cc++){
                if(cc==cl){
                    break;
                }
                    printf("(%d,%d)", cl, cc);
                      if(cc < cl-1 && cc <c){
                        printf("-");
                      }
             }
            printf("\n");
        }
        return 0;
    }