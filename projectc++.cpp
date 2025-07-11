    #include<iostream>
    #include<string>
    #include<fstream>
    using namespace std;
    class pin
    {
        private:
        string initialpin;
        string newpin;
        int attempts=3;
        public:
        //initial pin lai intialize
        pin()
        {
            initialpin="open";
        }
        //check initialpin
        void check()
        { 
            while(attempts>0)
            {
                string t;
                cout<<"enter open to continue"<<endl;
                cin>>t;
                if(t==initialpin && attempts!=0)
                {
                cout<<"acess granted"<<endl;
                break;
                }
                else if(attempts==0)
                {
                    cout<<"too many incorect attempts \n acess denied.......";
                    exit(0);
                }
                attempts--;
                cout<<attempts<<" atempts are left"<<endl;
            }
        }
        //change pin
        void authentication()
        { 
            attempts=3;
            string extract;//to check if file is empty
          ifstream file("pin.txt");
        if (file.is_open()) 
    {
        getline(file, extract);  // read first line from file into a
        file.close();
    }
     if (extract.empty()) 
        {
        initialpin="open";
        }
        else{
           initialpin=extract;
        }
        while(attempts>0)
            {
                string temp;
                cout<<"enter your old password:"<<endl;
                cin>>temp;
                if(temp==initialpin && attempts!=0)
                {
                   cout<<"enter your new password"<<endl;
                   cin>>newpin;
           
            ofstream file("pin.txt");  // overwrite in file
            if (file.is_open()) {
                file << newpin << endl;
                file.close();
                cout << "Password changed and saved successfully\n";
            } else {
                cout << "Failed to save password \n";
            }

                newcheck(); //new password check garna
                break;
            }
                
                else if(attempts==0)
                {
                    cout<<"too many incorect attempts \n acess denied.......";
                    exit(0);
                }
                attempts--;
                cout<<attempts<<" atempts are left"<<endl;
            }
        }
        //check your new password
    void newcheck()
    { 
         attempts=3;
        string temp;
         string checkpin;//file ma vako pass checkpin ma rakhne
    ifstream file("pin.txt");

    if (file.is_open()) {
        getline(file, checkpin);  // read the first line into checkpin
        file.close();
    } else {
        cout << "Unknown error occured\n";
    }
         while(attempts>0)
            {
                cout<<"enter your password:"<<endl;
                cin>>temp;
                if(checkpin==temp && attempts!=0)
                {
                cout<<"acess granted"<<endl;
                break;
                }
                else if(attempts==0)
                {
                    cout<<"to many incoorect attempts \n acess denied....";
                    exit(0);

                }
                 attempts--;
                cout<<attempts<<" atempts are left"<<endl;
            }
        }
    
    };
    int main()
    {
        string extract;//to check if file is empty
        int choice;
          ifstream file("pin.txt");
        pin p;
        if (file.is_open()) 
    {
        getline(file, extract);  // read first line from file into a
        file.close();
    }
    
        if (extract.empty()) 
        {
        p.check();
        }
        else{
            p.newcheck();
        }
        do
        {
            cout<<"1.change password"<<endl;
            cout<<"2.exit"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                p.authentication();
                break;
                case 2:
                exit(0);
                default:
                cout<<"incorrect option"<<endl;
                break;
            }
        } while (choice!=2);
    }
