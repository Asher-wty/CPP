#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    char name1[MAX], name2[MAX];
    int i;
    char ch;

    // 第一部分：不删除分界符
    i = 0;
    while (i < 10 && cin.peek() != '.' && cin.peek() != ' ' && cin.peek() != '\n' && cin.peek() != EOF) {
        cin.get(ch);
        name1[i++] = ch;
    }
    name1[i] = '\0';

    i = 0;
    while (cin.peek() != ' ' && cin.peek() != '\n' && cin.peek() != EOF) {
        cin.get(ch);
        name2[i++] = ch;
    }
    name2[i] = '\0';

    // 跳过空格
    cin.get(ch); // 读掉分隔的空格

    cout << name1 << endl;
    cout << "              " << name2 << endl;

    // 第二部分：删除分界符
    i = 0;
    while (i < 10 && cin.peek() != '.' && cin.peek() != ' ' && cin.peek() != '\n' && cin.peek() != EOF) {
        cin.get(ch);
        name1[i++] = ch;
    }
    name1[i] = '\0';

    // 如果下一个字符是 '.'，则忽略它
    if (cin.peek() == '.') {
        cin.get(ch);
    }

    i = 0;
    while (cin.peek() != ' ' && cin.peek() != '\n' && cin.peek() != EOF) {
        cin.get(ch);
        name2[i++] = ch;
    }
    name2[i] = '\0';

    cout << "              " << name1 << endl;
    cout << "               " << name2 << endl;

    return 0;
}