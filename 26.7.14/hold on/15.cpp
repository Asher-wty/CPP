#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

// 常见中文标点集合
const string puncts[] = {"，", "。", "；", "！", "？", "【", "】", "“", "”", "‘", "’",
                         "（", "）", "《", "》", "—", "…", "、", "：", "；", "　"}; // 全角空格
set<string> punctSet;

void initPunctSet() {
    for (int i = 0; i < sizeof(puncts)/sizeof(puncts[0]); ++i)
        punctSet.insert(puncts[i]);
}

// 提取一首诗中的所有汉字（去重）
set<string> extractWords(const string& line) {
    set<string> words;
    size_t i = 0;
    while (i < line.size()) {
        // 判断是否为双字节字符（中文字符/标点）
        if ((unsigned char)line[i] > 127 && i+1 < line.size()) {
            string ch = line.substr(i, 2);
            // 如果是标点符号则跳过
            if (punctSet.find(ch) == punctSet.end()) {
                words.insert(ch);
            }
            i += 2;
        } else {
            // 单字节字符（英文、数字、空格等）跳过
            ++i;
        }
    }
    return words;
}

int main() {
    initPunctSet();
    vector<set<string>> poemChars;
    vector<string> poems;
    string line;
    while (getline(cin, line)) {
        if (line == "0") break;
        poems.push_back(line);
        poemChars.push_back(extractWords(line));
    }
    
    int n = poems.size();
    vector<int> remaining(n);
    for (int i = 0; i < n; ++i) remaining[i] = i;
    
    set<string> learned;
    vector<int> order;
    
    while (!remaining.empty()) {
        int bestIdx = -1;
        int minNew = 1e9;
        // 找到生字最少的诗
        for (int i = 0; i < remaining.size(); ++i) {
            int idx = remaining[i];
            int cnt = 0;
            for (const string& w : poemChars[idx]) {
                if (learned.find(w) == learned.end()) cnt++;
            }
            if (cnt < minNew) {
                minNew = cnt;
                bestIdx = i; // 在remaining中的位置
            }
        }
        // 取出该诗的原始序号
        int idx = remaining[bestIdx];
        order.push_back(idx);
        // 学习该诗，将汉字加入learned
        for (const string& w : poemChars[idx]) {
            learned.insert(w);
        }
        // 从remaining中删除
        remaining.erase(remaining.begin() + bestIdx);
    }
    
    // 输出
    for (size_t i = 0; i < order.size(); ++i) {
        if (i > 0) cout << " ";
        cout << order[i];
    }
    cout << endl;
    
    return 0;
}