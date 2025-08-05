#include <iostream>
#include <queue>

using namespace std;

class Median {
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;

public:
    void insert(int num){
        if (low.empty() || num <= low.top())
            low.push(num);
        else
            high.push(num);
        
        if (low.size() > high.size()+1){
            high.push(low.top());
            low.pop();
        } else if (high.size() > low.size()){
            low.push(high.top());
            high.pop();
        }
    }
    void print_median() const{
        cout << low.top() << '\n';
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, input_num;
    Median m;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> input_num;
        m.insert(input_num);
        m.print_median();
    }
    return 0;
}