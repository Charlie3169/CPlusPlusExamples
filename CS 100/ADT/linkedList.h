#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList 
{ 
    private:     
        struct ListNode    
        {      
            double data;       
            ListNode *Next; 
        }; 

        ListNode *head;

    public:

        LinkedList()
        {
            head = NULL;
        }

        ~LinkedList();

        LinkedList(const LinkedList& l);

        void appendNode(double);
        void insertNode(double);
        void deleteNode(double);
        void displayList() const;
        void destroyList();
        LinkedList& operator=(const LinkedList& l);

};

#endif