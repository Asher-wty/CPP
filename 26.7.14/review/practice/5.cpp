#include <iostream>
using namespace std;
class Matrix
{
public:
    Matrix(int n);
    Matrix(const Matrix&);
    ~Matrix();
    Matrix& operator=(const Matrix&);
    int* operator[](int);
    const int* operator[](int) const;
    Matrix operator*(const Matrix&) const;
    int size() const;
};

//StudybarCommentBegin
// 矩阵快速幂算法实现
// 依赖考生实现的拷贝构造函数、赋值运算符以及矩阵乘法 operator*
    Matrix matrix_power(Matrix base, long long exp) {
    int n = base.size();
    Matrix res(n);
    
    // 初始化 res 为单位矩阵
    // 依赖考生实现的 operator[]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = (i == j) ? 1 : 0;
        }
    }
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = res * base;
        }
        base = base * base;
        exp /= 2;
    }
    
    return res;
}

int main() {
    // 优化标准 I/O 操作以提升大规模数据下的执行效率
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    long long k;
    
    // 读取顶点数、边数与路径长度
    if (!(std::cin >> n >> m >> k)) {
        return 0;
    }

    // 实例化考生的 Matrix 类
    Matrix A(n);
    
    // 初始化邻接矩阵 A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = 0;
        }
    }

    // 构建有向图邻接矩阵
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        // 约定输入顶点从 1 开始计，映射至 0-indexed
        --u; 
        --v;
        A[u][v] = (A[u][v] + 1) % 1000000007;
    }

    // 执行矩阵快速幂计算 A^k
    Matrix Ak = matrix_power(A, k);

    // 按照题目要求输出完整矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << Ak[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
//StudybarCommentEnd