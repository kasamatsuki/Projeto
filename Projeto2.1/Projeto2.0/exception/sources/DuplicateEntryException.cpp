
#include "../headers/DuplicateEntryException.h"


DuplicateEntryException::DuplicateEntryException(string data){
    this->data = "Error: ["+ data + "] duplicated!!";
}

const char* DuplicateEntryException::what(){
    return this->data.c_str();
}
