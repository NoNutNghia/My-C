/*So we know addition intergers a and b just a + b, but if a or b, maybe both of them is very large? (overwrite datatype long long unsigned integer)
My programing maybe fix it */

#include <stdio.h>

int main()
{
    int number1, number2;
    printf("Enter the number of digits 1: ");
    scanf(" %d", &number1);
    printf("Enter the number of digits 2: ");
    scanf(" %d", &number2);
    int i;
    int num_array1[number1];
    int num_array2[number2];
    int *sum_array = (int *) malloc(1 * sizeof(int));
    if(number1 > number2) sum_array = realloc(sum_array, number1 * sizeof(int));
    else sum_array = realloc(sum_array, number2 * sizeof(int));
    printf("Enter the first number 1: ");
    for(i = 0; i < number1; i++){
        scanf(" %d", &num_array1[i]);
    }
    printf("Enter the first number 2: ");
    for(i = 0; i < number2; i++){
        scanf(" %d", &num_array2[i]);
    }
    int delta;
    if(number1 > number2) delta = number1 - number2;
    else delta = number2 - number1;
    int remider = 0, temp;
    for(i = number1 - 1; i >= 0; i--){
        temp = num_array1[i] + num_array2[i] + remider;
        if(temp >= 10){ 
            temp -= 10;
            remider = 1;
            *(sum_array + i) = temp;
        } else{
            *(sum_array + i) = temp;
            remider = 0;
        }
    }
    *(sum_array + delta) = num_array2[delta] + remider;
    for(i = delta - 1; i >= 0; i++){
        *(sum_array + i) = num_array2[i];
    }
    printf("Result: \n");
    for(i = 0; i < number2; i++){
        printf(" %d ", *(sum_array + i));
    }
    free(sum_array);
    return 0;
}