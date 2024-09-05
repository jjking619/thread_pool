#include <stdio.h>


int main()
{
    int y,m,d;//定义当前输入的年月日
    scanf("%d%d%d",&y,&m,&d);

    int days = 0;//距离年末的日子

    //判断是平年还是闰年,单独放在二月份那里来操作

    switch(m)//判断当前是哪个月就OK了,就知道还剩余多少个月
    {
        case 1:
            days += 31;
        case 2:
            //判断是平年还是闰年
            days += 28;//先加28天,如果是闰年的话,再多加一天
            if(y%400==0 || y%4==0 && y%100!=0)
            {
                days++;//是闰年的话,二月份要多一天
            }
        case 3:
            days += 31;
        case 4:
            days += 30;
        case 5:
            days += 31;
        case 6:
            days += 30;                    
        case 7:
            days += 31;
        case 8:
            days += 31;                    
        case 9:
            days += 30;
        case 10:
            days += 31;                    
        case 11:
            days += 30;
        case 12:
            days += 31;
            break;                    
        default:
            printf("该日子不合理");
            break; 
    }
    //减去当前这个月已经过了的日子
    days -= d;

    printf("当前距离年末还有%d天\n",days);

    return 0;
}
