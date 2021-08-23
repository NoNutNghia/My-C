/*So we know addition intergers a and b just a + b, but if a or b, maybe both of them is very large? (overwrite datatype long long unsigned integer)
My programing maybe fix it */

#include <stdio.h>
#include <stdlib.h>

void addition(int *, int, int, int[], int[]);

int main(){
    int number1, number2;
    int i;  
    printf("Enter the number of digits 1: ");
    scanf(" %d", &number1);
    printf("Enter the number of digits 2: ");
    scanf(" %d", &number2);
    int num_array1[number1];
    int num_array2[number2];
    printf("Enter the first number 1: ");
    for(i = 0; i < number1; i++){
        scanf(" %d", &num_array1[i]);
    }
    printf("Enter the second number 2: ");
    for(i = 0; i < number2; i++){
        scanf(" %d", &num_array2[i]);
    }
    int *sum_array; 
    sum_array = (int *) malloc(1 * sizeof(int));
    if(number1 >= number2) addition(sum_array, number1, number2, num_array1, num_array2);
    else addition(sum_array, number2, number1, num_array2, num_array1 );
    free(sum_array);
    return 0;
}

void addition(int *sum_array, int number1, int number2, int *num_arr1, int *num_arr2){  
    sum_array = (int *) realloc(sum_array, number1 * sizeof(int)); 
    int delta;
    int remider = 0, temp;
    int i; 
    delta = number1 - number2;
    for(i = number2 - 1; i >= 0; i--){
        temp = num_arr2[i] + num_arr1[i + delta] + remider;
        if(temp >= 10){ 
            temp -= 10;
            remider = 1;
            *(sum_array + i) = temp;
        } else{
            *(sum_array + i) = temp;
            remider = 0;
        }
    }
    *(sum_array + delta) = num_arr1[delta] + remider;
    for(i = delta - 1; i >= 0; i++){
        *(sum_array + i) = num_arr1[i];
    }
    printf("Result: \n");
    for(i = 0; i < number1; i++){
        printf(" %d ", *(sum_array + i));
    }
}