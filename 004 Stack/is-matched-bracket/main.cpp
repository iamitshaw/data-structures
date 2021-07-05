#include <bits/stdc++.h>

bool is_valid_string(std::string& bracket_expression) {
    std::stack<char> s;
    for (const auto& bracket: bracket_expression) {
        if (bracket == '[' or bracket == '{' or bracket == '(') {
            s.push(bracket);
        } else if (bracket == ']' or bracket == '}' or bracket == ')') {
            if (!s.empty()) {
                /* if stack is non-empty then check whether
                 * closing bracket's corresponding opening
                 * bracket is available on top of the stack */
                if (s.top() == '(' && bracket ==')') {
                    s.pop();
                } else if (s.top() == '{' && bracket == '}') {
                    s.pop();
                } else if (s.top() == '[' && bracket == ']') {
                    s.pop();
                } else {
                    /* if closing bracket's corresponding opening
                     * bracket isn't available on top of the stack */
                    return false;
                }
            } else {
                /* if no opening bracket
                 * is available on stack */
                return false;
            }
        }
    }

    /* whether stack is empty after
     * processing every bracket */
    return s.empty();
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get bracket_expression */
    std::string expression;
    std::cin >> expression;

    /* print appropriate message */
    std::cout << expression << ": ";
    if (is_valid_string(expression)) {
        std::cout << "Valid\n";
    } else {
        std::cout << "Invalid\n" ;
    }
    return 0;
}