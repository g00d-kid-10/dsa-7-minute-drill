class Stack {
public:
    bool is_close(char c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool is_match(char c1, char c2) {
        return (c1 == '(' && c2 == ')') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '{' && c2 == '}');
    }


    bool valid_paranthesis(string s) {
        stack<char> stk;
        for(char c : s) {
            if(!stk.empty()) {
                if(is_close(c) && is_match(stk.top(), c)) {
                    stk.pop();
                    continue;
                }
            }
            stk.push(c);
        }

        return stk.empty();
    }
};