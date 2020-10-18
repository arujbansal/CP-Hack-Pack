struct LiChaoTree {

    struct Line {
        int slope, yIntercept;

        Line(int slope, int yIntercept) : slope(slope), yIntercept(yIntercept) {}

        int val(int x) {
            return slope * x + yIntercept;
        }
    };

    int n;
    vector<Line> t;

    void init(int n) {
        this->n = n;
        t.assign(4 * n, Line(0, INF));
    }

    void insert(int i, int l, int r, Line newLine) {
        int mid = (l + r) >> 1;
        if (newLine.val(mid) < t[i].val(mid)) swap(newLine, t[i]);
        if (r - l <= 1) return;
        if (newLine.val(l) <= t[i].val(l)) insert(lc(i), l, mid, newLine);
        else insert(rc(i), mid + 1, r, newLine);
    }

    int query(int i, int l, int r, int x) {
        if (r - l <= 1) return t[i].val(x);
        int mid = (l + r) >> 1;
        if (x <= mid) return min(t[i].val(x), query(lc(i), l, mid, x));
        else return min(t[i].val(x), query(rc(i), mid + 1, r, x));
    }

    void insert(int slope, int yIntercept) { insert(1, 0, n - 1, Line(slope, yIntercept)); }

    int query(int x) { return query(1, 0, n - 1, x); }
};