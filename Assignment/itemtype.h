#ifndef ITEMTYPE_H_INCLUDED
#define ITEMTYPE_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
const int size = 10;
enum Relation {LESS, GREATER, EQUAL};
class itemType{
private:
    int id;
    std::string name;
    int runArray[size];
public:
    void Initialize(int, std::string);
    int findTotal();
    float findAverage();
    int findMax();
    int findMin();
    Relation comparedTo(itemType item);
    int getId();
    void setRuns(std::vector<int> arr);
    std::string getName();

};

#endif // ITEMTYPE_H_INCLUDED
