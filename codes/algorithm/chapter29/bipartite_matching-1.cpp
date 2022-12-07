#include <iostream>
#include <vector>
#define MAX 101
#define NUM 3
using std::vector;
using std::fill;

vector<int> preferred_computers[MAX];
int preferred_computers_results[MAX];
bool is_visited_computer[MAX];
bool dfs(int human_index){
    for(int i = 0; i < preferred_computers[human_index].size(); i++){
        int computer_index = preferred_computers[human_index][i];
        if(is_visited_computer[computer_index]) 
            continue;
        is_visited_computer[computer_index] = true;
        if(preferred_computers_results[computer_index] == 0 || dfs(preferred_computers_results[computer_index])){
            preferred_computers_results[computer_index] = human_index;
            return true;
        }
    }
    return false;
}
int main(){
    // [1] initialise
    preferred_computers[1].push_back(1);
    preferred_computers[1].push_back(2);
    preferred_computers[1].push_back(3);
    preferred_computers[2].push_back(1);
    preferred_computers[3].push_back(2);
    // [2] process
    for(int i = 1; i <= NUM; i++){
        fill(is_visited_computer, is_visited_computer + MAX, false);
        dfs(i);
    }
    // [3] output
    for(int i = 1; i <= NUM; i++){
        printf("human: %d => computer: %d\n", preferred_computers_results[i], i);
    }
    return 0;
}