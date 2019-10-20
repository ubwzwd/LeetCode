#include <vector>
#include <iostream>
using namespace std;

class Solution {
    void probRec(vector<double>& prob, int target, double& res, double& temp, int index){
        if(index == prob.size() - 1){
            if(target > 0) temp += res*prob[index];
            else temp += res*(1-prob[index]);
            return;
        }
        if(target > 0){
            res *= prob[index];
            probRec(prob, target - 1, res, temp, index + 1);
            res /= prob[index];
        }
        res *= (1-prob[index]);
        probRec(prob, target, res, temp, index + 1);
    }
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double res = 1, temp = 0;
        probRec(prob, target, res, temp, 0);
        return temp;
    }
};

int main()
{

    return 0;
}