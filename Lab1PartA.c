/*Retrouvailles Manishimwe(vvk160)
Lab1
CS 2124 Section A1T
Bernard Ku
June 28, 2021
*/
#include <stdio.h>
double power(double a, int n) {
    if( n == 0)//if the exponent is zero
       return 1;
    if (n%2 == 0)//whole
        return (power(a, n/2))*(power(a, n/2));
    else
    {
        if(n > 0)//positive
            return a*(power(a, n/2))*(power(a, n/2));
        else//negative
            return ((power(a, n/2))*(power(a, n/2)))/a;
    }
}
int main() {
    double a, result;
    int n;
    int i=0;
    while(i<3){//loop to allow 3 entries per run
        printf("Enter base ");
        scanf("%lf", &a);
        printf("Enter exponent ");
        scanf("%d", &n);
        result = power(a, n);
        printf("%0g raised to the %d = %0g", a, n, result);
        printf("\n");
        i++;
    }
    return 0;
    //could not find any other way to get rid of trailing zeros wihout using %0g
}


