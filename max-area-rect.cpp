//Maximum area rectangle
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> computeNSE(int arr[], int size);
vector<int> computePSE(int arr[], int size);
int calculateMaximumArea(int *, vector<int>, vector<int>, int);

int main(){
    cout << "Enter the number of rows: ";
    int R;
    cin >> R;
    cout << "Enter the number of cols: ";
    int C;
    cin >> C;
    int arr[R][C];
    cout << "Enter the matrix :\n";
    int maxx = -1;

    for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) cin >>arr[i][j];

    for(int i = 0; i < R; i++){
        int t_arr[C];
        for(int j = 0; j < C; j++){
            if(i == 0){
                t_arr[j] = arr[i][j];
            }else{
                if(arr[i][j] == 0) t_arr[j] = 0;
                else{
                    int val = arr[i-1][j] + arr[i][j];
                    t_arr[j] = val;
                }
            }
        }
        int res = calculateMaximumArea(t_arr, computeNSE(t_arr, C), computePSE(t_arr, C), C);
        maxx =  res > maxx ? res : maxx;
    }

    cout << maxx;

    return 0;
}


vector<int> computeNSE(int arr[], int size){
    vector<int> v;
    stack<int> s;

    for(int i = size-1; i >= 0; i--){
        if(s.empty()) v.push_back(size);
        else if(arr[s.top()] < arr[i]) v.push_back(s.top());
        else{
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();

            v.push_back(s.empty() ? size : s.top());
        }
        s.push(i);
    }
    return v;
}

vector<int> computePSE(int arr[], int size){
    vector<int> v;
    stack<int> s;

    for(int i = 0; i < size; i++){
        if(s.empty()) v.push_back(-1);
        else if(arr[s.top()] < arr[i]) v.push_back(s.top());
        else{
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();

            v.push_back(s.empty() ? -1 : s.top());
        }
        s.push(i);
    }

    return v;
}

int calculateMaximumArea(int *arr, vector<int> right, vector<int> left, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        int res = (right[size-i-1] - left[i] - 1) * arr[i];
        max = res > max ? res : max;
    }

    return max;
}



