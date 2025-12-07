#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
     
        string s;
        cin >> s;
        
        if (s == "animal"){
            cout << "Panthera tigris\n";
        } else if (s == "flower"){
            cout << "Forsythia koreana\n";
        } else if (s == "tree"){
            cout << "Pinus densiflora\n";
        } else if (s == "end"){
            return 0;
        }
        
    }
}