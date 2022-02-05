#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
    private:
        // this map stores the number and its postion
        // 1 position has only 1 number, but 1 number may appear in many positions
        map<int, vector<int>> num_pos;  // number is the key, push back the positions as vectors
        map<int, int> pos_num;  // position is the key
        map<int, int> TurnToMap(vector<int>& num, vector<int>& pos)
        {
            // loop to fill in the map
        }
    public:
        int returnPosition(int pos)
        {
            // find the value "number" in this map
            int num = this->pos_num.find(pos);
            return num;
        }

        vector<int>* findPos(int num)
        {
            vector<int>* positions = new vector<int>{};
            positions = &this->num_pos.find(num);
            return positions;
        }

        void replace(int num_pre, int num_after)
        {
            // have to replace in both maps
            // find the positions the num_pre appears
            vector<int> v_num_pre = this->num_pos.find(num_pre);
            sort(v_num_pre.begin(), v_num_pre.back());
            // the first element in v_num is the first position num_pre occurs
            int pos = v_num_pre[0];

            // replace in map num_pos
            // first erase the position num_pre accurs
            v_num_pre.erase(v_num_pre.begin());
            // then add the position to the num_after
            vector<int> v_num_after = this->num_pos.find(num_after);
            v_num_after.push_back(pos);

            // replace in map pos_num
            // find the number in position pos
            int num_to_change = this->pos_num.find(pos);
            // change this num_to_change to num_after
            num_to_change = num_after;
        }

        void deleteGivenNumber(int num)
        {
            // record all the positions the number occurs
            vector<int> positions = this->num_pos.find(num);
            // delete in map num_pos
            map<int, vector<int>>::iterator num_to_delete = this->num_pos.find(num);
            this->num_pos.erase(num_to_delete);

            // delete in map pos_num
            vector<int>::iterator it = positions.begin();
            // go through the list
            while(it!=positions.end())
            {
                // find the position/number and delete
                map<int, int>::iterator num_to_delete_it = this->pos_num.find(*it);
                this->pos_num.erase(num_to_delete_it);   
                it++;
            }
        }
}