#include <iostream>
#include <cmath>

using namespace std;

int random_int(int s,int n){
  int n1= rand() % n+s;
  return n1;
}



int exp_mod(int a,int x,int n){
    int c=a%n;
    int r=1;
    while(x>0){
        if(x%2!=0){r=(r*c)%n;}
        c=(c*c)%n;
        x=x/2;
    }
    return r;
}

bool es_compuesto(int a,int n,int t,int u){
    int x=exp_mod(a,u,n);
    if(x==1||x==n-1){
        return false;
    }
    for(int i=1;i<t+1;i++){
        int ip=pow(2,i);
        int xi=exp_mod(x,2,n);
        x=xi;
        if(xi==n-1){
            return false;
        }
    }
    return true;
}

int miller_rabin(int n , int s){
    int t=0;
    int u=n-1;
    while(u%2==0){
        u=u/2;
        t++;
    }
    for(int j=1;j<s+1;j++){
        int a=random_int(2,n-1);
        if(es_compuesto(a,n,t,u)){return false;}
    }
    return true;
}

int main()
{   int x=pow(6,2);
    x=x%8;
    return 0;
}
