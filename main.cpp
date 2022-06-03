#include <iostream>
#include <cmath>

using namespace std;

long long random(long long  s,long long n){
    long long num=s+rand()%((n+1)-s);

  return num;
}



long long exp_mod(long long a,long long x,long long n){
    long long c=a%n;
    long long r=1;
    while(x>0){
        if(x%2!=0){r=(r*c)%n;}
        c=(c*c)%n;
        x=x/2;
    }
    return r;
}

bool es_compuesto(long long a,long long n,long long t,long long u){
    long long x=exp_mod(a,u,n);
    if(x==1||x==n-1){
        return false;
    }
    for(long long i=1;i<t+1;i++){
        //long long ip=pow(2,i);
        long long xi=exp_mod(x,2,n);
        x=xi;
        if(xi==n-1){
            return false;
        }
    }
    return true;
}

long long miller_rabin(long long n , long long s){
    long long t=0;
    long long u=n-1;
    while(u%2==0){
        u=u/2;
        t++;
    }
    //cout<<"n="<<n<<" t= "<<t<<" u="<<u<<endl;
    for(long long j=1;j<s+1;j++){
        long long a=random(2,n-1);
        //cout<<a<<endl;
        if(es_compuesto(a,n,t,u)){return false;}
    }
    //cout<<n<<endl;
    return true;

}

int main()

{   int o=1;
    cout<<"NUMEROS PRIMOS DEL 1 AL 1000"<<endl;


    for(long long i=3;i<1000  ;i++){
        long long s=sqrt(i);
        if(miller_rabin(i,s)){
            o++;
            cout<<"("<<o<<")";
            cout<<i<<"-";}

    }
    cout<<endl;
    cout<<"CANTIDAD DE NUMEROS PRIMOS TOTAL = "<<o<<endl<<endl;

    cout<<"NUMEROS PRIMOS DEL 1000 AL 10000"<<endl;
    int e=0;
    for(long long i=1000;i<10000  ;i++){
        long long s=sqrt(i);

        if(miller_rabin(i,s)){
            e++;
            cout<<"("<<e<<")";
            cout<<i<<"-";}
    }
    cout<<endl<<"CANTIDAD DE NUMEROS PRIMOS TOTAL = "<<o<<endl<<endl;

    cout<<"NUMEROS PRIMOS DEL 1000 AL 10000"<<endl;

    int r=0;
    for(long long i=10000;i<100000 ;i++){
        long long s=sqrt(i);

        if(miller_rabin(i,s)){
            r++;
            cout<<"("<<r<<")";
            cout<<i<<"-";}
    }
    cout<<endl<<"PRIMOS TOTAL DEL 1 AL 1000= "<<o<<endl;
    cout<<endl<<"PRIMOS TOTAL DEL 1000 AL 10000= "<<e<<endl;
    cout<<endl<<"PRIMOS TOTAL DEL 10000 AL 100000= "<<r<<endl;



    return 0;
}
