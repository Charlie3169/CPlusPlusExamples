#include <iostream>
#define ARRAY_SIZE 10

using namespace std;

template <class T>
class OrderedList
{
    protected:
        T *arr[ARRAY_SIZE] = {};
        T x;
        int moveCount = 0;
        int comparisonCount = 0;

    public:

        OrderedList()
        {

        }


        void AddItem(T item)
        {
            bool itemAdded = false;
            int index = 0;

            while(!itemAdded && index < ARRAY_SIZE)
            {
                comparisonCount++;
                if(isEmpty(index))
                {
                    arr[index] = new T;
                    *arr[index] = item;
                    itemAdded = true;                    
                    break;

                }
                index++;

                if(index == ARRAY_SIZE)
                {
                    cout << "Cannot add any more items!" << endl;
                }
            }
        }

        void RemoveItem(int index)
        {
            if(!isEmpty(index))
            {
                int i = index;
                while(i < ARRAY_SIZE - 1 && arr[i + 1] != NULL )
                {
                    arr[i] = arr[i + 1];

                    moveCount++;
                    comparisonCount++;

                    i++;
                }

                delete arr[i];
                arr[i] = NULL;

            }
            else
            {
                //Removed for testing
                //cout << "Index already empty!" << endl;
            }

        }


        bool isEmpty(int index)
        {
            if(arr[index] == NULL)
            {
                return true;
            }
            return false;
        }

        bool isFull()
        {
            for(int i = 0; i < ARRAY_SIZE; i++)
            {
                if(isEmpty(i))
                {
                    return false;
                }
            }
            return true;
        }

        void makeEmpty()
        {

            for(int i = 0; i < ARRAY_SIZE; i++)
            {
                if(!isEmpty(i))
                {
                    delete arr[i];
                    arr[i] = NULL;
                }
            }

        }

        void printArray()
        {
            for(int i = 0; i < ARRAY_SIZE; i++)
            {
                if(isEmpty(i))
                {
                    cout << "Index " << i << ": NULL" << endl;
                }
                else
                {
                    cout << "Index " << i << ": " << *arr[i] << endl;
                }

            }
            cout << endl;

        }

        void getTotalOperations()
        {
            cout << "Move count:" << moveCount << endl
                 << "Comparison count:" << comparisonCount << endl;
        }



        bool operator <(const T& rhs)
        {
            return (this < rhs);
        }

        bool operator >(const T& rhs)
        {
            return (this > rhs);
        }

        bool operator ==(const T& rhs)
        {
            return (this == rhs);
        }


};

/**
    Add the items at the end of the array
*/

template <class T>
class ReversedOrderList : public OrderedList<T>
{
    public:
        void AddItem(T item)
        {

            bool itemAdded = false;
            int index = ARRAY_SIZE - 1;

            while(!itemAdded && index > -1)
            {
                OrderedList<T>::comparisonCount++;

                if(OrderedList<T>::isEmpty(index))
                {
                    OrderedList<T>::arr[index] = new T;
                    *OrderedList<T>::arr[index] = item;
                    itemAdded = true;                    
                    break;

                }
                index--;

                if(index == -1)
                {
                    cout << "Cannot add any more items!" << endl;
                }
            }

        }

        void RemoveItem(int index)
        {

            if(!OrderedList<T>::isEmpty(index))
            {
                int i = index;
                while(i > 0 && OrderedList<T>::arr[i - 1] != NULL )
                {
                    OrderedList<T>::arr[i] = OrderedList<T>::arr[i - 1];

                    OrderedList<T>::moveCount++;
                    OrderedList<T>::comparisonCount++;

                    i--;
                }

                delete OrderedList<T>::arr[i];
                OrderedList<T>::arr[i] = NULL;

            }
            else
            {
                //Removed for testing
                //cout << "Index already empty!" << endl;
            }


        }

};

template <class T>
class AlternateOrderList : public OrderedList <T>
{
    private:

        void insertItem(int index, T item)
        {
            //Might not be necessary to check but just to be safe
            if(OrderedList<T>::isEmpty(index))
            {
                OrderedList<T>::arr[index] = new T;
                *OrderedList<T>::arr[index] = item;
            }
            else
            {
                *OrderedList<T>::arr[index] = item;
            }
            
        }

        //Shifts should only be called if the target index is already not empty
        void shiftLeft(int targetIndex)
        {
            int j = targetIndex;

            //Finds the location to shift everything relative to
            while(isValidIndex(j) && OrderedList<T>::arr[j] != NULL)
            {
                j--;
            }
            
            if(!isValidIndex(j))
            {
                //Walk back a step 
                j++;
            }

            int holeIndex = j;


            for(int i = holeIndex; i < targetIndex; i++)
            {
                OrderedList<T>::arr[i] = OrderedList<T>::arr[i + 1];
                OrderedList<T>::moveCount++;                
            }

        }

        //Shifts should only be called if the target index is already not empty
        void shiftRight(int targetIndex)
        {

            int j = targetIndex;

            //Finds the location to shift everything relative to
            while(isValidIndex(j) && OrderedList<T>::arr[j] != NULL)
            {
                j++;
            }

            if(!isValidIndex(j))
            {
                //Walk back a step 
                j--;
            }
            int holeIndex = j;


            for(int i = holeIndex; i > targetIndex; i--)
            {
                OrderedList<T>::arr[i] = OrderedList<T>::arr[i - 1];
                OrderedList<T>::moveCount++;
            }

        }


        bool spaceExistsLeft(int targetIndex)
        {
            for(int i = targetIndex; i > -1; i--)
            {
                if(OrderedList<T>::isEmpty(i))
                {                    
                    return true;
                }
            }
            return false;
        }

