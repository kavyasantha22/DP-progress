// Bottom-up
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> coins;
vector<int> computed;
int n, k;


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);   
    cin>>n;
    int temp;
    for (int i = 0; i < n; i++){
        cin>>temp;
        coins.push_back(temp);
    }
    cin>>k;
    computed.resize(k+1, INT_MAX);
    for (int i = 0; i <= k; i++){
        if (i == 0) computed[i] = 0;
        for (int j = 0; j < n; j++){
            if (i >= coins[j] && computed[i - coins[j]] != INT_MAX){
                computed[i] = min(computed[i], computed[i - coins[j]] + 1);
            }
        }
    }
    if (computed[k] == INT_MAX) cout<<-1<<endl;
    else cout<<computed[k]<<endl;
}

