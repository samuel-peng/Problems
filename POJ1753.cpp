//
//  POJ1753.cpp
//  POJ 1753
//
//  Created by Samuel Peng on 1/27/16.
//  Copyright © 2016 Samuel Peng. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;
int ftime=33;//Final Time, max should be 32
bool chess[4][4];
char input;
void init()
{
    int i , j ;
    for(i = 0 ; i < 4 ; i++)
    {
        for(j = 0 ; j < 4 ; j++)
        {
            scanf( "%c" , &input );
            if(input=='w')
                chess[i][j]=0;//If white then false
            else
                chess[i][j]=1;//If black then true
        }
        scanf("%c",&input);//For inputing the '\n'
    }
}
bool check()//Whether the colors are the same
{
    if(chess[0][0])
        for(int i = 0 ; i < 4 ; i++)
            for(int j = 0 ; j < 4 ; j++)
                if(!chess[i][j]) return false;
    if(!chess[0][0])
        for(int i = 0 ; i < 4 ; i++)
            for(int j = 0 ; j < 4 ; j++)
                if(chess[i][j]) return false;
    return true;
}
void flip(int i, int j)//flip one chessman
{
    chess[i][j]=!chess[i][j];
    //if the i-1, j-1, i+1, or j+1 doesn't exist, then don't flip
    if(i) chess[i-1][j]=!chess[i-1][j];
    if(j) chess[i][j-1]=!chess[i][j-1];
    if(i<3) chess[i+1][j]=!chess[i+1][j];
    if(j<3) chess[i][j+1]=!chess[i][j+1];
}
void ptconvert(int pt)
{
    flip(pt/4,pt%4); //Convert point number to coordinate
}
void search(int c,int b)
{
    if(check())
    {
        if(b<ftime) ftime=b;
        return;
    }
    if(c>=16) return;
    search(c+1,b);
    ptconvert(c);
    search(c+1,b+1);
    ptconvert(c);
}
int main()
{
    init();//Input & Initial Operations
    search(0,0);//Begin searching with chessman no.0 and 0 time of flippng
    if(ftime==33) printf("Impossible\n");//If ftime>max able flipping times, then impossible
    else printf("%d\n",ftime);
    return 0;
}