        bool spaceExistsRight(int targetIndex)
        {
            for(int i = targetIndex; i < ARRAY_SIZE; i++)
            {
                if(OrderedList<T>::isEmpty(i))
                {
                    return true;
                }
            }
            return false;
        }

        bool isValidIndex(int targetIndex)
        {
            return !(targetIndex > ARRAY_SIZE - 1 || targetIndex < 0);
        }


    public:

        void AddItem(T item)
        {
            if(OrderedList<T>::isFull())
            {
                cout << "Cannot add any more items!" << endl;
            }
            else
            {
                int targetIndex = (ARRAY_SIZE / 2) - 1;

                while(true)
                {
                    if(OrderedList<T>::isEmpty(targetIndex))
                    {
                        insertItem(targetIndex, item);
                        break;
                    }
                    else
                    {
                        if(item < *OrderedList<T>::arr[targetIndex])
                        {                            
                            targetIndex--;
                            if(isValidIndex(targetIndex))//To ensure no index out of bounds
                            {
                                if(!OrderedList<T>::isEmpty(targetIndex) && item > *OrderedList<T>::arr[targetIndex])
                                {
                                    //Spot to add
                                    if(spaceExistsLeft(targetIndex))
                                    {
                                        shiftLeft(targetIndex);
                                        insertItem(targetIndex, item);
                                        break;
                                    }
                                    else //It should be true that space exists to the right
                                    {
                                        shiftRight(targetIndex);
                                        insertItem(targetIndex, item);
                                        break;

                                    }
                                }
                            }
                            else
                            {
                                if(spaceExistsRight(0))
                                {
                                    shiftRight(0);
                                    insertItem(0, item);
                                    break;
                                }
                                else
                                {
                                    cout << "Array Full?" << endl;
                                    break;
                                }
                                
                            }

                            
                        }
                        else if(item > *OrderedList<T>::arr[targetIndex])
                        {
                            targetIndex++;
                            if(isValidIndex(targetIndex)) //To ensure no index out of bounds
                            {
                                if(!OrderedList<T>::isEmpty(targetIndex) && item < *OrderedList<T>::arr[targetIndex])
                                {
                                    //Spot to add
                                    if(spaceExistsRight(targetIndex))
                                    {
                                        shiftRight(targetIndex);
                                        insertItem(targetIndex, item);
                                        break;
                                    }
                                    else //It should be true that space exists to the left
                                    {
                                        shiftLeft(targetIndex);
                                        insertItem(targetIndex, item);
                                        break;
                                    }
                                }   
                            }
                            else 
                            {
                                if(spaceExistsLeft(ARRAY_SIZE - 1))
                                {
                                    shiftRight(ARRAY_SIZE - 1);
                                    insertItem(ARRAY_SIZE - 1, item);
                                    break;
                                }
                                else
                                {
                                    cout << "Array Full?" << endl;
                                    break;
                                }                                
                            }                            
                        }
                        else if(item == *OrderedList<T>::arr[targetIndex])
                        {
                            cout << "Item already exists!" << endl;
                            break;
                        }
                    }
                }
            }
        }

        void RemoveItem(int index)
        {
            if(!OrderedList<T>::isEmpty(index))
            {
                delete OrderedList<T>::arr[index];
                OrderedList<T>::arr[index] = NULL;

            }
            else
            {
                cout << "Index already empty!" << endl;
            }


        }

};




int main()
{
    
    OrderedList<int> list1;
    ReversedOrderList<int> list2;
    //AlternateOrderList<int> list3;



    cout << "Adding values..." << endl;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        int r = rand() % 100 + 1;

        list1.AddItem(r);
        list2.AddItem(r);
        //list3.AddItem(r);
    }

    cout << "List 1" << endl;
    list1.printArray();

    cout << "List 2" << endl;
    list2.printArray();

    //cout << "List 3" << endl;
    //list3.printArray();

    for(int i = 0; i < ARRAY_SIZE - 5; i++)
    {
        int r = rand() % ARRAY_SIZE;
        
        list1.RemoveItem(r);
        list2.RemoveItem(r);
        //list3.RemoveItem(r);
    }

    cout << "Removing values..." << endl;

    cout << "List 1" << endl;
    list1.printArray();    

    cout << "List 2" << endl;
    list2.printArray();

    //cout << "List 3" << endl;
    //list3.printArray();

    cout << endl;

    list1.getTotalOperations();
    cout << endl;

    list2.getTotalOperations();
    cout << endl;

    //list3.getTotalOperations();
    //cout << endl;

    cout << "Running the above program 99 more times" << endl << endl;

    list1.makeEmpty();
    list2.makeEmpty();

    for (int i = 0; i < 100; i++)
    {
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
            int r = rand() % 100 + 1;

            list1.AddItem(r);
            list2.AddItem(r);
            //list3.AddItem(r);
        }

        for(int i = 0; i < ARRAY_SIZE - 5; i++)
        {
            int r = rand() % ARRAY_SIZE;
            

            list1.RemoveItem(r);
            list2.RemoveItem(r);
            //list3.RemoveItem(r);
        }

        

        

        list1.makeEmpty();
        list2.makeEmpty();
        //list3.makeEmpty();
        
    }
    
    cout << "List 1" << endl;
    list1.getTotalOperations();
    cout << endl;

    cout << "List 2" << endl;
    list2.getTotalOperations();
    cout << endl;

    //cout << "List 3" << endl;
    //list3.getTotalOperations();
    //cout << endl;

    
    //Task 3 testing
    /*
    
    AlternateOrderList<int> test;


    for(int i = 0; i < 15; i++)
    {        
        test.AddItem(i * 2);
        cout << "Added item " << i << endl;
        test.printArray();
    }    

    */



    return 0;
}
