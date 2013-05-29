#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1001;
const int oo = 10000000;
const int dx[] = {1, 0, -1,  0};
const int dy[] = {0, 1,  0, -1};

char map[MAXN][MAXN];
bool visit[MAXN][MAXN];
int row, col, res, game_time;

struct node {
    int x, y, seconds;

    node(int x, int y) : x(x), y(y) {
        seconds = 0;
    }
    node() {
        seconds = 0;
    }
};

queue<node> fire;


bool isEdge(node cur) {
    if (cur.x == 0 || cur.x == row - 1 || cur.y == 0 || cur.y == col - 1) {
        return true;
    }
    return false;
}

bool isValid(node cur) {
    if (cur.x < 0 || cur.x >= row || cur.y < 0 || cur.y >= col) {
        return false;
    }
    if (map[cur.x][cur.y] == '#' || map[cur.x][cur.y] == '*') {
        return false;
    }
    return true;
}

void updateFire() {
    int i;
    int old_size = fire.size();

    while (old_size--) {
        node cur = fire.front();
        fire.pop();
        for (i = 0; i < 4; i++) {
            node next = cur;
            next.x += dx[i];
            next.y += dy[i];
            if (isValid(next)) {
                map[next.x][next.y] = '*';
                fire.push(next);
            }
        }
    }
}

void bfs(node start) {
    queue<node> que;
    int i;

    memset(visit, 0, sizeof(visit));
    que.push(start);
    visit[start.x][start.y] = true;
    while (! que.empty()) {
        node cur = que.front();
        que.pop();
        if (cur.seconds > game_time) {
            updateFire();
            game_time++;
        }
        if (map[cur.x][cur.y] == '*') {
            // this condition is very important
            continue;
        }

        if (isEdge(cur)) {
            if (cur.seconds < res) {
                res = cur.seconds;
            }
            return;
        }

        for (i = 0; i < 4; i++) {
            node next = cur;
            next.x += dx[i];
            next.y += dy[i];
            if (isValid(next) && ! visit[next.x][next.y]) {
                visit[next.x][next.y] = true;
                next.seconds++;
                que.push(next);
            }
        }
    }
}

int main() {
    int T, i, j;
    node start;

    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &col, &row);
        while (! fire.empty()) {
            fire.pop();
        }
        getchar();

        for (i = 0; i < row; i++) {
            gets(map[i]);
            for (j = 0; j < col; j++) {
                if (map[i][j] == '*') {
                    fire.push(node(i, j));
                } else if (map[i][j] == '@') {
                    map[i][j] = '.';
                    start.x = i;
                    start.y = j;
                }
            }
        }

        res = oo;
        game_time = 0;
        bfs(start);
        if (res == oo) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", res + 1);
        }
    }
    return 0;
}
