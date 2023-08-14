#include "headers.h"
#include <algorithm>
#include <sys/types.h>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
public:
    unordered_map<string,vector<pair<int, string>>> time_map;// key : vector<{time,value}>

    TimeMap() {
        time_map.clear();
    }
    
    void set(string key, string value, int timestamp) {
        this->time_map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &pairs = time_map[key];

        int l = 0,r = pairs.size()-1;

        if(pairs.empty()) return "";
        if(pairs[0].first > timestamp) return "";
        if(timestamp >= pairs[r].first) return pairs[r].second;


        while(l < r){
            int mid = l + (r - l + 1) / 2;

            if(pairs[mid].first > timestamp) r = mid - 1;
            else if(pairs[mid].first < timestamp){
            
                l = mid + 1;
            }else {
                return pairs[mid].second;
            }
        }
        return pairs[l].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

TEST(TimeMap_981, TimeMap_981_1)
{
    TimeMap s;
    // vector<int> in = {1, 2, 3};
    s.set("ctondw","ztpearaw",1);
    s.set("vrobykydll","hwliiq",2);
    s.set("gszaw","ztpearaw",3);
    s.set("ctondw","gszaw",4);
    s.set("vrobykydll","kcvcjzzwx",11);
    s.set("ztpearaw","zondoubtib",15);
    s.set("kcvcjzzwx","hwliiq",16);
    s.set("wtgbfvg","vrobykydll",17);
    s.set("hwliiq","gzsiivks",18);
    string ans = "zondoubtib";
    EXPECT_EQ(s.get("ztpearaw",20), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}