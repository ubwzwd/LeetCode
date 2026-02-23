/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <vector>
using namespace std;
// @lc code=start
class MyCalendar {
private:
  vector<pair<int, int>> classes;

public:
  MyCalendar() {}

  bool book(int startTime, int endTime) {
    for (auto &[s, e] : classes) {
      if (startTime < e && endTime > s) {
        return false;
      }
    }
    classes.push_back({startTime, endTime});
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
