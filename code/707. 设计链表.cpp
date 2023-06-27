class MyLinkedList {
public:
    struct MyListNode{
        int val;
        MyListNode* next;
        MyListNode(int val) : val(val), next(nullptr) {};
    };

    MyLinkedList() {
        _hdListNode = new MyListNode(0); // _hdListNode->|0|nullptr| 
                                        // 带头结点的链表，数据结构讲过
        _lSize = 0;
    }
    
    int get(int index) {//_hdListNode->|0|newnode|->|e|z|->|x|y|->|a|b|->|c|jnullptr| 4
        if (index < _lSize && index >= 0) {
            MyListNode* hdtmp = _hdListNode;
            for (int i = 0; i < index; i++) { //错误2，写成了for (int i = 0; i < _lSize; i++)
                hdtmp = hdtmp->next;
            }
            return hdtmp->next->val;
        } else {
            return -1;
        }
    }
    
    void addAtHead(int val) { // 错误1 ：一开始忘了链表的头结点结构，现在看起来，头结点也太香了
        // _hdListNode->|0|z|->|x|y| 链表有头结点就是香
        MyListNode* newnode = new MyListNode(val); // newnode->|val|nullptr|
        newnode->next = _hdListNode->next; // newnode->|val|z|
        _hdListNode->next = newnode; // _hdListNode->|0|newnode|->|val|z|->|x|y|
        _lSize++;
    }
    
    void addAtTail(int val) {
        MyListNode* hdtmp = _hdListNode;
        for (int i = 0; i < _lSize; i++) {
            hdtmp = hdtmp->next;
        }
        MyListNode* newnode = new MyListNode(val);
        hdtmp->next = newnode;
        _lSize++;
    }
    
    void addAtIndex(int index, int val) {
        MyListNode* hdtmp = _hdListNode;
        // _hdListNode->|0|newnode|->|e|z|->|x|y|->|a|b|->|c|jnullptr| 4
        if (index < _lSize) { 
            for (int i = 0; i < index; i++) { 
                hdtmp = hdtmp->next;
            } // hdtmp=z; index=2 
            // _hdListNode->|0|newnode|->|e|hdtmp|->|x|y| -v> 2|a|b|->|c|jnullptr| 4
            // 头结点，若想操作|a|b|，如删除或添加，应该拿到|e|z|，即hdtmp=z，前两格
            MyListNode* newnode = new MyListNode(val);
            newnode->next = hdtmp->next; // newnode->|val|y|
            hdtmp->next = newnode;
            _lSize++;
        } else if (index == _lSize) {
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        // _hdListNode->|0|newnode|->|e|z|->|x|y|->|a|b|->|c|jnullptr| 4
        if (index < _lSize) {
            MyListNode* hdtmp = _hdListNode;
            for (int i = 0; i < index; i++) {
                hdtmp = hdtmp->next;
            } // hdtmp == z; index == 2; 删除|a|b|
            MyListNode* deltmp = hdtmp->next; //|e|hdtmp|->|x|y|->|a|b|; deltmp=y
            hdtmp->next = hdtmp->next->next; //|e|hdtmp|->|x|b|->|c|jnullptr|
            delete deltmp;
            _lSize--;
        }
    }

private:
    int _lSize;
    MyListNode* _hdListNode;        
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */