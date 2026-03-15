// This implementation yet to be fully completed, was only done for implementing LRU Cache for now.
class DLL {
public:
    Node *head, *tail;
    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insert_front(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* get_last() {
        if(tail->prev == head) return nullptr;
        return tail->prev;
    }
};