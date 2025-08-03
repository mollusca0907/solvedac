#include <iostream>
#include <string>
using namespace std;

bool isAkarakaPalin(string s){
    int len=s.length();
    bool isPalin=true;

    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            isPalin=false;
        }
    }
    if(len>1){
        string prefix=s.substr(0,len/2);
        if(!isAkarakaPalin(prefix))
            isPalin=false;
    }
    return isPalin;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string origin;
    cin>>origin;

    if(isAkarakaPalin(origin)){
        cout<<"AKARAKA"<<'\n';
    }else{
        cout<<"IPSELENTI"<<'\n';
    }
    return 0;
}