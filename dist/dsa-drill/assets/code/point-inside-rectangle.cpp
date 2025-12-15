bool point_inside_rect(pair<int, int> point, vector<pair<int, int>> rect) {
    int x = point.first, y = point.second;
    int xmin = min(rect[0].first, rect[1].first);
    int xmax = max(rect[0].first, rect[1].first);
    int ymin = min(rect[0].second, rect[1].second);
    int ymax = max(rect[0].second, rect[1].second);
    return x > xmin && x < xmax && y > ymin && y < ymax;
}