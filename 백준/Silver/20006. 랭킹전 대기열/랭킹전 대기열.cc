#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int p, m;
    cin >> p >> m;

    vector<pair<int, string>> players(p);
    for (int i = 0; i < p; i++) {
        cin >> players[i].first >> players[i].second;
    }

    vector<vector<pair<int, string>>> rooms;

    for (int i = 0; i < p; i++) {
        bool entered = false;
        for (auto& room : rooms) {
            if (room.size() >= m) continue;
            if (abs(room[0].first - players[i].first) <= 10) {
                room.push_back(players[i]);
                entered = true;
                break;
            }
        }
        if (!entered) {
            rooms.push_back(vector<pair<int, string>>{players[i]});
        }
    }

    for (auto& room : rooms) {
        if (room.size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";

        sort(room.begin(), room.end(), [](auto a, auto b) {
            return a.second < b.second;
            });

        for (auto& player : room) {
            cout << player.first << " " << player.second << "\n";
        }
    }
}
