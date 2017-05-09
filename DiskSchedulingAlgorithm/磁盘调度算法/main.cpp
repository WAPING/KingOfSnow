#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#include<math.h>

using namespace std;

int max_id = 0;
int temp_poi;    //��ǰ��ͷλ��
int dir = 0;     //��ͷ�ƶ�����
vector<int> vec; //�����Ŵŵ�������е�����ṹ
int num = 0;
void FCFS()
{
	int temp = temp_poi;
	cout << temp;
	int len = 0;
	vector<int>::iterator itea;
	int i;
	for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)
	{
		len += abs(vec[i] - temp);
		temp = vec[i];	
		cout << ",";

		cout << temp;
	}
	cout << endl;
	cout << len << endl;
	return;
}
bool SortByDec(const int &v1, const int &v2)
{
	return v1 < v2;//��������
}
void SSTF()
{
	
	cout << temp_poi;
	int temp = temp_poi;
	int len = 0;
	while (num)
	{
		int minn = INT_MAX;
		int index = -1;
		vector<int>::iterator itea;
		int i=0;
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)//�ҳ��뵱ǰ��ͷλ������Ĵŵ�
		{
			
			if (abs(temp - vec[i]) <= minn)
			{
				if (abs(temp - vec[i]) == minn){
					if (dir == 1){
						if (vec[i] > vec[index]){
							index = i;
							continue;
						}
					}
					else if (dir == 0){
						if (vec[i] < vec[index]){
							index = i;
							continue;
						}
					}
				}
				minn = abs(temp - vec[i]);
				index = i;
			}
		}
		cout << ",";
		cout << vec[index];
		len += minn;
		temp = vec[index]; //��ǰ�ŵ����vec[i]
		vec.erase(vec.begin() + index); //ʹ�ù��Ĵŵ��Ӵŵ������г�ȥ
		num--;
	}
	cout << endl;
	cout << len << endl;
	return;
	
}
void SCAN()
{	
	cout << temp_poi;
	int temp = temp_poi;
	int len = 0;
	sort(vec.begin(), vec.end(), SortByDec); //����ŵ�������������

	if (dir == 1){
		vector<int>::iterator itea;
		int i;
		int index = -1;//��¼��ŵ�������ǰ����ʼ��λ��
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}
		if (index == -1){
			for (int jj = i - 1; jj >= 0; jj --)
			{
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		else{
			int jj;
			for (jj = index, itea = vec.begin() + index; itea != vec.end(); itea ++, jj ++)
			{
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
			for (int j = index - 1; j >= 0; j --)
			{
				cout << ",";
				cout << vec[j];
				len += abs(temp - vec[j]);
				temp = vec[j];
			}
		}
		
	}
	else{  //���ͷ�ż�С�����ƶ�

		vector<int>::iterator itea;
		int i;
		int index = -1;//��¼��ŵ���С����ǰ����ʼ��λ��
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)//�ҵ���ʼλ�õĺ�һ��λ�ã���һ���ȵ�ǰλ�ô��ǰ���£�
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}
		if (index == -1){    //ȫ�����Ǳȵ�ǰ�ڵ�С�Ĵŵ���������
			for (int jj = i - 1; jj >= 0; jj --){
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		else{
			for (int j = index - 1; j >= 0; j --)  //�����ҵ����������
			{
				cout << ",";
				cout << vec[j];
				len += abs(temp - vec[j]);
				temp = vec[j];
			}

			int jj;
			for (jj = index, itea = vec.begin() + index; itea != vec.end(); itea ++, jj ++)
			{
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		

	}
	cout << endl;
	cout << len << endl;
	return;
}
void CSCAN()
{
	cout << temp_poi;
	int temp = temp_poi;
	int len = 0;
	sort(vec.begin(), vec.end(), SortByDec); //����ŵ�������������

	if (dir == 1){
		vector<int>::iterator itea;
		int i;
		int index = -1;  //��¼��һ�����ڵ�ǰ�Ĵŵ�
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++) //�ҵ���ʼλ�õĺ�һ��λ�ã���һ���ȵ�ǰλ�ô��ǰ���£�
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}

		if (index == -1){    //ȫ�����Ǳȵ�ǰ�ڵ�С�Ĵŵ���������
			for (int jj = 0; jj < i; jj++){
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		else{
			int jj;
			for (jj = index, itea = vec.begin() + index; itea != vec.end(); itea++, jj++)
			{
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
			for (int ii = 0; ii < index; ii++)
			{
				cout << ",";
				cout << vec[ii];
				len += abs(temp - vec[ii]);
				temp = vec[ii];
			}
		}
	}
	else{

		vector<int>::iterator itea;
		int i;
		int index = -1;//��¼��ŵ���С����ǰ����ʼ��λ��
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)//�ҵ���ʼλ�õĺ�һ��λ�ã���һ���ȵ�ǰλ�ô��ǰ���£�
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}
		if (index == -1){    //ȫ�����Ǳȵ�ǰ�ڵ�С�Ĵŵ���������
			for (int jj = i - 1; jj >= 0; jj--){
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		else{
			for (int j = index - 1; j >= 0; j--)  //�����ҵ����������
			{
				cout << ",";
				cout << vec[j];
				len += abs(temp - vec[j]);
				temp = vec[j];
			}

			int jj;
			for (jj = index, itea = vec.begin() + index; itea != vec.end(); itea++, jj++);
			int ij;
			for (ij = jj - 1; ij >= index;ij --)
			{
				cout << ",";
				cout << vec[ij];
				len += abs(temp - vec[ij]);
				temp = vec[ij];
			}
		}
	}
	
	cout << endl;
	cout << len << endl;
	return;
}
int main()
{
	int type;
	cin >> type;
	cin >> temp_poi;
	cin >> dir;

	getchar();
	string str;
	cin >> str;
	str += ",";
	stringstream sstr(str);
	string taken;
	while (getline(sstr, taken, ','))
	{
		vec.push_back(atoi(taken.c_str()));
		num ++;
	}
	switch (type)
	{
		case 1:{
			FCFS();
			break;
			}
		case 2:{
			SSTF();
			break;
		}
		case 3:{
			SCAN();
			break;
		}
		case 4:{
			CSCAN();
			break;
		}
		default:
			break;
	}
	//system("pause");
	return 0;
}
