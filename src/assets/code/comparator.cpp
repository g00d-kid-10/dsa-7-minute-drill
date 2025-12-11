// Comparator struct for pair<int, int>
struct Compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if(p1.first != p2.first) {
            return p1.first < p2.first;
        }

        return p1.second < p2.second;
    }
};