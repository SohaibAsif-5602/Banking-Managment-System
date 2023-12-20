#include <windows.h>
#include <algorithm>
#include <cmath>     // include the math library
#include <fstream>   // include the file stream library
#include <iomanip>   // include the input/output manipulation library
#include <iostream>  // include the input/output stream library
#include <limits>    // include the limits library
#include <string>
using namespace std;  // use the standard namespace

void animateText(const string& text,int delay) {  // function for animation of intro() text
  for (char c : text) {
    cout << c << flush;
    Sleep(delay);
  }
}
void intro() {
  system("cls");
  system("color 0f");
  string str4 = "\n\n\t\t\t\t\tWELCOME TO JAYS BANKING MANAGEMENT SYSTEM\n\n";
  animateText(str4, 10);
  cout << setw(52);
  string str = "DSA Project By\n";
  animateText(str, 10);
  string str3 =
      "\t\t\t\t\t        Huzaifa Azhar 210982 \n\t\t\t\t\t        Abdul Ahad   "
      " 210904 \n\t\t\t\t                Sohaib Asif   210886\n";
  animateText(str3, 10);
  string str2 = "\n\t\t\t\t\t      Submitted to Sir Sagheer\n\n";
  animateText(str2, 10);
}
class user {
  user* nxt_user;
  static int count;
  int id;
  long long id_card;
  long long phone_no;
  string name;
  string Fname;
  string Mname;
  string address;
  float amount;
  int password;
  bool is_admin;

 public:
  user() 
  {
    count++;
    amount = 0;
    is_admin = 0;
  }
  user* get_nextUser() { return nxt_user; }
  static int get_count() { return count; }
  int get_id() { return id; }
  long long get_id_card() { return id_card; }
  long long get_phone_no() { return phone_no; }
  string get_name() { return name; }
  string get_Fname() { return Fname; }
  string get_Mname() { return Mname; }
  string get_address() { return address; }
  bool get_admin() { return is_admin; }
  void set_count(int C) { count = C; }
  void set_admin(bool adm) { is_admin = adm; }
  void set_nextUser(user* v) { nxt_user = v; }
  void set_id(int v) { id = v; }
  void set_id_card(long long v) { id_card = v; }
  void set_phone_no(long long v) { phone_no = v; }
  void set_name(string v) { name = v; }
  void set_Fname(string v) { Fname = v; }
  void set_Mname(string v) { Mname = v; }
  void set_address(string v) { address = v; }
  void setencrpassword(int pass) { password = pass; }
  void set_amount(float a) { amount = a; }

  void setpassword(string pass) {
    hash<string> hashFunction;
    size_t passwordHash = hashFunction(pass);
    password = passwordHash;
  }
  void deposit(float amo) { amount += amo; }
  bool withdraw(float amou) 
  {
    if (amou > amount) 
    {
      cout << "Insufficient Balance!" << endl;
      return 0;
    } else 
    {
      amount -= amou;
      return 1;
    }
  }
  // int get_password()
  // {
  //  return password;
  // }
  float get_amount() { return amount; }
  int get_password() { return password; }
  bool checkpassword(string pass) {
    hash<string> hashFunction;
    size_t passwordHash = hashFunction(
        pass);  // makin variable to save the user privided password(pass)
    if (password == passwordHash) {
      return 1;
    } else {
      return 0;
    }
  }
};

int user ::count = 220000;

class User 
{
  int noA;
  user* head;
  user* temp;

