#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define MAX max_element(s.begin(),s.end())
#define FOR for ( int i=0 ; i<N ; i++)
using namespace std ;
int N ;
vector <stack<int>> Y ;
void read_f(){
    int elems, va;
    cin >> N ;
    stack <int> mystk ;
    FOR{
        mystk = stack <int> () ;
        cin >> elems ;
        for(int j = 0; j < elems ; j++) {
            cin >> va;
            mystk.push(va) ;
        }
        Y.push_back(mystk) ;
    }
}
void show_f( vector<stack<int>> O){
    int i=0, val ;
    stack <int> s ;
    for(auto w : O){
        s = stack<int>();
        cout <<  ++i << " > ";
        while( !w.empty()){
           val = w.top() ;
           s.push(val) ;
           w.pop();
        }
        while( !s.empty()){
           val = s.top() ;
           cout << " " << val ;
           s.pop();
        } cout <<"\n" ;
    }
 }
int main() {
    read_f() ;
    vector <int> s;
    vector <int> vv;
    do{
        s.clear();
        vv.clear();
        FOR s.push_back(Y[i].size());
        if (*MAX-*min_element(s.begin(),s.end()) <= 1) break;
        int min_i,max_v;
        FOR{
            if (s[i] == *MAX) vv.push_back(Y[i].top());
            else continue; }
        max_v = *max_element(vv.begin(),vv.end());
        min_i = min_element(s.begin(),s.end())-s.begin() ;
        FOR{
            if (Y[i].empty()) continue;
            else {
                if(max_v == Y[i].top()){
                    Y[i].pop();
                    Y[min_i].push(max_v);
                    break;  }
            }
        }
       s.clear();
       FOR s.push_back(Y[i].size());
    } while (*MAX-*min_element(s.begin(),s.end()) > 1);
    show_f(Y);
    return 0;
}
