#include <iostream>

using namespace std;

class DoublyLinkedList 
{
  private:
    typedef struct Node
	{
		int data;
		Node* next;
        Node* prev;

	}*nodePtr;

    Node* head;
    Node* tail;
    
  public:
    
    DoublyLinkedList()
    {
      head = NULL;      
      tail = NULL;
    }

    void AppendNode(int nodeData)
    {
        nodePtr n = new Node;

		n->next = NULL;
		n->data = nodeData;

        nodePtr curr;

		if (head != NULL)
		{
			curr = head;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = n;
            n->prev = curr;
		}
		else
		{			
            //If the list is empty
			head = n;
            tail = n;
            n->prev = NULL;
		}

    }

    void PrependNode(int nodeData)
    {
        nodePtr n = new Node;
        nodePtr temp = head;

		n->prev = NULL;
		n->data = nodeData;
        
        head = n;
        n->next = temp;
        temp->prev = n;

    }

    void RemoveNode(int nodeData)
    {
        nodePtr curr = head;
        bool nodeFound = true;

        while (curr->data != nodeData)
        {
            if(curr->next != NULL)
            {
                curr = curr->next;
            }
            else
            {
                nodeFound = false;
                break;
            }            
        }        

        if(nodeFound)
        {
            nodePtr next = curr->next;
            nodePtr prev = curr->prev;
            if(next != NULL)
            {
                next->prev = prev;
            }            
            else
            {
                tail = prev;
            }

            if(prev != NULL)
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }            

            free(curr);
        }
        else
        {
            cout << "Node not found" << endl;
        }

    }

    void Print()
    {
        nodePtr curr = head;
        while(curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.AppendNode(9);
    list.AppendNode(7);
    list.AppendNode(4);
    list.AppendNode(5);
    list.AppendNode(2);

    cout << "Initial State" << endl;
    list.Print();

    cout << "Removing 5" << endl;
    list.RemoveNode(5);
    list.Print();

    cout << "Removing 2" << endl;
    list.RemoveNode(2);
    list.Print();

    cout << "Removing 6" << endl;
    list.RemoveNode(6);
    list.Print();

    cout << "Prepending 99" << endl;
    list.PrependNode(99);
    list.Print();

    cout << "Appending 101" << endl;
    list.AppendNode(101);
    list.Print();
}
