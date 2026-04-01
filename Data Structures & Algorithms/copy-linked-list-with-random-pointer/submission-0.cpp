/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> hash_map;
        Node* curr = head;

        while (curr != nullptr) {
            // 創建新節點並存入 map
            hash_map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            hash_map[curr]->next = hash_map[curr->next];
            hash_map[curr]->random = hash_map[curr->random];
            curr = curr->next;

        }

        return hash_map[head];
    }
};
