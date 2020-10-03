#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#define F for (unsigned long long i=0; i<64; i++)

using namespace std;

vector <string>     v1;
vector <string>     v2;
vector <long long>  v3;
string r = "";
int k=0;

string long_to_bit() {
    bitset <64> bmap;
    unsigned long long x;
    cin >> x;
    bmap = x;
    string s = bmap.to_string();

    return s;
}

void make_string(){
    F{
        string w = v1[i];
        r.push_back(w[k]);
    }
    v2.push_back(r);
    r ="";
    k++;
}

unsigned long long string_to_bit(string s){
    bitset <64> bmap2(s);
    unsigned long long res = bmap2.to_ullong();

    return res;
}

int main()
{
    F  v1.push_back(long_to_bit());
    F  make_string();
    F  v3.push_back(string_to_bit(v2[i]));
    F  cout << v3[i] << endl;

    return 0;
}
