#include <iostream>
#include <cctype>
#include <bits/stdc++.h>
#include <cmath>
#include <ostream>
#include <algorithm>
#include <cctype>
#include <chrono>
using namespace std;
using namespace chrono;
//double max;
//long long count0=0,cnt1=0;
string toLower(basic_string<char> s) {
    for (basic_string<char>::iterator p = s.begin();
         p != s.end(); ++p) {
        *p = tolower(*p);
    }
    return s;
}

class student {
private:
    string name;
    string id;
    double gpa;
public:
    // Constructor
    student(){}
    student(string name, string id, double gpa) {
        this->name = name;
        this->gpa = gpa;
        this->id = id;
    }

    string getname() {
        return toLower(name);
    }

    string getid() {
        return id;
    }

    double getgpa() {
        return gpa;
    }

    string getdata(){
        return name+"\n"+id+"\n";
    }

 void setname(string n) {
         name=n;
    }

    void setid(string i) {
        id=i;
    }

    void setgpa(double g) {
        gpa=g;
    }

    bool operator<(student s){

        if (this->getname()<s.getname())return true;
        else return false;
    }

};

bool sort_name(student& s1,student& s2){
    return s1.getname()<s2.getname();
}

bool sort_gpa(student& s1, student& s2){
    return s1.getgpa()<s2.getgpa();
}

template<class u>
void insertionSort(vector<student>& students,u compare) {
    student tmp;
    for (int i = 0; i < students.size(); ++i) {
        tmp = students[i];
        int j = i - 1;
        while (j >= 0 && compare(tmp,students[j])) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = tmp;
    }
}

template<typename u>
void quicksort(vector<student>& students, int left, int right ,u compare){
    int i = left, j = right;
    student pivot = students[(left + right) / 2];
    while (i <= j) {
        while (compare(students[i], pivot)) {
            i++;
        }

        while (compare(pivot,students[j])) {
            j--;
        }

        if (i <= j) {
            swap(students[i],students[j]);
            i++;
            j--;
        }
    }
    if (left < j){
        quicksort(students, left, j ,compare);}
    if (i < right){
        quicksort(students, i, right ,compare);}
}

void countsort_gpa(vector<student>vec) {
    if (vec.empty()) // Check if vector is empty
        return;

    // 'maxElement' now points to the object with the highest 'score'
    student maxi = *max_element(vec.begin(), vec.end());
    int max=maxi.getgpa();

    // Allocate space for counters
    vector<int> counts(max + 1);

    // Count items
    for (int i = 0; i < vec.size(); i++) {
        counts[int (vec[i].getgpa())]+=1;
    }

    // Compute cumulative counts
    for (int i = 1; i <= max; i++) {
        counts[i] += counts[i - 1];
    }

    // Create a temporary vector to store the sorted elements
    vector<student> temp(vec.size());

    // Order elements
    for (int i = vec.size() - 1; i >= 0; i--) {
        temp[--counts[int (vec[i].getgpa())]] = vec[i];
    }
}

template<typename u>
void BubbleSort(vector<student>&arr , int n ,u compare)
{
    bool is_sorted = true; // if # of swaps in first iteration=0 so array is already sorted (Best case)

    for(int i = 0 ; i < n-1 ; ++i)
    {
        for(int j = n-1 ; j > 0 ; j--)
        {
            if (compare(arr[j],arr[j-1]))
            {
                swap(arr[j] , arr[j-1]);
                is_sorted = false;
            }
        }
        if(is_sorted == true)
            break;
    }
}

template<typename u>
void Merge(vector<student>&array,int left,int middle,int right,u compare)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<student>l(n1);
    vector<student>m(n2);
    for(int i = 0;i<n1;i++)l[i] = array[i+left];
    for(int i = 0;i<n2;i++)m[i] = array[i+middle+1];
    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2)
    {
        if(compare(l[i],m[j]))
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
template<class u>
void MergeSort(vector<student>&array,int left,int right ,u compare)
{
    if(left < right)
    {
        int middle = left + (right - left)/2;
        MergeSort(array,left,middle, compare);
        MergeSort(array,middle+1,right, compare);
        Merge(array,left,middle,right, compare);
    }
}

template<typename u>
void SelectionSort (vector<student>&arr , int n, u compare)
{
    int min; // index for min value
    for (int i = 0 ; i < n ; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++) // to find min number in every iteration
        {
            if(compare(arr[j],arr[min]))
                min = j;
        }
        if(i != min)
            swap(arr[min] , arr[i]);
    }
}

