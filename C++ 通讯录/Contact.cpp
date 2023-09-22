#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#define MAX 100


using namespace std;

void menu()
{
	cout << "********************************" << endl;
	cout << "****** 欢迎来到通讯录系统 ******" << endl;
	cout << "********************************" << endl;
	cout << "******    1.增加联系人    ******" << endl;
	cout << "******    2.显示联系人    ******" << endl;
	cout << "******    3.修改联系人    ******" << endl;
	cout << "******    4.查找联系人    ******" << endl;
	cout << "******    5.删除联系人    ******" << endl;
	cout << "******    6.清空联系人    ******" << endl;
	cout << "******    7.退出通讯录    ******" << endl;
	cout << "********************************" << endl;
}

struct People
{
	string Name;
	int Age;
	int Sex;
	string Phone;
	string Addr;
};

struct ContactBooks
{
	People s[MAX];
	int size;
};

//增加联系人
void AddContact(ContactBooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已经满了，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入联系人的姓名:" << endl;
		cin >> name;
		abs->s[abs->size].Name = name;

		int age;
		cout << "请输入联系人的年龄:" << endl;
		cin >> age;
		abs->s[abs->size].Age = age;

		cout << "请输入联系人的性别:" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->s[abs->size].Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}

		string phone;
		cout << "请输入联系人的电话:" << endl;
		cin >> phone;
		abs->s[abs->size].Phone = phone;

		string addr;
		cout << "请输入联系人的地址:" << endl;
		cin >> addr;
		abs->s[abs->size].Addr = addr;

		abs->size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

void ShowContact(ContactBooks* abs)
{
	if (abs->size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名: " << abs->s[i].Name << "\t";
			cout << "年龄: " << abs->s[i].Age << "\t";
			cout << "性别: " << (abs->s[i].Sex == 1 ? "男": "女") << "\t";
			cout << "电话: " << abs->s[i].Phone << "\t";
			cout << "住址: " << abs->s[i].Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int IsExistContact(ContactBooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->s[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}


void DeleteContact(ContactBooks* abs)
{
	cout << "请输入你要删除的联系人:" << endl;
	string name;
	cin >> name;

	int ret = IsExistContact(abs, name);

		if (ret != -1)
		{
			for (int i = ret; i < abs->size; i++)
			{
				//数据前移
				abs->s[i] = abs->s[i + 1];
			}
			abs->size--;
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
	system("pause");
	system("cls");
}

void FindContact(ContactBooks* abs)
{
	cout << "请输入你要查找联系人的名字:" << endl;
	string name;
	cin >> name;

	int ret = IsExistContact(abs, name);
	if (ret != -1)
	{
		cout << "姓名: " << abs->s[ret].Name << "\t";
		cout << "年龄: " << abs->s[ret].Age << "\t";
		cout << "性别: " << abs->s[ret].Sex << "\t";
		cout << "电话: " << abs->s[ret].Phone << "\t";
		cout << "地址: " << abs->s[ret].Addr << endl;;
	}
	else
	{
		cout << "没有该联系人" << endl;
	}
	system("pause");
	system("cls");
}

void ModifyContact(ContactBooks* abs)
{
	cout << "请输入你要修改联系人的姓名:" << endl;
	string name;
	cin >> name;
	
	int ret = IsExistContact(abs, name);
	if (ret != -1)
	{
		cout << "请输入想要修改的选项: " << endl;
		cout << "1. 姓名        2. 年龄" << endl;
		cout << "3. 性别        4. 电话" << endl;
		cout << "       5. 地址        " << endl;
		
	
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cout << "请输入姓名:" << endl;
				string name;
				cin >> name;
				abs->s[ret].Name = name;
			}
			break;
			case 2:
			{
				cout << "请输入年龄:" << endl;
				int age;
				cin >> age;
				abs->s[ret].Age = age;
			}
			break;
			case 3:
			{
				while (true)
				{
					cout << "请输入性别:" << endl;
					cout << "1-------男" << endl;
					cout << "2-------女" << endl;

					int sex;
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						abs->s[ret].Sex = sex;
					}
					else
					{
						cout << "输入错误，请重新输入:" << endl;
					}
					break;
				}
			}
			break;
			case 4:
			{
				cout << "请输入电话:" << endl;
				string phone;
				cin >> phone;
				abs->s[ret].Phone = phone;
			}
			break;
			case 5:
			{
				cout << "请输入地址:" << endl;
				string addr;
				cin >> addr;
				abs->s[ret].Addr = addr;
			}
			break;
			default:
				cout << "输入错误，请重新输入" << endl;
				system("pause");
				break;
			}
		
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "没有找到该联系人" << endl;
	}
}

void CleanContact(ContactBooks* abs)
{
	abs->size = 0;
	cout << "通讯录已经被清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	ContactBooks abs;
	abs.size = 0;
	int select = 0;
	
	while (true)
	{
		menu();
		cin >> select;
		switch (select)
		{
		case 1: //增加联系人
			AddContact(&abs);
			break;
		case 2: //显示联系人
			ShowContact(&abs);
			break;
		case 3: //修改联系人
			ModifyContact(&abs);
			break;
		case 4: //查找联系人
			FindContact(&abs);
			break;
		case 5: //删除联系人

		//{cout << "请输入删除联系人的姓名：" << endl;
		//string name;
		//cin >> name;
		//if (IsExistContact(&abs,name) == -1)
		//{
		//	cout << "查无此人" << endl;
		//}
		//else
		//{
		//	cout << "找到此人" << endl;
		//}
		//}

			DeleteContact(&abs);
			break;
		case 6: //清空联系人
			CleanContact(&abs);
			break;
		case 7: //退出通讯录
			cout << "退出通讯录，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			break;
		}
		
	}
	system("pause");
	return 0;
}

