#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class pin
{
private:
    string initialpin;
    string newpin;
    int attempts = 3;

public:
    // initial pin lai intialize
    pin()
    {
        initialpin = "open";
    }
    // check initialpin
    void check()
    {
        while (attempts >= 0)
        {
            string t;
            cout << "Enter 'open' to continue: ";
            cin >> t;
            if (t == initialpin && attempts != 0)
            {
                cout << "Access granted" << endl;
                break;
            }
            else if (attempts == 0)
            {
                cout << "Too many incorrect attempts \n Access denied.......";
                exit(-1);
            }
            attempts--;
            cout << attempts << " Attempts are left" << endl;
        }
    }

    // change pin
    void authentication()
    {
        attempts = 3;
        string extract; // to check if file is empty
        ifstream file("pin.txt");
        if (file.is_open())
        {
            getline(file, extract); // read first line from file into a
            file.close();
        }
        if (extract.empty())
        {
            initialpin = "open";
        }
        else
        {
            initialpin = extract;
        }
        while (attempts >= 0)
        {
            string temp;
            cout << "Enter your 'old' password: ";
            cin >> temp;
            if (temp == initialpin && attempts != 0)
            {
                cout << "Enter your 'new' password: ";
                cin >> newpin;

                ofstream file("pin.txt"); // overwrite in file
                if (file.is_open())
                {
                    file << newpin << endl;
                    file.close();
                    cout << "Password changed and saved successfully\n";
                }
                else
                {
                    cout << "Failed to save password \n";
                }

                newcheck(); // new password check garna
                break;
            }

            else if (attempts == 0)
            {
                cout << "Too many incorrect attempts \n Access denied.......";
                exit(0);
            }
            attempts--;
            cout << attempts << " Attempts are left" << endl;
        }
    }

    // check your new password
    void newcheck()
    {
        attempts = 3;
        string temp;
        string checkpin; // file ma vako pass checkpin ma rakhne
        ifstream file("pin.txt");

        if (file.is_open())
        {
            getline(file, checkpin); // read the first line into checkpin
            file.close();
        }
        else
        {
            cout << "Unknown error occured\n";
        }
        while (attempts >= 0)
        {
            cout << "Enter your password: ";
            cin >> temp;
            if (checkpin == temp && attempts != 0)
            {
                cout << "Access granted" << endl;
                break;
            }
            else if (attempts == 0)
            {
                cout << "To many incorrect attempts \n Access denied....";
                exit(-1);
            }
            attempts--;
            cout << attempts << " Attempts are left" << endl;
        }
    }
};

class person
{
protected:
    string name;
    int age;
    float height;

public:
    void inputpersondata()
    {
        cout << "Enter your name:" << endl;
        cin >> name;
        cout << "Enter your age:" << endl;
        cin >> age;
        cout << "Enter your height in cm:" << endl;
        cin >> height;
        try
        {
            if (age < 0 || height < 0)
            {
                throw invalid_argument("");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: Invalid input detected." << endl;
            return; // Exit the function if invalid input
        }
        set_in_file(); // save personal data to file
    }
    void set_in_file()
    {
        ofstream file("person.txt");
        if (file.is_open())
        {
            file << name << endl;
            file << age << endl;
            file << height << endl;
            file.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }
    }
};

class HealthData : public person
{

protected:
    float water_intake;
    float weight;
    float sleep;
    int BP_systolic;
    int BP_diastolic;
    int steps;
    float BMI;
    float calories;
    float BMR;

public:
    void inputdata()
    {
        string temp;
        ifstream file("person.txt");
        if (file.is_open())
        {
            getline(file, temp); // read first line from file into temp
            file.close();
        }
        // If file doesn't exist or is empty, ask for personal data and save it
        if (temp.empty())
        {
            inputpersondata(); // get data from user
            // Now temp is still empty, but file is created and filled
        }

        // Now read the data from the file
        ifstream filep("person.txt");
        if (filep.is_open())
        {
            getline(filep, name);
            string agetemp, heighttemp;
            getline(filep, agetemp);
            getline(filep, heighttemp);
            age = stoi(agetemp);
            height = stof(heighttemp);
            filep.close();
        }
        else
        {
            cout << "Failed to open person file after writing." << endl;
            return;
        }
        cout << "enter your water intake in litres:" << endl;
        cin >> water_intake;
        cout << "enter your weight in kg:" << endl;
        cin >> weight;
        cout << "enter your sleep in hours:" << endl;
        cin >> sleep;
        cout << "enter your BP_systolic:" << endl;
        cin >> BP_systolic;
        cout << "enter your BP_diastolic:" << endl;
        cin >> BP_diastolic;
        cout << "enter your steps:" << endl;
        cin >> steps;
        try
        {
            if (water_intake < 0 || weight < 0 || sleep < 0 || BP_systolic < 0 || BP_diastolic < 0 || steps < 0)
            {
                throw invalid_argument(""); // You can leave the message empty or use a generic one
            }
        }
        catch (const invalid_argument &e)
        {
            string msg = "Negative values are not allowed.";
            cout << "Error: " << msg << endl;
            return; // Exit the function if invalid input
        }
        calculations();
    }

