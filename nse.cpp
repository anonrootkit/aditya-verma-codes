//Next smaller element
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void findNSE(int arr[], int size);
void printVector(vector<int>, int);

int main(){
    int size;
    cout << "Enter the size of array :"; cin>>size;int arr[size];
    for(int i = 0; i < size;i++)cin>>arr[i];
    findNSE(arr, size);
    return 0;
}

void findNSE(int arr[], int size){
    vector<int> v;
    stack<int> s;

    for(int i = size-1; i>=0; i--){
        if(s.empty()) v.push_back(-1);
        else if(s.top()<arr[i]) v.push_back(s.top());
        else{
            while(!s.empty() && s.top() >= arr[i]){
                s.pop();
            }
            v.push_back(s.empty() ? -1 : s.top());
        }
        s.push(arr[i]);
    }

    printVector(v, size);
}

void printVector(vector<int> v, int size){
    for(int i = size-1; i >= 0 ; i--){
        cout << v[i] << " ";
    }
    cout <<"\n";
}
