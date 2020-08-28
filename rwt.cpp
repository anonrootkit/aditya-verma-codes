//Rain water trapping
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void compute(int *arr, int len);

int main(){
    int N;
    cout << "Enter the number of buildings : "; cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];

    compute(arr, N);
    return 0;
}

void compute(int *arr, int len){
    int a_left[len];
    for(int i = 0 ; i < len; i++){
        if(i == 0) a_left[i] = arr[i];
        else{
            a_left[i] = (a_left[i-1] > arr[i] ? a_left[i-1] : arr[i]);
        }
    }

    int a_right[len];
    for(int i = len - 1; i >= 0; i--){
        if(i == len - 1) a_right[i] = arr[i];
        else {
            a_right[i] = (a_right[i+1] > arr[i] ? a_right[i+1] : arr[i]);
        }
    }


    int totalArea = 0;

    for(int i = 0; i < len; i++){
        int right = a_right[i];
        int left = a_left[i];

        int minn = right > left ? left : right;
        totalArea += (minn <= 0 ? 0 : minn - arr[i]);
    }

    cout << "Total area : "<< totalArea;
    cout << endl;
}























