#include<unordered_set>;
using std::unordered_set;
class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size(); i++){
                  unordered_set<char>rows; 
                  unordered_set<char>cols;
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    if(rows.contains(board[i][j]))
                        return false;
                    rows.insert(board[i][j]); 
                }

                if(board[j][i]  != '.'){
                    if(cols.contains(board[j][i]))
                        return false;
                    cols.insert(board[j][i]);
                } 
            }
        }

        for(int i = 0 ; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
                int subrow{i * 3};
                int subcol{j * 3};
                
                unordered_set<char>box;
                for(int k = 0 ; k < 3; k++){
                    for(int l = 0 ; l < 3 ; l++){
                        if(board[subrow + k][subcol + l] != '.'){
                            if(box.contains(board[subrow+k][subcol + l]))
                                return false;
                            box.insert(board[subrow+k][subcol+l]);   
                        }
                    }
                }
            }
        }
        return true;
    }
};

//board = 

//
//    [["5","3",".",".","7",".",".",".","."]
//    ,["6",".",".","1","9","5",".",".","."]
//    ,[".","9","8",".",".",".",".","6","."]
//    ,["8",".",".",".","6",".",".",".","3"]
//    ,["4",".",".","8",".","3",".",".","1"]
//    ,["7",".",".",".","2",".",".",".","6"]
//    ,[".","6",".",".",".",".","2","8","."]
//    ,[".",".",".","4","1","9",".",".","5"]
//    ,[".",".",".",".","8",".",".","7","9"]]
