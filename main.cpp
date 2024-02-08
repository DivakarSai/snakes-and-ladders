#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <sstream>
#include "player.cpp"
#include "board.cpp"
#include "dice.cpp"
using namespace std;






int main() {
    // Your code here
    int num_snakes = 0;
    int num_ladders = 0;
    int num_players = 0;

    Board board;

    cin >> num_snakes;
    for(int i = 0; i < num_snakes; i++) {
        int start, end;
        cin >> start >> end;
        board.snakes.push_back(Snake(start, end));
    }

    cin >> num_ladders;
    for(int i = 0; i < num_ladders; i++) {
        int start, end;
        cin >> start >> end;
        board.ladders.push_back(Ladder(start, end));
    }

    cin >> num_players;

    // start the game

    vector<Player> players;
    for(int i = 0; i < num_players; i++) {
        players.push_back(Player());
    }

    bool game_over = false;

    Dice dice = Dice();

    while(!game_over) {
        for(int i = 0; i < num_players; i++) {
            int dice_val = dice.roll();
            // if new position is greater than 100, do not move
            if(players[i].position + dice_val > 100) {
                cout << "Player " << i + 1 << " rolled a " << dice_val << " and is now at position " << players[i].position << endl;
                continue;
            }
            players[i].position += dice_val;
            cout << "Player " << i + 1 << " rolled a " << dice_val << " and is now at position " << players[i].position << endl;

            for(int j = 0; j < board.snakes.size(); j++) {
                if(players[i].position == board.snakes[j].start_position) {
                    players[i].position = board.snakes[j].end_position;
                }
            }

            for(int j = 0; j < board.ladders.size(); j++) {
                if(players[i].position == board.ladders[j].start_position) {
                    players[i].position = board.ladders[j].end_position;
                }
            }

            if(players[i].position >= 100) {
                cout << "Player " << i + 1 << " wins!" << endl;
                game_over = true;
                break;
            }
        }
    }





    





    return 0;
}
