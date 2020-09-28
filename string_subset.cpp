#include <iostream>
#include <string>

using namespace std;

void solve(string, string);

int main(){

    string str = "he";
    string output = "";

    solve(str, output);
    return 0;
}

void solve(string in, string op){
    if(in.length() == 0){
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op2.push_back(in.at(0));
    in.erase(in.begin() + 0);

    solve(in, op1);
    solve(in, op2);
}



