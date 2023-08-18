#include<iostream>
#include "admin.h"

using namespace std;








int main(){

	refresh:
		system("cls");
cout<<"______________________________________________"<<endl<<endl;
cout<<"               I MANAGER           "<<endl;
cout<<"______________________________________________"<<endl<<endl<<endl;
char option;
cout<<"-----------------------------------"<<endl;
cout<<"   Press 1 for Admin Login "<<endl;
cout<<"   Press 2 for Customer Services "<<endl;
cout<<"   Press 3 for ketchen interface"<<endl;
cout<<"----------------------------------"<<endl<<"ENTER :";
cin>>option;

	Admin o1;
	Customer o2;
switch (option){
	case '1':
	
		cout<<endl;
		login:
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"   press 1 for Sign-In OR press 2 for Sign-Up "<<endl;
		cout<<"-------------------------------------------------------"<<endl<<"ENTER :";
		char sel;
		cin>>sel;
		switch(sel){
		
			case '1':
			
				o1.login();
				system("cls");
				goto refresh;
				break;
			case '2':
			
			    o1.create_ac();	
			    system("cls");
			    goto login;
			    break;
  
		}
		break;
	
	case '2':
		
	again:
		o2.showmenu();
		o2.selectmenu();
		system("cls"); 
		//goto refresh;
	goto again;	
		break;
		
	case '3':
		refreshhh:
		system("cls");
		Ketchen obj;
		obj.showorders();
		
		goto refreshhh;
	    	
		
}



}

