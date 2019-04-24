//g++ -o main.exe main.cpp -static-libstdc++

#include <iomanip>
#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct student_info{
  string name;
  double midterm, final;
  vector<double> homework;
};

double grade(double midterm, double final , double homework){
  return  0.2 * midterm + 0.4*final + 0.4*homework;
}


double median(vector<double> vec){
  typedef vector<double>::size_type vec_sz;
  vec_sz size (vec.size());

  if (size == 0){
    throw domain_error("median of an empty vector");
  }

  sort(vec.begin(), vec.end());
  vec_sz mid = size/2;
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}



double grade(double midterm, double final , const vector<double>& hw){
  if (hw.size() == 0){
    throw domain_error("sudent has done no homework");
  }
  return  grade(midterm, final, median(hw));
}

double grade(cost student_info& s){
  return grade(s.midterm, s.final, s.homework);
}

bool compare(const student_info& x, const student_info& y){
  return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw){
  if (in){
    hw.clear();

    double x;
    while (in >> x){
      hw.push_back(x);
    }
    in.clear();
  }
  return in;
}

istream& read(istream& is, student_info& s){
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);
  return is;
}




int main(void){
  vector<student_info> students;
  student_info record;
  string::size_type mexlen = 0;

  while (read(cin,record)){
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<student_info>::size_type i = 0); i != students.size(); ++i){
    cout << students[i].name
         << string(maxlen + 1 - students[i].name.size(),' ');

    try{
       double finalGrade = grade(students[i]);
       streamsize prec = cout.precision();
       cout << "final grade average is " << setprecision(4)
            << finalGrade
            << setprecision(prec);
     } catch (domain_error e){
       cout e.what();
     }
     cout << endl;
  }
  return 0;
}

//Rectangle rect (3,4);
//cout << "area: " << rect.area() << endl;
/*
class Rectangle{
    int width,height;
  public:
    Rectangle (int,int);
    int area(void);
};

Rectangle::Rectangle (int a, int b){
  width = a, height = b;
}
int Rectangle::area(void){
  return width*height;
}
*/