    void calculations()
    {
        BMI = weight / ((height / 100) * (height / 100));
        BMR = 10 * weight + 6.25 * height - 5 * age + 5;
        calories = BMR * 1.2;
        set_to_file();
    }

    void showdata()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Water Intake: " << water_intake << " litres" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Sleep: " << sleep << " hours" << endl;
        cout << "Blood Pressure: " << BP_systolic << "/" << BP_diastolic << endl;
        cout << "Steps: " << steps << endl;
        cout << "BMI: " << BMI << endl;
        cout << "BMR (Assuming minimal activity): " << BMR << " kcal/day" << endl;
        cout << "Approximate calories Burned: " << calories << endl;
    }

    void set_to_file()
    {
        ofstream file("water.txt", ios::app);
        if (file.is_open())
        {
            file << water_intake << endl;
            file.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }

        ofstream file1("weight.txt", ios::app);
        if (file1.is_open())
        {
            file1 << weight << endl;
            file1.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }

        ofstream file2("sleep.txt", ios::app);
        if (file2.is_open())
        {
            file2 << sleep << endl;
            file2.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }

        ofstream file3("BP.txt", ios::app);
        if (file3.is_open())
        {
            file3 << BP_systolic << "/" << BP_diastolic << endl;
            file3.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }

        ofstream file4("BMI.txt", ios::app);
        if (file4.is_open())
        {
            file4 << BMI << endl;
            file4.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }

        ofstream file5("calories.txt", ios::app); // append mode
        if (file5.is_open())
        {
            file5 << calories << endl;
            file5.close();
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }
    }

    void history()
    {
        // Water intake history
        cout << "...Displaying history..." << endl;
        ifstream file("water.txt");
        if (file.is_open())
        {
            string line;
            cout << "Water Intake History:" << endl;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Failed to open water intake history file." << endl;
        }

        // Weight history
        ifstream file1("weight.txt");
        if (file1.is_open())
        {
            string line;
            cout << "Weight History:" << endl;
            while (getline(file1, line))
            {
                cout << line << endl;
            }
            file1.close();
        }
        else
        {
            cout << "Failed to open weight history file." << endl;
        }

        // Sleep history
        ifstream file2("sleep.txt");
        if (file2.is_open())
        {
            string line;
            cout << "Sleep History:" << endl;
            while (getline(file2, line))
            {
                cout << line << endl;
            }
            file2.close();
        }
        else
        {
            cout << "Failed to open sleep history file." << endl;
        }

        // Blood pressure history
        ifstream file3("BP.txt");
        if (file3.is_open())
        {
            string line;
            cout << "Blood Pressure History:" << endl;
            while (getline(file3, line))
            {
                cout << line << endl;
            }
            file3.close();
        }
        else
        {
            cout << "Failed to open blood pressure history file." << endl;
        }

        // BMI history
        ifstream file4("BMI.txt");
        if (file4.is_open())
        {
            string line;
            cout << "BMI History:" << endl;
            while (getline(file4, line))
            {
                cout << line << endl;
            }
            file4.close();
        }
        else
        {
            cout << "Failed to open BMI history file." << endl;
        }

        // Calories burned history
        ifstream file5("calories.txt");
        if (file5.is_open())
        {
            string line;
            cout << "Calories Burned History:" << endl;
            while (getline(file5, line))
            {
                cout << line << endl;
            }
            file5.close();
        }
        else
        {
            cout << "Failed to open calories burned history file." << endl;
        }
    }
};

class Goal : public person
{
private:
    float waterGoal;
    float sleepGoal;
    float weightGoal;

public:
    Goal() // default values intiallize gara
    {
        waterGoal = 3;
        sleepGoal = 8;
        weightGoal = (int)((int)22 / ((int)height * (int)height / 10000));
    }

    void initializeGoalFile() // goal value lai file ma save garxa
    {
        ifstream file("goal.txt");
        if (!file.is_open())
        {
            ofstream newfile("goal.txt");
            if (newfile.is_open())
            {
                newfile << waterGoal << " " << sleepGoal << " " << weightGoal << endl;
                newfile.close();
            }
        }
        else
        {
            file.close();
        }
    }

    void loadGoalFromFile() // goal value lai file bata load garxa
    {
        ifstream file("goal.txt");
        if (file.is_open())
        {
            file >> waterGoal >> sleepGoal >> weightGoal;
            file.close();
        }
    }

    void showGoal()
    {
        cout << "-----Current Goals-----\n";
        cout << "Water Intake: " << waterGoal << " L\n";
        cout << "Sleep: " << sleepGoal << " hr\n";
        cout << "Weight: " << weightGoal << " kg\n";
    }

