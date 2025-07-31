# Student Attendance System (C++ CGI + HTML)

This project is a simple web-based student attendance system using:
- **C++** for backend logic via **CGI scripts**
- **HTML + Tailwind CSS** for frontend UI
- **Text files** for local attendance storage

## How It Works
1. Mark attendance (stores date under `roll.txt`)
2. View attendance (reads data for a student)
3. View statistics (counts attendance entries)

## Run Locally
1. Install XAMPP & enable CGI in Apache
2. Compile C++ files in `src/` to `cgi-bin/` using `g++`
3. Place `html/` and `styles/` inside `htdocs/`
4. Access pages via `localhost/project-folder/`

