bool overlap_or_touch(const pair<int, int> p1, const pair<int, int> p2) {
    pair<int, int> p1 = p1.first <= p2.first ? p1 : p2;
    pair<int, int> p2 = p2.first <= p1.first ? p2 : p1;
    return p1.second >= p2.first;
}