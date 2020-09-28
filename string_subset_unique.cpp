#include <bits/stdc++.h>

using namespace std;

void solve(string, string);

set<string> unique_sets;

int main(){
    string in = "Hey";
    solve(in, "");

    for(string const& str : unique_sets){
        cout << str << endl;
    }

    return 0;
}

void solve(string in, string out){
    if(in.length() == 0){
        unique_sets.insert(out);
        return;
    }

    string op1 = out;
    string op2 = out;

    op2.push_back(in[0]);
    in.erase(in.begin() + 0);

    solve(in, op1);
    solve(in, op2);
}