 public:
  User() {
    noA = 0;
    head = NULL;
    temp = NULL;
  }
  void
  load_data()  // loads the data from already existing file in the linked list
  {
    if (noA == 0) {
      cout << "\nNO RECORD ENTERED YET!\n";
      return;
    }
    int temp_id;
    long long temp_id_card;
    long long temp_phone_no;
    string temp_name;
    string temp_Fname;
    string temp_Mname;
    string temp_address;
    int temp_password;
    float temp_amount;
    bool temp_admin;
    ifstream in("sample.txt", ios::in);
    for (int i = 0; i < noA; i++) {
      in >> temp_password;
      in >> temp_id;
      in >> temp_id_card;
      in >> temp_phone_no;
      in >> temp_amount;
      in >> temp_admin;
      in >> temp_name;
      in >> temp_Fname;
      in >> temp_Mname;
      in >> temp_address;
      replace(temp_name.begin(), temp_name.end(), '_', ' ');
      replace(temp_Fname.begin(), temp_Fname.end(), '_', ' ');
      replace(temp_Mname.begin(), temp_Mname.end(), '_', ' ');
      replace(temp_address.begin(), temp_address.end(), '_', ' ');
      if (i == 0) {
        user* newuser = new user();
        newuser->setencrpassword(temp_password);
        newuser->set_id(temp_id);
        newuser->set_id_card(temp_id_card);
        newuser->set_phone_no(temp_phone_no);
        newuser->set_name(temp_name);
        newuser->set_Fname(temp_Fname);
        newuser->set_Mname(temp_Mname);
        newuser->set_address(temp_address);
        newuser->set_amount(temp_amount);
        newuser->set_admin(temp_admin);
        newuser->set_nextUser(NULL);
        head = newuser;
        int x;
        ifstream in("ID.txt", ios::in);
        in >> x;
        in.close();
        newuser->set_count(x);
      } else {
        user* temp = head;
        while (temp->get_nextUser() != NULL) {
          temp = temp->get_nextUser();
        }
        user* newuser = new user();
        newuser->setencrpassword(temp_password);
        newuser->set_id(temp_id);
        newuser->set_id_card(temp_id_card);
        newuser->set_phone_no(temp_phone_no);
        newuser->set_name(temp_name);
        newuser->set_Fname(temp_Fname);
        newuser->set_Mname(temp_Mname);
        newuser->set_address(temp_address);
        newuser->set_amount(temp_amount);
        newuser->set_admin(temp_admin);
        newuser->set_nextUser(NULL);
        temp->set_nextUser(newuser);

        int x;
        ifstream in("ID.txt", ios::in);
        in >> x;
        in.close();
        newuser->set_count(x);
      }
    }
    in.close();

    cout << "\nData Loaded In Linked List Succesfully\n\n";
  }

  int get_noA() { return noA; }  // returns Number of users(nodes) in linked
                                 // list

