#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<windows.h>
int z=0;
int main();
using namespace std;
class account
{
	int acno;
	char name[100];
	long long int deposit;
    char type[50];
	long long int phoneno;
	int age;
	char address[200];
	int pin;

public:

	void create_account(int acno, int);
	void show_account() const;
	void modify_admin();
	void modify_user();
	void dep(int);
	void draw(int);
	void report(int) const;
	int retacno() const;
	int retdeposit() const;
	void printtype() const;
	int retpin() const;
	void show_transfer() const;



};

void account::create_account(int acno, int option)
{
	this->acno=acno+1;
	deposit =0;

	cout<<"\n\n\t\t\tEnter the Name of the Account holder                : ";
	cin.ignore();
    cin.getline(name,100);
    while(!strcmp(name,""))
   {cout<<"\n\n\t\t\tEnter the Name of the Account holder              : ";
    cin.getline(name,100);
	}
	label1:
	cout<<"\n\t\t\tEnter the age                                       : ";
	cin>>age;
	if(age==0)
    {
       system("CLS");
       main();
    }
	if(age<18)
       {
         cout<<"\n\n\t\t\tYou Should be at least 18 years old to open bank account!!!!\n\n\t\t\tif you want to return to main menu press0!!!";
         goto label1;
       }
    if(age>150)
       { cout<<"\n\n\t\t\t\tInvalid Age!!!";
        goto label1;
       }
    label2:
	cout<<"\n\t\t\tEnter the phone no                                  :+91  ";
	cin>>phoneno;
	if(phoneno<1000000000||phoneno>9999999999)
    {
        cout<<"\n\n\t\t\t\tInvalid mobile no.!!!";
         cout<<"\n\t\t\t\tPlease Enter 10 digit mobile no!!!";
        goto label2;
    }
	cout<<"\n\t\t\tEnter the address                                   : ";
	cin.ignore();
	cin.getline(address,200);
	 while(!strcmp(address,""))
   {cout<<"\n\t\t\tEnter the address                                   : ";
	 cin.getline(address,200);
	 }
	cout<<"\n\t\t\tEnter Type of the Account (Current(c/C)/Saving(s/S)) : ";
	string c;
	cin>>c;
	while(!(c=="c"||c=="s"||c=="C"||c=="S"))
	{cout<<"\n\n\tInvalid  Account type!!!!!! ";
	cout<<"\n\t\t\tEnter Type of the Account (Current(c)/Saving(s))     : ";
	cin>>c;
	}
	if(c=="c"||c=="C")
	{strcpy(type,"Credit");
	}
	else{strcpy(type,"Saving");
	}
	if(option==1)
    {
	 cout<<"\n\t\t\tEnter initial amount to be deposit                  : ";
	 cin>>deposit;
	 cout<<" Rs.";
    }
      label3:
     cout<<"\n\t\t\tSet your Bank Account Pin                           : ";
	 cin>>pin;
	 if(pin<1000||pin>9999)
     {
         cout<<"\n\n\t\t\t\tInvalid pin!!!";
         cout<<"\n\t\t\t\tPlease Enter 4 digit pin!!!";
        goto label3;
     }
	 system("CLS");
	 cout<<"\n\n\t\t\tYour Account No is:  "<<this->acno<<endl;


}

void account::show_account() const
{
	cout<<"\n\t\t\tAccount No.         : "<<acno;
	cout<<"\n\t\t\tType of Account     : ";
	printtype();
	cout<<"\n\t\t\tBalance amount      : "<<deposit<<" Rs.";

}

 void account::show_transfer() const
 {
     cout<<"\n\tAccount No.        : "<<acno;
     cout<<"\n\tAccount Holder Name: "<<name<<endl;
 }


