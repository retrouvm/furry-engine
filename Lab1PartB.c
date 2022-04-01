/*Retrouvailles Manishimwe(vvk160)
Lab1
CS 2124 Section A1T
Bernard Ku
June 28, 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
double kthPowerIterative(double k);
double kthPowerRecursive(double k);
double kthNegativePower(double k);
int main()
{
    char ch;
    double trials;
    double k;
    do{
        printf("Enter number of trials: ");
        scanf("%lf",&trials);
        printf("\nEnter base: ");
        scanf("%lf", &k);
        clock_t begin;
        clock_t end;
        double time_spent1;
        double time_spent2;
        
        begin = clock();//timer for iterative function
        kthPowerIterative(k);
        end = clock();
        time_spent1 = (double)(end - begin) / CLOCKS_PER_SEC;
        
        begin = clock();//timer for recursive function
        kthPowerRecursive(k);
        end = clock();
        time_spent2 = (double)(end - begin) / CLOCKS_PER_SEC;
        
        printf("\nProcessing...\n");
        printf("***********************************************************************\n");
        printf("Trial runs: %0g\n", trials);
        printf("Base used: %0g\n", k);
        printf("Recursive time: %0g = %0g/call\n", time_spent2, time_spent2 / trials);
        printf("Iterative time: %0g = %0g/call\n", time_spent1, time_spent1 / trials);
        printf("***********************************************************************\n");
        double it1=fabs(time_spent1-time_spent2);//used fabs instead of abs so that the extremely small number wouldn't be turned into just 0
        double rec1=fabs(time_spent2-time_spent1);
        if(time_spent1 < time_spent2) //if statement to take into account the 5% of the time iterative is not more effective
        {
            printf("Iteration is more effective by %0g seconds\n", it1);          
        } 
        else if (time_spent2 < time_spent1)
        { 
            printf("Recursive is more effective by %0g seconds\n", rec1);  
        } 
        else 
        {
	        printf("Both are equally effective\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf("%c",&ch);
        scanf("%c",&ch);
        printf("\n");
    }
    while (ch == 'y');//wrote in a while loop to contnuously ask for more trials
}

double kthPowerIterative(double k){
   double product = 1;
   int neg;
   if(k < 0){
      neg = -1;
   }
   while(k != 0.0){
      product *= 2;
      if(k > 0){
         k--;
      }else{
         k++;
      }
   }
   if(neg < 0){
      return 1/product;
   }

   return product;
}

double kthPowerRecursive(double k){
    if(k == 0.0){
        return 1;
    }else if(k > 0){
        return 2 * kthPowerRecursive(k-1);
    }else{
        return 1/(kthNegativePower(k));
    }
}

double kthNegativePower(double k){//extra function to help recursive be able to process negative powers
   if(k == 0.0){
      return 1.0;
   }else{
      return 2 * kthNegativePower(k+1);
   }
}


