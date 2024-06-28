#include <iostream>
#include <string>

using namespace std;


class myVector
{
    public:
      double *dataArray;
      size_t  dataSize;
      size_t  dataCapacity;
    public:
      myVector(); // constructor
      ~myVector();
      void push_back(double data);
      double at(size_t index) const;
      double &operator[](size_t index); 
      size_t size() const;
      size_t capacity() const;
};



myVector::myVector()
{
  dataArray = new double[2];
  dataCapacity = 2;
  dataSize = 0;
}


myVector::~myVector()
{
  delete [] dataArray;
  dataCapacity = 0;
  dataSize = 0;
}

void myVector::push_back(double data)
{  
  if(size() < capacity())
  {    
    dataArray[size()] = data;    
    dataSize++; 
  }
  else
  {    
    //Original data
    double *oldData = dataArray;    
    size_t  oldDataCapacity = dataCapacity;
    size_t  oldDataSize = dataSize;      
    
    
    //Create data
    dataArray = new double[oldDataCapacity * 2];
    dataCapacity = oldDataCapacity * 2;
    dataSize = 0;

    //Copying old data over to new data
    for (size_t i = 0; i < oldDataSize; i++)
    {
      
      dataArray[i] = oldData[i];      
      dataSize++;     
    }

    //Delete temp data, not sure if necessary because it wasn't created explicitly with new
    delete [] oldData;

    //Pushing back original element
    dataArray[oldDataSize] = data;
    dataSize++; 
  }
  

}
double myVector::at(size_t index) const
{
  return dataArray[index];
}
double& myVector::operator[](size_t index)
{
  return dataArray[index];
}

size_t myVector::size() const
{
  return dataSize;
}

size_t myVector::capacity() const
{
  return dataCapacity;
}






// define a queue of strings
//
struct node
{
  string data;
  node *next;
};

class stringQueue
{
  public:
    node* head; // pointer to the list
  public:
    stringQueue(); // make sure you initialize the queue to be initially empty.
    ~stringQueue(); // make sure you release all memory blocks
    void enqueue(string s); // enter a string to the queue
    string dequeue();  // remove an item from the front of the queue and return the string
    bool isEmpty();    // return true if queue is empty, otherwise return false;
};


stringQueue::stringQueue()
{
    head = NULL;
    //head->next = NULL;    
}

stringQueue::~stringQueue()
{
    // delete all nodes. However you don't have to implement this function and we will not test it
    head = NULL;
}

void stringQueue::enqueue(string s)
{
  node* newNode = new node;
  newNode->data = s;
  newNode->next = NULL;

  if(isEmpty())
  {
    head = newNode;    
  }
  else
  {
    node* currentNode = head;
    while (currentNode->next != NULL)
    {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
  }
  

}

string stringQueue::dequeue()
{  
  string returnVal = head->data;  
  head = head->next;
  return returnVal;

}

bool stringQueue::isEmpty()
{
  if(head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }

}


// the following main function is provided to you to test your code. This portion will not be unit-tested. 
// You are free to modify the main() function.

int main()
{
  /*
   // 
   // testing queue operations
   //
   
     stringQueue myQueue;
     myQueue.enqueue("1st string");
     myQueue.enqueue("2nd string");
     myQueue.enqueue("3rd string");
     myQueue.enqueue("4th string");
     
     cout << "Starting dequeueing ... \n";
     while (! myQueue.isEmpty())
     {
         cout << myQueue.dequeue() << endl;
     }
  */
     
  
   // 
   // testing myVector operations
   //
    myVector v;
    
    cout << "vector size = " << v.size()
         << " vector capacity = " << v.capacity() << endl;
         
    cout << "vector contains: ";
    for (size_t i=0; i<v.size(); i++)
      cout << v.at(i) << " ";
    cout << endl;
            
    cout << "Now adding some data...\n";
    
    v.push_back(11.1);
    v.push_back(22.2);
    //cout << v.at(0) << endl;    
    v.push_back(33.3);
    //cout << v.at(0) << endl;
    v.push_back(44.4);
    v.push_back(55.5);
    
    cout << "vector size = " << v.size()
         << " vector capacity = " << v.capacity() << endl;
         
    cout << "vector contains: ";
    for (size_t i=0; i<v.size(); i++)
      cout << v.at(i) << " ";
    cout << endl;
            
    
    cout << "testing [] opertator: ";
    for (size_t i=0; i<v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
            
    cout << "testing [] opertator again: ";
    v[0]  = 0;
    v[1]  = -1;
    for (size_t i=0; i<v.size(); i++)
      cout << v[i] << " ";
    cout << endl;    

  
    
    
}
