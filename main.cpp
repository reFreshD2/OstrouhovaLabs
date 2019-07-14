#include <iostream>
#include "generation.cpp"
#include "sorting.cpp"

int main() {
    string type = "Down";
    string count = "10000";
    string low = "0";
    string high = "10000";
    string part = "8";
    GenerateV1(type,count,low,high,part);
    string file =
            "C:\\Users\\refre\\CLionProjects\\Kursovaya\\" + type + count + '(' + low + '-' + high + ") - " + part +
            ".txt";
    Paste(Parser(file,Analist(file)),Analist(file));
    Tim(Parser(file,Analist(file)),Analist(file));
    return 0;
}