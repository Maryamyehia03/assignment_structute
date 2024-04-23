#include <iostream>
#include <fstream>
#include <cctype>
#include <bits/stdc++.h>
#include <cmath>
#include <ostream>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

long long count0=0,cnt1=0;
string toLower(basic_string<char> s)
{
    for (basic_string<char>::iterator p = s.begin();
         p != s.end(); ++p)
    {
        *p = tolower(*p);
    }
    return s;
}


class student{
private:
    string name;
    string id;
    double gpa;
public:
    // Constructor
    student(){}

    student(string name, string id, double gpa)
    {
        this->name = name;
        this->gpa = gpa;
        this->id = id;
    }

    string getname()
    {
        return toLower(name);
    }

    string getid()
    {
        return id;
    }

    double getgpa()
    {
        return gpa;
    }

    string getdata()
    {
        return name+"\n"+id+"\n";
    }

    void setname(string n)
    {
        name=n;
    }

    void setid(string i)
    {
        id=i;
    }

    void setgpa(double g)
    {
        gpa=g;
    }

    bool operator<(student s)
    {

        if (this->getname()<s.getname())return true;
        else return false;
    }

};


// QUICK SORT
void quicksort_gpa(vector<student>&a, int left, int right)
{
    int i = left, j = right;
    double pivot = a[(left + right) / 2].getgpa();
    while (i <= j)
    {
        cnt1++;
        while (a[i].getgpa() < pivot)
            cnt1++, i++;
        while (a[j].getgpa() > pivot)
            cnt1++, j--;
        if (i <= j)
        {
            cnt1++;
            swap(a[i],a[j]);
            i++;
            j--;
        }
    };
    if (left < j){cnt1++;
        quicksort_gpa(a, left, j);}
    if (i < right){cnt1++;
        quicksort_gpa(a, i, right);}
}

void quicksort_name(vector<student>&a,int left,int right)
{

    string pivot=a[(right+left)/2].getname();
    int i=left,j=right;
    while (i<=j)
    {count0++;
        while (a[i].getname()<pivot)i++,count0++;
        while (a[j].getname()>pivot)j--,count0++;
        if (i<=j)
        { count0++;
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if (i<right){count0++; quicksort_name(a,i,right);}
    if(j>left){count0++; quicksort_name(a,left,j);}
}


// MERGE SORT
void Merge_GPA(vector<student>&array,int left,int middle,int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<student>l;
    vector<student>m;
    for(int i = 0;i<n1;i++)l[i] = array[i+left];
    for(int i = 0;i<n2;i++)m[i] = array[i+middle+1];
    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2)
    {
        if(l[i].getgpa() < m[j].getgpa())
        {
            array[k] = l[i];
            i++;
        }
        else
        {
            array[k] = m[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        array[k] = l[i];
        i++;k++;
    }
    while(j < n2)
    {
        array[k] = m[j];
        k++;j++;
    }
}
void MergeSort_GPA(vector<student>&array,int left,int right)
{
    if(left < right)
    {
        int middle = left + (right - left)/2;
        MergeSort_GPA(array,left,middle);
        MergeSort_GPA(array,middle+1,right);
        Merge_GPA(array,left,middle,right);
    }
}
void Merge_Name(vector<student>&array,int left,int middle,int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<student>l;
    vector<student>m;
    for(int i = 0;i<n1;i++)l[i] = array[i+left];
    for(int i = 0;i<n2;i++)m[i] = array[i+middle+1];
    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2)
    {
        if(l[i].getname() < m[j].getname())
        {
            array[k] = l[i];
            i++;
        }
        else
        {
            array[k] = m[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        array[k] = l[i];
        i++;k++;
    }
    while(j < n2)
    {
        array[k] = m[j];
        k++;j++;
    }
}
void MergeSort_Name(vector<student>&array,int left,int right)
{
    if(left < right)
    {
        int middle = left + (right - left)/2;
        MergeSort_Name(array,left,middle);
        MergeSort_Name(array,middle+1,right);
        Merge_Name(array,left,middle,right);
    }
}


// SELECTION SORT
void SelectionSort_GPA (vector<student>&arr , int n)
{
    int min; // index for min value
    for (int i = 0 ; i < n ; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++) // to find min number in every iteration
        {
            if(arr[min].getgpa() > arr[j].getgpa())
                min = j;
        }

        if(i != min)
            swap(arr[min] , arr[i]);
    }
}

void SelectionSort_Name (vector<student>&arr , int n)
{
    int min; // index for min value
    for (int i = 0 ; i < n ; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++) // to find min number in every iteration
        {
            if(arr[min].getname() > arr[j].getname())
                min = j;
        }

        if(i != min)
            swap(arr[min] , arr[i]);
    }
}


// BUBBLE SORT
void BubbleSort_GPA (vector<student>&arr , int n)
{
    bool is_sorted = true; // if # of swaps in first iteration=0 so array is already sorted (Best case)

    for(int i = 0 ; i < n-1 ; ++i)
    {
        for(int j = n-1 ; j > 0 ; j--)
        {
            if (arr[j].getgpa() < arr[j-1].getgpa())
            {
                swap(arr[j] , arr[j-1]);
                is_sorted = false;
            }
        }
        if(is_sorted == true)
            break;
    }
}

void BubbleSort_Name (vector<student>&arr , int n)
{
    bool is_sorted = true; // if # of swaps in first iteration=0 so array is already sorted (Best case)

    for(int i = 0 ; i < n-1 ; ++i)
    {
        for(int j = n-1 ; j > 0 ; j--)
        {
            if (arr[j].getname() < arr[j-1].getname())
            {
                swap(arr[j] , arr[j-1]);
                is_sorted = false;
            }
        }
        if(is_sorted == true)
            break;
    }
}

// FOR FILES
vector<student>datas;
int Size;
string line;
string k;
int i=0,cnt=1;
ifstream file("student.txt");
ofstream file1("SortedByGPA.txt");
ofstream file2("SortedByName.txt");
void readfile()
{

    if (!file.is_open())
    {
        cout <<"The file isn't opened." << '\n';
        return ;
    }
    while (file)
    {
        while (getline(file, line))
        {
            k=(line);
            break;
        }
        Size = stoi(k);
        student s;
        while (getline(file, line))
        {
            if (cnt==1)
            {
                s.setname(line);
                cnt++;
                continue;
            }
            else if (cnt==2)
            {
                s.setid(line);cnt++;
                continue;
            }
            else if (cnt==3)
            {
                s.setgpa(stod(line));cnt=1;datas.push_back(s);i++;
                continue;
            }
        }
    }
}

int main() {
    readfile();

//    // QUICK SORT BY NAME
//    quicksort_name(datas,0,Size -1);
//    file2<<"Algorithm: Quick Sort\n"<<"Running Time:4 microseconds \n"<<"Number of comparisons: 11\n";
//    for (int j = 0; j < Size ; ++j)
//    {
//        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";
//    }
//    file2.close();
//
//    // QUICK SORT BY GPA
//    quicksort_gpa(datas,0,Size-1);
//    file1<<"Algorithm: Quick Sort\n"<<"Running Time: 2 microseconds \n"<<"Number of comparisons: 9\n";
//    for (int j = 0; j < Size; ++j)
//    {
//        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";
//    }
//    file1.close();

    // SELECTION SORT BY NAME
    // SELECTION SORT BY GPA
    // BBUBBLE SORT BY NAME
    // BBUBBLE SORT BY GPA

    file.close();
    return 0;
}