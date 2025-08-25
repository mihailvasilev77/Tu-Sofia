#include <stdio.h>
#include <stdlib.h>


int func1(){
    int a = 20;
    int *v = &a;
    a=15;

    printf("Address: %p Value:%d\n",v,*v);

    return 0;
}

int func2(){
    int a = 15, b = 5;

    int *a1 = &a;
    int *b2 = &b;

    if(*b2 == 0){
        return -1;
    }

    printf("Sum:%d, Sub:%d, Mult:%d, Div:%d\n",*a1+*b2,*a1-*b2,*a1*(*b2),*a1/(*b2));
    
    return 0;
}

int square(int a,int b){
    return a*b;
}

float circle(int r){
    return r*r*3.14;
}

int func3(){
    int n,a,b;
    float area;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        scanf("%d %d",&a,&b);
        area = square(a,b);
        printf("Area of rectangle:");
        break;
    case 2:
        scanf("%d",&a);
        area = square(a,a);
        printf("Area of square:");
        break;
    case 3:
        scanf("%d %d",&a,&b);
        area = square(a,b)/2;
        printf("Area of square triangle:");
        break;
    case 4:
        scanf("%d",&a);
        area = circle(a);
        printf("Area of circle:");
        break;
    
    default:
        break;
    }

    printf("%f\n",area);

    return 0;
}

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void swap2(int *a, int *b){
    int temp = *a;
    *a = *b ;
    *b = temp;
}

int is_even(int a){
    if(a%2 == 0){
        return 1;
    }

    return 0;
}

int dec_to_bin(int n){
    int remainder;
    while(n != 0){
        remainder = n % 2;
        n = n/2;

        printf("%d", remainder);
    }

    return 0;
}

int main() {
    printf("%d",dec_to_bin(5));
    return 0;
}
