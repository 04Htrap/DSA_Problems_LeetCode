class MedianFinder {
public:
    //Left half should have a maxHeap cus we need the top element to be the larget
    priority_queue<int> leftH;
    //Right half should have a minHeap cus we need the mid element to be the smallest in that Half
    priority_queue<int, vector<int>, greater<int>> rightH;

    MedianFinder() {
        
    }
    /*
    What we do is that we maintain two queue. If num is less than left top we push in it else right
    Next we maintain a balance between the two queues to maintain a diff of just 1 el cus split
    is done from the mid 
    */
    void addNum(int num) {
        if(leftH.empty() || num < leftH.top())
            leftH.push(num);
        else
            rightH.push(num);
        
        if(abs((int)leftH.size() - (int)rightH.size()) > 1) {
            if(leftH.size() > rightH.size()) {
                rightH.push(leftH.top());
                leftH.pop();
            }
            else {
                leftH.push(rightH.top());
                rightH.pop();
            }
        }
    }
    //If both the queue are of same size, we take avg of both tops else we take left top
    double findMedian() {
        if(leftH.size() == rightH.size())
            return ((leftH.top() + rightH.top()) / 2.0);
        else if(leftH.size() < rightH.size()) return rightH.top();
        else return leftH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */