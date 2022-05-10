#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Subscriber
{
public:
	Subscriber()
	{
		this->phoneNumber = "Default Number";
		this->surname = "Default Surname";
		this->name = "Default Name";
	}
	Subscriber(string phoneNumber, string surname, string name)
	{
		this->phoneNumber = phoneNumber;
		this->surname = surname;
		this->name = name;
	}
	~Subscriber()
	{
		delete this;
	}
	string phoneNumber;
	string surname;
	string name;
};

Subscriber& Search(const string &data)
{

}

int main()
{
	set <Subscriber> PhoneBookSet
	{
		Subscriber("+380956347984","Petrov","Sergey"),
		Subscriber("+380673596842","Samburov","Roman"),
		Subscriber("+380669845632","Kraynev","Igor"),
	};

	multiset <Subscriber> PhoneBookMultiSet;
	map <int, Subscriber> PhoneBookMap;
	multimap <int, Subscriber> PhoneBookMultiMap;

	string data = "";

	while (true)
	{
		cout << "For searching, please, enter the data" << endl;
		cin >> data;
		auto findIfResult = find_if(PhoneBookSet.begin(), PhoneBookSet.end(), [data](const Subscriber& P)
		{
				if (P.phoneNumber == data || P.surname == data || P.name == data)
				{
					return &P;
				}
		});

		if (findIfResult == PhoneBookSet.end())
		{
			cout << "String is NOT found" << endl;
		}
		else
		{
			cout << "String is found" << endl;
		}

	}
	
	//sort (PhoneBookVector.begin(), PhoneBookVector.end(), [](const Subscriber& P1, const Subscriber& P2)
	//	{ return P1.surname < P2.surname; });

	return 0;
}
