#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

struct StudentRec
{
    string FirstName;
    string LastName;
    string ID;
    double GPA; 
};

void writeFile(string filename, vector<StudentRec> & v)
{
    ofstream outFile;
    outFile.open(filename);
    	
    if (!outFile.is_open()) 
    {
        cout << "Problem creating file";        
        exit(1);           
    }   

    for (int i = 0; i < v.size(); ++i)
    {
        outFile << setprecision(2) << fixed
                << v.at(i).FirstName << " "
                << v.at(i).LastName << " "
                << v.at(i).ID << " " 
                << v.at(i).GPA << endl;        
    }

    outFile.close();

}

void display(vector<StudentRec> & v)
{
    double sum = 0;
    int count = 0;

    cout << "No." << setw(15) << "Name" << setw(23) << "ID" << setw(22) << "GPA" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    for (int i = 0; i < v.size(); ++i)
    {
        cout << left << setprecision(2) << fixed
             << setw(14) << i + 1
             << setw(23) << v.at(i).LastName + ", " + v.at(i).FirstName              
             << setw(22) << v.at(i).ID
             << v.at(i).GPA << endl;        

        sum += v.at(i).GPA;
        count++;
    }

    double average = sum / count;

    cout << right << endl << setw(27) << "Class Average" << setw(36) << average << endl;

}

int stringToInt(string id)
{
    string newString = id.substr(1, id.size());    
    int value = stoi(newString);
}

int binarySearch(vector<StudentRec> & v, int searchID)
{
    int mid = 0;
    int low = 0;
    int high = v.size() - 1;
   
    while (high >= low) 
    {
        mid = (high + low) / 2;
        if (stringToInt(v.at(mid).ID) < searchID) 
        {
            low = mid + 1;
        }
        else if (stringToInt(v.at(mid).ID) > searchID) 
        {
            high = mid - 1;
        }
        else 
        {
            return mid;            
        }
    }    

    return -1;

}

void sortDatabase(int size, vector<StudentRec> & v)
{    
    //IDK why but this doesn't sort when called
    StudentRec temp;

    for (int i = 0; i < size - 1; i++)
    {
      for (int j = 0; j < size - i - 1; j++) 
      {
         if (stringToInt(v.at(j).ID) > stringToInt(v.at(j + 1).ID)) 
         {
            temp = v.at(j);
            v.at(j) = v.at(j + 1);
            v.at(j + 1) = temp;
         }
      }
   }

}

void loadDatabase(string filename, vector<StudentRec> & v)
{    
    ifstream inFile;
    inFile.open(filename);     

    if(!inFile.is_open()) 
    {
        cout << "Problem loading file";        
        exit(1);
    }    

    while (!inFile.fail()) 
    {           
        StudentRec student;       

        inFile >> student.FirstName >> student.LastName >> student.ID >> student.GPA;
        v.push_back(student);        
    }    

    //It always loads in a comma as the last value (?) so this removes that
    v.pop_back();

    sortDatabase(v.size(), v);
    
    inFile.close();

}

StudentRec addStudent(vector<StudentRec> & v)
{
    StudentRec student;

    cin.clear();      
    cin.ignore(1000, '\n');

    cout << "Please enter a student's information:" << endl;
    cin >> student.FirstName >> student.LastName >> student.ID >> student.GPA;    

    int location = binarySearch(v, stringToInt(student.ID));
    if(location != -1)
    {
        cout << "Overriding student" << endl;  
        v.at(location) = student;      

    }

    return student;
}

void deleteStudent(vector<StudentRec> & v)
{
    int studentID;

    cin.clear();      
    cin.ignore(1000, '\n');

    cout << "Please enter a student's ID to delete:" << endl;
    cin >> studentID;

    int returnedStudentLocation = binarySearch(v, studentID);
    if(returnedStudentLocation != -1)
    {
        v.erase(v.begin() + returnedStudentLocation);    
              

    }
    else
    {
        cout << "No student exists with that ID" << endl;
    }

    
    
    
    
}

