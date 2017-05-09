#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#include<math.h>

using namespace std;

int max_id = 0;
int temp_poi;    //当前磁头位置
int dir = 0;     //磁头移动方向
vector<int> vec; //申请存放磁道请求队列的数组结构
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
	return v1 < v2;//升序排序
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
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)//找出离当前磁头位置最近的磁道
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
		temp = vec[index]; //当前磁道变成vec[i]
		vec.erase(vec.begin() + index); //使用过的磁道从磁道队列中除去
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
	sort(vec.begin(), vec.end(), SortByDec); //请求磁道序列升序排列

	if (dir == 1){
		vector<int>::iterator itea;
		int i;
		int index = -1;//记录向磁道增大方向前进开始的位置
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
	else{  //向磁头号减小方向移动

		vector<int>::iterator itea;
		int i;
		int index = -1;//记录向磁道减小方向前进开始的位置
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)//找到起始位置的后一个位置（有一个比当前位置大的前提下）
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}
		if (index == -1){    //全部都是比当前节点小的磁道请求序列
			for (int jj = i - 1; jj >= 0; jj --){
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		else{
			for (int j = index - 1; j >= 0; j --)  //先由右到左遍历排序
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
	sort(vec.begin(), vec.end(), SortByDec); //请求磁道序列升序排列

	if (dir == 1){
		vector<int>::iterator itea;
		int i;
		int index = -1;  //记录第一个大于当前的磁道
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++) //找到起始位置的后一个位置（有一个比当前位置大的前提下）
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}

		if (index == -1){    //全部都是比当前节点小的磁道请求序列
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
		int index = -1;//记录向磁道减小方向前进开始的位置
		for (itea = vec.begin(), i = 0; itea != vec.end(); itea++, i++)//找到起始位置的后一个位置（有一个比当前位置大的前提下）
		{
			if (vec[i] > temp){
				index = i;
				break;
			}
		}
		if (index == -1){    //全部都是比当前节点小的磁道请求序列
			for (int jj = i - 1; jj >= 0; jj--){
				cout << ",";
				cout << vec[jj];
				len += abs(temp - vec[jj]);
				temp = vec[jj];
			}
		}
		else{
			for (int j = index - 1; j >= 0; j--)  //先由右到左遍历排序
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
