#include <bits/stdc++.h>
#define f(x) 0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x //y =f(x)
#define f2(x) -400+6*675*x-12*900*x*x+20*400*x*x*x
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
    float even = 0;
    float odd = 0;
    for(int i=1;i<n;i++){
        if(i%2) odd+=y[i];
        else even+=y[i];
    }
    float result = h/3*(sum1+4*odd+2*even);// approximate value
    float E_t = abs((true_value - result)*100)/true_value;
    float E_a = abs((2400/180)*(0.8*0.8*0.8*0.8*0.8)/(n*n*n*n))*100;
    printf("n=%d\t h=%.6f\t  I_n = %.6f\t E_a = %.4f",n,h,result,E_a);
    cout<<"%\t  ";
    printf("E_t = %.4f",E_t);
    cout<<"%\n";
    return;
}


int main()
{
    int arr[3]={4,10,20};
    for(int i=0;i<3;i++){
        solve(arr[i]);
    }

    return 0;
}


