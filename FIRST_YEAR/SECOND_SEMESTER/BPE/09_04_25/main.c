#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLASS_SIZE 3

typedef struct Point{
    float x;
    float y;
}point;

typedef struct Triangle{
    point points[3];
    float A;
    float B;
    float C;
}triangle;

int find_side(point p1, point p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

typedef struct Vehicle{
    float hp;
    char brand[255];
    char model[255];
    float weight;
    char plate[8];
}vehicle;

typedef struct Car{
    vehicle c1;
    float enginge;
    char fuel[10];
}car;

typedef struct Airplane{
    vehicle p1;
    float res;
}airplane;

typedef struct Boat{
    vehicle b1;
    float maxspeed;
}boat;

typedef struct Student{
    char firstName[10];
    char lastName[10];
    int id;
    float gda;
}student;

typedef struct Vipusk{
    student students[CLASS_SIZE*2];
    float gda[2];
}vipusk;

float calc_gda(int size,student students[]){
    if(size == 0){
        return 0;
    }

    float sum = 0;
    for(int i = 0; i < size; i++){
        sum += students[i].gda;
    }

    return sum/size;
}

int main() {
    triangle one ={{{0,0},{0,50},{25,20}}};
    one.A = find_side(one.points[0],one.points[1]);
    one.B = find_side(one.points[1],one.points[2]);
    one.C = find_side(one.points[0],one.points[2]);

    printf("Side A:%.2f\nSide B:%.2f\nSide C:%.2f\n",one.A, one.B, one.C);

    student groupA[CLASS_SIZE] = {{"Mihail","Vasilev",1,6},{"Stefcho","Vasilev",2,5.6},{"Ivo","Vasilev",3,3.6}};
    student groupB[CLASS_SIZE] = {{"Kircho","Vasilev",1,6},{"Stivun","Vasilev",2,4.4},{"Hasan","Vasilev",3,3.1}};

    float groupAavg = calc_gda(CLASS_SIZE,groupA);
    float groupBavg = calc_gda(CLASS_SIZE,groupB);

    printf("Class A avg:%f\nClass B avg:%f\n",groupAavg,groupBavg);

    vipusk dvaispeta = {{groupA,groupB},{groupAavg,groupBavg}};

    float vipAvg = (groupAavg + groupBavg) / 2;

    printf("Vipusk avg:%f\n",vipAvg);

    return 0;
}
