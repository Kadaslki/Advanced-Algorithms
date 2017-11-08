#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct pt{
    int x,y;
};

int drctn(pt p0, pt p1, pt p2){
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

bool nsgmnt(pt pi, pt pj, pt pk){
    if((min(pi.x,pj.x)<=pk.x && max(pi.x,pj.x)>=pk.x) && (min(pi.y,pj.y)<=pk.y && max(pi.y,pj.y)>=pk.y))
        return true;
    else 
        return false;
}

bool sgmntsctn(pt p[4])
{
    int d1,d2,d3,d4;
    d1=drctn(p[2],p[3],p[0]);
    d2=drctn(p[2],p[3],p[1]);
    d3=drctn(p[0],p[1],p[2]);
    d4=drctn(p[0],p[1],p[3]);
    
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)))
        return true;
        
    if(d1==0 && nsgmnt(p[2],p[3],p[0]))
        return true;
    else if(d2==0 && nsgmnt(p[2],p[3],p[1]))
        return true;
    else if(d3==0 && nsgmnt(p[0],p[1],p[2]))
        return true;
    else if(d4==0 && nsgmnt(p[0],p[1],p[3]))
        return true;
    else 
        return false;
}

int main(){
    pt p[4];
    cout<<"Enter points...\n";
    for(int i=0;i<4;i++){
        cout<<'x'<<i<<": ";
        cin>>p[i].x;
        cout<<"y"<<i<<": ";
        cin>>p[i].y;
        cout<<'\n';
    }
    if(sgmntsctn(p))
        cout<<"Lines Intersects.";
    else
        cout<<"Lines Do Not Intersects";
    return 0;
}