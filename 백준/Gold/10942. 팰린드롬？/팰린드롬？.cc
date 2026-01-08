#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, S, E;
    int input[2001] = {0};
    bool pel_dp[2001][2001] = {0};

    cin >> N;
    for (int i=1; i<=N; i++) cin >> input[i];

    // dp
    // len = 1: pel_dp[i][i] = true;
    // input의 길이가 홀수인 경우
    for (int i=1; i<=N; i++)
        pel_dp[i][i] = true;

    // len = 2: input[i] == input[i+1] ?
    // input의 길이가 짝수인 경우
    for (int i=1; i<N; i++)
    //  pel_dp[i][i+1] = (input[i] == input[i+1])? true : false;
        pel_dp[i][i+1] = (input[i] == input[i+1]);

    // len > 2: dp[s][e] = (input[s] == input[e]) && dp[s+1][e-1]
        // [s+1, e-1]로부터 [s, e] 결과를 도출해야 하므로 길이가 짧은 것부터
    for (int len=3; len<=N; len++){ // [s,e] 길이
        for (int s=1; s+len-1<=N; s++){ // s: 시작점
            int e = s+len-1; // e: 끝점
            pel_dp[s][e] = (input[s] == input[e]) && pel_dp[s+1][e-1];
        }
    }

    cin >> M;
    for (int i=0; i<M; i++){
        cin >> S >> E;
        cout << pel_dp[S][E]  << '\n';
    }
    exit(0);
}