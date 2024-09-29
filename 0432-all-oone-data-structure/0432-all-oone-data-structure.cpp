
using namespace std;

class AllOne {
    // A doubly linked list node, where each node holds a set of keys with the same count
    struct Node {
        int count;
        unordered_set<string> keys;
        Node(int count) : count(count) {}
    };
    
    list<Node> nodes;  // Doubly linked list to store nodes with different counts
    unordered_map<string, list<Node>::iterator> keyCountMap;  // Maps key to its corresponding node in the list

public:
    AllOne() {
    }
    
    void inc(string key) {
        // If the key is already present, increment its count
        if (keyCountMap.count(key)) {
            auto currNode = keyCountMap[key];
            auto nextNode = next(currNode);
            // If the next node doesn't exist or doesn't have count+1, insert a new node
            if (nextNode == nodes.end() || nextNode->count != currNode->count + 1) {
                nextNode = nodes.insert(nextNode, Node(currNode->count + 1));
            }
            nextNode->keys.insert(key);
            keyCountMap[key] = nextNode;
            // Remove the key from the current node
            currNode->keys.erase(key);
            // If the current node becomes empty, remove it
            if (currNode->keys.empty()) {
                nodes.erase(currNode);
            }
        } else {
            // If the key is not present, insert it with count 1
            if (nodes.empty() || nodes.front().count != 1) {
                nodes.push_front(Node(1));
            }
            nodes.front().keys.insert(key);
            keyCountMap[key] = nodes.begin();
        }
    }
    
    void dec(string key) {
        auto currNode = keyCountMap[key];
        if (currNode->count == 1) {
            // If the count becomes 0, remove the key completely
            keyCountMap.erase(key);
        } else {
            auto prevNode = prev(currNode);
            // If the previous node doesn't exist or doesn't have count-1, insert a new node
            if (currNode == nodes.begin() || prevNode->count != currNode->count - 1) {
                prevNode = nodes.insert(currNode, Node(currNode->count - 1));
            }
            prevNode->keys.insert(key);
            keyCountMap[key] = prevNode;
        }
        // Remove the key from the current node
        currNode->keys.erase(key);
        // If the current node becomes empty, remove it
        if (currNode->keys.empty()) {
            nodes.erase(currNode);
        }
    }
    
    string getMaxKey() {
        return nodes.empty() ? "" : *(nodes.back().keys.begin());
    }
    
    string getMinKey() {
        return nodes.empty() ? "" : *(nodes.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
