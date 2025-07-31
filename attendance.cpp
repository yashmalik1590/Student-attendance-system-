#include <iostream>  //libraries
#include <fstream>    //for file handling
#include <string>   
#include <ctime>
#include <cstdlib>

using namespace std;

string getCurrentDate() {
    time_t now = time(0);    //for current time
    tm *ltm = localtime(&now);   //converting to local time
    char dateStr[20];
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", ltm);
    return string(dateStr);    // to return as string
}

int main() {
    cout << "Content-type: text/html\n\n";    //Yeh line browser ko batati hai ki output HTML format mein

    // Read form data from POST
    string data;
    int len = atoi(getenv("CONTENT_LENGTH"));   //// Kitna data aaya form se
    for (int i = 0; i < len; ++i) {
        char ch = cin.get();       // // Character by character read
        data += ch;
    }

    string roll = data.substr(data.find("=") + 1);    //Roll Number Extract Karna

    string date = getCurrentDate();      // Aaj ki date
    string filename = roll + ".txt";     //// Eg: 21BCS001.txt

    // Open individual roll number file for append
    ofstream file("attendance/" + filename, ios::app);     //Attendance File Open karna and Date Append karna
    if (!file) {
        cout << "<h3>Error writing to file!</h3>";
        return 1;
    }

    file << date << "\n";
    file.close();

    cout << "<h2>✅ Attendance marked for " << roll << " on " << date << "</h2>";
    cout << "<br><a href='/index.html'>Back</a>";
    return 0;
}
