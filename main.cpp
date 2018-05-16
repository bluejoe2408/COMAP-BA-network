#define MAXSIZE 1000
#define INITPOINT 3
#define M 10

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int initpoint[INITPOINT] = {0, 1, 2};
int a[MAXSIZE][MAXSIZE];
int degree[MAXSIZE];
double k[MAXSIZE];


void init()
{
    for(int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++) a[i][j] = 0;
    for(int i = 1; i < INITPOINT; i++) a[initpoint[0]][initpoint[i]] =  a[initpoint[i]][initpoint[0]] = 1;
}

int main()
{
    init();
    for (int i = INITPOINT; i < MAXSIZE; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            for(int jj = 0; jj < MAXSIZE; jj++) degree[j] += a[j][jj];
            sum = sum + degree[j];
        }
        for (int j = 0; j < i; j++) k[j] = degree[j] * 1.0 / sum;

        int times = M;
        if (times > i) times = i;
        while(times--) {
            srand((unsigned)time(nullptr));
            double x, y = 0.0;
            int con;
            x = rand() / double(RAND_MAX);
            for (int j = 0; j < i; j++) {
                y += k[j];
                if (y >= x){
                    con = j;
                    k[j] = 0;
                    break;
                }
            }
            a[i][con] = a[con][i] = 1;
            y = 0;
            for(int j = 0; j < i; j++) {
               y+= k[j];
            }
            for(int j = 0; j < i; j++) {
                k[j] = k[j]/y;
            }
        }
    }
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

