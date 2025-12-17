bool isValid(string s) {
    function<bool(char)> is_close = [&](char c) -> bool {
        return c == ')' || c == ']' || c == '}';
    };

    function<bool(char, char)> is_match = [&](char c1, char c2) -> bool {
        return (c1 == '(' && c2 == ')') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '{' && c2 == '}');
    };

    stack<char> stk;
    for (char c : s) {
        if (!stk.empty()) {
            if (is_close(c) && is_match(stk.top(), c)) {
                stk.pop();
                continue;
            }
        }
        stk.push(c);
    }

    return stk.empty();
}