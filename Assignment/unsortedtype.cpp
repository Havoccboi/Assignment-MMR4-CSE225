//
// Created by Havoc-PC on 7/24/2019.
//

#include "unsortedtype.h"


 unsortedType::unsortedType(){
    listData=NULL;
    length =0;
}
bool unsortedType::isFull(){
    try{
        NodeType *location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

int unsortedType::getLength() {
    return length;
}
void unsortedType::makeEmpty() {
    NodeType *location;
    while(listData != NULL){
        location = listData;
        delete location;
    }
    length =0;
}

void unsortedType::putItem(itemType item){

    NodeType* location =  new NodeType;
    location->next = listData;
    location->info = item;
    listData = location;
    ++length;
}

itemType unsortedType::getItem(itemType &item,bool& found){
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = location != NULL;
    while(moreToSearch && !found){
        switch(item.comparedTo(location->info)){
            case LESS :
            case GREATER: location= location->next;
            moreToSearch = (location != NULL);
            break;
            default :
                found = true;
                item=location->info;
        }
    }
    return item;
}

void unsortedType::deleteItem(itemType item) {
    NodeType* location;
    location = listData;
    NodeType *tempLocation;
    if(item.comparedTo(listData->info) == EQUAL){
        tempLocation=location;
        listData = listData->next;
    }
    else {
        while(item.comparedTo(location->info) != EQUAL)
            location=location->next;
        tempLocation=location->next;
        location->next = location->next->next;
    }
    delete tempLocation;
    length--;
}
void unsortedType::resetList() {
    currentPos= NULL;
}
itemType unsortedType::getNextItem() {
    if(currentPos = NULL){
        currentPos = listData;
    }
    else currentPos = currentPos->next;
    return currentPos->info;
}

unsortedType::~unsortedType() {
    makeEmpty();
}


