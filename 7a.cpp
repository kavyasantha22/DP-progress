// Top-bottom
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> computed;
vector<int> coins;
int n, k;


int best(int x){
    if (x == 0) return 0;
    else if (x < 0) return -1;
    else if (computed[x] != -2) return computed[x];
    int mini = INT_MAX;
    for (int i = 0; i < n; i++){
        int y = best(x - coins[i]);
        if (y == -1) continue;
        else mini = min(mini, y+1);
    }
    if (mini == INT_MAX){
        computed[x] = - 1;
        return -1;
    }
    else{
        computed[x] = mini;
        return mini;
    }
    

}

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
    computed.resize(k+1, -2);
    cout<<best(k)<<endl;;
}

