// File name: A3_SheetPb1_20220139
// Purpose: Label Generator.
// Author(s): remon raafat nassif
// ID(s): 20220139
// Section: S6
// Date:6/7/2023
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class LabelGenerator
{
	string figure;
	int num;
	int next_num;
public:
	LabelGenerator(string fig, int n);
	LabelGenerator();
	virtual string nextlabel();
};
LabelGenerator::LabelGenerator(string f, int n) : figure(f), num(n) { next_num = num; }
LabelGenerator::LabelGenerator() : figure("--"), num(0) { next_num = 0; }
string LabelGenerator::nextlabel() {return figure + to_string(next_num++);}
 
class FileLabelGenerator : public LabelGenerator
{
	string filename;
	int i;
public:
	FileLabelGenerator();
	FileLabelGenerator(string fig, int n, string fn);
	vector<string> Identify_The_File();
	string nextlabel();
};
vector<string> FileLabelGenerator::Identify_The_File()
{
	ifstream file(filename);
	vector<string>s;
	if (file.is_open()) {
		string line;
		while (getline(file, line)) s.push_back(line);
		return s;
	}
	else
	{
		cout << "Error opening file: " << endl;
		return {};
	}
}
FileLabelGenerator::FileLabelGenerator() : LabelGenerator(), filename("---") { i = 0; }
FileLabelGenerator::FileLabelGenerator(string fig, int n, string fn) : LabelGenerator(fig, n), filename(fn) { i = 0; }
string FileLabelGenerator::nextlabel()
{
	string next = LabelGenerator::nextlabel();
	vector<string> file = Identify_The_File();

	return next + " " + file[i++] + "\n";
}

int main()
{
	LabelGenerator figureNumbers("figure ", 1);
	LabelGenerator pointNumbers("p", 0);
	cout << "Figure numbers : ";
	for (int i = 0; i < 3; i++)
	{
		cout << figureNumbers.nextlabel() ;
		if (i != 2) cout << " , ";
	}
	cout << endl;
	cout << "point numbers : ";
	for (int i = 0; i < 5; i++)
	{
		cout << pointNumbers.nextlabel() ;
		if (i != 4) cout << " , ";
	}
	cout << endl;
	cout << "More Figures : ";
	for (int i = 0; i < 3; i++)
	{
		cout << figureNumbers.nextlabel() ;
		if (i != 2) cout << " , ";
	}
	FileLabelGenerator figureLabels("figure ", 1 , "labels.txt");
	cout << endl;
	cout << "Figure labels : \n";
	for (int i = 0; i < 3; i++)
	{
		cout << figureLabels.nextlabel();
	}
	return 0;
}