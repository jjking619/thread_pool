#include <stdio.h>


int main()
{
    //S1:定义所需要的数据 出生年月日 当前年月日 日子的总和
    int c_y,c_m,c_d,y,m,d,days = 0;
    int day1 = 0;
    int day2 = 0;
    int day3 = 0;
    //days代表是最后的结果 day1是当年到年末的时间 day2是年初到当前日子的时间
    //day3是中间那些年的时间

    printf("请输入您的出生日期:\n");
    scanf("%d%d%d",&c_y,&c_m,&c_d);
    printf("请输入当前日期:\n");
    scanf("%d%d%d",&y,&m,&d);      


    //S2:求出生那天到那年年末的日子
    switch(c_m)
    {
        case 1:
            day1 += 31;
        case 2:
            //判断是平年还是闰年
            day1 += 28;//先加28天,如果是闰年的话,再多加一天
            if((c_y%400==0) || (c_y%4==0 && c_y%100!=0))
            {
                day1++;//是闰年的话,二月份要多一天
            }
        case 3:
            day1 += 31;
        case 4:
            day1 += 30;
        case 5:
            day1 += 31;
        case 6:
            day1 += 30;                    
        case 7:
            day1 += 31;
        case 8:
            day1 += 31;                    
        case 9:
            day1 += 30;
        case 10:
            day1 += 31;                    
        case 11:
            day1 += 30;
        case 12:
            day1 += 31;
            break;                    
        default:
            printf("该日子不合理");
            break; 
    }   
    day1 =  day1 - c_d;//已经把出生那年到年末的时间计算好了



    //S3:求出生那一年的后一年 到今年的前一年的日子总合 
    for(int i = c_y+1;i < y;i++)
    {
        //如果是闰年,就加366天
        if((i%400==0) || (i%4==0 && i%100!=0))
        {
            day3 = day3 + 366;
        }
        else
        {
            day3 = day3 + 365;
        }
    }


    //S4:求今年年初到现在这个日子的时间 十二月也不是计算在其中的
    switch(m - 1)
    {
        case 11:
            day2 += 30;
        case 10:
            day2 += 31;
        case 9:
            day2 += 30;
        case 8:
            day2 += 31;
        case 7:
            day2 += 31;
        case 6:
            day2 += 30;
        case 5:
            day2 += 31;
        case 4:
            day2 += 30;
        case 3:
            day2 += 31;
        case 2:
            //判断是平年还是闰年
            days += 28;//先加28天,如果是闰年的话,再多加一天
            if((y%400==0) || (y%4==0 && y%100!=0))
            {
                day2++;//是闰年的话,二月份要多一天
            }
        case 1:
            day2 += 31;
            break;
        default:
            break;
    }
    //还要加上当前这个月已经过了的日子
        day2 += d;

    if(c_y == y)
    {
            if((y%400==0) || (y%4==0 && y%100!=0))
            {
                days = day1 + day2 -366;
            }
            else
            {
                days = day1 + day2 - 365;

            }
    }
    else
    {
        days = day1 + day2 + day3;
    }

    printf("您已经活了%d天,请继续加油\n",days);
    return 0;
}