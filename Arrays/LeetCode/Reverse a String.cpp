#include "iostream"
#include "vector" 
#include <algorithm>      

using namespace std;
int main(){
    cout << "Enter the number of elements" << endl;
    int n;
    cin>>n;
    vector<string> s;
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++){
        string elem;
        cin>>elem;
        s.push_back(elem);
    }
    int l = 0;
    int r = s.size() -1;
    while(l<r){
        string temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
    cout << "Reversed elements" << endl;
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}