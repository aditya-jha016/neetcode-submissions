class MyHashMap {
public:
    vector<vector<pair<int,int>>> adi;
    static const int size=1000;
    int hash(int key){
        return key%size;
    }
    MyHashMap() {
        adi.resize(size);
    }
    
    void put(int key, int value) {
        int index=hash(key);
        for(auto &p:adi[index]){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        adi[index].push_back({key, value});
    }
    
    int get(int key) {
        int index=hash(key);
        for(auto &p:adi[index]){
            if(p.first==key){
                return p.second;
            }
        }
        return -1;
        
    }
    
    void remove(int key) {
        int index=hash(key);
        for(int i=0;i<adi[index].size();i++){
            if(adi[index][i].first==key){
                adi[index].erase(adi[index].begin()+i);
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */