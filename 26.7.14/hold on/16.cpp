#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int score;
    char choices[5];
    char admitted;
    int order; // 输入顺序
};

bool cmpByScore(const Student& a, const Student& b) {
    if (a.score != b.score)
        return a.score > b.score;
    return a.order < b.order; // 分数相同按输入顺序
}

int main() {
    int quota[10];
    for (int i = 0; i < 10; ++i) {
        cin >> quota[i];
    }

    vector<Student> students;
    int id, score;
    char c1, c2, c3, c4, c5;
    while (cin >> id >> score >> c1 >> c2 >> c3 >> c4 >> c5) {
        if (id == 0 && score == 0) break;
        Student s;
        s.id = id;
        s.score = score;
        s.choices[0] = c1;
        s.choices[1] = c2;
        s.choices[2] = c3;
        s.choices[3] = c4;
        s.choices[4] = c5;
        s.admitted = 'x';
        s.order = students.size();
        students.push_back(s);
    }

    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), cmpByScore);

    for (size_t i = 0; i < sorted.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            int idx = sorted[i].choices[j] - 'a';
            if (quota[idx] > 0) {
                quota[idx]--;
                // 找到原始学生并更新
                for (size_t k = 0; k < students.size(); ++k) {
                    if (students[k].id == sorted[i].id) {
                        students[k].admitted = sorted[i].choices[j];
                        break;
                    }
                }
                break;
            }
        }
    }

    for (size_t i = 0; i < students.size(); ++i) {
        cout << students[i].id << " " << students[i].admitted << endl;
    }

    return 0;
}