//Stock span problem
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void computeProblem(int arr[], int);
void printVector(vector<int>, int);

int main(){
    int size;
    cout << "Enter the size of array : ";cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) cin >> arr[i];

    computeProblem(arr, size);
    return 0;
}

void computeProblem(int arr[], int size){
    stack<pair<int,int> > s;
    vector<int> v;

    for(int i = 0; i < size; i++){
        if(s.empty()) v.push_back(-1);
        else if(s.top().first > arr[i]){v.push_back(s.top().second);}
        else{
            while(!s.empty() && s.top().first <= arr[i]){
                s.pop();
            }

            v.push_back(s.empty() ? -1 : s.top().second);
        }
        s.push({arr[i], i});
    }

    printVector(v, size);
}

void printVector(vector<int> v, int size){
    for(int i = 0; i < size ; i++){
        cout << i - v[i] << " ";
    }
    cout <<"\n";
}



