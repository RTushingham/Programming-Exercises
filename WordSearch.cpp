class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m_RowMax = board.size();
        m_ColumnMax = board[0].size();
        
        for(int RowIndex=0; RowIndex<m_RowMax; RowIndex++)
        {
            for(int ColumnIndex=0; ColumnIndex<m_ColumnMax; ColumnIndex++)
            {
                if(recurse(board, word, RowIndex, ColumnIndex, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool recurse(vector<vector<char>>& board, string word, int RowIndex, int ColumnIndex, int CharacterIndex)
    {
        if(CharacterIndex == word.size())
        {
            return true;
        }
        else if(ColumnIndex<0 || ColumnIndex==m_ColumnMax || RowIndex<0 || RowIndex==m_RowMax || board[RowIndex][ColumnIndex] != word[CharacterIndex])
        {
            return false;
        }
        else
        {
            char placeholder = board[RowIndex][ColumnIndex];
            board[RowIndex][ColumnIndex] = '!';
            if(recurse(board, word, RowIndex-1, ColumnIndex, CharacterIndex+1) || recurse(board, word, RowIndex, ColumnIndex-1, CharacterIndex+1) || recurse(board, word, RowIndex+1, ColumnIndex, CharacterIndex+1) || recurse(board, word, RowIndex, ColumnIndex+1, CharacterIndex+1))
            {
                return true;
            }
            else
            {
                board[RowIndex][ColumnIndex] = placeholder;
                return false;
            }
        }
    }
    
    int m_ColumnMax;
    int m_RowMax;
};
