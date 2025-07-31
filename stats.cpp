#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem; //filesystem use ho raha hai folder ke andar files ko list karne ke liye.

int main() {
    cout << "Content-type: text/html\n\n";   //HTML Response Header
    cout << "<h2>📊 Attendance Statistics</h2><ul>";

    string dirPath = "attendance";   // Attendance Folder Check Karna
    if (!fs::exists(dirPath)) {
        cout << "<li>No attendance records found.</li>";
        cout << "</ul><a href='/index.html'>Back</a>";
        return 0;
    }

    for (const auto &entry : fs::directory_iterator(dirPath)) {  //Folder ke Andar Har File Par Loop Lagana
        string filename = entry.path().filename().string();
        string roll = filename.substr(0, filename.find("."));

        ifstream file(entry.path()); //Attendance Count Karna (Lines Count = Days Present)
        int count = 0;
        string line;
        while (getline(file, line)) count++;
        file.close();
//HTML Output Show Karna
        cout << "<li>Roll No: " << roll << " | Days Present: " << count << "</li>";
    }
// HTML List Close + Back Button
    cout << "</ul><a href='/index.html'>Back</a>";
    return 0;
}
