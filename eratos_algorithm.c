/* Eratos algorithm check the number entered is a prime or not */
#include <stdio.h>
#define NUMBER 1000 /* You can change another value, maybe more than or less than */

void eratos(int, int *); /* Prototype */

int main()
{   
    int i, number;
    int cache[NUMBER]; /* Cache array save elements are prime number */
    cache[0] = 0; /* 0 and 1 are not prime number */
    cache[1] = 0;
    for(i = 2; i < NUMBER; i++) /* Assign index array from 2 to 1000 with 1 */
    {
        cache[i] = 1;            
    }
    int *p = cache[0];
    int jump = 2;
    eratos(jump, p); /* Call function */
    /* Enter number still more than 1000 */
    do
    {
        printf("Enter a number: ");
        scanf(" %d", &number);
        if( cache[number] ) printf("%d is a prime number", number); /* If an element in cache contain 1, the number is a prime */
        else printf("%d is not a prime number!", number); /* If not, the number is not a prim */
    }while(number <= NUMBER);
    return 0;
}

void eratos(int jump, int *p)
{
    int i;
    /* If not a prime, continue */
    if( *(p + jump) == 1 )
    {     
        for(i = jump + jump; i < NUMBER; i += jump){
            *(p + i) = 0; /* Any multiples of a prime are not prime number */
        }
    }
    if(jump <= NUMBER) eratos(jump + 1, p);   
} 
