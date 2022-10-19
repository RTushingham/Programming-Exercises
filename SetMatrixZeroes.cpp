
/* It is also possible to do an in-place version of this where Matrix[0]
	acts as the columns which had zeroes in them, and you don't track
	which rows have already been zeroed (except Matrix[0])*/

#include <unordered_set>
#include <string.h>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> ColumnsContainingAZero, RowsWhichHaveBeenZeroed;
        
        int RowMax = matrix.size();
        int ColumnMax = matrix[0].size();
        
        for(int RowIndex=0; RowIndex<RowMax; RowIndex++)
        {
            bool bThisRowConatinedAZero = false;
            for(int ColumnIndex=0; ColumnIndex<ColumnMax; ColumnIndex++)
            {
                if(matrix[RowIndex][ColumnIndex] == 0)
                {
                    bThisRowConatinedAZero = true;
                    ColumnsContainingAZero.insert(ColumnIndex);
                }
            }
            
            if(bThisRowConatinedAZero)
            {
                memset(matrix[RowIndex].data(), 0, ColumnMax*sizeof(int));
                RowsWhichHaveBeenZeroed.insert(RowIndex);
            }
        }
        
        for(int RowIndex=0; RowIndex<RowMax; RowIndex++)
        {
            for(int ColumnIndex=0; ColumnIndex<ColumnMax; ColumnIndex++)
            {
                if(RowsWhichHaveBeenZeroed.count(RowIndex) == 0)
                {
                    for(const auto& column: ColumnsContainingAZero)
                    {
                        matrix[RowIndex][column] = 0;
                    }
                }
            }
        }
    }
};


// Here it is

#include <string.h>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool bRowZeroContainedAZeroe = false;
        int RowMax = matrix.size();
        int ColumnMax = matrix[0].size();
        
        for(int ColumnIndex=0; ColumnIndex<ColumnMax; ColumnIndex++)
        {
            if(matrix[0][ColumnIndex] == 0)
            {
                bRowZeroContainedAZeroe = true;
            }
        }
        
        for(int RowIndex=1; RowIndex<RowMax; RowIndex++)
        {
            bool bThisRowConatinedAZero = false;
            for(int ColumnIndex=0; ColumnIndex<ColumnMax; ColumnIndex++)
            {
                if(matrix[RowIndex][ColumnIndex] == 0)
                {
                    bThisRowConatinedAZero = true;
                    matrix[0][ColumnIndex] = 0;
                }
            }
            
            if(bThisRowConatinedAZero)
            {
                memset(matrix[RowIndex].data(), 0, ColumnMax*sizeof(int));
            }
        }
        
        for(int RowIndex=1; RowIndex<RowMax; RowIndex++)
        {
            for(int ColumnIndex=0; ColumnIndex<ColumnMax; ColumnIndex++)
            {
                if(matrix[0][ColumnIndex] == 0)
                {
                    matrix[RowIndex][ColumnIndex] = 0;
                }
            }
        }
        
        if(bRowZeroContainedAZeroe)
        {
            memset(matrix[0].data(), 0, ColumnMax*sizeof(int));
        }
        
        return;
    }
};
