#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class String
{
private:
	char* p_str;
public:
	String()
	{
		p_str = (char*)malloc(80 * sizeof(char));
		strcpy(p_str, "None");
	}
	String(int size)
	{
		p_str = (char*)malloc(size * sizeof(char));
		strcpy(p_str, "None");
	}
	String(char* str)
	{
		p_str = (char*)malloc(strlen(str) * sizeof(char) + 1);
		strcpy(p_str, str);
	}
	String(String& old_str)
	{
		p_str = (char*)malloc(strlen(old_str.p_str) * sizeof(char) + 1);
		strcpy(p_str, old_str.p_str);
	}

	void Show_Str()
	{
		cout << p_str << endl;
	}

	void Enter_Str()
	{
		char p_str[200];
		cin >> p_str;
		this->p_str = (char*)realloc(this->p_str, strlen(p_str) * sizeof(char) + 1);
		strcpy(this->p_str, p_str);
	}
	~String()
	{
		free(p_str);
	}
};

void Func(String str_new)
{
	str_new.Show_Str();
}

int main()
{
	String str(10);
	str.Show_Str();
	str.Enter_Str();
	str.Show_Str();
	Func(str);

	String temp = str;
	temp.Show_Str();

	return 0;
}