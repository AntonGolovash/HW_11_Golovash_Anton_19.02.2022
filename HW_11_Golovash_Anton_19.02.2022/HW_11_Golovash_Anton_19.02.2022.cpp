#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class PhoneBook
{
public:
	PhoneBook(string phoneNumber, string surname, string initials)
	{
		this->phoneNumber = phoneNumber;
		this->surname = surname;
		this->initials = initials;
	}
	~PhoneBook()
	{
		delete this;
	}
	string phoneNumber { "default" };
	string surname { "default" };
	string initials { "default" };
};


int main()
{
	vector<PhoneBook> setPhoneBook
	{
		PhoneBook("+380956347984","Петров","С.П."),
		PhoneBook("+380673596842","Самбуров","Р.Е."),
		PhoneBook("+380669845632","Крайнев","И.Н."),
		PhoneBook("","",""),
		PhoneBook("","",""),
		PhoneBook("","",""),
		PhoneBook("","",""),
		PhoneBook("","",""),
		PhoneBook("","",""),
		PhoneBook("","",""),
	};

	sort (setPhoneBook.begin(), setPhoneBook.end(), [](const PhoneBook& P1, const PhoneBook& P2)
		{ return P1.surname < P2.surname; });

	auto findIfResult = find_if (setPhoneBook.begin(), setPhoneBook.end(), [](const PhoneBook &P)
		{
			return P.surname == "Самбуров";
		});

	if (findIfResult == setPhoneBook.end())
	{
		cout << "Строка НЕ найдена" << endl;
	}
	else
	{
		cout << "Строка найдена" << endl;
	}
	return 0;
}
