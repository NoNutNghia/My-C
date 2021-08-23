/*My final test C, so in this time i try hard and ready for the exam in Aptech */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
   char name[25];
   char nationality[25];
   int birth_year;
   float net_worth;
} Person ; /*Typedef a struct name Person */

int number;/*Use global variable to easily to use in function*/

/*Include prototype, all of these function will be used*/
void input_data(Person *); 
void sort_data(Person *);
void analyze_data(Person *);
void find_data(Person *);
void save_data(Person *);
void open_data();
void data(Person *);
void processNumChoice(Person *, int);
void menu();
void choice();

/*Function main*/
int main(){
    menu(); //The menu user can see and enter a number they want
    int num_choice; //The choice that user choose when run programing.
    char char_choice; //The choice that user choose when user completely did a option. 
    Person *plist = (Person *) malloc(1 * sizeof(Person)); //Use static dynamic, 1 memory left.
    do{
        printf("Enter a number: ");
        scanf(" %d", &num_choice);    
        if(num_choice == 7) return 2; //If enter 7, excute
        if( 1 >= num_choice <= 6 ) processNumChoice(plist, num_choice); // The conditional is true, user can continue.
        else continue; // If not, just enter again
        do{ //When user completely done, the next choice board includes
        /* Like enter number choice, conditional is true then do continue, if not, just enter again */
            choice();
            scanf(" %c", &char_choice);
            //If user enter 'y' or 'Y', the menu show again and break this loop
            if(char_choice == 'y' || char_choice == 'Y') { 
                menu();
                break;
            }
            //If user enter 'c' or 'C', the screen is cleared, the menu will show and break the loop
            else if(char_choice == 'c' || char_choice == 'C') { 
                system("@cls");
                menu();
                break;
            }    
            // If user enter 'c' or 'C', show data person(s) user entered en excute     
            else if(char_choice == 'n' || char_choice == 'N') {
                data(plist);
                return 3;
            }
            //Check conditional 
            else printf("\nEnter your choice again!\n");
        }while(1);
    }while(1);
    free(plist); //free memory
    return 0;
}
/*Enter person(s) data */
void input_data(Person *plist){
    int i;
    do{
        printf("Enter number of people: ");
        scanf(" %d", &number);
    }while(number < 0); //The loop check the amount of people that user entered is positive integer or not 
    plist = realloc(plist, number * sizeof(Person)); //Realloc, use memory equal to number entered
    for(i = 0; i < number; i++){
        printf("Enter person %d: \n", i + 1);
        printf("Name: "); 
        scanf(" %24[^\n]%*c", plist[i].name); //Enter name with c regex, till 24th character or '\n'
        printf("Nationality: ");
        scanf(" %24[^\n]%*c", &plist[i].nationality);//Enter nationality with c regex, till 24th character or '\n'
        do{
            printf("Birth year: ");
            scanf(" %d", &plist[i].birth_year);
            if( (2021 - plist[i].birth_year ) < 30) printf("You must enter age more than or equal to 30!\n");
            else break;
        }while(1);//If age < 30, user must enter again
        do{
            printf("Net worth: ");
            scanf(" %f", &plist[i].net_worth);
            if ( plist[i].net_worth < 1 || plist[i].net_worth > 100 ) printf("You must enter a value between 100!\n");
            else break;
        }while(1);//If net worth > 100 or net worth < 1, user must enter again
    }
}
/*Sort data person(s) with decrease net worth */
void sort_data(Person *plist){
    int arr_sort[number]; //Use a temp array, that contain index
    int i, j, temp;
    for(i = 0; i < number; i++){
        arr_sort[i] = i; //Assign each elements of temp array by index
    }
    for(i = 0; i < number - 1; i++){
        for(j = i + 1; j < number; j++){//Use sort array algorithm i have used in sort_array. You can see in git hub
            if( plist[arr_sort[i]].net_worth < plist[arr_sort[j]].net_worth ){ 
                temp = arr_sort[i];
                arr_sort[i] = arr_sort[j];
                arr_sort[j] = temp; 
            }
        }
    }
    printf("Sort: \n");//Print the result after sort
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|%-24s|%-24s|%-15s|%-24s|\n", "Person Name", "Nationality", "Birth Year", "Net Worth (billion $)");
    printf("+------------------------------------------------------------------------------------------+\n");
    for(i = 0; i < number; i++){
        printf("|%-24s|%-24s|%-15d|%-24.2f|\n", plist[arr_sort[i]].name,
                                              plist[arr_sort[i]].nationality,
                                              plist[arr_sort[i]].birth_year,
                                              plist[arr_sort[i]].net_worth);
        printf("+------------------------------------------------------------------------------------------+\n");
    }
}
/*Analyze how many people in nationality corresponding*/
void analyze_data(Person *plist){
    int arr_analyze[number];//Use another temp array
    int i, j;
    int count = 1;//Count the people in the same nation
    for(i = 0; i < number; i++){ //Assign all elements of temp array by 1
        arr_analyze[i] = 1;
    }
    for(i = 0; i < number; i++){
        if( arr_analyze[i] ){ //Check the value, if 1 then do, if 0 skip
            for(j = i + 1; j < number; j++){
                if( strcmp( plist[i].nationality, plist[j].nationality ) == 0){ //If in position i, nationality is same in j, assign this element by 0
                    arr_analyze[j] = 0;
                    count++;//Count plus 1
                }
            }
            //End of 1 loop, print the 1 result, not repeat result 
            printf("There are %d person(s) from '%s'. \n", count, plist[i].nationality);
            count = 1;
        }
    }    
}
/*Find and print all data person(s) if the conditional before is true*/
void find_data(Person *plist){
    float min_networth; // Enter a min net worth, all of person(s) have net worth more than is accept
    char find_nationality[25];// Enter nationality, all of person(s) from here is accept 
    int i, ret;
    printf("Enter nationality you want to check: ");
    scanf(" %24[^\n]%*c", &find_nationality); //Enter nationality with c regex
    do{
        printf("Enter the min net worth: ");
        scanf(" %f", &min_networth);
        if( min_networth > 100 || min_networth < 1 ) printf("You must enter a value between 1 and 100!\n");
        else break;
    }while(1);//Check same like user enter net worth in function input_data();
    printf("Result: \n"); // Print the result after find
    /*Note: If no data is found, the result we take just heading table*/
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|%-24s|%-24s|%-15s|%-24s|\n", "Person Name", "Nationality", "Birth Year", "Net Worth (billion $)");
    printf("+------------------------------------------------------------------------------------------+\n");
    for(i = 0; i < number; i++){
        ret = strcmp( plist[i].nationality, find_nationality);
        if(ret == 0){
            if( min_networth < plist[i].net_worth ){
                printf("|%-24s|%-24s|%-15d|%-24.2f|\n", plist[i].name,
                                              plist[i].nationality,
                                              plist[i].birth_year,
                                              plist[i].net_worth);
            printf("+------------------------------------------------------------------------------------------+\n");
            }
        }
    }
}

