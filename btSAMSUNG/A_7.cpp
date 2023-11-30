#include <iostream>
using namespace std;


int n, m;
int a[101][101];
int b[101][101];

bool checkIn(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int n, int m) {
    b[x][y] = 1;
    cout << x << "," << y << " ";

    if (checkIn(x - 1, y - 1, n, m) && b[x - 1][y - 1] == 0&&a[x][y]==a[x-1][y-1]) {
        dfs(x - 1, y - 1, n, m);
    }
    if (checkIn(x - 1, y, n, m) && b[x - 1][y] == 0&&a[x][y]==a[x-1][y]) {
        dfs(x - 1, y, n, m);
    }
    if (checkIn(x, y - 1, n, m) && b[x][y - 1] == 0&&a[x][y]==a[x][y-1]) {
        dfs(x, y - 1, n, m);
    }
    if (checkIn(x + 1, y - 1, n, m) && b[x + 1][y - 1] == 0&&a[x][y]==a[x+1][y-1]) {
        dfs(x + 1, y - 1, n, m);
    }
    if (checkIn(x + 1, y, n, m) && b[x + 1][y] == 0&&a[x][y]==a[x+1][y]) {
        dfs(x + 1, y, n, m);
    }
    if (checkIn(x + 1, y + 1, n, m) && b[x + 1][y + 1] == 0&&a[x][y]==a[x+1][y+1]) {
        dfs(x + 1, y + 1, n, m);
    }
    if (checkIn(x, y + 1, n, m) && b[x][y + 1] == 0&&a[x][y]==a[x][y+1]) {
        dfs(x, y + 1, n, m);
    }
    if (checkIn(x - 1, y + 1, n, m) && b[x - 1][y + 1] == 0&&a[x][y]==a[x-1][y+1]) {
        dfs(x - 1, y + 1, n, m);
    }
}

void connectedComponents(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 0) {
                cout << "Cac diem cung mau la:" << endl;
                dfs(i, j, n, m);
                cout << endl;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // Khởi tạo mảng b sau khi đã biết giá trị của n và m
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    connectedComponents(n, m);

    return 0;
}
