#pragma once
#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

class train
{
private:
	uint32_t number;
	string time;
	string destination;
public:
	train(uint32_t number, string time, string destination) {
		this->destination = destination;
		this->time = time;
		this->number = number;
	}
	train() :train(0,"","") {};
	uint32_t Getnumber()const{return this->number; }
	string GetTime()const { return this->time; }
	string Getdestination()const { return this->destination; }
	friend ostream& operator<<(ostream& out, train& obj) {
		out << "Number:  " << obj.number << "  "<<"time: "
			<< obj.time <<"  "<< "destination: " << obj.destination << endl;
		return out;
	}
};

class info_board
{
 private:
	 vector <train>* t;
public:
	info_board() { this->t = new  vector <train>(); }
	~info_board() { t->~vector(); }
	void Add(uint32_t number, string time, string destination) {
		train obj(number, time, destination);
		t->push_back(obj);
	}
	void Print() {
		if (t->empty()) {
			cout << "\nNo information!" << endl;
		}
		else {
			auto iter = t->begin();
			for (; iter != t->end(); iter++) {
				cout <<(* iter) << endl;
			}
		}
	}
	void Search(string time) {
		bool chek = false;
		auto iter = t->begin();
		if (!t->empty()) {
			for (size_t i = 0; i < t->size(); i++) {
				for (; iter != t->end(); iter++) {
					if (iter->GetTime() == time) {
						cout << (*iter);
						chek = true;
					}
				}
			}
		}
		if (!chek) {
			cout << "\nNo information!" << endl;
		}
		system("pause");
	}
	void Menu() {
		bool a = true;
		while (a) {
			system("cls");
			int switch_o = 0;
			cout << "\nMenu:" << endl;
			cout << "\n1- Add info" << endl;
			cout << "\n2- Search info" << endl;
			cout << "\n3-Out all info" << endl;
			cout << "\n4-Exit" << endl;
			cout << "\nDo your choise: ";
			cin >> switch_o;
			if (switch_o == 1) {
				uint32_t num;
				string time;
				string dest;
				cout << "\nEnter a number of traine: ";
				cin >> num;
				cout << "\nEnter a train departure time: ";
				cin >> time;
				cout << "\nEnter a destination: ";
				cin >> dest;
				this->Add(num, time, dest);
			}
			else if (switch_o == 2) {
				string time;
				cout << "\nEnter a train departure time: ";
				cin >> time;
				this->Search(time);
			}
			else if (switch_o == 3) {
				this->Print();
				system("pause");
			}
			else if (switch_o == 4) {
				a = false;
				return;
			}
			else {
				cout << "\n Uncorrect value!" << endl;
			}
		}
    }
};



