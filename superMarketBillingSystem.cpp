#include<iostream>
#include<fstream>   // fstream is used for file handling

using namespace std;

class shopping{

 private:

     string pname;
     float price;
     float disc;
     int pcode;

 public:

      void menu();
      void receipt();
      void administrator();
      void buyer();
      void add();
      void edit();
      void rem();
      void lis();

};

void shopping :: menu()
{
    m:
    string email;
    string password;
    int choice;

    cout<<"\t\t\t\t ____________________________________\n";
    cout<<"\t\t\t\t                                        \n";
    cout<<"\t\t\t\t      SuperMarket Billing Menu          \n";
    cout<<"\t\t\t\t ____________________________________\n";
    cout<<"\t\t\t\t                                         \n";

    cout<<"\t\t\t\t| 1). Administrator   |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t| 2).    Buyer         |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t| 3).    Exit          |\n";
    cout<<"\n\t\t  Please select Your Choice ";
    cin >> choice ;

    switch(choice)
    {
    case 1: // for administrator or the shopkeeper
         cout<< "\t\t\t  Please Login \n";
         cout<<"\t\t\t  ------------ \n\n";
         cout<< "\t\t\t Enter Email  \n";
         cin >> email;
         cout<< "\t\t\t  Password     \n";
         cin >> password;

         // now we have to choose the 1 particular email address and password to login administrator

         if(email == "ashu@gmail.com" && password == "ashu@123")
         {
             administrator();
         }
         else{
            cout<<" \t\t\t Invalid Email and Password \n";
         }

    case 2:{
             buyer();
           }

    case 3:
           {
             exit(0);
           }
    default:
           {
            cout<< "\t\t\td Please enter valid Choice";
           }

    }
    goto m;

}



void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\t\t\t------Administrator Menu-----\n";

    cout<<"\n\t\t\t |___1) Add the product___|";
    cout<<"\n\t\t\t |                        |";
    cout<<"\n\t\t\t |__2)Modify the product__|";
    cout<<"\n\t\t\t |                        |";
    cout<<"\n\t\t\t |__3)Delete the product__|";
    cout<<"\n\t\t\t |                        |";
    cout<<"\n\t\t\t |__4)Back to main menu___|";

    cout<< "\n\t\t\t Enter choice ";
    cin >> choice;

    switch(choice)
    {

    case 1:
        {
            add();
            break;
        }
    case 2:
        {
            edit();
            break;

        }
    case 3:
        {
            rem();
            break;
        }
    case 4:
        {

            menu();
            break;
        }
    default:
        {
            cout<<"\n\t Please enter Valid Choice ";

        }
    }
    goto m;
}





