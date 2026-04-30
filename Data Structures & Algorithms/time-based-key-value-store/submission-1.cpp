class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &temp = mp[key];

        int low = 0, high = temp.size()-1;
        string res = "";
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(temp[mid].first <= timestamp) {
                res = temp[mid].second;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }
};
