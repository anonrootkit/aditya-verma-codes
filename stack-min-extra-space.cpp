//Get min element from st using extra space
#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    stack<int> minElementStack;

    cout << "Enter the number of elements you want to push in stack :";
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        st.push(value);
        if(minElementStack.empty()) minElementStack.push(value);
        else if(minElementStack.top() >= value) minElementStack.push(value);
    }

    cout << "How many elements you want to pop ? : ";
    cin >> N;

    for(int i = 0 ; i < N; i++) {
            if(minElementStack.top() == st.top()) minElementStack.pop();
            st.pop();
    }
    cout << "Min element present in st is : " << (minElementStack.empty() ? -1 : minElementStack.top());
    return 0;
}
