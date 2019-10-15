#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include <math.h>

int main()
{
    Pilha* p = criar_pilha(10);
    while (1)
    {
        char x[120];
        scanf("%s", x);
        if( strcmp(x ,"*") == 0 ) {
            //times
            double num1 = pop(p);
            double num2 = pop(p);
            double result = num1* num2;
            push(p, result);
            printf("resultado é %f\n", result);

        }
        else if( strcmp(x ,"/") == 0) {
            //divide
            double num1 = pop(p);
            double num2 = pop(p);
            double result = num2/num1;
            push(p, result);
            printf("resultado é %f\n", result);

        }
        else if( strcmp(x ,"+") == 0 ) {
            //sum
            double num1 = pop(p);
            double num2 = pop(p);
            double result = num1+num2;
            push(p, result);
            printf("resultado é %f\n", result);
        }
        else if( strcmp(x ,"-") == 0) {
            //minus 
            double num1 = pop(p);
            double num2 = pop(p);
            double result = num1-num2;
            push(p, result);
            printf("resultado é %f\n", result);
        }
        else if(strcmp(x ,"log") == 0) {
            double num1 = pop(p);
            double result = log2(num1);
            push(p, num1);
            printf("resultado é %f\n", result);
        }

        else if( strcmp(x ,"raiz") == 0) {
            double num = pop(p);
            double result = sqrt(num);
            push(p, result);
            printf("resultado é %f\n", result);
            
        }
        else if( strcmp(x ,"exp") == 0) {
            double num1 = pop(p);
            double num2 = pop(p);
            double result = pow(num2, num1);
            push( p, result);
            printf("resultado é %f\n", result);

        }
        else
        {
            double converted = atof(x);
            if(converted != 0) {
                push(p, converted);
            }
        }
    }
    


   return 0;
}
