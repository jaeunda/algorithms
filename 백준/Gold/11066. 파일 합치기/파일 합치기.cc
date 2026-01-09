#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, K, C[1024];
    cin >> T;
    for (int t=0; t<T; t++){ // Test Case
        cin >> K;
        int dp[K+1][K+1] = {0};
        int sum[K+1] = {0};
        for (int k=1; k<=K; k++){
            cin >> C[k];
            sum[k] = sum[k-1]+C[k];
        }

        // dp[i][j]: [i, j] 합치는 비용
            // 왼쪽 비용 + 오른쪽 비용 (누적) + 합치는 비용
        // (X) dp[i][j] := min(dp[i][i]+dp[i+1][j], ... , dp[i][j-1]+dp[j][j])          
        /*
            dp[i][j] := min over l such that i <= l < j
                            dp[i][l] + dp[l+1][j] + sum(i,j)
        */
        for (int len=2; len<=K; len++){
            for (int i=1; i+len-1<=K; i++){
                int j = i+len-1;
                dp[i][j] = 1e9;
                for (int l=i; l<j; l++){
                    int cost = dp[i][l] + dp[l+1][j] + (sum[j]-sum[i-1]);
                    if (dp[i][j] > cost)
                        dp[i][j] = cost;
                }
            }
        }
        cout << dp[1][K] << '\n';
    }
    exit(0);
}