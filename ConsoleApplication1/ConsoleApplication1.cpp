#include <iostream>
#include <string>
#include<stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <map>
#include "info_board.h"
#include "Dictionary.h"
#include "windows.h"

void Task1() {
      info_board* info = new  info_board();
    info->Menu();
}
void Task2() {
    bool a = true;
    int n = 0;
    string path = "MyFile.txt";
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    Dictionary* diction = new  Dictionary();
    while (a) {
        system("cls");
        diction->Print();
        cout << "\nMenu" << endl;
        cout << "\n1-Search word" << endl;
        cout << "\n2-Add word" << endl;
        cout << "\n3-Remove word" << endl;
        cout << "\n4-Edit word" << endl;
        cout << "\n5-Save in file" << endl;
        cout << "\n6-Read fron file" << endl;
        cout << "\n7-Quite" << endl;
        cout << "\nDo your choise: ";
        cin >> n;
        if (n == 1) {
            string search;
            cout << "\nEnter  english word for searching: ";
            cin >> search;
            diction->Search(search);
        }
        else if (n == 2) {
            string enWord;
            string ruWord;
            cout << "\nEnter  english word for adding: ";
            cin >> enWord;
            cout << "\nEnter  russian word for adding: ";
            cin >> ruWord;
            diction->Add(enWord, ruWord);
        }
        else if (n == 3) {
            string del;
            cout << "\nEnter  english word for removing: ";
            cin >> del;
            diction->DelWord(del);
        }
        else if (n == 4) {
            string edit;
            string newEn;
            string newRu;
            cout << "\nEnter  english word for editing: ";
            cin >> edit;
            cout << "\nEnter a new english word: ";
            cin >> newEn;
            cout << "\nEnter a new russian word: ";
            cin >> newRu;
            diction->Redact(edit, newEn, newRu);
        }
        else if (n == 5) {
            File< Dictionary>* f = new File< Dictionary>(path);
            uint32_t sizeD = (sizeof(diction) / sizeof(Dictionary));
            f->Save(diction, sizeD);
        }
        else if (n == 6) {
            File< Dictionary>* f = new File< Dictionary>(path);
            uint32_t sizeD = (sizeof(diction) / sizeof(Dictionary));
            f->Load(diction);
        }
        else if (n == 7) {
            a = false;
            return;
        }
        else {
            cout << "\nUncorrect item menu!" << endl;
        }
    }
}
   
using namespace std;
int main()
{
  //Task1();
    Task2();
     return 0;
}

