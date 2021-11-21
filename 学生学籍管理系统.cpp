#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class Student        //学生类
{
public:
	//以下函数会访问Student类中的私有成员，因此设置为友元函数
	friend void Delete();
	friend void Recompose();
	friend void Find();
	friend void Count();
	friend void PutOutFile();
	friend void PutInFlie();

	void setStu()
	{
		cin >> Number >> Name >>Gender >> Age >> Class >> Major >> Department;
	}
	void showStu()
	{
		cout << Number <<'\t' << Name << '\t' << Gender << '\t'
			<< Age << '\t' << Class << '\t' <<'\t'<< Major << '\t'
			<< '\t' << Department << endl;
	}
private:
	string Number;        //学号
	string Name;          //姓名
	string Gender;        //性别
	int Age;              //年龄
	string Class;         //班号
	string Major;         //专业名称
	string Department;    //系别
};



vector<Student> stu;       //用vector容器来创建学生数组
int total = 0;              //录入的学生人数



void Input()           //录入信息函数
{
	int n;          //要录入信息的学生人数
	cout << "执行“录入学生信息”操作---------->请输入要录入信息的学生人数：";
	cin >> n;
	cout << "请依次输入学生的学号、姓名、性别、年龄、班号、专业名称、系别：" << endl;
	for (int i = 0; i < n; i++)
	{
		Student S;
		S.setStu();
		stu.push_back(S);    //将输入的学生信息放入vector<Student>容器中
	}
	total += n;
}



void Delete()          //删除信息函数
{
	cout << "执行“删除学生信息”操作---------->请输入要删除学生的学号：";
	string num;
	cin >> num;
	//用迭代器来遍历容器所有元素，用于查找和删除
	vector<Student>::iterator it = stu.begin();
	for (; it != stu.end(); it++)
	{
		if ((*it).Number == num)
		{
			stu.erase(it);    //删除迭代器it指向的学生信息
			total--;       //删除一名学生的信息后，系统记录学生的人数减一
			cout << "--------->学号为" << num << "的学生的信息已删除！" << endl;
			return;
		}
	}
	cout << "--------->未找到学号为" << num << "的学生，请检查学号是否输入错误！" << endl;
}



void Recompose()           //修改学生信息
{
    cout<< "执行“修改学生信息”操作---------->请输入要修改学生的原学号：";
	string num;
	cin >> num;
	//用迭代器来遍历容器所有元素，用于查找和删除
	vector<Student>::iterator it = stu.begin();
	for (; it != stu.end(); it++)
	{
		if ((*it).Number == num)
		{
			cout << "依次输入修改后的学生的学号、姓名、性别、年龄、班号、专业名称、系别：" << endl;
			(*it).setStu();    //调用成员函数重新给该学生的属性赋值
			cout << "--------->原学号为"<<num<<"的学生的信息已修改！" << endl;
			return;
		}
	}
	cout << "--------->未找到学号为" << num << "的学生，请检查学号是否输入错误！" << endl;
}



