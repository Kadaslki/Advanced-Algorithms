#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct pt{
    int x,y;
};

struct ln{
    pt pi,pj;
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
    int i,j,n;
    cout<<"Enter number of lines: ";
    cin>>n;
    ln ln[n];
    pt p[4];
    cout<<"Enter lines...\n";
    for(int i=0;i<n;i++){
     cout<<"Line "<<i<<": ";
     cin>>ln[i].pi.x>>ln[i].pi.y>>ln[i].pj.x>>ln[i].pj.y;
     cout<<endl;
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++){
            p[0].x=ln[i].pi.x; p[0].y=ln[i].pi.y;
            p[1].x=ln[i].pj.x; p[1].y=ln[i].pj.y;
            p[2].x=ln[j].pi.x; p[2].y=ln[j].pi.y;
            p[3].x=ln[j].pj.x; p[3].y=ln[j].pj.y;
            if(sgmntsctn(p))
                cout<<"\nLines Intersects.";
            else
                cout<<"\nLines Do Not Intersects";            
    }
    return 0;
}