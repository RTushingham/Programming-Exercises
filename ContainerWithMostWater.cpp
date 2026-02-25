#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
//   Find two lines that together with the x-axis form a container, such that the container contains the most water.
//   Return the maximum amount of water a container can store.
// Assume:
//   n == height.length
//   2 <= n <= 10**5
//   0 <= height[i] <= 104

int water_size( int first_height, std::size_t first_index, int second_height, std::size_t second_index )
{
    const int water_height{ (first_height < second_height) ? first_height : second_height };

    return water_height * ( second_index - first_index );
}

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
    int maxArea(vector<int>& height) {
        std::size_t first_index{ 0 };
        std::size_t last_index{ height.size()-1 };

        int first_height{ height.at(first_index) };
        int last_height{ height.at(last_index) };

        int current_max{ water_size( first_height, first_index, last_height, last_index ) };

        while( last_index-first_index>1 )
        {
            const int last_min{ first_height<last_height ? first_height : last_height };

            if( first_height <= last_height )
            {
                for( ; first_index<last_index && (height.at(first_index) <= last_min ); first_index++ ) {}
                if( first_index==last_index )
                    break;
            }
            if( last_height <= first_height )
            {
                for( ; first_index<last_index && (height.at(last_index) <= last_min ); last_index-- ) {}
                if( first_index==last_index )
                    break;
            }

            first_height = height.at(first_index);
            last_height = height.at(last_index);
            const int size{ water_size( first_height, first_index, last_height, last_index ) };
            current_max = current_max > size ? current_max : size;
        }
        return current_max;
    }
};


#include "gtest/gtest.h"

TEST( ContainerWithMostWater, FromLeetcode )
{
    vector<int> height;
    Solution solution{};
    
    height = vector<int>{ 1,8,6,2,5,4,8,3,7 };
    EXPECT_EQ( solution.maxArea( height ), 49 );
    
    height = vector<int>{ 1,1 };
    EXPECT_EQ( solution.maxArea( height ), 1 );
    
    height = vector<int>{ 1,2,4,3 };
    EXPECT_EQ( solution.maxArea( height ), 4 );
}
