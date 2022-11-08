#include<stdio.h>
#include<stddef.h>
#include<string.h>
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
double gpa(int arr[],int size){
    int i;
    double result=0;
    for(i=0 ; i<size ; i++){
        result += lesson_gpa(arr[i]);
    }return result;
}
int main(int argc, char const *argv[]){
    //math algeb prog phy
    int math[3] = {100,70,55},
        algeb[3] = {19,37,61},
        prog[3] = {45,80,90},
        phy[3] = {50,60,40},i,j;
    int *lessons[] = {math,algeb,prog,phy};
    int **mPtr = lessons;
    char *lessonsCh[] = {"Maths      ", "Algebra    ", "Programming", "Physics    "};
    //printf("%lf",lesson_gpa(algeb));
    printf("\n\t     CGPA\n");
    for(i=0 ; i<4 ; i++){
        printf("%s :%.2lf\n",lessonsCh[i],lesson_gpa(lessons[i]));
    }printf("GPA     :%lf\n",gpa(lessons,4));
    
    
    
    /*printf("\t\t");
    for(i=1 ; i<4 ; i++){
        printf("Note %d    ",i);
    }puts("");
    for(i=0 ; i<4 ; i++){
        printf("%s     ",lessonsCh[i]);
        for(j=0 ; j<3 ; j++){
            printf(" %6d",*(*(mPtr+i)+j));
        }puts("");
    }*/
    /*printf("%d\n",*(*(mPtr+1)));
    printf("%d\n",*(*(mPtr+1)+1));
    printf("%d\n",*(*(mPtr+1)+2));*/
    return 0;
}
