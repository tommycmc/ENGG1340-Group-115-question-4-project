#include <iostream>
#include <string>
#include <vector>
#include "Record.h"
#include "Database.h"

using namespace std;

int main(){
    int databaseSize{3}, numOfRecord{0};                                                                //initialize the size of database, no. of records in database
    Database database(databaseSize);                                                                    //initialize the database
    
    
    Record acc1{10000, "USD", "F", "C", "001123456789", "11042019", "2300"};                            //initialize a record - for demonstration only//

    for(int i{0}; i<50; i++){
        Record acc{100000.0-i, "USD", "F", "C", "001123456789", "31032019", to_string(1259-i)};
        database.addRecord(acc, numOfRecord, databaseSize);                                             //add 50 records to database
    }                                                                                                   //initial size of database = 3
                                                                                                        //1st expansion of database = 6
                                                                                                        //2nd expansion of database = 12
                                                                                                        //3rd expansion of database = 24
                                                                                                        //4th expansion of database = 48
                                                                                                        //5th expansion of database = 96 > 50 (enough!!)


    //Database: record 1,   record 2,   record 3,   record 4, ...
    //position:     0           1           2           3
    
    for(int i{0}; i<20; i++){
        Record acc{100000.0-i, "USD", "F", "C", "001123456789", to_string(30-i)+"042019", "1230"};
        database.addRecord(acc, numOfRecord, databaseSize);                                             //add 20 records to database
    }         
    
    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database
    
    cout << endl;
    database.changeDataInRecord(3, 700.9, "JPY", "T", "A", "NULL", "21022019", "1228");                 //change 4th record(pos = 3)
    
    cout << endl;
    database.changeDataInRecord(6, 500.54, "USD", "A", "A", "NULL", "20022019", "1300");                //change 7th record(pos = 6)

    
    cout << endl;
    database.filterShowDatabase(numOfRecord, 7);                                                        //filter the records in database with criteria(WHERE)
                                                                                                        //1:   Amount
                                                                                                        //2:   characterOfPayment
                                                                                                        //3:   typeOfPayment
                                                                                                        //4:   bankName
                                                                                                        //5:   accNoOfBank
                                                                                                        //6:   Date
                                                                                                        //7:   Time
                                                                                                        //!!need to divide the bulky program into two small program
    
    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database

    int choice{1};                                                                                      //initialize the sort choice no.
    database.sortDatabase(numOfRecord, choice);                                                         //sort the records with different priority(GROUP BY)
                                                                                                        //1:    characterOfPayment                
                                                                                                        //2:    typeOfPaymentCond
                                                                                                        //3:    date + Time
    
    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database

    
    cout << endl;
    database.deleteRecord(6, numOfRecord, databaseSize);                                                //delete 7th record(pos = 6)
    
    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database
    


    
    return 0;
}