#include <bits/stdc++.h>
#define f(x) 0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x //y =f(x)
#define true_value 1.640533
using namespace std;

void solve(int n){
    float a,b,h;
    a=0;
    b=0.8;
    h=(b-a)/n;//interval of x
    float x[n+2],y[n+2];
    x[0] = 0;
    y[0] = 0.2;
    int i=1;
    while(i<=n){
        x[i]=x[i-1]+h;
        y[i]=f(x[i]);
        i++;
    }
    float sum1 = y[0]+y[n];
    float sum2 = 0;
    for(int i=0;i<=n;i++){
        //printf("x%d = %.4f\t y%d = %.4f\n",i,x[i],i,y[i]);
        sum2+=y[i];
    }
    sum2-=sum1;
    float result = h/2*(sum1+2*sum2);// approximate value
    float E_t = ((true_value - result)*100)/true_value;
    float E_a = ((60/12)*(0.8*0.8*0.8)/(n*n))*100;
    printf("n=%d\t h=%.6f\t  I_n = %.6f\t E_a = %.4f",n,h,result,E_a);
    cout<<"%\t  ";
    printf("E_t = %.2f",E_t);
    cout<<"%\n";
    return;
}


int main()
{
    int n;
    int arr[6]={2,5,10,20,50,100};
    for(int i=0;i<6;i++){
        solve(arr[i]);
    }

    return 0;
}