void account::modify_admin()
{
	cout<<"\n\t\t\tEnter the choice to update the details:\n";
	cout<<"\n\t\t\t1.Name ";
	cout<<"\n\t\t\t2.account Type(c/s) ";
	cout<<"\n\t\t\t3.Mobile no. ";
	cout<<"\n\t\t\t4.Age ";
	cout<<"\n\t\t\t5.Address ";
	cout<<"\n\t\t\t6.Pin ";
	cout<<"\n\t\t\t7.Return to main menu ";
	cout<<"\n\n\t\t\tSelect Your Option (1-7): ";

	int n;
	cin>>n;
	switch (n)
	{case 1:cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,100);
	 cout<<"\n\n\t\t\tRecord Updated";
	break;
	case 2:cout<<"\n\t\t\tEnter Type of the Account (Credit(C/c)/Saving(S/s)) : ";
	char c;
	cin>>c;
	while(!(c=='c'||c=='s'))
	{cout<<"\n\t\t\tEnter Type of the Account (Credit(C/c)/Saving(S/s)) :";
	cin>>c;
	}
	if(c=='c')
	{strcpy(type,"Credit");
	}
	else{strcpy(type,"Saving");
	}
	 cout<<"\n\n\t\t\tRecord Updated";
	break;
	case 3:
	    label2:
	cout<<"\n\t\t\tEnter the phone no                                  :+91  ";
	cin>>phoneno;
	if(phoneno<1000000000||phoneno>9999999999)
    {
        cout<<"\n\n\t\t\t\tInvalid mobile no.!!!";
         cout<<"\n\t\t\t\tPlease Enter 10 digit mobile no!!!";
        goto label2;
    }
	 cout<<"\n\n\t\t\tRecord Updated";
	break;
	case 4:label1:
	cout<<"\n\t\t\tEnter the age                                       : ";
	cin>>age;
	if(age<18)
       { cout<<"\n\n\t\t\t\tYou Should be at least 18 years old to open bank account!!!";
        goto label1;
       }
    if(age>150)
       { cout<<"\n\n\t\t\t\tInvalid Age!!!";
        goto label1;
       }
     cout<<"\n\n\t\t\tRecord Updated";
    break;
    case 5:cout<<"\n\t\t\tModify Address : ";
    cin.ignore();
	cin.getline(address,200);
     cout<<"\n\n\t\t\tRecord Updated";
	break;
	case 6:
	    label3:
     cout<<"\n\t\t\tSet your Bank Account Pin                           : ";
	 cin>>pin;
	 if(pin<1000||pin>9999)
     {
         cout<<"\n\n\t\t\t\tInvalid pin!!!";
         cout<<"\n\t\t\t\tPlease Enter 4 digit pin!!!";
        goto label3;
     }
	 cout<<"\n\n\t\t\tRecord Updated";
	 break;
	case 7: break;
	default:cout<<"Wrong choice"<<endl;
	}
}
void account::modify_user()
{    cout<<"\n\t\t\tSelect the choice to update the details:\n";
	cout<<"\n\t\t\t1.Mobile no. ";
	cout<<"\n\t\t\t2.Address. ";
	cout<<"\n\t\t\t3.Pin ";
	cout<<"\n\t\t\t4.Return to main menu ";
	cout<<"\n\n\t\t\tSelect Your Option (1-4): ";
	int n;
	cin>>n;
	switch (n)
{   case 1:
    label2:
	cout<<"\n\t\t\tEnter the phone no                                  :+91  ";
	cin>>phoneno;
	if(phoneno<1000000000||phoneno>9999999999)
    {
        cout<<"\n\n\t\t\t\tInvalid mobile no.!!!";
         cout<<"\n\t\t\t\tPlease Enter 10 digit mobile no!!!";
        goto label2;
    }
	 cout<<"\n\n\t\t\tRecord Updated";
	break;
    case 2:cout<<"\n\t\t\tModify Address : ";
    cin.ignore();
	cin.getline(address,200);
     cout<<"\n\n\t\t\tRecord Updated";
	break;
	case 3: label3:
     cout<<"\n\t\t\tSet your Bank Account Pin                           : ";
	 cin>>pin;
	 if(pin<1000||pin>9999)
     {
         cout<<"\n\n\t\t\t\tInvalid pin!!!";
         cout<<"\n\t\t\t\tPlease Enter 4 digit pin!!!";
        goto label3;
     }
	 cout<<"\n\n\t\t\tRecord Updated";
    case 4: break;
	default:cout<<"Wrong choice"<<endl;
}

}


void account::dep(int x)
{
	deposit+=x;

}

void account::draw(int x)
{
	deposit-=x;
	cout<<"\n\t\t\tBalance Amount: "<<deposit<<" Rs.\n\n";
}

