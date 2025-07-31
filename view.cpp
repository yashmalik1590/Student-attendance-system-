#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Content-type: text/html\n\n";      //CGI HTML Header Output

    // Read POST data
    string data;
    int len = atoi(getenv("CONTENT_LENGTH"));     // Total POST data length
    for (int i = 0; i < len; ++i) {
        char ch = cin.get();                     // Read char by char
        data += ch;
    }

    string roll = data.substr(data.find("=") + 1);     //Roll Number Extract Karna
    string filename = "attendance/" + roll + ".txt";   //File Ka Path Set Karna

    ifstream file(filename);
    if (!file) {                //Agar file exist nahi karti (ya attendance nahi mark ki gayi):
        cout << "<h3>No records found for Roll No: " << roll << "</h3>";
        cout << "<a href='/index.html'>Back</a>";    
        return 0;
    }

    cout << "<h2>Attendance for Roll No: " << roll << "</h2><ul>";
    string date;
    while (getline(file, date)) {     //Attendance List Show Karna (HTML List)
        cout << "<li>" << date << "</li>";
    }
    cout << "</ul><a href='/index.html'>Back</a>";
    file.close();

    return 0;
}
