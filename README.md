# 💪 Health Tracker

A comprehensive command-line health and fitness tracking application built with C/C++ to help you monitor and manage your wellness journey.

## 📖 About

This health tracker is a personal wellness management system that allows users to track multiple health metrics in one place. With secure PIN protection and persistent data storage, you can monitor your progress over time and work towards your fitness goals.

## ✨ Features

### 🎯 Core Tracking Modules
- **BMI Calculator** - Calculate and track Body Mass Index
- **Calorie Tracker** - Monitor daily calorie intake and expenditure
- **Water Intake** - Track daily hydration levels
- **Sleep Monitor** - Record and analyze sleep patterns
- **Blood Pressure** - Log blood pressure readings
- **Weight Management** - Set and track weight goals

### 🔐 Additional Features
- PIN-based authentication for data privacy
- Persistent file storage (data saved between sessions)
- Historical data tracking
- Personalized goal setting
- User profile management
- Activity history logs

## 🛠️ Technologies Used

- **Languages:** C and C++
- **Concepts:** File I/O, data structures, modular programming, user authentication
- **Storage:** Text file-based persistence for each metric

## 📁 File Structure

```
health_tracker/
├── SEM2.cpp              # C++ implementation
├── project.c             # C implementation
├── projectc++.cpp        # Alternative C++ version
├── BMI.txt               # BMI data storage
├── BP.txt                # Blood pressure records
├── calories.txt          # Calorie tracking data
├── water.txt             # Water intake logs
├── sleep.txt             # Sleep pattern records
├── weight.txt            # Weight tracking data
├── goal.txt              # User fitness goals
├── person.txt            # User profile information
├── pin.txt               # Security PIN storage
├── balance.txt           # Additional tracking data
├── history.txt           # Activity history
└── .vscode/              # VS Code configuration
```

## 🚀 How to Run

### Prerequisites
- C/C++ compiler (GCC, MinGW, or MSVC)
- Terminal/Command Prompt

### Compilation

**For C++ version:**
```bash
g++ SEM2.cpp -o health_tracker
# or
g++ projectc++.cpp -o health_tracker
```

**For C version:**
```bash
gcc project.c -o health_tracker
```

### Execution

```bash
# On Linux/Mac
./health_tracker

# On Windows
health_tracker.exe
```

## 💡 Usage Guide

### First Time Setup
1. Run the application
2. Create a secure PIN
3. Set up your profile (name, age, initial weight, height)
4. Set your fitness goals

### Daily Usage
1. Enter your PIN to access the system
2. Choose from the main menu:
   - Track daily metrics (calories, water, sleep)
   - Log health readings (BMI, blood pressure, weight)
   - View historical data and progress
   - Update goals
   - View activity summary

### Example Workflow
```
1. Enter PIN → 2. Log breakfast calories → 3. Record water intake
→ 4. Check BMI → 5. View weekly progress → 6. Exit (auto-save)
```

## 📊 Tracking Categories

### 🍎 Nutrition
- Daily calorie intake
- Meal logging
- Calorie balance calculations

### 💧 Hydration
- Water consumption (glasses/liters)
- Daily hydration goals
- Intake reminders

### 😴 Sleep
- Sleep duration
- Sleep quality ratings
- Sleep pattern analysis

### ⚖️ Body Metrics
- Weight tracking with trend analysis
- BMI calculations
- Body measurements

### 🩺 Health Vitals
- Blood pressure monitoring
- Heart rate (if implemented)
- Health status indicators

## 🎯 Learning Outcomes

This project helped develop skills in:
- C/C++ file handling and data persistence
- Modular programming and code organization
- Working with multiple data files simultaneously
- Implementing user authentication systems
- Data validation and error handling
- Creating menu-driven console applications
- Managing user data securely

## 🔮 Future Improvements

- [ ] Add data visualization (charts/graphs)
- [ ] Implement data export (CSV/JSON format)
- [ ] Add exercise tracking module
- [ ] Include nutrition database integration
- [ ] Add health recommendations based on tracked data
- [ ] Implement data backup and restore
- [ ] Add multi-user support
- [ ] Create mobile or web interface
- [ ] Include medication reminders
- [ ] Add report generation (daily/weekly/monthly summaries)

## 🐛 Known Issues

- Limited input validation in some modules
- No data encryption (PIN stored in plain text)
- No automatic data backup

## 🔒 Security Note

**Important:** This is an educational project. The PIN protection uses basic file storage and should not be considered secure for sensitive health data in production environments.

## 🤝 Contributing

This was built as a semester project, but improvements are welcome! Feel free to:
- Report bugs or issues
- Suggest new features
- Improve code quality
- Add documentation
- Submit pull requests

## 👥 Contributors

This project was created as a collaborative semester project. Special thanks to all contributors!

- @purnikaKhanal
- @ThePrashanna-062

## 📧 Contact

**Prijesh Pradhan**
- GitHub: [@prijesshh](https://github.com/prijesshh)
- LinkedIn: [prijeshpradhan](https://www.linkedin.com/in/prijeshpradhan/)
- Email: prijeshpradhan@gmail.com

## 📝 Project Context

Built as a semester 2 project for Computer Engineering coursework, focusing on:
- Practical application of C/C++ programming
- File I/O operations
- Data structure implementation
- Real-world problem solving

## 🙏 Acknowledgments

- Course instructors and mentors
- Team members and collaborators
- Open-source community resources

## 📜 License

This project is open source and available for educational purposes.

---

⭐ If you find this project useful for your learning journey, consider giving it a star!

💡 **Health Tip:** Regular tracking leads to better awareness and healthier choices!
