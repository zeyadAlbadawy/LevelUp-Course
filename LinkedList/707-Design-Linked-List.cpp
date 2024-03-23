class MyLinkedList {
public:
    ListNode* dummy;
    ListNode* head;
    int cnt;

    MyLinkedList() {
        dummy = new ListNode(0);
        head = nullptr;
        cnt = 0;
    }

    int get(int index) {
        int itr = 0;
        ListNode* temp = head;
        while (temp && itr != index) {
            temp = temp->next;
            itr++;
        }
        return (temp && itr == index) ? temp->val : -1;
    }

    void addAtHead(int val) {
        ListNode* newN = new ListNode(val);
        newN->next = head;
        head = newN;
        cnt++;
    }

    void addAtTail(int val) {
        ListNode* newN = new ListNode(val);
        if (!head) {
            head = newN;
        } else {
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newN;
        }
        cnt++;
    }

    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        ListNode* newN = new ListNode(val);
        if (index <= 0) {
            newN->next = head;
            head = newN;
        } else {
            ListNode* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newN->next = temp->next;
            temp->next = newN;
        }
        cnt++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        ListNode* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            ListNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        cnt--;
    }
};