void account::report (int option) const
{   cout<<"\n\t\tAccount No.         : "<<acno;
	cout<<"\n\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\tPhone no            : +91 "<<phoneno;
    cout<<"\n\t\tAge                 : "<<age;
	cout<<"\n\t\tAddress             : "<<address;
	cout<<"\n\t\tType of Account     : ";
	cout<<type;
	if(option==1)
	cout<<"\n\t\tBalance amount      : "<<deposit<<" Rs.";
}

int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}
int account::retpin() const
{
    return pin;
}

void account::printtype() const
{
	cout<<type;
}

void write_account(int);
void display_sp(int, int);
void modify_account(int, int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void transfer1(int);
int transfer2(int, int);


int user_login()
{    system("CLS");
    int acc1;
    int pin;
    account ac;

	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
        main();
	}
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\t\tUSER LOGIN";
	cout<<"\n\t\t\t\t======================\n";
    cout<<"\n\n\n\n\t\t\tEnter your bank account no: ";
    cin>>acc1;
    while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()==acc1)
		{   cout<<"\n\n\t\t\tEnter Your Pin.: ";
		    cin>>pin;
			if(ac.retpin()==pin)
            {
            inFile.close();
            return acc1;
            }
		}
	}
    inFile.close();
      system("CLS");
		cout<<"\n\n\tAccount number or Pin does not exist Please Enter Valid Account no. or Password";

	main();



}


int admin_login()
{
    string id;
    int pass;

	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\t\tADMIN LOGIN";
	cout<<"\n\t\t\t\t======================\n";
    for(int i=0;i<3;i++)
    {
	cout<<"\t\t\tEnter ID of ADMIN\n\t\t\t";
	cin>>id;
	string  e="Bankmanager";
	if(id==e)
	{cout<<"\t\t\tEnter the password of ADMIN\n\t\t\t";
    cin>>pass;
	if(pass==1234)
	{return true;
	}
	}


    }


       return false;
}

int main()
{   if(z==0)
    {
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tBANK MANAGEMENT SYSTEM";

	cout<<"\n\t\t\t\t\tMade By:-\n\n\t\t\t\t\tNITESH KUMAR\n\t\t\t\t\tALOK KUMAR \n\t\t\t\t\tOM PRAKASH\n";
	Sleep(2000);
	system("CLS");
    z++;
    }

	int ch;
	int ch1;
	int num;
	int a;



    cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";
    cout<<"\n\n\t\t\t\t1. USER LOGIN\t";
    cout<<"\n\t\t\t\t2. ADMIN LOGIN\t";
    cout<<"\n\t\t\t\t3. CREATE NEW BANK ACCOUNT\t";
    cout<<"\n\t\t\t\t4. EXIT\t";
    cout<<"\n\n\t\t\tSelect Your Option (1-4): ";

    cin>>ch1;

    switch(ch1)
    {
case 1:

    a=user_login();

     label1:
    do
    {
	system("CLS");
	cout<<"\n\n\t\t\t\t=========================\n";
	cout<<"\t\t\t\t| BANK MANAGEMENT SYSTEM |" ;
	cout<<"\n\t\t\t\t=========================\n\n";
        display_sp(a,3);
		cout<<"\n\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. VIEW FULL ACCOUNT DETAILS";
		cout<<"\n\t\t\t\t2. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t3. TRANSFER MONEY TO ANOTHER ACCOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. CLOSE ACCOUNT";
		cout<<"\n\t\t\t\t6. MODIFY ACCOUNT DETAILS";
		cout<<"\n\t\t\t\t7. LOGOUT";
		cout<<"\n\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-7): ";
		cin>>ch;

		switch(ch)
		{
        case 1:
            system("CLS");
            cout<<"\n\n\n\n";
            display_sp(a,4);
               break;
		case 2:
			system("CLS");

			deposit_withdraw(a, 2);
			break;
        case 3:
              system("CLS");
              cout<<"\n\t\tIf you want to cancel transition or If you want to return to main menu press 0 ";
              transfer1(a);
			break;
		case 4:
			system("CLS");

			display_sp(a,1);
			break;

		case 5:
			system("CLS");
            display_sp(a,3);
            cout<<"\n\n";
			delete_account(a);
			break;
		 case 6:
		 	system("CLS");

			modify_account(a, 1);
			break;
		 case 7:
		     system("CLS");
		     z=1;
		 	main();
		 	break;
         case 8:
             system("CLS");
             cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTHANKS FOR USING OUR SERVICES\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            exit(0);

		 default :goto label1;
		}
		cin.ignore();
		cin.get();
        }while(ch!=9);

                    break;


case 2:system("CLS");
    if(admin_login()){
     label2:
     do
    {
	system("CLS");
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. CREATE NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. TRANSFER AMOUNT";
		cout<<"\n\t\t\t\t5. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t6. VIEW ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t7. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t8. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t9. LOGOUT";
		cout<<"\n\t\t\t\t10. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-10): ";
		cin>>ch;

		switch(ch)
		{
		case 1:
			write_account(1);
			break;
		case 2:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
        case 4:
            system("CLS");
            cout<<"\n\t\tIf you want to cancel transition or If you want to return to main menu press 0 ";
            cout<<"\n\n\tEnter the Account no. of Sender. : "; cin>>num;
            if(num==0)
                goto label2;
            display_sp(num, 2);
            cout<<endl;
            transfer1(num);
            break;
		case 5:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num,1);
			break;
		case 6:
			display_all();
			break;
		case 7:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num,3);
            cout<<"\n\n";
			delete_account(num);
			break;
		 case 8:
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num, 2);
			break;
		 case 9:
		     system("CLS");

		 	main();
         case 10:
             system("CLS");
             cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTHANKS FOR USING OUR SERVICES\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            exit(0);

			break;
		 default :goto label2;
		}
		cin.ignore();
		cin.get();
    }while(ch!=11);
    }
    else { system("CLS");
	 main();
    }
    break;
