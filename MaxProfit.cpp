
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int Max=0;
    int bottom=prices[0];
    int top=prices[0];
    
    for(const auto& price : prices){
    	
    	/*
        if(price<bottom){
            bottom = price;
            top = price;
        }else if(price>top){
            top = price;
            Max = (top-bottom)>Max ? (top-bottom) : Max;
        }
        */
        
        top = price<bottom ? price : top;
        bottom = price<bottom ? price : bottom;
        
        top = price>top ? price : top;
        
        Max = (top-bottom)>Max ? (top-bottom) : Max;
        
    }
    
    return Max;
}

