#include<stdio.h>
int main() {
   int arr[] = { 1,2,3,4,6,9,-8,100,-101 };
   int len = sizeof(arr) / sizeof(arr[0]);
   int sum[5] = { 0 };

   printf("原数组：\n");
   for (int i = 0; i < len; i++) {
       printf("%d ", arr[i]);
   }


   for (int i = 0; i < len; i++) {
       if (arr[i] <= 0) arr[i] = 0;
   }

   printf("\n负数置0后的数组\n");
   for (int i = 0; i < len; i++) {
       if (arr[i] <= 0) arr[i] = 0;
       printf("%d ", arr[i]);
   }

   //求和数组 0会跳到数组的下一位 非0进行累加
   for (int i = 0, j = 0; i < len; i++) {
       if (arr[i] != 0) sum[j] += arr[i];
       else
       {
           j++;
           continue;
       }
   }
   //累加数组内的累加值
   int temp = sum[0];//找最大值
   printf("\n累加数组值：\n");
   for (int i = 0; i < 5; i++) {
       printf("%d ", sum[i]);
       if (sum[i] > temp)temp = sum[i];
   }
   printf("\n最大值为：%d\n", temp);
   return 0;
}