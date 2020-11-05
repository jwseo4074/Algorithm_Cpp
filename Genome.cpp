#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <fstream>
#define A auto it1= la.begin(); auto it2= la.begin(); advance(it1,a1); it1--; advance(it2,a2);
using namespace std;

int main() {
    ifstream in;
    in.open("sapiens.txt");
    string res;
    string rr;
    string a;
    getline(in,a);
    while(in.eof() == false){
        getline(in,rr);
        res += rr;
    }
    in.close();

    int num,a1,a2;
    char s[10];
    cin >> num;
    string result;
    auto it = res.begin();
    list <char> la;
    while ( it != res.end() ){
        la.push_back(*it);
        it++;
    }
    for(int i=0; i<num; i++){
        cin >> s >> a1 >> a2;
        if (strcmp(s,"front")==0){
            A
            la.splice(la.begin(),la,it1,it2);
        }
        else if (strcmp(s,"back")==0){
            A
            la.splice(la.end(),la,it1,it2);
        }
        else if (strcmp(s,"cut")==0){
            A
            it2 = la.erase(it1,it2);
        }
        else if (strcmp(s,"double")==0){
            auto it3 = la.begin();
            A
            it3 = it2;
            la.insert( it3, it1, it2);
        }
        else if (strcmp(s,"flip")==0){
            auto it1= la.begin();
            auto it2= la.begin();
            advance(it1,a1); it1--;
            advance(it2,a2);
            reverse(it1,it2);
        }
        else {
            auto it = la.begin();
            auto it1 = la.begin();
            advance(it,a1); it--;
            advance(it1,a2);
            for ( it; it != it1 ; it++) cout << *it ;
            cout << "\n";
        }
    }
}
