#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

static int count = 0;

class not_registered_error : public exception
{
public:
    const char *what()
    {
        return "Sorry. You have not yet registered\n";
    }
};

class age_criteria_error : public exception

{
public:
    const char *what()
    {
        return "Sorry. As your age is less than 18, you are not eligible for vaccination.\n";
    }
};

class vaccine
{
public:
    struct vaccination
    {
        string centre;
        int number;
    } cv[5], cs[5], pf[5];
};

class covaxin : public vaccine
{
public:
    covaxin()
    {
        cv[0].centre = "Rotary School, Hubli";
        cv[0].number = 500;
        cv[1].centre = "Smart Public School, Hubli";
        cv[1].number = 255;
        cv[2].centre = "National Public School, Dharwad";
        cv[2].number = 1000;
        cv[3].centre = "Corporation Middle School, Hubli";
        cv[3].number = 800;
        cv[4].centre = "JK School, Dharwad";
        cv[4].number = 150;
        cv[5].centre = "Sainik School, Dharwad";
        cv[5].number = 320;
    }

    void display1(covaxin v1);

    void vacinated(int t)
    {
        cv[t - 1].number -= 1;
    }
};

void display1(covaxin v1)
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ".  " << v1.cv[i].centre << "      - " << v1.cv[i].number << endl;
    }
}

class covishield : public vaccine
{
public:
    covishield()
    {
        cs[0].centre = "Rotary School, Hubli";
        cs[0].number = 500;
        cs[1].centre = "Smart Public School, Hubli";
        cs[1].number = 255;
        cs[2].centre = "National Public School, Dharwad";
        cs[2].number = 1000;
        cs[3].centre = "Corporation Middle School, Hubli";
        cs[3].number = 800;
        cs[4].centre = "JK School, Dharwad";
        cs[4].number = 150;
        cs[5].centre = "Sainik School, Dharwad";
        cs[5].number = 320;
    }

    void display2(covishield v2);

    void vacinated(int t)
    {
        cs[t - 1].number -= 1;
    }
};

class pfizer : public vaccine
{
public:
    pfizer()
    {
        pf[0].centre = "Rotary School, Hubli";
        pf[0].number = 500;
        pf[1].centre = "Smart Public School, Hubli";
        pf[1].number = 255;
        pf[2].centre = "National Public School, Dharwad";
        pf[2].number = 1000;
        pf[3].centre = "Corporation Middle School, Hubli";
        pf[3].number = 800;
        pf[4].centre = "JK School, Dharwad";
        pf[4].number = 150;
        pf[5].centre = "Sainik School, Dharwad";
        pf[5].number = 320;
    }

    void display3(pfizer v3);

    void vacinated(int t)
    {
        pf[t - 1].number -= 1;
    }
};

void display3(pfizer v3)
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ".  " << v3.pf[i].centre << " - " << v3.pf[i].number << endl;
    }
}

void display2(covishield v2)
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ".  " << v2.cs[i].centre << " - " << v2.cs[i].number << endl;
    }
}

class people
{
public:
    struct details
    {
        string name;
        int age;
        long long int phoneNumber;
        bool dose1;
        bool dose2;
        string password;
    } d[1000];

    void signUp()
    {
        cout << "Name: ";
        cin >> d[count].name;
        cout << "Phone Number: ";
        cin >> d[count].phoneNumber;
        cout << "Password: ";
        cin >> d[count].password;
        count++;
    }

    int login(long long int phno, string pwd)
    {
        for (int i = 0; i < count; i++)
        {
            if ((this->d[i].phoneNumber == phno) && !(this->d[i].password.compare(pwd)))
            {
                return i;
            }
        }
        return -1;
    }

    void firstDose(int t)
    {
        d[t].dose1 = true;
    }

    void secondDose(int t)
    {
        d[t].dose2 = true;
    }
};
class information
{
public:
    long long int aadhar;
    int yr_br, res_c, wrd_no, sub;
    char gne;
    string comor;
    void info()
    {
        cout << "\nAadhar number : ";
        cin >> aadhar;
        cout << "\nGender (M/F): ";
        cin >> gne;
        try
        {
            cout << "\nYear of birth : ";
            cin >> yr_br;
            if (yr_br > 2005)
                throw age_criteria_error();
        }
        catch (age_criteria_error &error)
        {
            cout << error.what() << endl;
            exit(0);
        }
        cout << "\nAny existing Comorbidities : ";
        cin >> comor;
        cout << "\n1. Hubballi Dharwad Muncipal Corporation\n2. Others";
        cout << "\nResidential Area : ";
        cin >> res_c;
        if (res_c != 1)
        {
            cout << "Sorry. This app only makes booking for the cities of Hubli-Dharwad\n";
            exit(0);
        }
        cout << "\nWard number (1 - 100): ";
        cin >> wrd_no;
    }
};