void Find()               //查询学生的信息
{
	cout  << "=========（a）按学号查询单个学生信息" << endl;
	cout  << "=========（b）按姓名查询单个学生信息" << endl;
	cout  << "=========（c）按性别查询学生信息" << endl;
	cout  << "=========（d）按班号查询学生信息" << endl;
	cout  << "=========>请根据以上序号选择查询类别：";
	char x;
	cin >> x;
	switch (x)
	{
	case 'a':
	{
		cout << "已选择“按学号查询单个学生信息”---------->请输入该学生的学号：";
		string num;
		cin >> num;
		vector<Student>::iterator it = stu.begin();
		cout << "--------->该学生的基本信息如下：" << endl;
		for (; it != stu.end(); it++)
		{
			if ((*it).Number == num)
			{
				(*it).showStu();
				break;
			}
		}
		if (it == stu.end())
			cout << "--------->未查询到学号为" << num << "的学生" << endl;
	}break;
	case 'b':
	{
		int flag=0;        //若查询到相关学生则置flag=1
		cout << "已选择“按姓名查询单个学生信息”---------->请输入该学生的姓名：";
		string name;
		cin >> name;
		vector<Student>::iterator it = stu.begin();
		cout << "--------->该学生的基本信息如下：" << endl;
		for (; it != stu.end(); it++)
		{
			if ((*it).Name == name)
			{
				(*it).showStu();
				//考虑到学生可能出现同名情况，此处不设break语句退出循环
				flag = 1;
			}
		}
		if (flag != 1)
			cout << "--------->未查询到为姓名为：" << name << "的学生" << endl;
	}break;
	case 'c':
	{
		cout << "已选择“按性别查询学生信息”---------->请输入要查询学生的性别：";
		string gender;
		cin >> gender;
		vector<Student>::iterator it = stu.begin();
		cout <<"--------->"<< gender << "性学生的信息如下：" << endl;
		for (; it != stu.end(); it++)
		{
			if ((*it).Gender == gender)
			{
				(*it).showStu();
			}
		}
	}break;
	case 'd':
	{
		cout << "已选择“按班号查询学生信息”---------->请输入要查询学生的班号：";
		string class2;
		cin >> class2;
		vector<Student>::iterator it = stu.begin();
		cout << "--------->" << class2 << "班学生的信息如下：" << endl;

		for (; it != stu.end(); it++)
		{
			if ((*it).Class == class2)
			{
				(*it).showStu();
			}
		}
	}break;
	}
}



void Count()         //统计学生信息
{
	cout  << "=========（a）按性别统计学生人数" << endl;
	cout  << "=========（b）按班号统计学生人数" << endl;
	cout  << "=========（c）按年龄统计学生人数" << endl;
	cout  << "=========（d）按系别统计学生人数" << endl;
	cout  << "========>请根据以上序号选择统计类别：";
	char x;
	cin >> x;
	switch (x)
	{
	case 'a':
	{
		cout << "已选择“按性别统计学生人数”---------->请输入要统计的学生的性别：";
		string gender;
		cin >> gender;
		int totalA = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Gender == gender)
			{
				totalA++;
			}
		}
		cout << "--------->" << gender << "性学生共有" << totalA << "个" << endl;
	}break;
	case 'b':
	{
		cout << "已选择“按班号统计学生人数”---------->请输入要统计的学生的班号：";
		string class2;
		cin >> class2;
		int totalB = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Class == class2)
			{
				totalB++;
			}
		}
		cout << "--------->" << class2 << "班学生共有" << totalB << "个" << endl;
	}break;
	case 'c':
	{
		cout << "已选择“按年龄统计学生人数”---------->请输入要统计的学生的年龄：";
		int age;
		cin >> age;
		int totalC = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Age == age)
			{
				totalC++;
			}
		}
		cout << "--------->" << "年龄为"<<age << "岁的学生共有" << totalC << "个" << endl;
	}break;
	case 'd':
	{
		cout << "已选择“按系别统计学生人数”---------->请输入要统计的学生的系别：";
		string dep;
		cin >> dep;
		int totalD = 0;
		vector<Student>::iterator it = stu.begin();
		for (; it != stu.end(); it++)
		{
			if ((*it).Department == dep)
			{
				totalD++;
			}
		}
		cout << "--------->" <<dep << "的学生共有" << totalD << "个" << endl;
	}break;
}
}


//删除文件中的第一行（学号	姓名	性别	年龄	班号	专业	系别）
//删除该行后才能正确地把数据写入到Student类的vector容器中
void DeleteFirstLine()
{
	//将文件中的数据逐行写入容器vec中
	vector<string> vec;
	string strLine;   //记录文件的每一行
	ifstream inFile("学生学籍信息.txt", ios::in);
	while (inFile)
	{
		getline(inFile, strLine);   //逐行读取文件内容到strLine中
		vec.push_back(strLine);     //将读取的一行内容放入容器中
	}
	inFile.close();

	//删除第一行
	vec.erase(vec.begin());

	//将剩余的内容重新写回到文件中
	ofstream outFile("学生学籍信息.txt", ios::out);
	vector<string>::const_iterator it = vec.begin();
	for (; it != vec.end(); it++)
	{
		//逐行将vec容器中的内容写入文件中
		outFile.write((*it).c_str(), (*it).size());
		outFile << endl;
	}
	outFile.close();          //关闭文件
}



