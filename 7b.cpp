#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);   
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> wp;
    for (int i = 0; i < k; i++){
        pair<int, int> temp;
        cin>>temp.first>>temp.second;
        wp.push_back(temp);
    }
    vector<pair<int, pair<int, vector<int>>>> dp(n + 1, {0, {0, {}}});
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            int weight = wp[j].first, value = wp[j].second;
            if (i >= weight) {
                auto prev = dp[i - weight];
                int new_value = prev.first + value;
                int new_weight = prev.second.first + weight;
                vector<int> new_sequence = prev.second.second;
                if (find(new_sequence.begin(), new_sequence.end(), j + 1) == new_sequence.end()) {
                    new_sequence.push_back(j + 1);
                    if (new_value > dp[i].first || 
                        (new_value == dp[i].first && new_weight < dp[i].second.first) || 
                        (new_value == dp[i].first && new_weight == dp[i].second.first && new_sequence < dp[i].second.second)) {
                        dp[i] = {new_value, {new_weight, new_sequence}};
                    }
                }
            }
        }
    }
    vector<int> result = dp[n].second.second;
    sort(result.begin(), result.end());
    for (int x :result){
        cout<<x<<endl;
    }
}