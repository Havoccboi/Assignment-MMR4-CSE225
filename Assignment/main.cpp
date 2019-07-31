#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <sstream>
#include "unsortedtype.h"
#include "unsortedtype.cpp"
#include "itemtype.h"
#include "itemtype.cpp"

using namespace std;
int main (int argc , char** argv){
    ifstream inFile;
    ofstream outFile;
    outFile.open("Players-Summary.txt");
    inFile.open("Players.txt"); // file is with , main ,cpp & h files
    if(inFile.fail()){
        cerr<<"Error in File!"<<endl; // to show error
        exit(1);
    }
        int n;
    cin>>n;
    unsortedType list;
    while(n--){

            int id;
            string temp;
            inFile >> temp;
            inFile >> id;
            inFile >> temp;
            string name;
            getline(inFile,name);
            inFile>>temp;
            string runs;
            getline(inFile,runs);
            vector<int> vect;

            stringstream ss(runs);

            for (int i; ss >> i;) {
            vect.push_back(i);
            if (ss.peek() == ',' || ss.peek() == ' ')
                ss.ignore();
            }


                itemType item;
            item.Initialize(id,name);
            item.setRuns(vect);
            list.putItem(item);

            //printing in players-summary.txt

            outFile<<"ID: "<<item.getId()<<endl;
            outFile<<"Name: "<<item.getName()<<endl;
            outFile<<"Total Run: "<<item.findTotal()<<endl;
            outFile<<"Average Run: "<<item.findAverage()<<endl;
            outFile<<"Maximum Run: "<<item.findMax()<<endl;
            outFile<<"Minimum Run: "<<item.findMin()<<endl;
            outFile<<endl;


    }


    inFile.close();
    outFile.close();
    exit(1);
    return 0;
}
