//created by insane-abhi
//FCFS scheduling
//Arrival time in seconds and Burst time in microseconds
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> FCFSalgo(vector<vector<int>> a) {
    unsigned int n=a.size();
    multimap<int, int> process;
    for(int i=0; i<n; i++){
        process.insert(pair<int,int>(a[i][0],a[i][1]));
    }
    vector<vector<int>> result(a.size());
    multimap<int,int>::iterator itr;
    int i=0;
    for(itr=process.begin(); itr!=process.end(); ++itr){
        result[i].push_back(itr->first);
        result[i].push_back(itr->second);
        i++;
    }
    vector<vector<int>> another(a.size());
    int count = 0;
    for(int j=0; j<n; j++){
        another[j].push_back(result[j][0]);
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
    cout << "Arrival(s)\tBurst(ms)" << endl;
    for(int i=0; i<n; i++){
//        cin >> x;
        x = rand()%50;
        input[i].push_back(x);
//        cin >> x;
        x = rand()%10;
        input[i].push_back(x);
        cout << input[i][0] << "\t\t" << input[i][1] << endl;
    }
    output = FCFSalgo(input);
    cout << endl << "Process\tService(ms)" << endl;
    for(int i=0; i<n; i++){
        cout << output[i][0] << "\t" << output[i][1] << endl;
    }
    return 0;
}