#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char name[25];
   char nationality[25];
   int birth_year;
   float net_worth;
} Person ;

int number;

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

int main(){
    menu();
    int num_choice;
    char char_choice;
    Person *plist = (Person *) malloc(1 * sizeof(Person));
    do{
        printf("Enter a number: ");
        scanf(" %d", &num_choice);    
        if(num_choice == 7) return 2;
        if( 1 >= num_choice <= 6 ) processNumChoice(plist, num_choice);
        else continue;
        do{
            choice();
            scanf(" %c", &char_choice);
            if(char_choice == 'y' || char_choice == 'Y') {
                menu();
                break;
            }
            else if(char_choice == 'c' || char_choice == 'C') {
                system("@cls");
                menu();
                break;
            }
            else if(char_choice == 'n' || char_choice == 'N') {
                data(plist);
                return 3;
            }
            else printf("\nEnter your choice again!\n");
        }while(1);
    }while(1);
    free(plist);
    return 0;
}

void input_data(Person *plist){
    int i;
    do{
        printf("Enter number of people: ");
        scanf(" %d", &number);
    }while(number < 0);
    plist = realloc(plist, number * sizeof(Person));
    for(i = 0; i < number; i++){
        printf("Enter person %d: \n", i + 1);
        printf("Name: ");
        scanf(" %24[^\n]%*c", plist[i].name);
        printf("Nationality: ");
        scanf(" %24[^\n]%*c", &plist[i].nationality);
        do{
            printf("Birth year: ");
            scanf(" %d", &plist[i].birth_year);
            if( (2021 - plist[i].birth_year ) < 30) printf("You must enter age more than or equal to 30!\n");
            else break;
        }while(1);
        do{
            printf("Net worth: ");
            scanf(" %f", &plist[i].net_worth);
            if ( plist[i].net_worth < 1 || plist[i].net_worth > 100 ) printf("You must enter a value between 100!\n");
            else break;
        }while(1);
    }
}

void sort_data(Person *plist){
    int arr_sort[number];
    int i, j, temp;
    for(i = 0; i < number; i++){
        arr_sort[i] = i;
    }
    for(i = 0; i < number - 1; i++){
        for(j = i + 1; j < number; j++){
            if( plist[arr_sort[i]].net_worth < plist[arr_sort[j]].net_worth ){
                temp = arr_sort[i];
                arr_sort[i] = arr_sort[j];
                arr_sort[j] = temp; 
            }
        }
    }
    printf("Sort: \n");
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

void analyze_data(Person *plist){
    int arr_analyze[number];
    int i, j;
    int count = 1;
    for(i = 0; i < number; i++){
        arr_analyze[i] = 1;
    }
    for(i = 0; i < number; i++){
        if( arr_analyze[i] ){
            for(j = i + 1; j < number; j++){
                if( strcmp( plist[i].nationality, plist[j].nationality ) == 0){
                    arr_analyze[j] = 0;
                    count++;
                }
            }
            printf("There are %d person(s) from '%s'. \n", count, plist[i].nationality);
            count = 1;
        }
    }    
}

void find_data(Person *plist){
    float min_networth;
    int i, ret;
    char find_nationality[25];
    printf("Enter nationality you want to check: ");
    scanf(" %24[^\n]%*c", &find_nationality);
    do{
        printf("Enter the min net worth: ");
        scanf(" %f", &min_networth);
        if( min_networth > 100 || min_networth < 1 ) printf("You must enter a value between 1 and 100!\n");
        else break;
    }while(1);
    printf("Result: \n");
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

void save_data(Person *plist){
    char file_name[256];
    int i;
    printf("Enter file name you want to save: ");
    scanf(" %255[^\n]%*c", &file_name);
    FILE *fw = NULL;
    fw = fopen(file_name, "wb");
    if( !fw ){
        printf("Can not save file!");
    } else{
        for(i = 0; i < number; i++){
            fwrite(plist + i, sizeof(Person), 1, fw);
        }
        printf("Save succeeded!\n");
    }
    fclose(fw);
}

void open_data(){
    char file_name[256];
    int i;
    printf("Enter file name you want to open: ");
    scanf(" %255[^\n]%*c", &file_name);
    FILE *fr = NULL;
    fr = fopen(file_name, "rb");
    if( !fr ){
        printf("Can not open file!\n");
    } else{
        Person *pdata = (Person *) malloc(number * sizeof(Person));
        for(i = 0; i < number; i++){
            fread(pdata + i, sizeof(Person), 1, fr);
        }
        data(pdata);
        free(pdata);
        fclose(fr);
    }
}

void menu(){
    printf("+------------------------------------------------------------------+\n");
    printf("|             BILLIONAIRES PROFILE MANAGEMENT PROGRAM              |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("|1. Input |2. Sort |3. Analyze |4. Find |5. Save |6. Open |7. Exit |\n");
    printf("+------------------------------------------------------------------+\n");
}

void choice(){
    printf("Do you want to continue?\n");
    printf("- Yes, I do. (press 'y' or 'Y')\n");
    printf("- No, I don't. (press 'n or 'N')\n");
    printf("- Please clear the screen ! (press 'c' or 'C')\n");
    printf("Your choice: ");
}

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

void processNumChoice(Person *plist,int num_choice){
    if (num_choice == 1) input_data(plist);
    if (num_choice == 2) sort_data(plist);
    if (num_choice == 3) analyze_data(plist);
    if (num_choice == 4) find_data(plist);
    if (num_choice == 5) save_data(plist);
    if (num_choice == 6) open_data();
}