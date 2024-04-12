#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;
int main(){
    // Time Complexity : O(N)
    // Space Complexity : O(1)
    string s;
    cout<< "Enter the String : "<<endl;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(remove_if(s.begin(),s.end(),[](char c){return !isalnum(c);}),s.end());
        int first = 0;
        int second = s.size()-1;
        while(first<=second){
            if(s[first]!=s[second]){
                cout << false;
            }
            first++;
            second--;
        }
        cout <<  true;
        return 0;
}