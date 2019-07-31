//
// Created by Havoc-PC on 7/24/2019.
//
#include "itemtype.h"



void itemType::Initialize(int _id, std::string _name) {
    id = _id;
    name = _name;
}

int itemType::findTotal(){
    int s=0;
    for(int i=0;i<size;i++){
        s+=runArray[i];
    }
    return s;
}

float itemType::findAverage() {
    float s = findTotal();
    s*=1.0;

    return s/size;
}
int itemType::findMax() {
    int max = runArray[0];
    for(int i=1;i<size;i++){
        if(max < runArray[i])
            max=runArray[i];
    }
    return max;
}

int itemType::findMin(){
    int min = runArray[0];
    for(int i=1;i<size;i++){
        if(min > runArray[i])
            min=runArray[i];
    }
    return min;
}
int itemType::getId(){
    return id;
}
Relation itemType::comparedTo(itemType item) {
    if(this->id == item.getId()){
        return EQUAL;
    }
    else if (this->id > item.getId())
        return GREATER;
    else return LESS;
}
void itemType::setRuns(std::vector<int> arr) {
    for(int i=0;i<size;i++){
         runArray[i]=arr[i];
    }
}
std::string itemType::getName() {
    return name;
}





