/*
本题目要求一元二次方程的根，结果保留2位小数。
输入格式:
输入在一行中给出3个浮点系数a、b、c，中间用空格分开。
输出格式：参考程序结尾。
输出示例: 参考程序结尾。
*/

#include <stdio.h>
#include <math.h>
int main()
{
    float a = 0,b = 0, c = 0;
    float x1 = 0, x2 = 0, real = 0, imag_abs = 0;
    int num = 0;
	/*定义变量。a,b,c为方程系数。x1,x2为实数根，
	real,imag_abs分别为复数根的实部的值，复数根
	虚部的绝对值。num为计数变量*/

    scanf("%f %f %f",&a,&b,&c);  //输入方程系数

    if (a==0 && b==0 && c==0)      //方程无根
    num = 100;
    else if (a==0 && b==0 && c!=0) //方程无根
    num = 200;
    else if (a!=0)                 //方程有两根
    num = 300;
    else if (a==0 && b!=0)         //方程有一根
    num = 400;
    /*判断根的情况。对于方程ax^2 + bx + c = 0, 它可能有零根，可能有两个根，可能有一个根。
	方程根的情况可以通过系数进行判断。此处使用计数变量num对方程根的多种情况进行记录，并
	在程序结束前将num的记录值导入switch语句，进行运行结果的打印。*/

    if (num == 300)  //方程有两根的情况
    {
        if((b*b-4*a*c) >= 0)  //判别式大于零，有两实根
        num += 10;
        else                  //判别式小于零，有两复数根
        num += 20;

        if (num == 310)  //计算两实根
        {
            x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
            x2 = (-b-sqrt(b*b-4*a*c))/(2*a);

            if (x1 > x2) //比较大小，调整打印结果
            num += 1;
            else if (x1 < x2)
            num += 2;
            else if (x1 == x2)
            num += 3;
        }

        if (num == 320)  //计算两复数根
        {
            real = (-b)/(2*a);                     //实部
            imag_abs = sqrt(-(b*b-4*a*c))/(2*a);   //虚部

            if (real != 0)  //判断实部情况，调整打印结果
            num += 1;
            else
            num += 2;
        }
    }

    if (num == 400)  //方程有一根的情况
        x1=x2= (-c)/b;

    switch(num)  //判断num的值，打印相应的结果语句。
    {
    case 100 : printf("Zero Equation");break;
    case 200 : printf("Not An Equation");break;    
    case 311 : printf("%.2f\n%.2f",x1,x2);break;
    case 312 : printf("%.2f\n%.2f",x2,x1);break;
    case 313 : printf("%.2f",x1);break;
    case 321 : printf("%.2f+%.2fi\n%.2f-%.2fi",real,imag_abs,real,imag_abs);break;
    case 322 : printf("0.00+%.2fi\n0.00-%.2fi",imag_abs,imag_abs);break;
    case 400 : printf("%.2f",x1);break;
    default  : printf("error : num == %d",num);
    }
    /*
    输出格式:
    1.0)如果系数都为0，则输出"Zero Equation"；
    2.0)如果a和b为0，c不为0，则输出"Not An Equation"。
    3.1)如果方程有两个不相等的实数根，则每行输出一个根，先大后小；
    3.2)如果方程有两个不相等复数根，则每行按照格式“实部+虚部i”输出一个根，先输出虚部为正的，后输出虚部为负的；
    4.0)如果方程只有一个根，则直接输出此根；
	*/
	
    return 0;
}

    /*
    附录：
    输入样例1:
    2.1 8.9 3.5
    输出样例1:
    -0.44
    -3.80
    输入样例2:
    1 2 3
    输出样例2:
    -1.00+1.41i
    -1.00-1.41i
    输入样例3:
    0 2 4
    输出样例3:
    -2.00
    输入样例4:
    0 0 0
    输出样例4:
    Zero Equation
    输入样例5:
    0 0 1
    输出样例5:
    Not An Equation
    */