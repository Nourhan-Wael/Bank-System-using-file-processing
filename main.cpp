#include<bits/stdc++.h>
#include<fstream>
using namespace std;
  
void yasmeen_fakhri(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  #ifndef ONLINE_JUDGE   
    //freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}
 class account
{
public:
    char name[20]{};
    int balance, id;
    int age;
    
 
public:
    account()
    {
        balance = 0;
        id = 0;
        age = 0;
    }
public:    
    void create_account();
    void display_accounts();
    void search(int);
    void delete_account(int);
    void add_to_file(account);
    void deposit(int);
    void dep(int, account*) ;
    void modify(account *, int);
    void modify_account(int);
};
 
void account::create_account()
{
    account a;
    cout << "Enter name: ";
    cin >> a.name;
    cout << "Enter id: ";
    cin >> a.id;
    cout << "Enter age: ";
    cin >> a.age;
    cout << "Enter balance: ";
    cin >> a.balance;
    fstream file;
    file.open("project.txt", ios::out | ios::app);
    // add this abject to the file
    file.write((char *)&a, sizeof(a));
    file.close();
}
 
// modify ACOUNT 
//edit records by id
void account::modify_account(int _id)
{
    fstream file;
    file.open("project.txt", ios::in | ios::out);
    file.seekg(0, ios::beg);
 
    account x, a;
    while (file.read((char *)&x, sizeof(x)))
    {
        if (x.id == _id)
        {
            cout << "Enter name to modify: ";
            cin >> a.name;
            cout << "Enter id to modify: ";
            cin >> a.id;
            cout << "Enter age to modify: ";
            cin >> a.age;
            cout << "Enter balance to modify: ";
            cin >> a.balance;
            file.seekp(file.tellg() - sizeof(x));
            file.write((char *)&a, sizeof(a));
            break;
        }
    }
    file.close();
}
 
// // display all records
void account :: display_accounts()
{
    account a;
    fstream file;
    file.open("project.txt", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char *)&a, sizeof(a)))
    {
        if(a.id == -1)
          continue;
        cout << "Name: " << a.name << endl;
        cout << "Id: " << a.id << endl;
        cout << "Age: " << a.age << endl;
        cout << "Balance: " << a.balance << endl;
    }
    file.close();
}
 
// // search ACOUNT 
void account :: search(int id){
    fstream f;
    account c;
    bool flag = 0;
    f.open("project.txt",ios::in);
    while(!f.eof()){
        f.read((char *)&c,sizeof(c));
        if(c.id==id){
            flag = 1;
            cout<<c.id<<" "<<c.name<<" "<<c.balance<<" "<<c.age<<"\n";
            break;
        }
    }
    if(!flag)
      cout << "account not found\n";
 
    f.close();
}
 
// delete ACOUNT 
void account :: delete_account(int id){
    fstream f;
    account d;
    f.open("project.txt",ios::in|ios::out);
    while(!f.eof()){
        f.read((char*)&d,sizeof(d));
        if(d.id == id)
        {
            d.id = -1;
            int end = f.tellg();
            int size = sizeof(d);
            f.seekp(end-size, ios::beg);
            f.write((char*)&d,size);
            break;
        }
    }
    
    if(d.id == 0)
    {
        cout << "This name is not found in the file\n";
    }
    f.close();
}
void account :: modify(account *acc, int id)
{
    fstream file;
    file.open("project.txt", ios::in | ios::out);
    file.seekg(0, ios::beg);
 
    account x;
    while (file.read((char *)&x, sizeof(x)))
    {
        if (x.id == id)
        {
            file.seekp(file.tellg() - sizeof(x));
            file.write((char *)acc, sizeof(*acc));
            break;
        }
    }
    file.close();
}
//DEPOSITE 
void account::dep(int x, account *acc)
{
    acc -> balance+=x;
}
void account::deposit(int id){
  int amount ;
  fstream file ;
  bool found = false ;
  account acc ;
 
  file.open("project.txt" , ios::in | ios::out);
  if (!file.is_open()){
    cout<<"File couldn't be open ...  press any kay to exit ...";
    return ;
  }
  while(!file.eof()){
    file.read((char *)&acc , sizeof(acc));
    if (acc.id == id){
      cout<<"Enter The Amount You Want To Deposit : ";
      cin>>amount ;
      acc.dep(amount, &acc);
    }
    // modify function 
    modify(&acc, acc.id);
    found = true ;
  }
  file.close();
  if (found == false ) cout<<"Customer Not Found ";
}
int main(){
  account a;
  char ch;
  do{  
cout<<"*****************************Bank Management System*****************************";
cout<<"MAIN MENU"<<"\n";
cout<<"1)  NEW ACCOUNT "<<"\n";
//cout<<"2)  DEPOSIT AMOUNT"<<"\n";
//cout<<"3)  WITHDRAW AMOUNT"<<"\n";
cout<<"4)  MODIFY ACCOUNT "<<"\n";
cout<<"5)  DELETE ACCOUNT "<<"\n";
cout<<"6)  Search for an acount "<<"\n";
cout<<"7)  SHOW ALL ACCOUNTS  "<<"\n";
cout<<"8)  EXIT "<<"\n";
cout<<"*********************************************************************************\n";
cout<<"Enter the number of transaction you want  : "<<endl;
cin>>ch ;
switch (ch)
{
    case '1':
    a.create_account();
      break;
 
    case '2':
    //cout<<"Enter Your id you want to deposite\n";
    a.deposit(1);
    break;
 
    case '3':
    // write function
    cout<<"Enter amount you want to withdraw : ";
      break;
 
    case '4':
    // write function
    a.modify_account(1);
      break;  
 
    case '5':
    // write function
    a.delete_account(5);
      break;
 
    case '6':
    // write function
    a.search(7);
      break;
 
    case '7':
    // write function
    a.display_accounts();
      break;  
 
    case '8':
        cout<<"Thanks for using Our Bank Management System";
      break;  
 
    default:
    break;
     
}
}while(ch !=  '8');
  return 0;
}

