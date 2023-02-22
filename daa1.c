`#include <stdio.h>
#include <math.h>

double func1(int i){
    return pow(2,i);
    }

int func2(int n){
    return n;
}

double  func3(double n){
    return log2(n);
}

double func4(double n){
    return n*log(n);
}

double func5(double n){
    double a = log2(n);
    return sqrt(a);
}

double func6(int n){
    return round(pow((3.0/2.0),n));
}

int func7(int n){
    return pow(n,3);
}

double func8(double n) {
    return round(pow(2, log2(n)));
}

double func9(int n){
    return n*(pow(2,n));
}

double func10(int n){
    return log2(log2(n));
}

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main()
{
    printf("Input  ||  FUNCTION 1(n)\t || \tFUNCTION 2(2^n)\t \t ||\t \tFUNCTION3(log2(n)) ||\t \tFUNCTION4(n*log(n))  ||\t\t\tFUNCTION5(Sqr(log(n)))\n");
    for(int j=0; j <= 100; j++){
        printf("n=%d\t\t",j);

        //1st function call [n]
        int f2= func2(j);
        printf("%d",f2);

        //2nd function call [2^n]
        double result = func1(j);
        printf("\t\t\t\t");
        printf(" %.1f",result);

        //3rd function call [log2(n)]
        double l1 = (double) j;
        double lg = func3(l1);
        printf("\t\t\t\t");
        printf("%lf",lg);

        //4th function call [n*log(n)]
        double lg2 = func4(j);
        printf("\t\t\t\t");
        printf("%lf",lg2);

        //5th function call [Sqr(log(n))]
        double sqr = func5(j);
        printf("\t\t\t\t");
        printf(" %lf \n",sqr);

    }
printf("\n");
printf("Input  ||\tFUNCTION6((3/2)^n)  ||\tFUNCTION7(n^3)  ||\tFUNCTION8(2^log2(n))  ||\tFUNCTION9(n*2^n)  ||\tFUNCTION10(log2(log2(n)))\n");
printf("\n");
        for(int i=0; i <= 100; i++){

        printf("n=%d\t\t",i);

//6th function call [(3/2)^n]
         double fun6 = func6(i);
        printf(" %.1lf ",fun6);

//7th function call [n^3]
        printf("\t\t\t  %d",func7(i));

//8th function call [2^log(n)]
        double fun8 = func8(i);
        printf("\t\t \t\t%.2f",fun8);

//9th function call [n*2^n]
        double fun9 = func9(i);
        printf("\t\t \t\t%.1lf",fun9);

//10th function call [log2(log2n)]
        double fun10 = func10(i);
        printf("\t\t \t\t%lf\n",fun10);
        }

//11th function call [n!]
printf("INPUT\t\tFUNCTION11(n!)");
for (int k = 0; k <= 20; k++)
{
    printf("n=%d\n",k);

        double fun11 = factorial(k);
        printf("\t\t \t\t%lf\n",fun11);
        }
    return 0;
}
