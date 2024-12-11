#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<pair<int, int>> batus;
vector<vector<int>> memo;


int solve(int i, int c){
    if (i == 0 || c == 0) return 0;
    else if (memo[i][c] != -1) return memo[i][c];
    int best = solve(i-1, c);
    if (c >= batus[i].first){
        best = max(best, solve(i - 1, c - batus[i].first) + batus[i].second);
    }
    memo[i][c] = best;
    return best;
}


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);   
    cin>>n>>k;
    memo.resize(k+1, vector<int>(n+1, -1));
    batus.push_back({0, 0});
    for (int i = 0; i <  k; i++){
        pair<int, int> temp;
        cin>>temp.first>>temp.second;
        batus.push_back(temp);
    }
    solve(k, n);
    int w = n;
    stack<int> used;
    for (int i = k; i > 0; i--){
        if (memo[i][w] != memo[i-1][w]) {
            used.push(i);
            w -= batus[i].first;
        }
    }
    while (!used.empty()){
        cout<<used.top()<<endl;
        used.pop();
    }
}