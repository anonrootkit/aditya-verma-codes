//Maximum area histogram
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Next smaller element
vector<int> computeNSE(int arr[], int size);

//Previous smaller element
vector<int> computePSE(int arr[], int size);

void displayVector(vector<int>, int);

int calculateMaximumArea(int *, vector<int>, vector<int>, int);


int main(){
    int N;
    cout <<"Enter the size of array :"; cin>>N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >>arr[i];

    cout << "Computing NSE\n";
    vector<int> right = computeNSE(arr, N);
    cout << "NSE vector stored in right vector.\n";

    cout << "Computing PSE\n";
    vector<int> left  = computePSE(arr, N);
    cout << "PSE vector stored in left vector.\n";

    displayVector(right, N);
    displayVector(left, N);

    int result = calculateMaximumArea(arr, right, left, N);
    cout << "Max area : " << result <<endl;

    return 0;
}


vector<int> computeNSE(int arr[], int size){
    vector<int> v;
    stack< pair<int,int> > s;

    cout << "NSE computation started...\n";

    for(int i = size-1; i >= 0; i--){
        if(s.empty()) v.push_back(size);
        else if(s.top().first < arr[i]) v.push_back(s.top().second);
        else{
            while(!s.empty() && s.top().first >= arr[i]) s.pop();

            v.push_back(s.empty() ? size : s.top().second);
        }
        s.push({arr[i], i});
    }

    cout << "NSE computed (rev)\n";

    vector<int> rev;
    for(int  i = size-1; i>=0 ; i--){
        rev.push_back(v[i]);
    }


    cout << "NSE computed (non-rev) returning vector...\n";

    return rev;
}

vector<int> computePSE(int arr[], int size){
    vector<int> v;
    stack< pair<int, int> > s;

    cout << "PSE computation started...\n";

    for(int i = 0; i < size; i++){
        if(s.empty()) v.push_back(-1);
        else if(s.top().first < arr[i]) v.push_back(s.top().second);
        else{
            while(!s.empty() && s.top().first >= arr[i]) s.pop();

            v.push_back(s.empty() ? -1 : s.top().second);
        }
        s.push({arr[i], i});
    }

    cout << "PSE computation finished, returning vector...\n";

    return v;
}

void displayVector(vector<int> v, int size){
    for(int i = 0; i < size; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int calculateMaximumArea(int *arr, vector<int> right, vector<int> left, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        int res = (right[i] - left[i] - 1) * arr[i];
        max = res > max ? res : max;
    }

    return max;
}
