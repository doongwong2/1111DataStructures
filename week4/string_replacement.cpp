#include<iostream>
#include<string>
using namespace std;

int main()
{
	char str1[100] = { 0 }, tgt1[100] = { 0 }, rpl1[100] = { 0 };
	fgets(str1, 100, stdin);
	fgets(tgt1, 100, stdin);
	fgets(rpl1, 100, stdin);
	char str[100] = { 0 };
	char rpl[100] = { 0 };
	char tgt[100] = { 0 };
	string ans = "";
	int i = 0;
	while (str1[i] != '\n')
	{
		str[i] = str1[i];
		i++;
	}
	i = 0;
	while (tgt[i] != '\n')
	{
		tgt[i] = tgt1[i];
		i++;
	}
	i = 0;
	while (rpl1[i] != '\n')
	{
		rpl[i] = rpl1[i];
		i++;
	}
	string sample = str, target = tgt, replace = rpl;
	while (sample.find(target, 0) != -1)
	{
		ans = "";
		ans.append(sample, 0, sample.find(target, 0));
		ans.append(sample, sample.find(target, 0) + target.length(), sample.length());
		ans.insert(sample.find(target, 0), replace);
		sample = ans;
	}
	cout << ans << endl;
	return 0;
}
