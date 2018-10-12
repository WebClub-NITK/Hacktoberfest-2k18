// created by insane-abhi
#include <iostream>
#include <vector>
using namespace std;
//sorts in range *low* to *high-1* (both inclusive)
void bubbleSort(vector<int>& A, int low, int high) {
    int flag;
    for(int i=low; i<=high; i++) {
        flag = 0;
        for(int j=low; j<high-1; j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
}
int main() {
    //driver function
    unsigned int n;
    cout << "Enter no. of elements: " << endl;
    cin >> n;
    cout << "Enter the space seperated array of no. " << endl;
    vector<int> sort(n);
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        sort[i] = x;
    }
    bubbleSort(sort,1,n);
    for(int i=0; i<n; i++) {
        cout << sort[i] << endl;
    }
    return 0;
}