void shopping :: buyer()
 {

     m:
     int choice ;
     cout<< "\n\t\t\t   Buyer     \n";
     cout<< "\t\t\t    ------     \n";

     cout<< "\t\t 1) Buy product \n";
     cout<< "                    \n";
     cout<< "\t\t 2) Go Back     \n";

     cout<< "/t/t/tPlease Enter Your Choice! /n";
     cin >> choice;

     switch(choice)
     {

     case 1:
            receipt();
            break;

     case 2:
             menu();
             break;

     default:
        cout<<"Please Enter Valid Choice";
     }

     goto m;
 }




 void shopping:: add()
 {
     m:
     fstream data;
     float p;
     float d ;
     string n ;
     int c ;
     int token = 0;


     cout<< "\n\t\t\t Add New Product/n";
     cout<< "\n\t\t\t Enter the product Code\n";
     cin >> pcode ;
     cout<<"/t/t/t Enter the product Name \n";
     cin >> pname ;
     cout<<"\t\t\t Enter the product price \n";
     cin >> price ;
     cout<<"\t\t\t Enter the Discount \n";
     cin >> disc ;

    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt" ,ios::app|ios::out);
      data <<" " << pcode << " " <<  pname <<" " << price << " " << disc << "\n";
        data.close();
    }
    else{
        data >> c >> n >> p >> d;
        while(!data.eof())
        {

            if(c == pcode){
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();



        if(token == 1){
            goto m;
        }
        else{
        data.open("database.txt" ,ios::app|ios::out);
      data <<" " << pcode << " " <<  pname <<" " << price << " " << disc << "\n";
        data.close();

        }
    }

       cout<<"\n\n\t Record Inserted \n";


 }


 void shopping:: edit()
 {
     fstream data , data1;
     int token = 0;
     int c ;
     float d;
     float p ;
     int pkey ;
     string n ;

    cout << "\n\t\t Modify the record\n";
    cout << "\n\t\t Enter Product code \n\n";
    cin >> pkey ;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n\t  File Does Not Exist \n";

    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

       data>>pcode>>   pname  >> price >> disc ;
       while(!data.eof()){
        if(pkey == pcode){
            cout<<"\n\t\t Product new Code \n";
            cin >> c;
            cout<<"\t\t\t Enter the product Name \n";
            cin >> n ;
            cout<<"\t\t\t Enter the product price \n";
            cin >> p ;
            cout<<"\t\t\t Enter the Discount \n";
            cin >> d ;

            data1<<" " << c << " " <<  n <<" " << p << " " << d << "\n";
             cout<< "\n\t\t\t Record Edited \n";
             token++;

        }
        else{
            data1 <<" " << pcode << " " <<  pname <<" " << price << " " << disc << "\n";
        }
        data>>pcode>>pname>>price>>disc;
       }
       data.close();
       data1.close();
       remove("database.txt");
       rename("database1.txt","database.txt");
       if(token == 0){
        cout<<"\n\t\t Sorry record not Found!";
       }

    }

 }

 void shopping::rem(){

 fstream data , data1;
 int pkey;
 int token = 0;
 cout<<"\n\t\t\t Delete Product";
 cout<<"\n\t\t Product Code ";
 cin >> pkey;
 data.open("database.txt",ios::in);
 if(!data){
    cout<<"file doesNot Exists" << endl;
 }
 else{
    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>disc;
    while(!data.eof()){
        if(pcode == pkey){
            cout<<"\n\t\t product deleted successfully";
            token++;
        }
        else{
            data1 << " " << pcode << " " << pname << " " << price << " "<< disc<<"\n";
        }
         data>>pcode>>pname>>price>>disc;

    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token == 0){
        cout<<"\n\t\t Record not found ";
    }
 }
}

void shopping::lis()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\t_____________________________________";
    cout<<"\n prono       \tName    \tPrice\n";
    cout<<"\n\t_____________________________________";
    cout<<endl;
    data>>pcode>>pname>>price>>disc;
    while(!data.eof()){
        cout<<pcode <<"\t\t " << pname <<"\t\t " << price<<"\n\n";
        data>>pcode>>pname>>price>>disc;
     }
     data.close();


}

 void shopping:: receipt()
 {
     fstream data;
     int arrc[100];
     int arrq[100];
     char choice;
     int c = 0;
     float amount = 0;
     float dis = 0;
     float total = 0;
     cout<<"\n\n\t\t\t\t\t RECEIPT \t\t\t";
     data.open("database.txt",ios::in);
     if(!data)
     {

         cout<<"\n\n Empty DataBase" ;
     }

     else{
        data.close();
        lis();
        cout<<"\n\t\t\t _______________________________\t\t\n";
        cout<<"\n                                           \n";
        cout<< " \t\t\t       Please place an order              ";
        cout<<"\n                                           \n";
         cout<<"\n\t\t\t _______________________________\t\t\n";
         do{
                m:
            cout<<"\n\t\t Enter product Code \t\n";
            cin >> arrc[c];
            cout<<endl<< " \t\t\t Enter the product Quantity\n";
            cin >> arrq[c];

            for(int i=0; i<c; i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\t\t Duplicate code! Please Try Again";
                    goto m;
                }
            }
            c++;
            cout<<"\t\t Do you want to buy another product if yes press y else no \n";
            cin >> choice;
         }
         while(choice == 'y');
         cout<<"\n\n\n\t\t\t __________________RECEIPT____________________\t\n";
         cout<<"productno     productname    product quantity     price    amount    amount with discount\n";

         for(int i=0; i<c; i++){
             data.open("database.txt",ios::in);
             data>>pcode>>pname>>price>>disc;
             while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price *arrq[i];
                    disc = amount - (amount *disc/100);
                    total = total + disc;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t" <<amount<<"\t\t"<<disc;
                }
                 data>>pcode>>pname>>price>>disc;
             }
         }
            data .close();

     }
     cout<<"\n\t\t_________________________________________________________\t\t";
     cout<<"\n\t\t  Amount To Pay  \t" << total<< " Rs"<<endl;
     cout<<"\n\t\t_________________________________________________________\t\t";
     cout<<endl<<endl<<endl<<endl<<endl;
 }
 int main()
 {
     shopping s;
     s.menu();
 }



