  void set_noA()  // to set the noA from file
  {
    int a = 0;
    ifstream read("noA.txt", ios::in);
    read >> a;
    noA = a;
    read.close();
  }
  void insert_User()  // function to add user in linked list
  {
    long long temp_id_card;
    long long temp_phone_no;
    string temp_name;
    string temp_Fname;
    string temp_Mname;
    string temp_address;
    string temp_password;
    bool temp_admin = 0;
    cout << "Enter Details of New User" << endl;
    cout << "Enter Password for New User: ";
    cin >> temp_password;
    int size = 0;
    while (size != 13) {
      cout << "Enter Identity Number: ";
      cin >> temp_id_card;
      size = get_length(temp_id_card);
      if (size != 13) {
        cout << "Please Enter 13 Digit CNIC Number!" << endl;
      }
    }
    while (size != 10) {
      cout << "Enter Phone Number: +92 ";
      cin >> temp_phone_no;
      size = get_length(temp_phone_no);
      if (size != 10) {
        cout << "Please Enter 10 Digits of Phone Number!" << endl;
        cout << "Do not include the 0 at the start" << endl;
      }
    }
    cout << "\nEnter Name: ";
    cin.clear();
    fflush(stdin);
    getline(cin, temp_name);
    cout << "\nEnter Father Name: ";
    getline(cin, temp_Fname);
    cout << "\nEnter Mother Name: ";
    getline(cin, temp_Mname);
    cout << "\nEnter Address: ";
    getline(cin, temp_address);
    if (head == NULL) {
      user* newuser = new user;
      newuser->set_id(newuser->get_count());
      newuser->set_id_card(temp_id_card);
      newuser->set_phone_no(temp_phone_no);
      newuser->set_name(temp_name);
      newuser->set_admin(1);
      newuser->setpassword(temp_password);
      newuser->set_Fname(temp_Fname);
      newuser->set_Mname(temp_Mname);
      newuser->set_address(temp_address);
      newuser->set_nextUser(NULL);
      head = newuser;

      ofstream out("sample.txt", ios::app);
      out << newuser->get_password() << "\n";
      out << newuser->get_id() << "\n";
      out << newuser->get_id_card() << "\n";
      out << newuser->get_phone_no() << "\n";
      out << newuser->get_amount() << "\n";
      out << newuser->get_admin() << "\n";
      replace(temp_name.begin(), temp_name.end(), ' ','_');  // function to replace space with _ in file
      out << temp_name << "\n";
      replace(temp_Fname.begin(), temp_Fname.end(), ' ', '_');
      out << temp_Fname << "\n";
      replace(temp_Mname.begin(), temp_Mname.end(), ' ', '_');
      out << temp_Mname << "\n";
      replace(temp_address.begin(), temp_address.end(), ' ', '_');
      out << temp_address << "\n";
      out.close();

      ofstream Out("ID.txt", ios::app);
      Out << newuser->get_count();
      Out.close();

      cout << "\n================================\n";
      display(newuser);

      ofstream out3("noA.txt", ios::app);
      noA++;
      out3 << noA;
      out3.close();
    }

    else {
      temp = head;
      while (temp->get_nextUser() != NULL) 
      {
        temp = temp->get_nextUser();
      }
      cout << "Enter 1 if the User is Admin" << endl;
      cout << "Enter 0 if the User is not Admin" << endl;
      cout << "Choice: ";
      cin >> temp_admin;
      user* newuser = new user;
      newuser->set_id(newuser->get_count());
      newuser->set_id_card(temp_id_card);
      newuser->set_phone_no(temp_phone_no);
      newuser->set_name(temp_name);
      newuser->set_admin(temp_admin);
      newuser->setpassword(temp_password);
      newuser->set_Fname(temp_Fname);
      newuser->set_Mname(temp_Mname);
      newuser->set_address(temp_address);
      newuser->set_nextUser(NULL);
      temp->set_nextUser(newuser);

      ofstream out("sample.txt", ios::app);
      out << newuser->get_password() << "\n";
      out << newuser->get_id() << "\n";
      out << newuser->get_id_card() << "\n";
      out << newuser->get_phone_no() << "\n";
      out << newuser->get_amount() << "\n";
      out << newuser->get_admin() << "\n";
      replace(temp_name.begin(), temp_name.end(), ' ', '_');
      out << temp_name << "\n";
      replace(temp_Fname.begin(), temp_Fname.end(), ' ', '_');
      out << temp_Fname << "\n";
      replace(temp_Mname.begin(), temp_Mname.end(), ' ', '_');
      out << temp_Mname << "\n";
      replace(temp_address.begin(), temp_address.end(), ' ', '_');
      out << temp_address << "\n";
      ;
      out.close();
      cout << "New User added Successfully!!" << endl;

      ofstream Out("temp.txt", ios::app);
      Out << newuser->get_count();
      Out.close();
      remove("ID.txt");
      rename("temp.txt", "ID.txt");

      cout << "\n================================\n";
      display(newuser);
      noA++;

      ofstream out3("temp.txt", ios::app);
      out3 << noA;
      out3.close();
      remove("noA.txt");
      rename("temp.txt", "noA.txt");
    }
  }
  void updateacc(user* newuser)  // to update a user
  {
    int temp_id;
    long long temp_id_card;
    long long temp_phone_no;
    string temp_name;
    string temp_Fname;
    string temp_Mname;
    string temp_address;
    string temp_password;
    int temp_amount;
    bool temp_admin;
    fstream read("sample.txt", ios::in);
    fstream temp;
    if (!read) {
      cout << "NO SUCH FILE PRESENT" << endl;
    } else {
      temp.open("temp.txt", ios::out | ios::app);

      read >> temp_password >> temp_id >> temp_id_card >> temp_phone_no >>
          temp_amount >> temp_admin >> temp_name >> temp_Fname >> temp_Mname >>
          temp_address;

      while (!read.eof()) {
        if (newuser->get_id() == temp_id) {
          int choice = 0;
          while (choice != 8) {
            cout << "Press 1 to Update Your Name" << endl;
            cout << "Press 2 to Update Father Name" << endl;
            cout << "Press 3 to Update Mother Name" << endl;
            cout << "Press 4 to Update Password" << endl;
            cout << "Press 5 to Update Identity Number" << endl;
            cout << "Press 6 to Update Phone Number" << endl;
            cout << "Press 7 to update Address" << endl;
            cout << "Press 8 to Go Back" << endl;
            cout << "Choice: ";
            cin >> choice;
            int size = 0;
            cin.clear();
            fflush(stdin);
            switch (choice) {
              case (1):
                cout << "Enter Name: ";
                getline(cin, temp_name);
                newuser->set_name(temp_name);
                cout << "Name Updated Successfully!" << endl;
                break;
              case (2):
                cout << "Enter Father Name: " << endl;
                getline(cin, temp_Fname);
                newuser->set_Fname(temp_Fname);
                cout << "Father Name Updated Successfully!" << endl;
                break;
              case (3):
                cout << "\nEnter Mother Name: ";
                getline(cin, temp_Mname);
                newuser->set_Mname(temp_Mname);
                cout << "Mother Name Updated Successfully!" << endl;
                break;
              case (4):
                cout << "Enter Your Password: ";
                cin >> temp_password;
                newuser->setpassword(temp_password);
                cout << "Password Updated Successfully!" << endl;
                break;
              case (5):
                while (size != 13) {
                  cout << "Enter Identity Number: ";
                  cin >> temp_id_card;
                  size = get_length(temp_id_card);
                  if (size != 13) {
                    cout << "Please Enter 13 Digit CNIC Number!" << endl;
                  }
                }
                newuser->set_id_card(temp_id_card);
                cout << "CNIC Number Updated Successfully" << endl;
                break;
              case (6):
                while (size != 10) {
                  cout << "Enter Phone Number: +92 ";
                  cin >> temp_phone_no;
                  size = get_length(temp_phone_no);
                  if (size != 10) {
                    cout << "Please Enter 10 Digits of Phone Number!" << endl;
                    cout << "Do not include the 0 at the start" << endl;
                  }
                }
                newuser->set_phone_no(temp_phone_no);
                cout << "Phone Number Updated Successfully!" << endl;
                break;
              case (7):
                cout << "\nEnter Address: ";
                getline(cin, temp_address);
                newuser->set_address(temp_address);
                cout << "Address Updated Successfully" << endl;
                break;
              case (8):
                break;
              default:
                cout << "Please Enter Correct Choice" << endl;
                break;
            }
          }
          replace(temp_name.begin(), temp_name.end(), ' ', '_');
          replace(temp_Fname.begin(), temp_Fname.end(), ' ', '_');
          replace(temp_Mname.begin(), temp_Mname.end(), ' ', '_');
          replace(temp_address.begin(), temp_address.end(), ' ', '_');
          int temp_encr_pass = newuser->get_password();
          temp << temp_encr_pass << "\n"
               << temp_id << "\n"
               << temp_id_card << "\n"
               << temp_phone_no << "\n"
               << temp_amount << "\n"
               << temp_admin << "\n"
               << temp_name << "\n"
               << temp_Fname << "\n"
               << temp_Mname << "\n"
               << temp_address << "\n";
        }

        else {
          // int temp_encr_pass=newuser->get_password();
          temp << temp_password << "\n"
               << temp_id << "\n"
               << temp_id_card << "\n"
               << temp_phone_no << "\n"
               << temp_amount << "\n"
               << temp_admin << "\n"
               << temp_name << "\n"
               << temp_Fname << "\n"
               << temp_Mname << "\n"
               << temp_address << "\n";
        }
        read >> temp_password >> temp_id >> temp_id_card >> temp_phone_no >>
            temp_amount >> temp_admin >> temp_name >> temp_Fname >>
            temp_Mname >> temp_address;
      }
      read.close();
      temp.close();
      remove("sample.txt");
      rename("temp.txt", "sample.txt");
    }
  }
  int get_length(long long a) 
  {
    int size = trunc(log10(a)) + 1;
    return size;
  }
  void display(user* temp) {
    if (temp == NULL) {
      cout << "User Does Not Exist" << endl;
    } else {
      cout << "|Account Number: " << setw(14) << temp->get_id() << "|" << endl;
      cout << "|CNIC Number:    " << setw(14) << temp->get_id_card() << "|"
           << endl;
      cout << "|Phone Number:   "
           << "+92 " << setw(10) << temp->get_phone_no() << "|" << endl;
      cout << "|Name:           " << setw(14) << temp->get_name() << "|"
           << endl;
      cout << "|Father Name:    " << setw(14) << temp->get_Fname() << "|"
           << endl;
      cout << "|Mother Name:    " << setw(14) << temp->get_Mname() << "|"
           << endl;
      cout << "|Address:        " << setw(14) << temp->get_address() << "|"
           << endl;
      cout << "|______________________________|\n";
    }
  }
  bool login(user* temp_user) {
    string temp_pass;
    bool corrpass = 0;
    int counter = 3;
    while (counter != 0 && corrpass != 1) {
      cout << "Please Enter your Password: ";
      cin >> temp_pass;
      if (temp_user->checkpassword(temp_pass) == 0) {
        counter--;
        cout << "Password Incorrect. Please Enter your Password again!" << endl;
        cout << "You have " << counter << " more tries!" << endl;
      } else if (temp_user->checkpassword(temp_pass) == 1) {
        corrpass = 1;
        cout << "Login Successful" << endl;
      }
    }
    return corrpass;
  }

