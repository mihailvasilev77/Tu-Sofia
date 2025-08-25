#include <stdio.h>
#include <stdlib.h>

int find_max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int find_min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int find_maxes(){
    int x;
    scanf("%d",&x);
    int max = x;
    int min = x;
    do
    {
        scanf("%d",&x);
        max = find_max(max,x);
        min = find_min(min,x);
        printf("%d",min);
        
    } while (x != 0);

    printf("Max:%d Min:%d\n", max, min);

    return 0;
    
}

int clock(int hours, int mins){
    mins = mins + 15;

    if(mins > 59){
        hours++;
    }
    
    if(mins < 10){
        printf("Time after 15 mins %d:0%d\n",hours%24, mins%60);
    }else{
        printf("Time after 15 mins %d:%d\n",hours%24, mins%60);
    }

    return 0;
}

int are_equal(int a, int b, int c){
    if(a == b && b == c){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}

int points(int point){
    float points = 0;
    if (point <= 100) {
        points += 5;
    }
    else if (point > 100) {
        points += 20.0/100*point;
    }
    else if (point > 1000) {
        points += 10.0/100*point;
    }

    if (point % 2 == 0) {
        points++;
    }

    if (point % 5 == 0) {
        points += 2;
    }

    printf("%f\n%.lf\n",points,point+points);

    return 0;
}

int sport(int a, int b, int c){
    int mins = 0;
    int temp = a + b + c;
    int secs = temp % 60;
    
    if(secs < 10){
        printf("%d:0%d\n",temp/60, secs);
    }else{
        printf("%d:%d\n",temp/60, secs);
    }

    return 0;
}

int is_in_triangle(){
    int x,y,x1,y1,x2,y2;
    printf("Enter point\n");
    scanf("%d %d", &x, &y);
    printf("Enter triangle\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter triangle\n");
    scanf("%d %d", &x2, &y2);

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        printf("Inside\n");
    else
        printf("Outside\n");

    return 0;
}

float taxi(int n, char mode){
    float taxi = 0.7;

    if(mode == 'D'){
        taxi += 0.79*n;
    }else if(mode == 'N'){
        taxi += 0.9*n;
    }

    return taxi;
}

float bus(int n, char mode){
    if(n < 20){
        return -1;
    }

    return n*0.09;
}

float train(int n, char mode){
    if(n < 100){
        return -1;
    }

    return n*0.06;
}

int transport(){
    int n;
    char mode;
    scanf("%d %c",&n, &mode);

    float t = taxi(n,mode);
    float b = bus(n,mode);
    float tr = train(n,mode);

    float min = t;
    
    if(min > b && b != -1){
        min = b;
    }
    if(min > t && t != -1){
        min = t;
    }

    return min;
}

int pool(){
    float vol, p1, p2, N;
    float water_level = (p1+p2)*N;
    
    if(water_level <= vol){
        printf("Pool is filled %fl.", water_level);
    }else{
        printf("For %.1lf hours the pool overflows with %.1lf liters.\n", N, water_level-vol);
    }

    return 0;
}

int garden(int X, int Y, int Z){
    float wine_area = 40.0/100*X;
    float kgs = wine_area;
    float l = 2.5 * kgs;

    if(l >= Z){
        printf("sufficient amount\n");
    }else{
        printf("unsufficient amount\n");
    }

    return 0;
}

int fortress(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n*2; j++){
            if(i == 0){
                if(j == 0){
                    printf("/");
                }
                else if(j == ((n*2)-1)){
                    printf("\\");
                }else{
                    prinf("^");
                }
            }else if(i == n){
                if(j == 0){
                    printf("/");
                }
                else if(j == ((n*2)-1)){
                    printf("\\");
                }else{
                    prinf("^");
                } 
            }
            
        }
    }

    return 0;
}

int zad10(){
    int n = 7 
    int arr[n] = {1, 1000, 23, 243, 231, 304, 102};
    int p1=0, p2=0, p3=0, p4=0, p5=0;
    for(int i=0; i<n; i++){
        if(arr[i] < 200){
            p1++;
        }else if(arr[i] > 200 && arr[i]>399){
            p2++:
        }else if(arr[i] > 400 && arr[i]>599){
            p2++:
        }else if(arr[i] > 600 && arr[i]>799){
            p2++:
        }else{
            p5++;
        }
    }

}




int main() {
    clock(23,59);
    points(175);
    sport(35,45,44);
    //transport();
    return 0;
}
