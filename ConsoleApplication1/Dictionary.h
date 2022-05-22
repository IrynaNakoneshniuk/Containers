#pragma once
#include <map>
#include<iostream>
#include <fstream>
using namespace std;

template<typename T>class File {
private:
    fstream file;
    string path; 
public:
    void ChangePath(string path)
    {
        this->path = path;
    }
 
    bool Save(T* object, uint32_t length = 0)
    {
        try {
            this->file.open(path, ios::out | ios::binary);
            if (!file.is_open())
            {
                throw;
            }
            else {
                T buf = *object;
                file.write((char*)&buf, sizeof(buf));
                file.close();
            }
            return true;
        }
        catch (const ifstream::failure& e)
        {
            cout << e.what() << endl;
            return false;
        }
    }
    void Load(T* object)
    {
        try {
            object = new T();
            this->file.open((path), ios::in|ios::binary);
            if (!file.is_open())
            {
                throw;
            }
            else {
                T buf;
                file.read((char*)&buf, sizeof(buf));
                *object = buf;
                file.close();
            }
        }
        catch (const ifstream::failure& e)
        {
            cout << e.what() << endl;
        }
    }
    bool Clear()
    {
        try {
            this->file.open((path), ios::trunc | ios::binary);
            if (!file.is_open())
            {
                throw;
            }
            else {
                cout << "Clear!" << endl;
                file.close();
            }
            return true;
        }
        catch (const ifstream::failure& e)
        {
            cout << e.what() << endl;
            return false;
        }
    }
    File() = default;
    File(string path)
    {
        ChangePath(path);
    }
};
class Dictionary
{
private:
	map <string,string>*dictionary;
public:
	Dictionary() {
		dictionary = new map < string, string>();
	}
	~Dictionary() {
		dictionary->clear();
	}
	void Add(string keyWord, string  ruWord) {
		pair<string, string> p1(keyWord, ruWord);
		dictionary->insert(p1);
	}
	void DelWord(string keyWord) {
		dictionary->erase(keyWord);
	}
	void Search(string keyWord) {
		auto item=dictionary->find(keyWord);
		if (item != dictionary->end()) {
			cout << item->first << ": " << " " << item->second << endl;
		}
		else {
			cout << "\nWord not found!" << endl;
		}
	}
	void Redact(string keyWord,string key,string val) {
		pair<string, string> element(key, val);
		auto item = dictionary->find(keyWord);
		if (item != dictionary->end()) {
			dictionary->erase(keyWord);
			dictionary->insert(element);
		}
		else {
			cout << "\nWord not found!" << endl;
		}
	}
	void Print() {
		auto item = dictionary->begin();
		for ( ;item != dictionary->end(); item++)
		{
			cout << item->first << " : " << item->second << endl;
		}
	}
};