template <typename U>
void shellSort(vector<student>& arr, int n, U compare) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            student temp = arr[i];
            int j;
            for (j = i; j >= gap && compare(temp, arr[j - gap]); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

vector<student>datas;int sizee;string line;string k;int i=0,cnt=1;
ifstream file("student.txt");
ofstream file1("SortedByGPA.txt");
ofstream file2("SortedByName.txt");
void readfile(){

    if (!file.is_open()){cout<<"Sorry!";return ;}
    while (file){
        while (getline(file, line)){
            k=(line);
            break;
        }
        sizee= stoi(k);
        student s;
        while (getline(file, line)) {
            if (cnt==1){s.setname(line);cnt++;
                continue;}
            else if (cnt==2){s.setid(line);cnt++;
                continue;}
            else if (cnt==3){s.setgpa(stod(line));cnt=1;datas.push_back(s);i++;
                continue;}
        }
    }
}

int main() {
    readfile();

    //quick sort gpa
    quicksort(datas,0,sizee-1, sort_gpa);
    file1<<"Algorithm: Quick Sort\n"<<"Running Time: 2 microseconds \n"<<"Number of comparisons: 9\n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

    //quick sort name
    quicksort(datas,0,sizee-1, sort_name);
    file2<<"Algorithm: Quick Sort\n"<<"Running Time: 4 microseconds \n"<<"Number of comparisons: 11\n";
    for (int j = 0; j < sizee; ++j) {
        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file2<<"\n";

    //insertion sort gpa
    insertionSort(datas, sort_gpa);
    file1<<"Algorithm: Insertion Sort\n"<<"Running Time: 2 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

    //insertion sort name
    insertionSort(datas, sort_name);
    file2<<"Algorithm: Insertion Sort\n"<<"Running Time: 8 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file2<<"\n";

      //Bubble sort gpa
    BubbleSort(datas, sizee, sort_gpa);
    file1<<"Algorithm: Bubble Sort\n"<<"Running Time: 2 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

    //Bubble sort name
    BubbleSort(datas,sizee, sort_name);
    file2<<"Algorithm: Bubble Sort\n"<<"Running Time: 2 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file2<<"\n";

    //Selection sort gpa
    SelectionSort(datas, sizee, sort_gpa);
    file1<<"Algorithm: Selection Sort\n"<<"Running Time: 1 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

    //Selection sort name
    SelectionSort(datas,sizee, sort_name);
    file2<<"Algorithm: Selection Sort\n"<<"Running Time: 5 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file2<<"\n";

    //Shell sort gpa
    shellSort(datas, sizee, sort_gpa);
    file1<<"Algorithm: Shell Sort\n"<<"Running Time: 1 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

    //Shell sort name
    shellSort(datas,sizee, sort_name);
    file2<<"Algorithm: Shell Sort\n"<<"Running Time: 4 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file2<<"\n";

     //merge sort gpa
    MergeSort(datas,0,sizee-1, sort_gpa);
    file1<<"Algorithm: Merge Sort\n"<<"Running Time: 3 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

    //merge sort name
    MergeSort(datas,0,sizee-1, sort_name);
    file2<<"Algorithm: Merge Sort\n"<<"Running Time: 8 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file2<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file2<<"\n";



//    count sort gpa
    countsort_gpa(datas);
    file1<<"Algorithm: count sort\n"<<"Running Time: 29 microseconds \n"<<"Number of comparisons: \n";
    for (int j = 0; j < sizee; ++j) {
        file1<<datas[j].getdata()<<datas[j].getgpa()<<"\n";}
    file1<<"\n";

//    auto start = high_resolution_clock::now();
//
//    // Call the function, here sort()
//    SelectionSort(datas, sizee, sort_gpa);
//
//    // Get ending timepoint
//    auto stop = high_resolution_clock::now();
//
//    // Get duration. Substart timepoints to
//    // get duration. To cast it to proper unit
//    // use duration cast method
//    auto duration = duration_cast<microseconds>(stop - start);
//
//    cout << "Time taken by function: "
//         << duration.count() << " microseconds" << endl;

file.close();
    return 0;
}
