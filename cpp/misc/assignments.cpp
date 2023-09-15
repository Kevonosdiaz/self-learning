#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int earliest_deadline(std::vector<std::pair<int,int>> vec) {
    using namespace std;

    // Heuristic: Go by earliest deadline, and by most points as a tiebreaker
    int res = 0; // point counter
    unordered_set<int> seen; // track which assignments we've done

    // Sort based on heuristic (second val, which is deadline) 
    // https://stackoverflow.com/questions/279855/how-do-i-sort-a-vector-of-pairs-based-on-the-second-element-of-the-pair
    sort(vec.begin(), vec.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    // Iterate through the assignments in sorted order (i represents the day)
    for (int i = 1; i <= vec.size(); i++) {
        int j = i;
        // Skip past anything that's already past its deadline
        while (i < vec[j].second) {
            j++;
        }

        int count = 0; // In case of tiebreaker
        int index;
        int curr_val = vec[j].second; // Helps to check all contenders for earliest deadline
        while (curr_val = vec[j].second) {
            if (vec[j].first > count && seen.find(j) == seen.end()) {
                index = j;
                count = vec[j].first;
            }
            j++;
        }
        seen.emplace(index);
        res += count;
    }

    return res;
} 


int main() {
    using namespace std;

    // Example Data (points, deadline)
    vector<pair<int,int>> ex1 = {
        make_pair(105,3),
        make_pair(205,3),
        make_pair(305,2),
        make_pair(85,3),
        make_pair(155,6),
        make_pair(405,1),
        make_pair(55,1)
    };

    vector<pair<int,int>> ex2 = {
        make_pair(35,2),
        make_pair(55,8),
        make_pair(75,3),
        make_pair(25,5),
        make_pair(145,2),
        make_pair(115,4)
    };

    int points1 = earliest_deadline(ex1);
    int points2 = earliest_deadline(ex2);

    cout << "Points Given Using 'Earliest Deadline' Heuristic On Example 1: " << points1 << "\n";
    cout << "Points Given Using 'Earliest Deadline' Heuristic On Example 2: " << points2 << "\n";
 

    return 0;
}