/* Save data person(s) entered in binary file */
void save_data(Person *plist){
    char file_name[256];
    int i;
    printf("Enter file name you want to save: ");
    scanf(" %255[^\n]%*c", &file_name);//Enter file name to write
    FILE *fw = NULL;
    fw = fopen(file_name, "wb"); //Open file in "wb", if not exist then create new
    if( !fw ){
        printf("Can not save file!"); //If can not open file, alert user end close file
    } else{
        for(i = 0; i < number; i++){
            fwrite(plist + i, sizeof(Person), 1, fw);//Write to file if open file successfull
        }
        printf("Save succeeded!\n");//Alert user save completely
    }
    fclose(fw);//Close file *very important*
}

/*Open a binary file to read data */
void open_data(){
    char file_name[256];
    int i;
    printf("Enter file name you want to open: ");
    scanf(" %255[^\n]%*c", &file_name);//Enter file name to read
    FILE *fr = NULL;
    fr = fopen(file_name, "rb"); //Open file in "rb"
    if( !fr ){
        printf("Can not open file!\n"); //If can not open file, alert user and close file
    } else{ 
        //If file opened, declare a pointer type Person and take memory equal to number, that user entered in input_data() 
        Person *pdata = (Person *) malloc(number * sizeof(Person)); 
        for(i = 0; i < number; i++){
            fread(pdata + i, sizeof(Person), 1, fr);//Read data from binary file 
        }
        data(pdata);//Show data on the screen
        free(pdata);//Free memory after used
        fclose(fr);//Close file
    }
}

// The menu choice
void menu(){ 
    printf("+------------------------------------------------------------------+\n");
    printf("|             BILLIONAIRES PROFILE MANAGEMENT PROGRAM              |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|1. Input |2. Sort |3. Analyze |4. Find |5. Save |6. Open |7. Exit |\n");
    printf("+------------------------------------------------------------------+\n");
}

// The board choice after an option is done
void choice(){
    printf("Do you want to continue?\n");
    printf("- Yes, I do. (press 'y' or 'Y')\n");
    printf("- No, I don't. (press 'n or 'N')\n");
    printf("- Please clear the screen ! (press 'c' or 'C')\n");
    printf("Your choice: ");
}

// Data user entered
void data(Person *plist){
    int i;
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|%-24s|%-24s|%-15s|%-24s|\n", "Person Name", "Nationality", "Birth Year", "Net Worth (billion $)");
    printf("+------------------------------------------------------------------------------------------+\n");
    for(i = 0; i < number; i++){
        printf("|%-24s|%-24s|%-15d|%-24.2f|\n", plist[i].name,
                                              plist[i].nationality,
                                              plist[i].birth_year,
                                              plist[i].net_worth);
        printf("+------------------------------------------------------------------------------------------+\n");
    }
}
/* With a number choice user enter, an option is performed*/ 
void processNumChoice(Person *plist,int num_choice){ 
    if (num_choice == 1) input_data(plist);
    if (num_choice == 2) sort_data(plist);
    if (num_choice == 3) analyze_data(plist);
    if (num_choice == 4) find_data(plist);
    if (num_choice == 5) save_data(plist);
    if (num_choice == 6) open_data();
}