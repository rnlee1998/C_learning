#include <iostream>
#define MAXLEN 100
using namespace std;

class Sstring
{
public:
	char ch[MAXLEN + 1];
	int length;
	Sstring(const char* str):length(strlen(str))
	{
		for (int i = 1; i <= length;i++) 
		{
			ch[i] = *str;
			str++;
		}		
	}
};

int index_BF(Sstring slong, Sstring sshort);

int main()
{
	Sstring s1("aio");
	Sstring s2("45bnaaio");
	for(int i=1;i<=s1.length;i++){
		cout << s1.ch[i];
	}
	cout << endl;
	for (int i = 1; i <= s2.length; i++) {
		cout << s2.ch[i];
	}

	cout << endl;
	cout << index_BF(s2, s1)<<endl;
	return 0;
}

int index_BF(Sstring slong, Sstring sshort)
{
	int i = 1,j = 1;
	while (i <= sshort.length&&j <= slong.length) {
		if (sshort.ch[i] == slong.ch[j]) {
			i++;
			j++;
		}
		else
		{
			j = j - i + 2;//回溯：j = j-(i-1)+1
			i = 1;
		}

	}

	if (i >= sshort.length)	return (j - sshort.length);
	else return 0;
}