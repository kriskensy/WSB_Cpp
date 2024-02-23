//Mateusz Pieda 18.05.2023 - Zadanie 1 Programowanie w C++

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Container {

  public:
    int counter;
    T array[20];

    Container()
    :counter(0){
    }

    void addElement(const T& object) {
      if (counter < 20) {
        array[counter] = object;
        counter++;
      } else {
        cout<<"Container is full. No more objects can be added."<<endl;
      }
    }

    friend ostream& operator<<(ostream& out, const Container<T>& container)
    {
        for (int i = 0; i < container.counter; i++) {
            out <<container.array[i]<<" ";
        }
        return out;
    }

};

class Furniture {

  protected:
    double weight;
    double width;
    double depth;
    double height;

  public:
    Furniture(double weight, double width, double depth, double height)
    :weight(weight), width(width), depth(depth), height(height){
    }

    Furniture() {
    }

};

class Table:public Furniture {

  private:
    string ID;
    int noOfLegs;

  public:

    Table(double weight, double width, double depth, double height, string ID, int noOfLegs)
    :Furniture(weight, width, depth, height), ID(ID),noOfLegs(noOfLegs){
    }

    Table() {
    }

    ~Table(){
    }

    friend ostream& operator<<(ostream& out, const Table& toDisplay) {
      return out <<toDisplay.ID<<" "<<toDisplay.noOfLegs<<" "<<toDisplay.weight;
    }

    friend bool operator==(const Table& tOne, const Table& tTwo) {
      return tOne.noOfLegs == tTwo.noOfLegs;
    }

    friend istream& operator>>(istream& in, Table& toInput) {
      in>>toInput.weight;
      in>>toInput.width;
      in>>toInput.depth;
      in>>toInput.height;
      in>>toInput.ID;
      in>>toInput.noOfLegs;

      return in;
    }

};

int main(int argc, char *argv[]) {

  Container<Table> tables;

  for (int i = 0; i < 5; i++) {
    double weight, width, depth, height;
    string ID;
    int noOfLegs;

    cin>>weight;
    cin>>width;
    cin>>depth;
    cin>>height;
    cin>>ID;
    cin>>noOfLegs;

    tables.addElement(Table(weight,width,depth,height,ID,noOfLegs));
    
  }

  cout<<tables;
  
  if (tables.array[3]==tables.array[4]) {
    cout<<"equal";
    return 0;
  }
  cout<< "different";

  return 0;

}