  void deleteNode_specific(int position) {
    // If linked list is empty
    if (head == NULL)
      return;

    // Store head node
    temp = head;

    // If head needs to be removed
    if (position == 0) {
      // Change head
      head = temp->get_nextUser();
      //free old head
      free(temp);
      return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 2; i++)
      temp = temp->get_nextUser();

    // If position is more than number of nodes
    if (temp == NULL || temp->get_nextUser() == NULL)
      return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    user* next = temp->get_nextUser()->get_nextUser();

    // Unlink the node from linked list
    free(temp->get_nextUser());  // Free memory
    // link the node with next pointer to make link between two nodes temp and
    // temp+2 node
    temp->set_nextUser(next);
    noA--;
  }
  user* search(int val) {  // to search by ID and return node(user) address of
                           // that user in LL
    temp = head;
    bool check = 0;
    while (temp != NULL && check == 0) {
      if (temp->get_id() == val) {
        check = 1;
        break;
      }
      temp = temp->get_nextUser();
    }
    if (check == 0) {
      return NULL;
    } else {
      return temp;
    }
  }
  int Search(
      int val) {  // to search by ID and return position of that user in LL
    int count = 1;
    temp = head;
    bool check = 0;
    while (temp != NULL && check == 0) 
    {
      if (temp->get_id() == val) {
        check = 1;
        break;
      }
      temp = temp->get_nextUser();
      count++;
    }
    if (check == 0) {
      return 0;
    } else {
      return count;
    }
  }
  void transfer_amount(
      user* temp_user,
      int temp_id) {  // to transfer amount to another account id
    user* temp_user2;
    int deposit_amount;
    int temp_id2;
    cout << "Enter amount to transfer: ";
    cin >> deposit_amount;
    if (deposit_amount > 0) {
      cout << "Enter account number to transfer money to: ";
      cin >> temp_id2;
      if (temp_id2 == temp_id) {
        cout << "You can not transfer the money to yourself!" << endl;
      } else {
        temp_user2 = search(temp_id2);
        if (temp_user2 != NULL) {
          int temp_with = temp_user->withdraw(deposit_amount);
          if (temp_with != 0) {
            temp_user2->deposit(deposit_amount);
            transaction_history("DEPOSIT", deposit_amount, NULL, temp_user2);
            cout << "Amount Transferred Successfully!!" << endl;
            cout << "Your Remaining Balance is: " << temp_user->get_amount()
                 << endl;
            transaction_history("TRANSFER", deposit_amount, temp_user2,
                                temp_user);
          }
        } else {
          cout << "User not found in the database!" << endl;
        }
      }
    } else {
      cout << "Transfer amount needs to be greater than 0" << endl;
    }
  }
  void update_data() {  // function to update data in files according to the
                        // current LL.
    temp = head;
    ofstream out("temp2.txt", ios::out | ios::app);
    string temp_name, temp_Fname, temp_Mname, temp_address;
    while (temp != NULL) {
      temp_name = temp->get_name();
      temp_Fname = temp->get_Fname();
      temp_Mname = temp->get_Mname();
      temp_address = temp->get_address();
      replace(temp_name.begin(), temp_name.end(), ' ', '_');
      replace(temp_Fname.begin(), temp_Fname.end(), ' ', '_');
      replace(temp_Mname.begin(), temp_Mname.end(), ' ', '_');
      replace(temp_address.begin(), temp_address.end(), ' ', '_');
      out << temp->get_password() << "\n";
      out << temp->get_id() << "\n";
      out << temp->get_id_card() << "\n";
      out << temp->get_phone_no() << "\n";
      out << temp->get_amount() << "\n";
      out << temp->get_admin() << "\n";
      out << temp_name << "\n";
      out << temp_Fname << "\n";
      out << temp_Mname << "\n";
      out << temp_address << "\n";
      temp = temp->get_nextUser();
    }
    out.close();
    remove("sample.txt");
    rename("temp2.txt", "sample.txt");

    ofstream out2("temp3.txt", ios::out | ios::app);
    out2 << noA;
    out2.close();
    remove("noA.txt");
    rename("temp3.txt", "noA.txt");
  }
  void Display() {
    user* temp = head;
    while (temp != NULL) {
      cout << "|Account Number: " << setw(14) << temp->get_id() << "|" << endl;
      cout << "|CNIC Number:    " << setw(14) << temp->get_id_card() << "|"
           << endl;
      cout << "|Phone Number:   "
           << "+92 " << setw(10) << temp->get_phone_no() << "|" << endl;
      cout << "|Name:           " << setw(14) << temp->get_name() << "|"
           << endl;
      cout << "|Father Name:    " << setw(14) << temp->get_Fname() << "|"
           << endl;
      cout << "|Mother Name:    " << setw(14) << temp->get_Mname() << "|"
           << endl;
      cout << "|Address:        " << setw(14) << temp->get_address() << "|"
           << endl;
      cout << "|______________________________|\n";
      temp = temp->get_nextUser();
    }
  }
  void transaction_history(string type,
                           float amount,
                           user* recipient,
                           user* current) {
    int i = current->get_id();
    string text = "transaction_history_";
    text += to_string(i);
    // cout<<text;
    ofstream history_file;
    history_file.open(text, ios_base::app);
    history_file << type << " " << amount;
    if (recipient != NULL) {
      history_file << " " << recipient->get_name();
    }
    history_file << endl;
    history_file.close();
  }
  void display_transaction_history(user* current) 
  {
    int i = current->get_id();
    string text = "transaction_history_";
    text += to_string(i);
    ifstream history_file;
    history_file.open(text);
    string line;
    while (getline(history_file, line)) 
    {
      cout << line << endl;
    }
    history_file.close();
  }
};

