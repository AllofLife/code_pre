#include<iostream>
#include <vector>
// 数据存储数据结构
struct data{
    int key;
    int value;
};
// 查找和替换数据结构
struct Node{
    struct data* row;
    struct Node* last;
    struct Node* next;
};
struct HashNode
{
    struct Node* data;
    struct HashNode * last;
    struct HashNode * next;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        HashTable.reserve(capacity);
        Head = new Node;
        Tail = new Node;
        Head->next = NULL;
        Head->last = NULL;
        Tail->next = NULL;
        Tail->last = NULL;
        for(auto &i : HashTable)
            i = new HashNode;
        currentSize = 0;
        cacheSize = capacity;
    }
    
    int get(int key) 
    {
        int hash_ = key % cacheSize;
        HashNode* p = HashTable[hash_];
        if(p == NULL)
        {
            return -1;
        }
        else
        {
                while(p->next != NULL)
                {
                    if(p->data->row->key == key)
                    {
                        return key;
                    }
                    p = p ->next;
                }
        }
        return -1;
    }
    HashNode* getA(int key)
    {
        int hash_ = key % cacheSize;
        struct HashNode* p = HashTable[hash_];
        if(p == NULL)
        {
            return p;
        }
        else
        {
                while(p->next != NULL)
                {
                    if(p->data->row->key == key)
                    {
                        return p;
                    }
                    p = p ->next;
                }
        }
        return p;
    }
    
    void put(int key, int value) {
        if(get(key) == -1)
        {
            if(currentSize < cacheSize)
            {
                // 当前大小小于总容量 还可new对象
                struct data* pdata  = new (struct data);
                pdata->key = key;
                pdata->value = value;
                struct Node* pNode = new (struct Node);
                // 插入查找链表
                pNode->next = Head->next;
                pNode->row = pdata;
                pNode -> last = Head;
                if(pNode->next!= NULL)
                {
                    pNode->next->last = pNode;
                }               
                Head->next = pNode;
                // 插入hash表
                struct HashNode* pHashNode = getA(key);
                pHashNode ->data = pNode;
            }
            else
            {
                // cache 满了 之后要替换
                // 先去找到 链表的尾指针的元素
                struct Node * pNode = Tail;
                int outKey = Tail->row->key;
                // 修改 dada
                Tail->row->key = key;
                Tail->row->value = value;
                // 插入查找链表
                pNode ->last ->next = pNode->next;
                pNode->next = Head->next;
                Head->next->last = pNode;
                Head->next = pNode;

                struct HashNode* pHashNode = getA(outKey);
                // 插入hash 表
                if((key % cacheSize) != (outKey % cacheSize))
                {
                    pHashNode -> last ->next = pHashNode->next;
                    //  旧hash 前后节点处理
                    if(pHashNode->next != NULL)
                    { 
                       pHashNode->next->last = pHashNode->last;
                        pHashNode->last->next = pHashNode->next;
                    }
                    else
                    {
                        // 旧hash的下一个位置为空 只需要改上一个节点的next指针
                        pHashNode->last->next = pHashNode->next;
                    }
                    int key_hash = key % cacheSize;
                    //  新的hash插入新的位置
                     // hash位置为空
                    if(HashTable[key_hash] == NULL){
                        HashTable[key_hash] = pHashNode;
                    }
                    else
                    {
                        // 新增加值与后续节点互指
                        pHashNode->next = HashTable[key_hash];
                        HashTable[key_hash]->next->last = pHashNode;
                        // 新增加值与头节点互指 头插法
                        HashTable[key_hash]->next= pHashNode;
                        pHashNode->last = HashTable[key_hash];
                    }
                }
                


            }

        }
        else
        {
            struct HashNode * pHashNode = getA(key);
            pHashNode->data->row->value = value;
            // 修改 查找链表
            struct Node* pNode = pHashNode->data;
            if(pNode->next != NULL)
            {
                pNode->next->last = pNode->last;
            }
            else
            {
                // 修改的是链表最后一个节点
                Tail = pNode->last;
            }
            pNode->last->next = pNode->next;
            // 插入头
            pNode->next = Head->next;
            pNode->next->last = pNode;
            Head->next = pNode;
        }


    }
public:
// 查找数据hash表
vector<int> HashTable;
// 插入 修改的头节点
Node* Head;
// 插入算法 尾节点
Node* Tail;
// 当前 cache 大小
int currentSize ;
// cache大小
int cacheSize;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */