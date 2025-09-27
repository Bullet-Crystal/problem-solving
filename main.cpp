#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int>> stacks(3,vector<int>(n, 0));
    unordered_map<int, vector<int>> pos;
    vector<int> top_stack(3);

    int direction = (n & 1) ? 1 : -1;
    int m = 0;
    top_stack[0] = 1;
    top_stack[1] = 0;
    top_stack[2] = 0;

    // fill the first stack
    for(int i = 0; i < n; i++) stacks[0][i] = n - i;

    for(int i = 0; i < n; i++) pos[i + 1] = {0, n - i - 1};
    int steps = 0;
    // cout<<(1<<n) - 1<<endl;
    while(steps < (1<<n) - 1){
        for(int num = 1; num <= n; num++){
            for(int stack = 0; stack < 3; stack++){
                if(top_stack[stack] == num){
                    m = pos[num][0] + ((num & 1) ? -1 : 1) * direction;
                    if(m < 0) m += 3;
                    if(m >= 3) m -= 3;
                    
                    if(top_stack[m] == 0 || top_stack[m] > num){
                        // cout<<stack + 1<<" "<<m + 1<<endl;
                        cout<<"\n";
                        for(int i = 0; i < 3; i++){
                            cout<<"stack "<<i+1<<" : ";
                            for(int j = 0; j < n; j++){
                                cout<<stacks[i][j]<<" ";
                            }
                            cout<<", top = "<<top_stack[i]<<"\n";
                        }
                        top_stack[pos[num][0]] = pos[num][1] > 0 ? stacks[pos[num][0]][pos[num][1] - 1] : 0;
                        
                        stacks[pos[num][0]][pos[num][1]] = 0;
                        pos[num][0] = m;
                        if(top_stack[m] == 0){
                            pos[num][1] = 0;
                            stacks[m][0] = num;
                        }else{
                            pos[num][1] = pos[top_stack[m]][1] + 1;
                            stacks[m][pos[top_stack[m]][1] + 1] = num;
                        }
                        top_stack[m] = num;
                        steps++;
                    }
                    break;
                }
            }
        }
    }
    cout<<"\n";
    for(int i = 0; i < 3; i++){
        cout<<"stack "<<i+1<<" : ";
        for(int j = 0; j < n; j++){
            cout<<stacks[i][j]<<" ";
        }
        cout<<", top = "<<top_stack[i]<<"\n";
    }
    

    return 0;
}
