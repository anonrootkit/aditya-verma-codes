#include <bits/stdc++.h>
using namespace std;

void push(int);
void pop();
int minElement();

stack<int> s;
int minn;

int main(){
    cout << "How many elements you want to insert in the stack : ";
    int N; cin >> N;

    for(int i = 0; i < N; i++) {int value; cin>>value; push(value);}

    cout << "Min : "<<minElement()<<endl;
    pop();
    cout << "Min : "<<minElement()<<endl;
    pop();
    cout << "Min : "<<minElement()<<endl;
    pop();
    cout << "Min : "<<minElement()<<endl;
    pop();
    return 0;
}


void push(int value){
    if(s.empty()){
        minn = value;
        s.push(value);
    }else if(value < minn){
            s.push(2*value - minn);
            minn = value;
    }else{
            s.push(value);
    }
}

void pop(){
    if(s.empty()) return;
    if(s.top() < minn){
        minn = 2*minn - s.top();
        s.pop();
    }else{
        s.pop();
    }
}

int minElement(){
    return minn;
}
