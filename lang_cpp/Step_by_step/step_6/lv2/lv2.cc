#include <iostream>
#include <string>

#define KING 1
#define QUEEN 1
#define ROOK 2
#define BISHOP 2
#define KNIGHT 2
#define PAWN 8

using namespace std;

int main()
{
    int king_num, queen_num, rook_num, bishop_num, knight_num, pawn_num;
    int king_diff, queen_diff, rook_diff, bishop_diff, knight_diff, pawn_diff;

    cin >> king_num >> queen_num >> rook_num >> bishop_num >> knight_num >> pawn_num;

    king_diff = KING - king_num;
    queen_diff = QUEEN - queen_num;
    rook_diff = ROOK - rook_num;
    bishop_diff = BISHOP - bishop_num;
    knight_diff = KNIGHT - knight_num;
    pawn_diff = PAWN - pawn_num;

    cout << king_diff << " " << queen_diff << " " << rook_diff << " " << bishop_diff << " " << knight_diff << " " << pawn_diff << endl;
    return 0;
}