// 社交数を求める
// 事前知識：4個組が161個,6個組が5つ,8個組が2つ,5個組・9個組・28個組が1つ見つかっている
// 今回は計算コストを減らすため4個組のみを対象とする

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  int i,j,k,l,m;
    int sum[4];
    int count=0;
    i=atoi(argv[1]);
    i=(i-1)*1000+1;
    m=i+1000;
    printf("%d ~ %d\n",i,m);
    for(;i<m;i++){

    // 配列初期化
    for( l = 0; l < 4; l++){
        sum[l]=1;
    }
    


    // 約数の和を取る
    for(j=2;j<=i/2;j++){
        if(i%j==0){
            sum[0]+=j;
        }
    }
    

    // 素数の時,一つ前と同じ時
    if(sum[0] ==1 ||i==sum[0]){
        continue;
    }
    
    for(k = 1; k < 4; k++){
        // 約数の和を取る
        for(j=2;j<=sum[k-1]/2;j++){
            if(sum[k-1]%j==0){
                sum[k]+=j;
            }
        }
        // 素数の時
        if(sum[k] ==1){
            break;
        }

        // 初めの数に戻ってしまった時)(友愛数)
        if(k<3 &&i==sum[k]){
            break;
        }
 
        
        
    }

    if(i==sum[3]&&i!=sum[1]&&sum[0]!=sum[2]){
        count++;
        printf("社交数%d:(%d,%d,%d,%d)\n",count,sum[3],sum[0],sum[1],sum[2]);
    }
    }
}