void PutOutFile()        //读取文件中的数据，并存入到vector<Student>容器中
{
	ifstream ifs;          //创建流对象
	//打开文件，并判断是否打开成功
	ifs.open("学生学籍信息.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	string number, name, gender;
	int age;
	string class1, major, dep;
	//以上变量用于存放文件每一行对应的学生信息数据，以便用文件中的每一行内容创建一个学生类对象，并存放到stu容器中

	while (ifs >> number >> name >> gender >> age >> class1 >> major >> dep)
	{
		Student s;
		s.Number = number;
		s.Name = name;
		s.Gender = gender;
		s.Age = age;
		s.Class = class1;
		s.Major = major;
		s.Department = dep;
		stu.push_back(s);
		total++;        //每创建一个学生类对象并存入容器stu中，将学生人数加一
	}
	ifs.close();          //关闭文件
}



void PutInFlie()          //将学生信息存储（写入）到文件中
{
	//将Student类中所有成员信息存储（写入）到文件中
	ofstream ofs;       //创建流对象
	//首次默认创建一个"学生学籍信息.txt"文件在与本项目同级文件夹中
	ofs.open("学生学籍信息.txt", ios::out);
	//将学生信息内容写进文件内
	ofs << "学号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "年龄" << '\t'
		<< "班号" << '\t' << '\t' << "专业" << '\t' << '\t' << '\t' << "系别"<<endl;
	for (int i = 0; i < total; i++)
	{
		ofs << stu[i].Number << '\t' << stu[i].Name << '\t' << stu[i].Gender
			<< '\t' << stu[i].Age << '\t' << stu[i].Class
			<< '\t' << '\t' << stu[i].Major << '\t' << '\t' << '\t' << stu[i].Department << endl;
	}
	ofs.close();      //关闭文件
}



int main()
{
	DeleteFirstLine();   //将文件中第一行（学号  姓名  性别  年龄  班号  专业  系别）删除
	PutOutFile();         //删除文件第一行后，将文件中的学生信息导入学生类的vector容器中

	/*测试讲文件中的内容导入容器后，输出的效果
	for (int i = 0; i < total; i++)
	{
		stu[i].showStu();
	}
	*/

	cout << "==========================学生学籍管理系统==========================" << endl;
	int x=0;         //记录用户选择功能的序号
	while (x != 6)   //若用户没有选择退出系统，则每执行完一个功能后重新显示菜单供用户选择
	{
		cout << endl << endl;
		cout << "|-------------------------------菜单-------------------------------|" << endl;
		cout << "|======================（1）学生基本信息的录入=====================|" << endl;
		cout << "|======================（2）学生基本信息的删除=====================|" << endl;
		cout << "|======================（3）学生基本信息的修改=====================|" << endl;
		cout << "|======================（4）学生基本信息的查询=====================|" << endl;
		cout << "|======================（5）学生基本信息的统计=====================|" << endl;
		cout << "|======================     （6）退出系统     =====================|" << endl;
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "请根据以上序号选择您要执行的功能：";
		cin >> x;     //用户根据菜单输入功能对应序号
		if (x == 6)
		{
			cout << "***************学生学籍管理系统已退出，";
			break;
		}
		switch (x)
		{
		case 1:
		{
			Input();
			cout << "已完成“录入学生信息”操作，点击回车继续操作...";
			getchar();
			getchar();
		} break;

		case 2:
		{
		    Delete();
			cout << "已完成“删除学生信息”操作，点击回车继续操作...";
			getchar();
			getchar();
		}break;

		case 3:
		{
			Recompose();
			cout << "已完成“修改学生信息”操作，点击回车继续操作...";
			getchar();
			getchar();
		}break;

		case 4:
		{
			Find();
			cout << "已完成“查询学生信息”操作，点击回车继续操作...";
			getchar();
			getchar();
		}break;

		case 5:
		{
			Count();
			cout << "已完成“统计学生信息”操作，点击回车继续操作...";
			getchar();
			getchar();
		}break;

		}
	}
	PutInFlie();      //将学生信息存储（写入）到文件中
	return 0;
}
