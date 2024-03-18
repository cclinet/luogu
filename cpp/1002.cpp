#include <iostream>
#include <array>
#include <set>
#include <utility>

int main()
{
    std::array<std::array<long long, 21>, 21> f;
    int m, n, hm, hn;
    std::cin >> m >> n >> hm >> hn;
    std::set<std::pair<int, int>> horse_control;
    constexpr std::array<std::pair<int, int>, 9> horse_relative_pos{{{0, 0}, {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}};
    std::pair<int, int> pos;
    for (int i = 0; i < 9; i++)
    {
        pos = horse_relative_pos[i];
        if (hm + pos.first >= 0 && hm + pos.first <= m && hn + pos.second >= 0 && hn + pos.second <= n)
        {
            horse_control.insert({hm + pos.first, hn + pos.second});
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (horse_control.contains({i, j}))
            {
                f[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                f[i][j] = 1;
            }
            else if (i == 0)
            {
                f[i][j] = f[i][j - 1];
            }
            else if (j == 0)
            {
                f[i][j] = f[i - 1][j];
            }
            else
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
    }
    std::cout << f[m][n] << std::endl;

    return 0;
}