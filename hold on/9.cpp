#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

map<int, string> digitMap = {
    {0, "零"}, {1, "壹"}, {2, "贰"}, {3, "叁"}, {4, "肆"},
    {5, "伍"}, {6, "陆"}, {7, "柒"}, {8, "捌"}, {9, "玖"}
};

map<int, string> unitMap = {
    {1, "拾"}, {2, "佰"}, {3, "仟"}
};

string transform4(const string &num4, bool isHead) {
    // 去掉前导零
    string n = num4;
    while (n.size() > 1 && n[0] == '0') n.erase(0, 1);
    if (n == "0") return isHead ? "" : "零";
    string res;
    int len = n.size();
    for (int i = 0; i < len; ++i) {
        int idx = len - i - 1; // 个位索引0
        int d = n[i] - '0';
        if (d == 0) {
            // 检查后面是否全零
            bool allZero = true;
            for (int j = i + 1; j < len; ++j) {
                if (n[j] != '0') { allZero = false; break; }
            }
            if (!allZero && (res.empty() || res[res.size()-1] != "零"[0])) {
                res += "零";
            }
        } else {
            // 处理壹拾省略
            if (idx == 1 && d == 1 && isHead && i == 0) {
                res += "拾";
            } else {
                res += digitMap[d];
                if (idx > 0) res += unitMap[idx];
            }
        }
    }
    return res;
}

string intToChinese(string integerPart) {
    if (integerPart == "0" || integerPart.empty()) return "零元";
    // 从右向左4位一组
    vector<string> groups;
    int len = integerPart.size();
    for (int i = len; i > 0; i -= 4) {
        int start = max(0, i - 4);
        groups.push_back(integerPart.substr(start, i - start));
    }
    reverse(groups.begin(), groups.end());
    
    static const string bigUnits[] = {"", "万", "亿", "万亿"};
    string res;
    for (size_t i = 0; i < groups.size(); ++i) {
        bool isHead = (i == 0);
        string groupRes = transform4(groups[i], isHead);
        if (groupRes.empty()) continue;
        if (!res.empty() && groupRes[0] != "零"[0]) {
            // 检查前一段是否以零结尾，不重复加零
            if (res[res.size()-1] == "零"[0]) {
                // 如果前面有零，且本段不为零开头，补零逻辑在transform内
            }
        }
        // 处理段间零：如果前段末尾不是零，本段开头不是零，且中间有一个或多个全零组，需要加零
        // 简化处理：transform4可能返回"零"，表示该组为零
        if (groupRes == "零") {
            if (i == groups.size() - 1) break; // 最低一组为零时忽略
            if (res.empty() || res[res.size()-1] != "零"[0]) {
                res += "零";
            }
        } else {
            res += groupRes;
            if (i < groups.size() - 1) res += bigUnits[groups.size() - 1 - i];
        }
    }
    // 去除结尾可能的零
    while (!res.empty() && res[res.size()-1] == "零"[0]) res.pop_back();
    if (res.empty()) res = "零";
    res += "元";
    return res;
}

string decimalToChinese(string decPart) {
    if (decPart.size() < 2) decPart += "0";
    int jiao = decPart[0] - '0';
    int fen = decPart[1] - '0';
    string res;
    if (jiao == 0 && fen == 0) {
        return "整";
    }
    if (jiao != 0) res += digitMap[jiao] + "角";
    if (fen != 0) res += digitMap[fen] + "分";
    return res;
}

int main() {
    string input;
    cin >> input;
    string intPart, decPart;
    size_t dotPos = input.find('.');
    if (dotPos == string::npos) {
        intPart = input;
        decPart = "00";
    } else {
        intPart = input.substr(0, dotPos);
        decPart = input.substr(dotPos + 1);
        if (decPart.size() == 1) decPart += "0";
        else if (decPart.size() > 2) decPart = decPart.substr(0, 2);
    }
    // 去除整数前导零，但保留至少一个零
    while (intPart.size() > 1 && intPart[0] == '0') intPart.erase(0,1);
    string result = "人民币" + intToChinese(intPart);
    string decStr = decimalToChinese(decPart);
    if (decStr == "整") {
        result += "整";
    } else {
        result += decStr;
    }
    cout << result << endl;
    return 0;
}