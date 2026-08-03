class LRUCache {
public:
    //dll structure with  map
    struct node{
        int key, val;
        node *prev;
        node *next;
        node(int k, int v){
            key=k;
            val=v;
        }
    };

    int cap=0;
    //initialised head tail nodes
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int, node*> m;


    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    //function to deletenode o(1)
    void deletenode(node *n){
        node *beforenode = n->prev;
        node *afternode = n->next;
        beforenode->next=afternode;
        afternode->prev = beforenode;
    }

    //add node after head , after getting used or inserted
    void addnode(node* n){
        node* n1 = head->next;
        head->next=n;
        n->next=n1;
        n->prev=head;
        n1->prev=n;
    }
    
    int get(int key) {
        //if not found
        if(m.find(key)==m.end()) return -1;
        //found->get node->get value->move node after head
        node* address = m[key];
        int ans = address->val;
        deletenode(address);
        addnode(address);
        m[key]=head->next;
        return ans;
    }
    
    void put(int key, int value) {
        //found key update, put it after head
        if(m.find(key)!=m.end()){
            node* add = m[key];
            deletenode(add);
            addnode(add);
            head->next->val=value;
        }else{
            //full so remove least used that is before tail
            if(m.size()==cap){
                //also delete map value
                m.erase(tail->prev->key);
                //delete node
                deletenode(tail->prev);
            }
            addnode(new node(key,value));
            m[key]=head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */