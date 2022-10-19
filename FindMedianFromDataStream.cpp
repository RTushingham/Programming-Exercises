#include <queue>

class MedianFinder {
public:
    MedianFinder()
    {
        m_UpperHalf = priority_queue<int, std::vector<int>, std::greater<int>>();
        m_LowerHalfAndMedian = priority_queue<int>();
    }
    
    void addNum(int num) {
        if(0 == m_LowerHalfAndMedian.size())
        {
            m_LowerHalfAndMedian.push(num);
            return;
        }
        else
        {
            if(num > m_LowerHalfAndMedian.top())
            {
                m_UpperHalf.push(num);
            }
            else
            {
                m_LowerHalfAndMedian.push(num);
            }
            
            if(m_UpperHalf.size() == m_LowerHalfAndMedian.size()+1)
            {
                m_LowerHalfAndMedian.push(m_UpperHalf.top());
                m_UpperHalf.pop();
            }
            else if(m_LowerHalfAndMedian.size() == m_UpperHalf.size()+2)
            {
                m_UpperHalf.push(m_LowerHalfAndMedian.top());
                m_LowerHalfAndMedian.pop();
            }
        }
    }
    
    double findMedian() {
        if(m_LowerHalfAndMedian.size() == m_UpperHalf.size())
        {
            return ((double)(m_LowerHalfAndMedian.top() + m_UpperHalf.top()))/2.0;
        }
        else
        {
            return (double)m_LowerHalfAndMedian.top();
        }
    }
    
private:
    priority_queue<int> m_LowerHalfAndMedian;
    priority_queue<int, std::vector<int>, std::greater<int>> m_UpperHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