void findStudentByName(vector<StudentRec> & v)
{
    string inputName;
    string lastName;
    string firstName;

    cin.clear();      
    cin.ignore(1000, '\n');

    cout << "Please enter a student's name (Last, First): " << endl;
    getline(cin, inputName);
    
    for (size_t i = 0; i < inputName.size(); i++)
    {        
        if(inputName[i] == ',')
        {
            lastName = inputName.substr(0, i);
            firstName = inputName.substr(i + 2, inputName.size() - 1);           
            i = inputName.size();
        }        
    }      

    bool matchFound = false;

    cout << endl << "Matches found:" << endl;

    for (size_t i = 0; i < v.size(); i++)
    {
        
        if(v.at(i).FirstName == firstName && v.at(i).LastName == lastName)
        {
            cout << fixed << setprecision(2) << v.at(i).LastName << ", " << v.at(i).FirstName << " " << v.at(i).ID << " " << v.at(i).GPA  << endl;
            matchFound = true;
        }
    }

    if(!matchFound)
    {
        cout << "No matches found" << endl;
    }

    
}

void findStudentByID(vector<StudentRec> & v)
{
    string inputID;
    cin.clear();      
    cin.ignore(1000, '\n');

    cout << "Please enter a student's ID to search: " << endl;
    getline(cin, inputID);

    int searchID = stringToInt(inputID);

    int location = binarySearch(v, searchID);

    if(location != -1)
    {
        cout << "Student found:" << endl;        
        cout << fixed << setprecision(2) << v.at(location).LastName << ", " << v.at(location).FirstName << " " << v.at(location).ID << " " << v.at(location).GPA  << endl;
    }
    else
    {
        cout << "No student with that ID found" << endl;
    }
    
    
}

void menu(string filename, vector<StudentRec> & v)
{
    
    int selection;    
    

    const int ADD = 1,
              DELETE = 2,
              FIND_ID = 3,
              FIND_NAME = 4,
              DISPLAY = 5,
              EXIT = 6;

    do
    {      
        cout << endl << "Student Records/Charlie Phelps/Copyright 2021" << endl << endl;
        cout << "Please choose:" << endl;
        cout << "(1) Add a student record" << endl; 
        cout << "(2) Delete a student record" << endl; 
        cout << "(3) Find a student's information by ID" << endl; 
        cout << "(4) Find a student's information by name" << endl; 
        cout << "(5) Display all information in the database" << endl; 
        cout << "(6) Exit Program" << endl << endl; 

        cout << v.size() << endl;

        cin.clear();      
        cin.ignore(1000, '\n');  
        cin >> selection;
               
        
        

        while (selection < ADD || selection > EXIT)       
        {            
               cout << "Please enter a valid menu choice: " << endl;
               cin.clear();
               cin.ignore(1000, '\n');
               cin >> selection;
        }

        

        switch (selection)
        {
            case ADD:
                v.push_back(addStudent(v)); 
                sortDatabase(v.size(), v);               
                break;

            case DELETE:
                deleteStudent(v);
                break;

            case FIND_ID:
                findStudentByID(v);                
                break;

            case FIND_NAME:
                findStudentByName(v);                
                break;

            case DISPLAY:
                display(v);                
                break;     

            case EXIT:
                writeFile(filename, v);   
                cout << "File written. Exiting..." << endl;
                           
                break;       

            default:
                //The while loop above wasn't catching the first case of an error, so I put this here as well
                cout << "Please enter a valid menu choice: " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                break;

        }

    } while (selection != EXIT);

}


int main() 
{      
    vector<StudentRec> AllStudentRecords;  
    string filename = "C:/Users/Charlie/Desktop/Useful/Code/C++/Files/StudentRecords.txt";        

    loadDatabase(filename, AllStudentRecords);
    menu(filename, AllStudentRecords);   
    

    return 0;
}