

class LRUCache {
public:
struct Node{
    int key, val;
    Node* next;
    Node* prev;

    Node(int k, int v){
        key = k;
        val = v;
    }
};

    int cap=0;
    
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    unordered_map<int, Node*> mpp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    //function to deletenode o(1)
    void deletenode(Node* n){
        Node* beforenode = n->prev;
        Node* afternode = n->next;
        beforenode->next=afternode;
        afternode->prev=beforenode;
    }

    //add node after head , after getting used or inserted
    void addnode(Node* n){
        Node* n1 = head->next;
        n->next=n1;
        n1->prev=n;
        head->next=n;
        n->prev=head;

    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;

        Node* address = mpp[key];
        int ans = address->val;
        deletenode(address);
        addnode(address);
        mpp[key] = head->next;
        return ans;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* address=mpp[key];
            deletenode(address);
            addnode(address);
            head->next->val = value;
        }
        else{
            if(mpp.size()==cap){
                mpp.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            addnode(new Node(key, value));
            mpp[key]=head->next;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */