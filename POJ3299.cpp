//
//  POJ3299.cpp
//  POJ3299
//
//  Created by Samuel Peng on 10/16/15.
//  Copyright © 2015 Samuel Peng. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

const double e=2.718281828;

double td2h(double t, double d){
    return t+0.5555*(6.11 * pow(e,5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
}

double dh2t(double d, double h){
    return h-0.5555*(6.11 * pow(e,5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
}

double th2d(double t, double h){
    return 273.16 / (1 - 273.16 * log((((h - t) / 0.5555 + 10.0) / 6.11)) /5417.7530) - 273.16;
}

int main(int argc, const char * argv[])
{
    char cond1, cond2;
    double x,y;
    while(scanf("%c",&cond1) && cond1!='E')
    {
        scanf("%lf %c %lf",&x,&cond2,&y);
        if(cond1=='T' && cond2=='D') printf("T %.1lf D %.1lf H %.1lf\n",x,y,td2h(x,y));
        else if(cond1=='D'&&cond2=='T') printf("T %.1lf D %.1lf H %.1lf\n",y,x,td2h(y,x));
        else if(cond1=='T'&&cond2=='H') printf("T %.1lf D %.1lf H %.1lf\n",x,th2d(x,y),y);
        else if(cond1=='H'&&cond2=='T') printf("T %.1lf D %.1lf H %.1lf\n",y,th2d(y,x),x);
        else if(cond1=='D'&&cond2=='H') printf("T %.1lf D %.1lf H %.1lf\n",dh2t(x,y),x,y);
        else if(cond1=='H'&&cond2=='D') printf("T %.1lf D %.1lf H %.1lf\n",dh2t(y,x),y,x);
    }
    return 0;
}
