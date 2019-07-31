#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED
#include "itemtype.h"
struct NodeType{
    itemType info;
    NodeType *next;
};

class unsortedType {
private :
    NodeType *listData;
    int length;
    NodeType *currentPos;
public:
    unsortedType();
    ~unsortedType();
    void putItem(itemType item);
    void deleteItem(itemType item);
    void makeEmpty();
    bool isFull();
    //bool isEmpty();
    int getLength();
    itemType getNextItem();
    itemType getItem(itemType& item, bool& found);
    void resetList();

};

#endif // UNSORTEDTYPE_H_INCLUDED
