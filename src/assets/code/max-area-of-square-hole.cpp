// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15

int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    int v = 0, h = 0;
    int vmax = 0, hmax = 0;
    for(int i = 0; i < hBars.size(); i++) {
        h = (i > 0 && hBars[i - 1] + 1 == hBars[i]) ? h + 1 : 1;
        hmax = max(hmax, h);
    }

    for(int i = 0; i < vBars.size(); i++) {
        v = (i > 0 && vBars[i - 1] + 1 == vBars[i]) ? v + 1 : 1;
        vmax = max(vmax, v);
    }

    int s = min(hmax, vmax) + 1;
    return s*s;
}