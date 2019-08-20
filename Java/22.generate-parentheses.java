/*
 * @lc app=leetcode id=22 lang=java
 *
 * [22] Generate Parentheses
 */
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        String temp = "";
        generateParenthesisRec(n, n, res, temp);
        return res;
    }
    private void generateParenthesisRec(int left, int right, List<String> res, String temp)
    {
        if(left < 0 || right < 0)
            return;
        if(left == 0 && right == 0)
            res.add(temp);
        if(left > 0)
        {
            generateParenthesisRec(left - 1, right, res, temp+"(");
        }
        if(right > 0 && right > left)
            generateParenthesisRec(left, right - 1, res, temp+")");

    }
}

