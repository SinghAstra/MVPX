#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2)
// Space Complexity : O(2)
vector<int> majorityElementsBruteForce(vector<int> nums){
    vector<int> ans;
    int n = nums.size();
    int min = (n/3)+1;
    for(int i=0;i<n;i++){
        int elem = nums[i];
        int count = 0;
        if(ans.size() == 0 ||ans[0]!=nums[i]){
        for(int j=0;j<n;j++){
            if(nums[j] == elem){
                count++;
                if(count == min){
                    ans.push_back(elem);
                    break;
                }
            }
        }
        }
        if(ans.size() == 2){
            break;
        }
    }
    return ans;
}

vector<int> majorityElementsHashMapBetterApproach(vector<int> nums){
    vector<int> ans;
    unordered_map<int, int> countMap;
    int n = nums.size();
    for(int i = 0; i < n;i++){
        countMap[nums[i]]++;
    }
    for(auto it = countMap.begin(); it != countMap.end();it++){
        if(it->second > (n/3)){
            ans.push_back(it->first);
            if(ans.size() == 2){
                break;
            }
        }
    }
    return ans;
}


// Time Complexity : O(n)
// Space Complexity : O(n+2)
vector<int> majorityElementsHashMapBetterApproachThanBetterApproach(vector<int> nums){
    vector<int> ans;
    unordered_map<int, int> countMap;
    int n = nums.size();
    int min = (n/3) + 1;
    for(int i = 0; i < n;i++){
        countMap[nums[i]]++;
        if(countMap[nums[i]] == min){
            ans.push_back(nums[i]);
            if(ans.size() == 2){
                break;
            }
        }
    }
    return ans;
}

// Approach 3 : Moore's Voting Algorithm
// Time Complexity : O(2*n)
// Space Complexity : O(2)
vector<int> majorityElements(vector<int> nums){
    // Phase 1 : Selecting the Candidates
    int count1 = 0;
    int elem1;
    int count2 = 0;
    int elem2;
    int n = nums.size();
    int min = (n/3) +1;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(count1 == 0 && nums[i]!=elem2){
            elem1 = nums[i];
            count1 = 1;
        }else if(count2 == 0 && nums[i]!=elem1){
            elem2 = nums[i];
            count2 = 1;
        }
        else if(nums[i] == elem1){
            count1++;
        }
        else if(nums[i] == elem2){
            count2++;
        }else{
            count1--;
            count2--;
        }
    }

    // Phase 2 : Verifying the Candidates
    int totalCount1 = 0;
    int totalCount2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == elem1){
            totalCount1++;
            if(totalCount1 == min){
                ans.push_back(elem1);
                if(ans.size() == 2){
                    break;
                }
            }
        }
        else if(nums[i] == elem2){
            totalCount2++;
            if(totalCount2 == min){
                ans.push_back(elem2);
                if(ans.size() == 2){
                    break;
                }
            }
        }
    }
    return ans;
}

void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {3,2,3};
    vector<int> ans = majorityElementsBruteForce(nums);
    printVector(ans);
    return 0;

}