    void changeGoal() // goal value lai overwrite (change) garxa
    {
        cout << "Enter new water intake goal(litre): " << endl;
        cin >> waterGoal;
        cout << "Enter new sleep goal(hour): " << endl;
        cin >> sleepGoal;
        cout << "Enter new weight goal(kg): " << endl;
        cin >> weightGoal;

        ofstream file("goal.txt");
        if (file.is_open())
        {
            file << waterGoal << " " << sleepGoal << " " << weightGoal << endl;
            file.close();
            cout << "Goals updated successfully!\n";
        }
    }
};

class Quote
{
private:
    string quoteOfDay;

public:
    void setQuote()
    {
        string quotes[10] =
            {
                "Push yourself, because no one else is going to do it for you.",
                "Success doesn't just find you. You have to go out and get it.",
                "Great things never come from comfort zones.",
                "Dream it. Wish it. Do it.",
                "Don't stop when you're tired. Stop when you're done.",
                "Work hard in silence, let success make the noise.",
                "The key to success is to focus on goals, not obstacles.",
                "Discipline is the bridge between goals and accomplishment.",
                "Start where you are. Use what you have. Do what you can.",
                "The harder you work for something, the greater you'll feel when you achieve it."};

        srand(time(0)); // only once per program run
        int index = rand() % 10;
        quoteOfDay = quotes[index];
    }

    void displayQuote()
    {
        cout << "\n------ Quote of the Day ------\n";
        cout << quoteOfDay << "\n\n"; // setqoutq ma vaya ko choosen qoute, yo line le display gardinxa
    }
};

void clearAllDataFiles()
{
    const char *files[] = // List all files you want to clear
        {
            "water.txt",
            "weight.txt",
            "sleep.txt",
            "BP.txt",
            "BMI.txt",
            "calories.txt",
            "person.txt",
            "pin.txt",
            "goal.txt"};
    int n = sizeof(files) / sizeof(files[0]);

    for (int i = 0; i < n; i++)
    {
        ofstream file(files[i], ios::trunc); // open file in truncate mode to clear it
        if (file.is_open())
        {
            file.close(); // just open & close to clear contents
        }
        else
        {
            cout << "Failed to clear " << files[i] << endl;
        }
    }
    cout << "All data files cleared successfully!\n";
}
// password haru check garxa ekai choti
void finalcheck()
{
    pin pass;
    string extract; // to check if file is empty
    ifstream file("pin.txt");
    if (file.is_open())
    {
        getline(file, extract); // read first line from file into a
        file.close();
    }

    if (extract.empty())
    {
        pass.check();
    }
    else
    {
        pass.newcheck();
    }
}

int main()
{
    finalcheck();
    pin p;
    HealthData data_per;
    Goal goal;
    Quote quote;
    int choice;

    goal.initializeGoalFile(); // goalfile vaya ko value lai call garxa
    goal.loadGoalFromFile();
    quote.setQuote();

    do
    {
        quote.displayQuote();

        cout << "\t1.Data" << endl;
        cout << "\t2.Display history" << endl;
        cout << "\t3.Personal goals" << endl;
        cout << "\t4.change password" << endl;
        cout << "\t5.Clear all stored data" << endl; // clear data
        cout << "\t6.exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int achoice;
            cout << "\t1.Enter data" << endl;
            cout << "\t2.Show data" << endl;
            cin >> achoice;
            switch (achoice)
            {
            case 1:
                cout << "\n";
                data_per.inputdata();
                break;

            case 2:
                cout << "\n";
                data_per.showdata();
                break;

            default:
                cout << "incorrect option" << endl;
                break;
            }
            break;

        case 2:
            cout << "\n";
            data_per.history();
            break;

        case 3:
            cout << "\n";
            int gchoice;
            cout << "\t1.Show goal" << endl;
            cout << "\t2.Change goal" << endl;
            cin >> gchoice;
            switch (gchoice)
            {
            case 1:
                goal.showGoal();
                break;
            case 2:
                goal.changeGoal();
                break;

            default:
                cout << "incorrect option" << endl;
                break;
            }
            break;

        case 4:
            cout << "\n";
            p.authentication();
            break;

        case 5:
            cout << "\n";
            cout << "Authorization is required" << endl;
            finalcheck();
            cout << "Are you sure you want to clear all stored data? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
            {
                clearAllDataFiles(); // clear garna function lai call
            }
            else
            {
                cout << "Clear data cancelled." << endl;
            }
            break;

        case 6:
            cout << "\n";
            cout << "exiting the program.......";
            exit(0);

        default:
            cout << "incorrect option" << endl;
            cout << "\t choose a correct option" << endl;
            break;
        }
        cout << "\n";
    } while (choice != 6);
}