case 3: write_account(0);
        system("CLS");
        cout<<"\n\n\tPlease login to continue:";
        main();
			break;
case 4: system("CLS");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTHANKS FOR USING OUR SERVICES\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
       exit(0);
default:system("CLS");
        cout<<"\n\n\n\n\t\t\t\t\t\tPlease Enter correct option";
        z=1;
        main();
    }

	return 0;
}
int search(int acno)
{   account ac;

	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return false;
	}
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()==acno)
		{  inFile.close();
			return true;
		}
	}
    return false;
}

void write_account(int n)
{   system("CLS");
    int acc;
	account ac;
	ofstream outFile;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	outFile.open("account.dat",ios::binary|ios::app);
	int a=0;
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
	a=ac.retacno();
    }
 if(a!=0)
 {ac.create_account(a,n);}
else{
    ac.create_account(1000,n);
	}
     ac.report(0);
	label:
    cout<<" \n\n\n\t\t\tAre you sure that you want to create new New Account????"<<endl;
    cout<<"\n\n\n\t\t\t1.Yes\t\t\t\t0.No"<<endl;
    cin>>acc;
    if(acc==1)
	outFile.write((char *) (&ac), sizeof(account));
	else if(acc==0)
    {

    }
    else{ system(("CLS"));
        cout<<"Please enter valid input";
        goto label;
    }
	outFile.close();
}


void display_sp(int n, int option)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
		    if(option==1)
            {
               cout<<"\n\t\t\tBALANCE DETAILS\n";
			   ac.show_account();
            }
			else if(option==2)
            {
                cout<<"\n\t Account Details:- ";
                ac.show_transfer();
            }
            else if(option==3)
                ac.show_transfer();
			else if(option==4)
                ac.report(0);
			flag=true;

		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist!!!!";
}



void modify_account(int n, int option)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.report(0);
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			if(option==1)
                ac.modify_user();
            else if(option==2)
                ac.modify_admin();
			int pos=(-1)*(int)(sizeof(account));
			File.seekp(pos,ios::cur);
		    File.write((char *) (&ac), sizeof(account));

		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tAccount Not Found ";
}



void delete_account(int n)
{
	account ac;
	int acc;
	ifstream inFile;
	ofstream outFile;
	label7:


	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	bool a=search(n);
	if(a)
	{

    cout<<"\n\n\n\t\t\t\tAre You Sure that You Want To Delete This Account:";
	cout<<"\n\n\t\t\t\t\t1.Yes\t\t\t\t0.No"<<endl;
	cin>>acc;
	if(acc==1)
    {

	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nAccount Deleted ..";
	 }
    else if(acc==0)
    {
        inFile.close();
	outFile.close();

    }
    else{ system("CLS");
        cout <<"\n\n\n\t\t\tPlease Enter Valid input";
        goto label7;
    }
	}

	else {cout<<"\nAccount not found"<<endl;
	}


}


