
#include <iostream>
#include <cmath>
#include <string>
#include <limits>
using namespace std;
/* Group #5
Members: Timothy Na, Hiwon Kim, Matea Milloshi */


struct vector {
  float x;
  float y;
};

void get_vector(string &name, vector &vec)
{
  Input:
  cout<<endl<<"Enter a name for the vector: "<<endl;
  cin>>name;
  cin.clear();

  cout<<"Enter a value for the x-value:"<<endl;
  cin>>vec.x;
  while ( !cin) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    cout << endl << "ERR: Please enter a valid integer, not a letter." << endl;
    goto Input;
  }
  cin.clear();

  cout<<"Enter a value for the y-axis:"<<endl;
  cin>>vec.y;
  while ( !cin) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    cout << endl << "ERR: Please enter a valid integer, not a letter." << endl;
    goto Input;
  }
  cin.clear(); 
}

void add_vector(const vector &vec1, const vector &vec2, vector &sum)
{
  sum.x = vec1.x + vec2.x;
  sum.y = vec1.y + vec2.y;
}

void subtract_vector(const vector &vec1, const vector &vec2, vector &differ)
{
  differ.x = vec1.x - vec2.x;
  differ.y = vec1.y - vec2.y;
}

void scalar_mult(const vector &vec1,int k,vector &s_mult )
{
  s_mult.x = vec1.x*k;
  s_mult.y = vec1.y*k;
}

void sProd_vector(const vector &vec1, const vector &vec2, vector &prod)
{
  prod.x = vec1.x * vec2.x;
  prod.y = vec1.y * vec2.y;
}

double magnitude(vector vec)
{
  return sqrt(pow(vec.x,2)+pow(vec.y,2));
}

int main()
{
  vector vec1, vec2, differ, sum, s_mult, prod;
  int choice, k;
  string name1,name2;

  menu:
  cout<< "Please choose a function"<< endl
  <<"[1] – Vector Addition"<< endl
  <<"[2] – Vector Subtraction"<< endl
  <<"[3] – Scalar Multiple"<< endl
  <<"[4] – Scalar Product"<< endl
  <<"[5] – Magnitude"<< endl
  <<"[6] Exit."<< endl;
  cin>>choice;

  while(!(cin >> choice)){
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Invalid Input." << endl;
    goto menu;
  }
  
  switch(choice)
  {
    case 1:
    get_vector(name1,vec1);
    get_vector(name2,vec2);
    add_vector(vec1,vec2,sum);
    cout<<endl;
    cout<<"Sum of "<<name1<<" + "<<name2<<" :"<<
    " ("<<sum.x<<","<<sum.y<<")"<<endl;
    goto menu;
    break;

    case 2:
    get_vector(name1, vec1);
    get_vector(name2, vec2);
    subtract_vector(vec1,vec2,differ);
    cout<<endl;
    cout<<"Difference of "<<name1<<" - "<<name2<<" :"<<" ("<<differ.x<<","<<differ.y<<")"<<endl;
    goto menu;
    break;

    case 3:
      get_vector(name1, vec1);
      cout<<"Please enter a scalar: ";
      cin>>k;
      scalar_mult(vec1,k,s_mult);
      cout<<"Scalar multiple: "<<"("<<s_mult.x<<" , "<<s_mult.y<<")"<<endl;
      goto menu;
    break;

     case 4:
     get_vector(name1, vec1);
     get_vector(name2, vec2);
      
     sProd_vector(vec1, vec2, prod);
     cout << "Scalar Product of " << name1 << " and " << name2 << " is: " << prod.x +prod.y << endl;
     goto menu;
     break;

    case 5:
    get_vector(name1, vec1);
    cout<<"Magnitude of "<<name1<<" is: "<<magnitude(vec1)<<endl;
    goto menu;
    break;

    case 6:
    return 0;

    default:
    cin.clear();
    cout<<"Invalid Choice. Try again."<<endl;
    goto menu;
    break;
   }
}
