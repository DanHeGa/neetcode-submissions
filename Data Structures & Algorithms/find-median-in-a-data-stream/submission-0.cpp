class MedianFinder {
private:
    int size;
    priority_queue<double, vector<double>, greater<double>> minheap;
    priority_queue<double> maxheap;
public:
    MedianFinder() {
        this->size = 0;
    }
    
    void addNum(int num) {
        if (minheap.empty() && maxheap.empty()){
            maxheap.push(num);
            size++;
            return;
        }

        if (num > maxheap.top()) {
            minheap.push(num);
        } else {
            maxheap.push(num);
        }
        
        //check both heaps stay with a valid size for approach to keep working
        if (minheap.size() > maxheap.size() + 1) {
            double ele = minheap.top();
            minheap.pop();
            maxheap.push(ele);
        } else if (maxheap.size() > minheap.size() + 1) { //
            double ele = maxheap.top();
            maxheap.pop();
            minheap.push(ele);
        }

        size++;
    }
    
    double findMedian() {
        double median;
        cout << "Size = " << size << endl;
        
        if (minheap.size() == maxheap.size() || size % 2 == 0) { //even size case
            median = (maxheap.top() + minheap.top()) / 2;
            cout << "max: " << maxheap.top()  << " min: "  << minheap.top() << endl;
        } else { //odd case
            if (maxheap.size() > minheap.size()) {
                median = maxheap.top();
            } else {
                median = minheap.top();
            }
        }
        cout << median << endl;

        return median;
    }
};
