int main(){
    int a[4][4]={1,9,-8,7,11-12,3,1,10,6,4,5,1,0,3,8};
    int b[4][4]={1,9,-8,7,11-12,3,1,10,6,4,5,1,0,3,8};
    /*比较行保留符合的数*/
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]<a[i][j+1]){
                b[i][j]=0;
            }
            else{
                b[i][j+1]=0;
            }
        }
    }
    /*比较列保留符合的数*/
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]<a[i+1][j]){
                b[i+1][j]=0;
            }
            else{
                b[i][j]=0;
            }
        }
 
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(b[i][j]!=0){
            printf("%d\t",b[i][j]);
            }
        }
 
    }
    printf("\n");
    return 0;
}
