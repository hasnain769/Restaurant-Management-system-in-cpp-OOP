#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
using namespace std;



class Admin;

class Menu{
	
	public:	
	string dish;
	int price;
	friend class Admin;
	
	Menu(){
	}	
		
	void setmenu(){
		char ch='n';
			fstream fill;
			fill.open("Menu.txt",ios::app);
		do{
		
	
		cout<<"   Enter the DISH name please ";cin>>dish;cin.ignore();
		cout<<"   Enter the DISH price please ";cin>>price;cin.ignore();
		
		
		fill<<dish/*setw()*/ <<"    "<<price<<endl;
		   	cout<<"   press any key to exit "<<endl;
			cout<<"   press (Y) to Add more dishes ";cin>>ch;
	
	}
	while(ch=='y');
		
		system("cls");
		
	}
			void showmenu(){
			
				system("cls");
				ifstream menu;
				menu.open("Menu.txt",ios::out);
				 int count=1;
				 cout<<"-------------------------------------------------"<<endl;
				cout<<"       #no   ITEM                  PRICE     "<<endl;
				cout<<"--------------------------------------------------"<<endl;
				while(menu){		
					menu>>dish;
					menu>>price;
					cout<<"        "<<count<<"  "<<dish<<"--------------Rs-"<<price<<endl;;	
					count ++;
				}
	       		cout<<"----------------------------------------------"<<endl;
			}
	




	 
	
	
};

class Customer:public Menu{
//	static int c;
	
friend class Admin;

		public:
			Customer(){
//				c=1;
			}
//			showmenu();
	
		void selectmenu(){
		

            
			string myname;
			static int orderno=0;
			cout<<endl;
			cout<<"Enter Your name please :";cin>>myname;
			cout<<"Hello Mr/Ms "<<myname<<" what You would like to take :";
			orderno++;
			string dishn;
			cin>>dishn;
			ofstream bill;
			ofstream sale;
			bill.open("bill.txt",ios::trunc);
			ofstream orders;
			orders.open("orders list.txt",ios::app);
			bill<<myname<<"       order no "<<orderno<<endl;
			bool choice=true;
			
		    orders<<"order no "<<orderno<<"   "<<myname<<endl;
			while(choice==true){

			ofstream sale;
			ifstream select;
			select.open("menu.txt",ios::out);
			while(select){
				select>>dish;
				select>>price;
				
				if(dishn==dish){
				
					sale.open("Total sale.txt",ios::app);
					orders<<"ITEM   "<<dish<<endl;
					bill<<dish<<"     "<<price<<endl;
					sale<<dish<<"     "<<price<<endl;
					break;	
				}
				
			}
			select.close();
		
			cout<<"Any thing else we can serve (y/n) :";
			char anything;
			cin>>anything;
			if(anything=='n' ){
			orders<<"_______________________________"<<endl;
            orders.close();
			choice=false;
			bill.close();
			system("cls");
			ifstream showbill;
			char line[100];
			showbill.open("bill.txt",ios::out);
			showbill.getline(line,100,'\n');
			 int total=0;
				showbill>>dish;
				showbill>>price;
				cout<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"               BILL          "<<endl;
				cout<<"-----------------------------------"<<endl<<endl;
				cout<<"   NAME :"<<line;
				cout<<endl;
				cout<<"   ITEMS                    PRICE :"<<endl;
			while(showbill){
				total+=price;
			    cout<<"   "<<dish<<"-----------------"<<"Rs"<<price<<endl;
				showbill>>dish;
				showbill>>price;
				
				
			} 
			const float tax=0.3*total;
			cout<<"   GST----------------------"<<tax<<endl;
			cout<<endl;
			cout<<"   Total bill is-------------"<<"Rs"<<total+tax<<endl<<endl;
			char exit;
			cout<<"_______________________________________"<<endl<<endl;
			cout<<"   press any thing to exit :";cin>>exit;
			cout<<endl<<endl;
			}
			else if(anything=='y'){
			cout<<"   what we can serve more :";
			cin>>dishn;
			
			}
			else{
				cout<<"   press (y/n)"<<endl;
				
				
			}
		}
		
			sale.close();
			
		

	
}
	
};

class Admin{
	int id,pin;
	public:
		
		Admin(){
		}
		void create_ac(){
			cout<<"   enter Id to create account :";
			cin>>id;
			cout<<"   enter pin to create account :";
			cin>>pin;
				ofstream outfile;
	outfile.open("Admin.txt", ios::app);
	outfile<<id<<"     "<<pin<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"      ACCOUNT CREATED SUCCESSFULLY!"<<endl;
	outfile.close();
			
		}
		
		void login(){
		cout<<"   please enter your ID :";cin>>id;
		cout<<"   please enter your pin:";cin>>pin;
		int i,p;
		fstream infile;
		infile.open("Admin.txt",ios::in);
		
		bool flag=false;
		int counter=0;
		while(infile){
			infile>>i;
	    	infile>>p;
	    
	
		if(i==id&&p==pin){
			flag=true;
			}
	
		
		}
		infile.close();
	
		
		if(flag==true){
	
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"    YOU HAVE LOG IN SUCCSESSFULLY "<<endl;
		cout<<endl;
//		system("cls");
		char option;
		again:
		system("cls");
		cout<<"_____________________________________"<<endl;
		cout<<"   press 1 to Edit menu         :"<<endl;
		cout<<"   press 2 to Record order  :"<<endl;
		cout<<"   press 3 to for Total sale    :"<<endl;
		cout<<"   press e to exit :"<<endl;
		cout<<"_____________________________________"<<endl<<"Enter";cin>>option;;
		Menu ob;
		Customer cust;
		
		switch(option){
			case '1':
				//why not Menu *ob;
				ob.showmenu();
	            ob.setmenu();
	            goto again;
	            break;
	            
	        case '3':
	        	calculatesale();
	        	goto again;
	        	break;
			break;  
			case'2':
				ob.showmenu();
				cust.selectmenu();
				goto again;	
				break;
			case'e':
			   break;	
			default:
				goto again;
		}
	}
		else{
			cout<<"   Incorrect Id or Pin!!"<<endl;
		}		
	}
		
		
		void calculatesale(){
			system("cls");
			ifstream sale;
			sale.open("Total sale.txt",ios::in);
			string item;int value;
			sale>>item;
			sale>>value;
			
			static int total=0;
			cout<<"--------------------------------------------------"<<endl<<endl;
			cout<<"                  Total Sales"<<endl;
			cout<<"--------------------------------------------------"<<endl<<endl;
			cout<<"       ITEMS                     PRICE"<<endl;
			while(sale){
				
				cout<<"      "<<item<<"-------------------"<<"Rs-"<<value<<endl;
				total+=value;
				sale>>item;
		     	sale>>value;
			}
			cout<<endl;
			cout<<"   Total sale---------Rs"<<total<<endl;
			cout<<"__________________________________________________";
			char exit;
			cout<<endl<<"   press any key to continue :";
			cin>>exit;
			system("cls");
		}

};
class Ketchen{
	public:
		Ketchen(){
		}
	void showorders(){
	string line;
	ifstream data;
	data.open("orders list.txt");
	getline(data,line);
	while(data){
		cout<<line<<endl;
		getline(data,line);
	}
	char any;
	cout<<endl;
	cout<<"press anything to Refresh lists";
	cin>>any;
		}
};





