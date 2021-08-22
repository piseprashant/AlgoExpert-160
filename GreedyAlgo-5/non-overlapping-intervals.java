class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length <= 1) return 0;
        final int N = intervals.length;
        Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[1], i2[1]));
        int res = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < N; i++) {
            if (intervals[i][0] < prevEnd) {
                res++;
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return res;
    }
}