class queueee
{
    int queuee[60];
    int part1_start = 0;
    int part2_start = part1_start + 60 / 3;
    int part3_start = part2_start + 60 / 3;
    int part1_end = part2_start - 1;
    int part2_end = part3_start - 1;
    int part3_end = 60 - 1;
    public:
    bool isEmpty1()
{
    return part1_start > part1_end;
}
bool isFull1()
{
    return part1_end == part2_start - 1;
}
bool isEmpty2()
{
    return part2_start > part2_end;
}
bool isFull2()
{
    return part2_end == part3_start - 1;
}
bool isEmpty3()
{
    return part3_start > part3_end;
}
bool isFull3()
{
    return part3_end == 60 - 1;
}

void fill()
    {
    for (int i = part1_start; i <= part1_end; i++)
    {
        queuee[i] = i+1;
    }
    for (int i = part2_start; i <= part2_end; i++)
    {
        queuee[i] = i+1;
    }
    for (int i = part3_start; i <= part3_end; i++)
    {
        queuee[i] = i+1;
    }
    }
int dequeue(int priority)
    {
        if(part1_start==part1_end)
        {
            part1_start=0;
        }
        if(part2_start==part2_end)
        {
            part2_start=20;
        }
        if(part3_start==part3_end)
        {
            part3_start=40;
        }
        if(isEmpty1()==0 && priority==1)
        {
            int i=queuee[part1_start];
            part1_start++;
            return i;
        }
        if(isEmpty2()==0 && priority==2)
        {
            int i=queuee[part2_start];
            part2_start++;
            return i;
        }
        if(isEmpty3()==0 && priority==3)
        {
            int i=queuee[part3_start];
            part3_start++;
            return i;
        }
    }
};

