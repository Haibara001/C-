#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#define MAX 100


using namespace std;

void menu()
{
	cout << "********************************" << endl;
	cout << "****** ��ӭ����ͨѶ¼ϵͳ ******" << endl;
	cout << "********************************" << endl;
	cout << "******    1.������ϵ��    ******" << endl;
	cout << "******    2.��ʾ��ϵ��    ******" << endl;
	cout << "******    3.�޸���ϵ��    ******" << endl;
	cout << "******    4.������ϵ��    ******" << endl;
	cout << "******    5.ɾ����ϵ��    ******" << endl;
	cout << "******    6.�����ϵ��    ******" << endl;
	cout << "******    7.�˳�ͨѶ¼    ******" << endl;
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

//������ϵ��
void AddContact(ContactBooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�Ѿ����ˣ��޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "��������ϵ�˵�����:" << endl;
		cin >> name;
		abs->s[abs->size].Name = name;

		int age;
		cout << "��������ϵ�˵�����:" << endl;
		cin >> age;
		abs->s[abs->size].Age = age;

		cout << "��������ϵ�˵��Ա�:" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->s[abs->size].Sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}

		string phone;
		cout << "��������ϵ�˵ĵ绰:" << endl;
		cin >> phone;
		abs->s[abs->size].Phone = phone;

		string addr;
		cout << "��������ϵ�˵ĵ�ַ:" << endl;
		cin >> addr;
		abs->s[abs->size].Addr = addr;

		abs->size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

void ShowContact(ContactBooks* abs)
{
	if (abs->size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "����: " << abs->s[i].Name << "\t";
			cout << "����: " << abs->s[i].Age << "\t";
			cout << "�Ա�: " << (abs->s[i].Sex == 1 ? "��": "Ů") << "\t";
			cout << "�绰: " << abs->s[i].Phone << "\t";
			cout << "סַ: " << abs->s[i].Addr << endl;
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
	cout << "��������Ҫɾ������ϵ��:" << endl;
	string name;
	cin >> name;

	int ret = IsExistContact(abs, name);

		if (ret != -1)
		{
			for (int i = ret; i < abs->size; i++)
			{
				//����ǰ��
				abs->s[i] = abs->s[i + 1];
			}
			abs->size--;
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "���޴���" << endl;
		}
	system("pause");
	system("cls");
}

void FindContact(ContactBooks* abs)
{
	cout << "��������Ҫ������ϵ�˵�����:" << endl;
	string name;
	cin >> name;

	int ret = IsExistContact(abs, name);
	if (ret != -1)
	{
		cout << "����: " << abs->s[ret].Name << "\t";
		cout << "����: " << abs->s[ret].Age << "\t";
		cout << "�Ա�: " << abs->s[ret].Sex << "\t";
		cout << "�绰: " << abs->s[ret].Phone << "\t";
		cout << "��ַ: " << abs->s[ret].Addr << endl;;
	}
	else
	{
		cout << "û�и���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

void ModifyContact(ContactBooks* abs)
{
	cout << "��������Ҫ�޸���ϵ�˵�����:" << endl;
	string name;
	cin >> name;
	
	int ret = IsExistContact(abs, name);
	if (ret != -1)
	{
		cout << "��������Ҫ�޸ĵ�ѡ��: " << endl;
		cout << "1. ����        2. ����" << endl;
		cout << "3. �Ա�        4. �绰" << endl;
		cout << "       5. ��ַ        " << endl;
		
	
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cout << "����������:" << endl;
				string name;
				cin >> name;
				abs->s[ret].Name = name;
			}
			break;
			case 2:
			{
				cout << "����������:" << endl;
				int age;
				cin >> age;
				abs->s[ret].Age = age;
			}
			break;
			case 3:
			{
				while (true)
				{
					cout << "�������Ա�:" << endl;
					cout << "1-------��" << endl;
					cout << "2-------Ů" << endl;

					int sex;
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						abs->s[ret].Sex = sex;
					}
					else
					{
						cout << "�����������������:" << endl;
					}
					break;
				}
			}
			break;
			case 4:
			{
				cout << "������绰:" << endl;
				string phone;
				cin >> phone;
				abs->s[ret].Phone = phone;
			}
			break;
			case 5:
			{
				cout << "�������ַ:" << endl;
				string addr;
				cin >> addr;
				abs->s[ret].Addr = addr;
			}
			break;
			default:
				cout << "�����������������" << endl;
				system("pause");
				break;
			}
		
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "û���ҵ�����ϵ��" << endl;
	}
}

void CleanContact(ContactBooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�Ѿ������" << endl;
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
		case 1: //������ϵ��
			AddContact(&abs);
			break;
		case 2: //��ʾ��ϵ��
			ShowContact(&abs);
			break;
		case 3: //�޸���ϵ��
			ModifyContact(&abs);
			break;
		case 4: //������ϵ��
			FindContact(&abs);
			break;
		case 5: //ɾ����ϵ��

		//{cout << "������ɾ����ϵ�˵�������" << endl;
		//string name;
		//cin >> name;
		//if (IsExistContact(&abs,name) == -1)
		//{
		//	cout << "���޴���" << endl;
		//}
		//else
		//{
		//	cout << "�ҵ�����" << endl;
		//}
		//}

			DeleteContact(&abs);
			break;
		case 6: //�����ϵ��
			CleanContact(&abs);
			break;
		case 7: //�˳�ͨѶ¼
			cout << "�˳�ͨѶ¼����ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			break;
		}
		
	}
	system("pause");
	return 0;
}

