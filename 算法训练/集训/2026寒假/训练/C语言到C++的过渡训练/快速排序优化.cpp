#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Student{
    string name;
    int math;
    int english;
    int total;
};

int main()
{
    int n;
    cin >> n;
    vector<Student> students(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> students[i].name >> students[i].math >> students[i].english;
        students[i].total = students[i].math + students[i].english;
    }
    
    sort(students.begin(),students.end(),[](const Student &a,const Student &b)
    {
        if(a.total != b.total)
        {
            return a.total > b.total;
        }
        else if(a.math != b.math)
        {
            return a.math > b.math;
        }
        else
        {
            return a.name < b.name;
        }
    });
    
/*
    sort(students.begin(),students.end(),[](const Student&a , const Student&b)
    {
        return a.total > b.total;
    });
    
    for(int i = 0 ; i < n ; i++)
    {
        if(students[i].total == students[i+1].total)
        {
            if(students[i+1].math > students[i].math)
            {
                swap(students[i],students[i+1]);
            }
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(students[i].math == students[i+1].math)
        {
            if(students[i+1].name < students[i].name)
            {
                swap(students[i],students[i+1]);
            }
        }
    }
        */

    for(const auto&s : students)
    {
        cout << s.name << " " << s.math << " " << s.english << " " << s.total << "\n";
    }
    return 0;
    
}