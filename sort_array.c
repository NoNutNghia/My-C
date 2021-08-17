/* Sort array but do not change the value of element in array */
#include <stdio.h>

int main(){
    int i, j, temp;
    int number;
    /* Enter number of array */
    do{
        printf("Enter number of array");
        scanf(" %d", &number);
    }while(number > 0); /* Loop still enter a positive */ 
    int arr[number];
    int arr_sort[number];
    /* Assign element of arr_sort equal to index */
    for(i = 0; i < number; i++)
    {
        arr_sort[i] = i;
    }
    /* Enter the value of element in array */
    for (i = 0; i < number; i++)
    {   
        printf("Enter number %d: ", i + 1);
        scanf(" %d", &arr[i]);
    }
    /* Sort arr_sort, not original array */     
    for(i = 0; i < number - 1; i++)
    {
        for ( j = i + 1; j  < number; j++)
        {
            if(arr[arr_sort[i]] < arr[arr_sort[j]]) /* Sort index of element in array */
            {
                temp = arr_sort[i];
                arr_sort[i] = arr_sort[j];
                arr_sort[j] = temp;        
            }
        }
        
    }
    printf("Result after sort: "); /* Increase numberring */
    for(i = 0; i < number; i++)
    {
        printf(" %d ", arr[arr_sort[i]]);
    }
    /* Or you can print decrease numberring
    for(i = number - 1; i >= 0; i--) 
    {
        printf(" %d ", arr[arr_sort[i]]);
    }
    */
    return 0; /* Return value */

}
