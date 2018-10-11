//created by insane-abhi
//FCFS scheduling
//Arrival time in seconds and Burst time in microseconds
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> FCFSalgo(vector<vector<int>> a) {
    unsigned int n=a.size();
    multimap<int, int> process;
    multimap<int, int> order;
    for(int i=0; i<n; i++){
        process.insert(pair<int,int>(a[i][0],a[i][1]));
        order.insert(pair<int,int>(a[i][0],i));
    }
    vector<vector<int>> result(a.size());
    multimap<int,int>::iterator itr;
    int i=0;
    for(itr=process.begin(); itr!=process.end(); ++itr){
        result[i].push_back(itr->first);
        result[i].push_back(itr->second);
        i++;
    }
    int m=0;
    for(itr=order.begin(); itr!=order.end(); ++itr){
        result[m].push_back(itr->second);
        m++;
    }
    vector<vector<int>> another(a.size());
    int count = 0;
    for(int j=0; j<n; j++){
        another[j].push_back(result[j][2]);
        another[j].push_back(count);
        count += result[j][1];
    }
    return another;
}

int main() {
    int n=10;
    srand(time(NULL));
    vector<vector<int>> input(n), output;
    int x;
    cout << "Input::" << endl;
    cout << "ProcessNo\tArrival(s)\tBurst(ms)" << endl;
    for(int i=0; i<n; i++){
//        cin >> x;
        x = rand()%10;
        input[i].push_back(x);
//        cin >> x;
        x = rand()%10;
        input[i].push_back(x);
        cout << i << "\t\t" << input[i][0] << "\t\t" << input[i][1] << endl;
    }
    cout << endl << "Output::" << endl;
    output = FCFSalgo(input);
    cout << "ProcessNo\tService(ms)" << endl;
    for(int i=0; i<n; i++){
        cout << output[i][0] << "\t\t" << output[i][1] << endl;
    }
    return 0;
}