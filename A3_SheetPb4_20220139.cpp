// File name: A3_SheetPb4_20220139
// Purpose: creat a set class
// Author(s): remon raafat nassif
// ID(s): 20220139
// Section: S6
// Date: 6/7/2013
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
template <typename T>
class Set {
    vector<T> data;
public:
    void insert(const T& item) {
        if (!contains(item)) {
            data.push_back(item);
        }
    }
    void remove(const T& item) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it == item) {
                data.erase(it);
                return;
            }
        }
    }
    size_t size() const {
        return data.size();
    }
    bool contains(const T& item) const {
        for (const auto& element : data) {
            if (element == item) {
                return true;
            }
        }
        return false;
    }
    const T* get_array() const {
        int size = static_cast<int>(data.size());
        T* array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = data[i];
        }
        return array;
    }
    void free_array(T* array) {
        delete[] array;
    }
};
template <typename T>
void add_items(Set<T>&s1)
{
    cout << "Do you want to add more items ? " << endl;
    cout << "1 - Yes      2 - No" << endl;
    string y;
    cin >> y;
    if (y == "Yes" || y == "yes" || y == "1") {
        cout << "Enter the item you want to add : "; T x; cin >> x;
        s1.insert(x);
        add_items(s1);
    }
}
template <typename T>
void remove_item(Set<T>& s1)
{
    cout << "Do you want to remove a item ? " << endl;
    cout << "1 - Yes      2 - No" << endl;
    string y1;
    cin >> y1;
    if (y1 == "Yes" || y1 == "yes" || y1 == "1") {
        cout << "Enter the item you want to remove : "; T x; cin >> x;
        if (s1.contains(x)) s1.remove(x);
        else cout << "This item is not in the list" << endl;
        remove_item(s1);
    }
}
int main()
{
    Set<int>s;
    cout << "First set of integers " << endl;
	
	int n; cout << "Enter the size of set : "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;cout<<"Enter "<<(i+1)<<" item : "; cin >> x;
		s.insert(x);
	}
    cout << "****************************" << endl;
    add_items(s);
    cout << "****************************" << endl;
    remove_item(s);
    cout << "****************************" << endl;
    cout << "the items : " << endl;
    const int* arr = s.get_array();
    for (size_t i = 0; i < s.size(); ++i) {
        cout << *(arr+i) << " ";
    }
    cout << "\n";
    cout << "*****************************" << endl;
    cout << "*****************************" << endl;
    cout << "second set of strings " << endl;
    Set<string>s2;
    int n2; cout << "Enter the size of set : "; cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        string x; cout << "Enter " << (i + 1) << " item : "; cin >> x;
        s2.insert(x);
    }
    cout << "*****************************" << endl;
    add_items(s2);
    cout << "*****************************" << endl;
    remove_item(s2);
    cout << "*****************************" << endl;
    cout << "the items : " << endl;
    const string* arr2 = new string[s2.size()];
    arr2 = s2.get_array();
    for (int i = 0; i < s2.size(); i++)
    {
        cout << *(arr2 + i) << " ";
    }
	return 0;
}