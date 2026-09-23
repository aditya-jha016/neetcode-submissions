class MyHashSet {
private:
    static const int size =1000;
    vector<list<int>> adi;
    
    int hash(int key){
        return key%size;
    }
public:
    MyHashSet() {
        adi.resize(size);
        
    }
    
    void add(int key) {
        int index=hash(key);
        for(int x:adi[index]){
            if(x==key){
                return;
            }
        }
        adi[index].push_back(key);
    }
    
    void remove(int key) {
        int index=hash(key);
        adi[index].remove(key);
        
    }
    
    bool contains(int key) {
        int index= hash(key);
        for(int x:adi[index]){
            if(x==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */