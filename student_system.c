#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
void print_lessons(size_t size,char *lessons[size]);
void print_lessons_notes(size_t size, int *lessons[size],char *lessons_char[]);
double thirty_percent(double x);
double fourty_percent(double x);
double lesson_gpa(int arr[]);
double gpa(int arr[],int size);



int main(int argc, char const *argv[]){
    char username[50];
    int password,choice,i,j;
    int math[3] = {100,70,55},
        algeb[3] = {10,95,50},
        prog[3] = {45,80,90},
        phy[3] = {50,60,40};
    int *les_write[] = {math,algeb,prog,phy};
    int **mPtr = les_write;
    char *lessons[] = {"Maths      ", "Algebra    ", "Programming", "Physics    "};
    printf("Enter your username : ");
    scanf("%s",username);
    printf("Enter your password : ");
    scanf("%d",&password);
        
    if(strcmp(username,"ery") == 0 && password == 123){
        printf("Login succesful.\n");
        while(1){
            printf("\n------------------Select Your Process------------------\n1-Lessons\n2-Lessons Notes\n3-Calculate GPA\n4-Exit\nChoice : ");
            scanf("%d",&choice);
            switch (choice){
            case 1:
                puts("");
                print_lessons(4,lessons);
                break;
            case 2:
                puts("");
                printf("\t\t");
                print_lessons_notes(4,les_write,lessons);
                break;
            case 3:
                double result_gpa = 0;
                puts("");
                printf("\n\t     CGPA\n");
                for(i=0 ; i<4 ; i++){
                    printf("%s :%.2lf\n",lessons[i],lesson_gpa(les_write[i]));
                }for(i=0 ; i<4; i++){
                    result_gpa += lesson_gpa(les_write[i]);
                }result_gpa = result_gpa/4;
                printf("\nGPA     :%lf\n",result_gpa);
                break;
            case 4:
                printf("Exiting...\n");
                exit++;
                break;   
            default:
                printf("Invalid value.\nExiting...\n");
                exit++;
                break;
            }
        }
    }else{
        printf("Wrong username or password.\nExiting...\n");
    }
return 0;
}

void print_lessons(size_t size,char *lessons[size]){
    char *char_ptr = NULL;
    int i;
    /*for ( i = 0; i < size; i++){   //shortest way
        printf("%d - %s\n",i+1,lessons[i]);
    }*/
    
    for(i=0 ; i<size ; i++){
        char_ptr = *(lessons+i);
        printf("%d - ",i+1);
        while(*char_ptr != '\0'){
            printf("%c",*char_ptr);
            char_ptr++;
        }printf("\n");
    }
}
void print_lessons_notes(size_t size, int *lessons[size], char *lessons_char[]){
    int i,j;
    int **mPtr = lessons;
    for(i=1 ; i<size ; i++){
        printf("Note %d    ",i);
    }puts("");
    for(i=0 ; i<size ; i++){
        printf("%s     ",lessons_char[i]);
        for(j=0 ; j<size-1 ; j++){
            printf(" %6d",*(*(mPtr+i)+j));
        }puts("");
    }
    
}
double thirty_percent(double x){
    return x*30/100;
}
double fourty_percent(double x){
    return x*40/100;
}
double lesson_gpa(int arr[]){
    double result = thirty_percent(arr[0]) + thirty_percent(arr[1]) + fourty_percent(arr[2]);
    return result;
}
