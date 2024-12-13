#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string, int> dp;

int solve(string input){
    int input_size = input.size();
    int best = 0;
    
    if (dp.find(input) != dp.end()) return dp[input];

    if (input_size == 0 || input_size == 1) return input_size;
    
    string newInput;
    if (input[0] == input[input_size - 1]){
        newInput = string(input.begin() + 1, input.end() - 1);
        best = max(best, solve(newInput) + 2);
    }else{
        newInput = string(input.begin() + 1, input.end());
        best = max(best, solve(newInput));
        newInput = string(input.begin(), input.end() - 1);
        best = max(best, solve(newInput));
    }
    dp[input] = best;
    return best; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    string temp;
    while (t--){
        cin>>temp;
        cout<<solve(temp)<<endl;
    }
}