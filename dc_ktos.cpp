
#include <iostream>
#include <exception>
#include <cassert>

enum class Activity {
	active,
	inactive,
};

class Client {
private:
	char* name;

public:
	Client(const char* name)
	{
		assert(name != nullptr);

		this->setName(name);
	}

	void setName(const char* name) 
	{
		this->name = const_cast<char*>(name);
	}

	char* getName()
	{
		return this->name;
	}



};

class BankAccount {
private:
	char* accountNumber;
	double balance;
	Activity activity;
	Client* client;
	double interestRate;

	static int activeAccountCounter;

public:


	BankAccount(const char* accountNumber, double balance, Activity activity, Client* client) {
		setAccountNumber(accountNumber);
		setBalance(balance);
		setActivity(activity);
		setClient(client);
	
		if (activity == Activity::active) {
			increaseActiveAccountCounter();
		}
	}

	~BankAccount()
	{
		this->decreaseActiveAccountCounter();
	}

	void setAccountNumber(const char* accountNumber)
	{
		assert(accountNumber != nullptr);

		this->accountNumber = const_cast<char*>(accountNumber);
	}

	void setBalance(double balance)
	{
		if (balance < 0) {
			throw std::domain_error("sexed!!!");
		}

		this->balance = balance;
	}

	void setActivity(Activity activity)
	{
		if (activity != this->activity)
		{
			if (activity == Activity::active)
			{
				this->increaseActiveAccountCounter();
			}
			else {
				this->decreaseActiveAccountCounter();
			}
		}

		this->activity = activity;
	}

	void setClient(Client* client)
	{
		assert(accountNumber != nullptr);

		this->client = client;
	}

	void setInterestRate(double interestRate)
	{
		this->interestRate = interestRate;
	}

	char* getAccountNumber()
	{
		return this->accountNumber ;
	}

	double getBalance()
	{
		return this->balance ;
	}

	Activity getActivity()
	{
		return this->activity;
	}

	Client* getClient()
	{
		return this->client;
	}

	double getInterestRate(double interestRate)
	{
		return this->interestRate ;
	}

	void increaseActiveAccountCounter()
	{
		this->activeAccountCounter++;
	}

	void decreaseActiveAccountCounter()
	{
		this->activeAccountCounter--;
	}

	int getActiveAccountCounter()
	{
		return this->activeAccountCounter;
	}

	double getYearForecast()
	{
		return this->balance * (interestRate + 1);
	}

	operator double(){
		return this->balance;
	}

	BankAccount& operator+= (double balance) {
		this->balance += balance;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& str,BankAccount& val)
	{
		if (val.activity == Activity::active)
		{
			str << "[" << val.getAccountNumber() << "]" << " " << val.getClient()->getName() << " : " << "[" << val.getBalance() << "]";
		}
		else {
			str << "[" << val.getAccountNumber() << "]" << "NIEAKTYWNE";
		}
		return str;
	}
};

class SavingBankAccount :BankAccount {
	SavingBankAccount(BankAccount bankAccount, double interestRate) : BankAccount(bankAccount) {
		this->setInterestRate(interestRate);
	}
};

BankAccount ClientToBankAccount(Client *client) {
	return { "123", 0, Activity::active, client};
}



int BankAccount::activeAccountCounter = 0;

int main()
{
	Client client123 = {"123"};

	auto test = BankAccount("123", 999, Activity::active, &client123);
	std::cout << test;
}
