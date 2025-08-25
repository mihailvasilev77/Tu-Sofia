#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

float rect_area(float a,float b){
    return a*b;
}

float circle_perim(float d){
    return 3.14*d;
}

void convert_time(int seconds){
    //sek -> minuti -> chasove
    int hours = seconds / 3600;
    int mins = (seconds-(hours/3600))/3600;
    int secs = (seconds-mins/60)/3600;
    printf("%d hours %d minutes %d seconds", hours,mins,secs);
}

int main(){
    char fname[20];
    char lname[20];
    char fak[20];
    int fnum;
    /*
    scanf("%s", fname);
    scanf("%s", lname);
    scanf("%s", fak);
    scanf("%d", &fnum);

    printf("First name:%s Second name:%s Fak:%s FNum:%d\n", fname, lname, fak, fnum);
    */

    float a = 10, b  = 2, d = 5;
    float area = rect_area(a,b);
    float per = circle_perim(d);

    printf("The area of the rectangle (Sides:%.2f %.2f) is %.2f sq units\n", a,b,area);
    printf("The perimeter of the circle (Diameter:%.2f) is %.2f sq units\n", d,per);

    int num = 456;
    int n = num / 100;
    int u = num / 10 % 10;
    int m = num % 10;
    printf("%d\n%d \n%d\n%d\n", num,n,u,m);

    int seconds = 0;
    scanf("%d", &seconds);
    convert_time(seconds);

    return 0;
}