class time_table
{
    struct Employee{
    string name;
    int shiftsWorked;
    };
    public:
    void generateTimetable(Employee* employees, int numEmployees, int shifts, int days, string timetable[][7]) 
{
    // Assign the employees to shifts in the timetable
    int employeeIndex = 0;
    for (int i = 0; i < shifts; i++) {
        for (int j = 0; j < days; j++) {
            // Check if we have run out of employees
            if (employeeIndex >= numEmployees) 
            {
                // Start over from the beginning of the list of employees
                employeeIndex = 0;
            }
            // Assign the next employee to the current shift
            timetable[i][j] = employees[employeeIndex].name;
            employees[employeeIndex].shiftsWorked++;
            // Move to the next employee
            employeeIndex++;
        }
    }
}
void get_table()
              {
                int no_employees;
                int shifts;
                int days;
                cout<<"Enter Number of Employees: ";
                cin>>no_employees;
                cout<<"Enter Number of Shifts Per Day: ";
                cin>>shifts;
                if(no_employees<=shifts)
                {
                  cout<<"Number of employees should be greater than number of shifts"<<endl;
                }
                else
                {
                Employee employees[no_employees];
                for(int i=1;i<=no_employees;i++)
                {
                string text = "Employee ";
                text += to_string(i);
                //cout<<text;
                employees[i-1].name=text;
                }
                string timetable[shifts][7];
                generateTimetable(employees, no_employees, shifts, 7, timetable);
                for (int i = 0; i < 7; i++) 
                {
                cout<<"Day "<<i+1<<": ";
                for (int j = 0; j < shifts; j++) {
                cout << timetable[j][i] << " ";
                }
                cout << endl;
                }
                }
              }
};
int main() {
  intro();
  int choice = 0;
  int choice2 = 0;
  int choice3 = 0;
  bool log_admin = 0;
  time_table tt;
  bool log = 0;
  user* temp_user;
  queueee q;
  q.fill();
  User u;
  u.set_noA();
  system("pause");
  system("cls");
  cout << "\nLoading Data..." << endl;
  u.load_data();
  //u.Display();
  // u.insert_User();

  while (choice != 4) {
    system("pause");
    system("cls");
    cout << "Press 1 for Admin Panel" << endl;
    cout << "Press 2 for User Panel" << endl;
    cout << "Press 3 for Token System" << endl;
    cout << "Press 4 to Exit" << endl;
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
      case (1):
        choice2 = 0;
        while (choice2 != 3) {
          system("pause");
          system("cls");
          cout << "Press 1 to Login into Admin Panel" << endl;
          cout << "Press 2 to View Schedule" << endl;
          cout << "Press 3 to Go Back" << endl;
          cout << "Choice: ";
          cin >> choice2;
          switch (choice2) {
            case (1):
              int temp_admin_id;
              user* temp_user_admin;
              cout << "Enter Your Login Details" << endl;
              cout << "Please Enter your Account Number: ";
            label2:
              cin >> temp_admin_id;
              temp_user_admin = u.search(temp_admin_id);
              if (temp_user_admin == NULL) {
                cout << "Account not found in the Database!!" << endl;
                cout << "Enter Account Number Again: ";
                goto label2;
              } else {
                if (temp_user_admin->get_admin() == 0) {
                  cout << "The User you entered does not have Administrator "
                  "Privileges"
                       << endl;
                } else {
                  log_admin = u.login(temp_user_admin);
                }
              }
              if (log_admin == 1) {
                choice3 = 0;
                while (choice3 != 6) {
                  system("pause");
                  system("cls");
                  cout << "Press 1 to Add New User" << endl;
                  cout << "Press 2 to Delete User" << endl;
                  cout << "Press 3 to Update Your Account Details" << endl;
                  cout << "Press 4 to View Your Account Details" << endl;
                  cout << "Press 5 to Display All Users" << endl;
                  cout << "Press 6 to go back" << endl;
                  cout << "Choice: ";
                  cin >> choice3;
                  switch (choice3) {
                    case (1):
                      u.insert_User();
                      break;
                    case (2): {
                      int accNo;
                      cout << "\nEnter the account number you want to delete: ";
                      cin >> accNo;
                      user* temp_user;
                      temp_user = u.search(accNo);
                      if (temp_user == NULL) {
                        cout << "\nAccount not present!";
                      } else {
                        int pos;
                        pos = u.Search(accNo);
                        cout << endl << pos;
                        u.deleteNode_specific(pos);
                        u.update_data();
                        u.set_noA();
                      }
                      break;
                    }
                    case (3):
                      u.updateacc(temp_user_admin);
                      break;
                    case (4):
                      cout << "\n================================\n";
                      u.display(temp_user_admin);
                      break;
                    case (5):
                      cout << "\n================================\n";
                      u.Display();
                      break;
                    case (6):
                      break;
                    default:
                      cout << "Please Enter Correct Choice!" << endl;
                      break;
                  }
                }
              }
              break;
            case (2):
              tt.get_table();
              break;
          }
        }
        break;
      case (2):
        log = 0;
        int temp_id;
        cout << "Enter Your Login Details" << endl;
        cout << "Please Enter your Account Number: ";
      label:
        cin >> temp_id;
        temp_user = u.search(temp_id);
        if (temp_user == NULL) {
          cout << "Account not found in the Database!!" << endl;
          cout << "Enter Account Number Again: ";
          goto label;
        } else {
          log = u.login(temp_user);
        }
        if (log == 1) {
          choice2 = 0;
          while (choice2 != 8) {
            system("pause");
            system("cls");
            cout << "Press 1 to View Balance" << endl;
            cout << "Press 2 to Deposit Money" << endl;
            cout << "Press 3 to Withdraw Money" << endl;
            cout << "Press 4 to Transfer Money" << endl;
            cout << "Press 5 to Display Transaction History" << endl;
            cout << "Press 6 to Update your Account Information" << endl;
            cout << "Press 7 to View Account Details" << endl;
            cout << "Press 8 to go back" << endl;
            cout << "Choice: ";
            cin >> choice2;
            switch (choice2) {
              case (1):
                cout << "Your Balance is: " << temp_user->get_amount() << endl;
                break;
              case (2):
                int deposit_amount;
                cout << "Enter amount to deposit: ";
                cin >> deposit_amount;
                if (deposit_amount > 0) {
                  temp_user->deposit(deposit_amount);
                  cout << "Your Balance is: " << temp_user->get_amount()
                       << endl;
                  u.update_data();
                  u.transaction_history("DEPOSIT", deposit_amount, NULL,
                                        temp_user);
                } else {
                  cout << "Deposit amount needs to be greater than 0" << endl;
                }
                break;
              case (3):
                int withdraw_amount;
                cout << "Enter amount to withdraw: ";
                cin >> withdraw_amount;
                if (withdraw_amount > 0) {
                  temp_user->withdraw(withdraw_amount);
                  cout << "Your Remaining Balance is: "
                       << temp_user->get_amount() << endl;
                  u.update_data();
                  u.transaction_history("WITHDRAW", withdraw_amount, NULL,
                                        temp_user);
                } else {
                  cout << "Withdraw amount needs to be greater than 0" << endl;
                }
                break;
              case (4):
                u.transfer_amount(temp_user, temp_id);
                u.update_data();
                break;
              case (5):
                u.display_transaction_history(temp_user);
                cout << "Your Current Balance is: " << temp_user->get_amount()
                     << endl;
                break;
              case (6):
                u.updateacc(temp_user);
                break;
              case (7):
                u.display(temp_user);
                break;
              case (8):
                break;
              default:
                cout << "Please Enter Correct Choice" << endl;
                break;
            }
          }
        }
        break;
      case (3):
        cout << "Welcome To Token System" << endl;
        choice2 = 0;
        while (choice2 != 4) {
          system("pause");
          system("cls");
          cout << "Enter 1 to get Token for Depositing Cheque" << endl;
          cout << "Enter 2 to get Token for Customer Support" << endl;
          cout << "Enter 3 to get Token for Customer Service" << endl;
          cout << "Enter 4 to go back to Main Menu" << endl;
          cout << "Choice: ";
          cin >> choice2;
          switch (choice2) {
            case (1):
              cout << "Your Token Number is: " << q.dequeue(1) << endl;
              break;
            case (2):
              cout << "Your Token Number is: " << q.dequeue(2) << endl;
              break;
            case (3):
              cout << "Your Token Number is: " << q.dequeue(3) << endl;
              break;
            case (4):
              break;
            default:
              cout << "Please Enter Correct Choice!" << endl;
              break;
          }
        }
        break;
      case (4):
        break;
      default:
        cout << "Please Enter Correct Choice!" << endl;
        break;
    }
  }
  return 0;
}