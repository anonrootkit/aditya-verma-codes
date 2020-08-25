//Nearest greatest right
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void findNGR(int arr[], int size);

int main(){
    int size;

    cout << "Enter the size of array :"; cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    findNGR(arr, size);

    return 0;
}

void findNGR(int arr[], int size){

    stack<int> s;
    vector<int> v;

    for(int i = size-1; i >= 0; i--){
        if(s.empty()){
            v.push_back(-1);
        }else if(s.top() > arr[i]){
            v.push_back(s.top());
        }else{
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }

            if(s.empty()){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    for(int i = size-1; i>=0; i--){
        cout << v.at(i) << " ";
    }
}