void display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST";
	while(inFile.read((char *) (&ac), sizeof(account)))
	{cout<<"\n\n";
		ac.report(1);
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	bool flag=false;
	account ac;
	int l=search(n);
	if(!l)
	{
	    cout<<"\n\n\n\n\t\t\t\t\tInvalid Account No.!!!!";
	    return;
	}

	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
				flag=true;
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficient balance";
				else{
					ac.draw(amt);
                    flag=true;
				}
		      }
			int pos=(-1)*(int)(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write((char *) (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
         if(flag==true)
         {

                    system("CLS");
                    cout<<"\n\n\n\n\n\n\t\t\t\t\tTransaction Processing....";
                    cout<<"\n\t\t\t\t\t  Please Wait....";
                    Sleep(2000);
                    system("CLS");
                    cout<<"\n\n\t\t\t\tTransition Successful";
					cout<<"\n\n\n\n\t\t\t\tRecord Updated!!";
         }
         else
         {

                    system("CLS");
                    cout<<"\n\n\n\n\n\n\t\t\t\t\tTransaction Processing....";
                    cout<<"\n\t\t\t\t\t  Please Wait....";
                    Sleep(2000);
                    system("CLS");
                    cout<<"\n\n\t\t\t\tTransition Failed XXXXX|";
					cout<<"\n\n\n\n\t\t\t\tInsufficient balance!!!";
         }
    File.close();
	if(found==false)
    		cout<<"\n\n\t\t\tAccount Not Found ";
}
void transfer1(int n)
{
    int amt,k;
	bool found=false;
	bool flag=false;
	account ac;
	int l= search(n);
	if(!l)
    { return;
    }
	label:
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

    cout<<"\n\n\n\tEnter account no. to whom you want to transfer:";
	cin>>k;
	if(k==0)
    {
        File.close();
        return;

    }
     else if(k==n)
     {
         cout<<"\n\t\t\tYou cannot transfer to your own account!!!!!";
         goto label;
     }


    while(!File.eof() && found==false)
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==k)
		{

            display_sp(k,2);
             cout<<"\n\n\t\t\tEnter The amount to be transfer: ";
             cin>>amt;
            int e =transfer2(n,amt);
            if(e)
            {
            ac.dep(amt);
            system("CLS");
            cout<<"\n\n\n\n\n\n\t\t\t\t\tTransaction Processing....";
            cout<<"\n\t\t\t\t\t  Please Wait....";
            Sleep(2000);
            system("CLS");
            cout<<"\n\n\t\t\t\tTransition Successful";
            found=true;
            }
            else
            {

                    system("CLS");
                    cout<<"\n\n\n\n\n\n\t\t\t\t\tTransaction Processing....";
                    cout<<"\n\t\t\t\t\t  Please Wait....";
                    Sleep(2000);
                    system("CLS");
                    cout<<"\n\n\t\t\t\tTransition Failed XXXXX|";
					cout<<"\n\n\n\n\t\t\t\tInsufficient balance!!!";

            }
			int pos=(-1)*(int)(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write((char *) (&ac), sizeof(account));

			found=true;
             flag=true;
	       }

         }



    File.close();

    if(flag==false)
    {
    cout<<"\n\t\t\t\tAccount does not exist!!!!"<<endl;
      goto label;
    }




}
int transfer2(int n, int amt1)
{

	bool found=false;

	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\t\t\tFile could not be open !! Press any Key...";
		return false;
	}

	while(!File.eof() && found==false)
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{




                int bal=ac.retdeposit()-amt1;
				if(bal<0)
                {
                    File.close();
                    return false;
				}
				else {
					ac.draw(amt1);
					found=true;
				}
			    int pos=(-1)*(int)(sizeof(ac));
			    File.seekp(pos,ios::cur);
			    File.write((char *) (&ac), sizeof(account));


	       }
         }


    File.close();
	if(found==false){

	  return false;
	}

        return true;
}
