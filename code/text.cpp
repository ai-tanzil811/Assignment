

#include<iostream>
using namespace std;

void DPCoinChange(int c[],int d,int M){
    int P[M+1];
    int b[M+1];
    P[0]=0;
    for(int m=1;m<=M;m++){
        P[m]=INT_MAX;
        for(int i=0;i<d;i++){
            if(m>=c[i]){
                //we can take the coin
                if( 1+P[ m-c[i] ] < P[m] ){
                        //taking i_th coin gives min coins required
                    P[m] = 1+P[ m-c[i] ];
                    b[m] = c[i];
                }
            }
        }
    }
    cout<<"minimum coins:"<<P[M]<<endl;
    cout<<"Taken coins:";
    int i=M;
    while(i>0){
        cout<<b[i]<<",";
        i = i - b[i];
    }
}

int main(){
    int c[]={1,2,6};//available coin set
    int d=3;//number of available coins
    int M=11;//changed amount
    DPCoinChange(c,d,M);

}