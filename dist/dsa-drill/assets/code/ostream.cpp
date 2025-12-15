// Globally overload operator << for vector<int>
ostream& operator<<(ostream& os, vector<int>& v) {
    os << '{';
    for(int i = 0; i < v.size(); i++) {
        os << v[i];
        if(i < v.size() - 1) os << ',';
    }
    os << '}';
    return os;
}