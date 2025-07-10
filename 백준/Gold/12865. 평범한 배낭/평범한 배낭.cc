#include <iostream>
#include <algorithm>
using namespace std;

const int max_k = 100001;
int dp[max_k];

int main(void){
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++){
        int w, v;
        cin >> w >> v;

        for (int j=k; j>=w; j--)
            dp[j] = max(dp[j], dp[j-w]+v);
    }

    cout << dp[k] << endl;
    return 0;
}