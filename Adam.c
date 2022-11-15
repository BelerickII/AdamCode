#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getSteps(char _case[]){
    int steps = 0;
    for(int i =0; i < strlen(_case); i++){
        char currentChar = _case[i];
        if(currentChar == 'D'){
            break;
        }
        steps++;
    }
    return steps;
}

int main() {
    //declaring a pointer to link the file to my code
    FILE* fptr;
    char first_line[100]; // {'5'} -> 5
    char next_line[100];
    int no_of_cases; // = 5
    char all_cases[no_of_cases][100];
    

    fptr = fopen("Adam.in","r");

    //Program exits if the file pointer returns NULL
    if(fptr == NULL)
   {
      printf("Error! opening file");   
      exit(1);             
   }
     
    if (fgets(first_line, 100, fptr) != NULL) {
        no_of_cases = atoi(first_line);
    }

    printf("No of cases: %d\n\n", no_of_cases);

    int counter = 0;
   
    while (fgets(next_line, 100, fptr) !=NULL) {
        // Storing each cases into all_cases array
        strcpy(all_cases[counter], next_line);

        // printf("Current case: %s\n", next_line);
        counter++;
    }

    for (int i = 0; i < no_of_cases; i++){
        int steps = getSteps(all_cases[i]);

        printf("\nCase %d is %s and no of steps is %d\n", i+1, all_cases[i], steps);
    }

    fclose(fptr);
    
    return 0;
}