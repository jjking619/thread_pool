// #include<stdio.h>
// int main() {
//     int arr[4][4] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//     int a, b;//保存鞍点的行 列号的
//     for (int i = 0; i < 4; i++) {
//         a = -1, b = -1;
//         int max;
//         max = arr[i][0];
//         //先求最大值
//         for (int j = 0; j < 4; j++) {
//             if (arr[i][j] > max) max = arr[i][j];
//         }
//         //通过最大值进行对比 取横纵坐标
//         for (int l = 0; l < 4; l++) {
//             if (arr[i][l] == max) {
//                     a = i; b = l;
//                     int min;
//                     min = arr[0][b];
//                     //再求最小值
//                 for (int k = 0; k < 4; k++) {
//                         if (arr[k][b] < min) min = arr[k][b];
//                 }
              
//                 if (arr[a][b] == min) { printf("鞍点值为%d ,arr[%d][%d]\n", arr[a][b], a, b); continue; }
//                 else
//                     printf("无鞍点\n");
//             }
//             }

//         }

//         printf("\n");
            
//     return 0;
// }


#include<stdio.h>
int main() {
    int N, M, K;
    scanf_s("%d %d %d", &N, &M, &K);
    int arr[100][100] = {0};

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf_s("%d", &arr[i][j]);

    int count, sum;
     count = sum = 0;
     for (int i = 0; i < N; i++) {
        // count = 0;
         for (int j = 0; j < M;) {
             if (arr[i][j] == 0) {
               
                 while (j<M&&arr[i][j++] == 0) { count++; 
                 }
                 if (count < K) sum += 0;
                 else   sum += count - K + 1;
             }

             else 
                    j++;

             count = 0;
         }
     }
        printf("方法数：%d\n",sum);         
    return 0;
}
