#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (line == "//000") break;
        lines.push_back(line);
    }
    string source;
    for (size_t i = 0; i < lines.size(); ++i) {
        source += lines[i];
        if (i != lines.size() - 1) source += '\n';
    }

    string result;
    enum State { NORMAL, LINE_COMMENT, BLOCK_COMMENT };
    State state = NORMAL;
    for (size_t i = 0; i < source.size(); ) {
        if (state == NORMAL) {
            if (source[i] == '/' && i + 1 < source.size()) {
                if (source[i + 1] == '/') {
                    state = LINE_COMMENT;
                    i += 2;
                    continue;
                } else if (source[i + 1] == '*') {
                    state = BLOCK_COMMENT;
                    i += 2;
                    continue;
                }
            }
            result += source[i];
            ++i;
        } else if (state == LINE_COMMENT) {
            if (source[i] == '\n') {
                result += '\n';
                state = NORMAL;
            }
            ++i;
        } else { // BLOCK_COMMENT
            if (source[i] == '*' && i + 1 < source.size() && source[i + 1] == '/') {
                state = NORMAL;
                i += 2;
            } else {
                ++i;
            }
        }
    }

    // 去除开头空白行
    size_t start = 0;
    while (start < result.size() && result[start] == '\n') ++start;
    // 去除结尾空白行
    size_t end = result.size();
    while (end > start && result[end - 1] == '\n') --end;
    result = result.substr(start, end - start);
    cout << result;
    return 0;
}