int main()
{
    cout << "************************************\n\n";
    cout << "                                      VACCINE RESERVATION                                                 \n\n";
    cout << "************************************\n\n";
    int ch1, ch2, ch3, n1, n2;
    int sub1, sub2;
    long long int phone;
    string name, password, last;
    people p;
    covaxin v1;
    covishield v2;
    pfizer v3;
    information obj;
    do
    {
        cout << "\n\t\t\t1. Register\n\t\t\t";
        cout << "2. Login\n\t\t\t";
        cout << "3. Covaxin Slot Availability\n\t\t\t";
        cout << "4. Covishield Slot Availability\n\t\t\t";
        cout << "5. Pfizer Slot Availability\n\t\t\t";
        cout << "6. Exit";
        cout << "\n\t\t\tEnter your choice (1 - 6) :  ";
        cin >> ch1;
        cout << endl;
        switch (ch1)
        {
        case 1:
        {
            cout << "**  REGISTER  **" << endl;
            p.signUp();
            break;
        }
        case 2:
        {
            cout << "**  LOGIN  **" << endl;
            cout << "Phone Number: ";
            cin >> phone;
            cout << "Password: ";
            cin >> password;
            try
            {
                n1 = p.login(phone, password);
                if (n1 == -1)
                {
                    throw not_registered_error();
                    break;
                }
            }
            catch (not_registered_error &error)
            {
                cout << error.what();
                continue;
            }
            cout << "\n1. First Dose\n2. Second Dose ";
            cout << "\nDosage of Vaccination : ";
            cin >> ch2;
            if (ch2 == 1)
            {
                p.firstDose(n1);
            }
            else if (ch2 == 2)
            {
                p.secondDose(n1);
            }
            cout << "\n1. Covaxin\n2. Covishield\n3. Pfizer: ";
            cout << "\nVaccine Type : ";
            cin >> ch3;
            if (ch3 == 1)
            {
                cout << "\n";
                display1(v1);
                cout << "Select center number: ";
                cin >> n2;
                v1.vacinated(n2);
                obj.info();
                cout << "Confirm Submission  1. Yes  2. No : ";
                cin >> sub1;
                if (sub1 == 1)
                {
                    cout << "\nDear " << name << ", you have successfully registered for the Covaxin Vaccination.\n";
                    cout << "Your slot for vaccinating will be alloted shortly. Thankyou for Registering!!!\n";
                    cout << "Helpline : 10789";
                }
                else if (sub1 == 2)
                {
                    cout << "If you want to make changes. Please exit and Re-login into it.\n";
                }
            }
            else if (ch3 == 2)
            {
                cout << "\n";
                display2(v2);
                cout << "Select center number: ";
                cin >> n2;
                v2.vacinated(n2);
                obj.info();
                cout << "\nConfirm Submission  1. Yes  2. No : ";
                cin >> sub2;
                if (sub2 == 1)
                {
                    cout << "Dear " << name << ", you have successfully registered for the Covishield Vaccination.\n";
                    cout << "Your slot for vaccinating will be alloted shortly. Thankyou for Registering!!!\n";
                    cout << "Helpline : 10789";
                }
                else if (sub2 == 2)
                {
                    cout << "If you want to make changes. Please Re-login into it.\n";
                }
            }
            else if (ch3 == 3)
            {
                cout << "\n";
                display3(v3);
                cout << "Select center number: ";
                cin >> n2;
                v3.vacinated(n2);
                obj.info();
                cout << "\nConfirm Submission  1. Yes  2. No : ";
                cin >> sub2;
                if (sub2 == 1)
                {
                    cout << "Dear " << name << ", you have successfully registered for the Pfizer Vaccination.\n";
                    cout << "Your slot for vaccinating will be alloted shortly. Thankyou for Registering!!!\n";
                    cout << "Helpline : 10789";
                }
                else if (sub2 == 2)
                {
                    cout << "If you want to make changes. Please Re-login into it.\n";
                }
            }
            cout << "\n\n\t\t\t##  GUIDELINE  ##\n";
            cout << "Dear user, Please kindly do follow the below guideline while getting vaccination \n";
            cout << "1. Arrive at the Vaccination Center at the correct time.\n";
            cout << "2. Please carry the Aadhar photo id proof with you.\n It will be verified at the time of vaccination appoinment.\n";
            cout << "3. Please be patient at the Vaccination center.\n";
            cout << "4. Don't forget to get back your photo id proof.\n";
            cout << "5. Don't rub your hands as soon as vaccine is injected.\n";
            cout << "\n\t\t\t  HAPPY VACCINATION :)            \n";
            break;
        }
        case 3:
        {
            cout << "**  COVAXIN SLOT AVAILABILITY  **" << endl;
            display1(v1);
            break;
        }
        case 4:
        {
            cout << "**  COVISHIELD SLOT AVAILABILITY  **" << endl;
            display2(v2);
            break;
        }
        case 5:
        {
            cout << "**  PFIZER SLOT AVAILABILITY  **" << endl;
            display3(v3);
            break;
        }
        case 6:
        {
            cout << "**  EXIT  **" << endl;
            exit(0);
        }

     }

    } while (ch1 != 6);
    return 0;
}