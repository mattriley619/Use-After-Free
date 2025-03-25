#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>
#include <cstring>
#include <string>

using namespace std;

void loadRandomEntry(char** arr) 
{
    ifstream file;
    file.open("file.txt");

    int maxLength = 100; 

    string str;
    int lineCount = 21; 
    int randNum = rand() % lineCount;

    for (int i = 0; i <= randNum; i++) 
    {
        getline(file, str);
        
    }

    int arrNum = 0;
    while (arr[arrNum] != nullptr) 
    {
        arrNum++;
    }

    if (str.length() > maxLength) 
    {
        str = str.substr(0, maxLength);
    }
    arr[arrNum] = new char[str.length() + 1];
    strcpy(arr[arrNum], str.c_str());

    file.close();
}

int main()
{
    char** arr = new char*[100]();
    string str;

    ifstream file;
    file.open("file.txt");

    int n = 0;
    int maxLength = 100; 

    while(!file.eof())
    {
        getline(file, str);
        if (n < 100) 
        {
            if (str.length() > maxLength) 
            {
                str = str.substr(0, maxLength);
            }
            arr[n] = new char[str.length() + 1];
            strcpy(arr[n], str.c_str());
            n++;
        } 
        else
        {
            break;
        }
    }

    file.close();

    int num;
    int arrNum;
    bool isFull = false;

    while(!isFull) 
    {
        num = rand() % 4;

        if(num == 0) //delete a random entry
        {
            arrNum = rand() % 100;
            if (arr[arrNum] != nullptr) 
            {
                delete[] arr[arrNum];
                arr[arrNum] = nullptr;
            }

        }
        else if(num == 1)//display and then delete a random entry
        {  
            bool isNotEmpty = false;
            for (int i = 0; i < 100; i++) 
            {
                if (arr[i] != nullptr) 
                {
                    isNotEmpty = true;
                    break;
                }
            }

            if (isNotEmpty) 
            {
                arrNum = rand() % 100;

                while(arr[arrNum] == nullptr)
                {
                    arrNum = rand() % 100;

                    if (arr[arrNum] != nullptr) 
                    {
                        cout << arr[arrNum] << endl;
                        delete[] arr[arrNum];
                        arr[arrNum] = nullptr;
                        break;
                    }
                }
            
            }
        }
        else if(num == 2)//load a new entry into the array
        {
            loadRandomEntry(arr);
        }
        else if(num == 3)//load 2 entries into the array
        {
            loadRandomEntry(arr);
            loadRandomEntry(arr);
        }

        for(int i = 0; i < 100; i++)
        {
            if(arr[i] == nullptr)
            {
                isFull = false;
                break;
            }
            else
            {
                isFull = true;
            }
        }
    }

    for(int i = 0; i < 100; i++)
    {
        int random = rand() % 100;
        if(arr[random] != nullptr)
        {
            cout << arr[random] << endl;
            delete[] arr[random];
            arr[random] = nullptr;
        }
        else
        {
            i--;
        }
    }


   
}





