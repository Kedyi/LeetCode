class Solution {
public:
    bool binarySearch(int sz, int limit, int m) {
    int len_a = 1, up = 9, len_b = to_string(m).size();
    for (int a = 1; a <= m && sz > 0; ++a) {
        sz -= limit - 3 - len_a - len_b;
        if (a == up) {
            ++len_a;
            up = up * 10 + 9;
        }
    }
    return sz <= 0;
}
vector<string> splitMessage(string mess, int limit) {
    int l = 1, r = 9, sz = mess.size();
    vector<string> res;
    while (l <= sz && !binarySearch(sz, limit, r)) {
        l *= 10;
        r = min(r * 10 + 9, sz + 1);
    }
    if (l <= sz) {
        while (l < r)
            if (int m = (l + r) / 2; binarySearch(sz, limit, m))
                r = m;
            else
                l = m + 1;
        for (int i = 0, a = 1; a <= l; ++a) {
            string suff = "<" + to_string(a) + "/" + to_string(l) + ">";
            res.push_back(mess.substr(i, limit - suff.size()) + suff);
            i += limit - suff.size();
        }
    }
    return res;
}
};