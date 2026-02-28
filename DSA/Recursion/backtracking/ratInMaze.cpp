#include <iostream>
#include <vector>

using namespace std;

void getAns(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis)
{
    int n = mat.size();
    // if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c] == true)
    // no need of visited matrix
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1)
    {
        return;
    }
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // vis[r][c] = true;
    mat[r][c] = -1;
    getAns(mat, r + 1, c, path + "D", ans, vis); // down
    getAns(mat, r - 1, c, path + "U", ans, vis); // up
    getAns(mat, r, c - 1, path + "L", ans, vis); // left
    getAns(mat, r, c + 1, path + "R", ans, vis); // right
    // vis[r][c] = false;
    mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string path = "";
    getAns(mat, 0, 0, path, ans, vis);
    for (string a : ans)
    {
        cout << a << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    findPath(mat);
    return 0;
}