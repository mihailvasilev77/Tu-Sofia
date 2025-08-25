#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func1(){
    printf("----------\n-        -\n-        -\n-        -\n----------\n");
    return 0;
}

int func2(){
    float inch = 0;

    printf("Enter length in inches: ");
    scanf("%f",&inch);

    printf("Inch is %fmm, %fcm, %fdm, %fm\n",inch*25.4,inch*2.54,inch*0.254,inch*0.0254);

    return 0;
}

int func3(){
    float inch = 0;

    printf("Enter temp in C: ");
    scanf("%f",&inch);

    printf("Temp in Kelvin: %f\n",(inch*9/5+32));

    return 0;
}

int func4(){
    float inch = 0;

    printf("Enter grad: ");
    scanf("%f",&inch);

    printf("Grad in rad: %f\n",(inch*3.14/180));

    return 0;
}

int func5(){
    float inch = 0;

    printf("Enter levs: ");
    scanf("%f",&inch);

    printf("Lev is: %f$, %f£, %fE\n",inch*1.87,inch*2.36,inch*1.96);

    return 0;
}

int func6(){
    float a = 0,b = 0, h = 0;

    printf("Enter a,b,h:");
    scanf("%f %f %f",&a,&b,&h);

    printf("Area is: %f\n",((a+b)*h/2));

    return 0;
}

int func7(){
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    printf("Enter x1 and y1:");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 and y2:");
    scanf("%f %f", &x2, &y2);

    printf("Area of the triangle: %f\n", (fabs(x2-x1)*fabs(y2-y1)));

    return 0;
}

int func8(){
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

    printf("Enter x1 and y1:");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 and y2:");
    scanf("%f %f", &x2, &y2);

    printf("Enter x3 and y3:");
    scanf("%f %f", &x3, &y3);

    printf("Area of the triangle: %f\n", 0.5*(fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))));

    return 0;
}

int func9(){
    float w = 0, h = 0;
    float w_space_area = 0.7;
    float h_space_area = 1.2;
    float hall = 1;

    printf("Enter w and h:");
    scanf("%f %f", &w, &h);

    printf("Spaces available:%.f\n", (((w-1)/w_space_area)*(((h-1)/h_space_area)))-3);

    return 0;
}

int func10(){
    float N = 0;
    float M = 0;
    int kgN = 0;
    int kgM = 0;

    scanf("%f %f %d %d", &N, &M, &kgN, &kgM);

    printf("Oborot: %f", (N*kgN+M*kgM)*1.95);

    return 0;
}

int func11(){
    float N = 0,W = 0,L = 0,M = 0,O = 0;
    float time = 0.2;

    scanf("%f %f %f %f %f %f",&N,&W,&L,&M,&O,&time);

    float area = N*N;
    float tile = W*L;
    float bench = O*M;

    float tiles = (area-bench)/tile;

    printf("Needed tiles: %f for %fm", tiles, tiles*time);

    return 0;
}

int func12(){
    float N = 0, M = 0, course = 0;
    scanf("%f %f %f",&N,&M,&course);

    float salary = N*M;
    float bonus = salary*2.5;
    float yearly = 12*salary + bonus;
    float income = (yearly - 25.0/100*yearly)/365;

    printf("Yearly income in bgn %f", income*course);

    return 0;
}

int func13(){
    float a = 0, b = 0;

    scanf("%f %f",&a,&b);

    printf("%f",(a+b-sqrt(a*a+b*b)/2));

    return 0;
}

int func14(){
    float a = 0, b = 0, w = 0;
    scanf("%f %f %f",&a,&b,&w);
    
    float pool_area = a*b;
    float whole_area = (a+w)*(b+w);
    float path_area = whole_area-pool_area;

    printf("Area of path %f", path_area);

    return 0;
}

int func15(){
    int S;
    printf("Enter sum S: ");
    scanf("%d", &S);

    int count_10 = S / 10; 
    S = S % 10;

    int count_5 = S / 5;
    S = S % 5; 

    int count_2 = S / 2; 
    S = S % 2;

    int count_1 = S;

    printf("Minimal amount of coins:\n");
    printf("Coins of 10 leva: %d\n", count_10);
    printf("Coins of 5 leva: %d\n", count_5);
    printf("Coins of 2 leva: %d\n", count_2);
    printf("Coins of 1 lev: %d\n", count_1);

    return 0;
}

int func16(){
    float L = 0, x = 0;
    scanf("%f %f",&L,&x);

    printf("%f",L/x);
    
    return 0;
}

int main(){
    //func1();
    //func2();
    func9();
    return 0;
}