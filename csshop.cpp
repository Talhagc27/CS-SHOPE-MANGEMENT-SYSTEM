//CS SHOPE PROJECT
//Design by @Kashif Mehmood
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class cs_shope
{
  public:
 void update_product();
    void shope_menue();
    void add_product();
    void show_product();
    void check_product();
    
};
    void cs_shope::shope_menue()
    {
    	system("cls");
    	cout<<"\n\n\n\t\t\t\t Wellcome to Cs Shope";
    	cout<<"\n\t\t\t\t ____________________";
    	cout<<"\n\n\n\t\t\t\t     Shope Menue";
    	cout<<"\n\n\n 1.Add New Product";
    	cout<<"\n\n 2.Display Product ";
    	cout<<"\n\n 3.Check Specific Product";
    	cout<<"\n\n 4.Update Product";
    	cout<<"\n\n 5.Delete Product";
    	cout<<"\n\n 6.Exit";
	
	
	void cs_shope::add_product()
	{
		system("cls");
		fstream file;
		string n_name,n_id;
		cout<<"\n\n\n\t\t\t\t Add New Product";
		cout<<"\n\n Product Id : ";
		cin>>n_id; 
		cout<<"\n\n\t\t\t Product Name : ";
		cin>>n_name;
		file.open("D://csshope.txt",ios::out|ios::app);
		file<<" "<<n_id<<" "<<n_name<<"\n";
		file.close();
	}
	 cs_shope::show_product()
	{
		system("cls");
		fstream file;
		string n_name,n_id;
		cout<<"\n\n\t\t\t\tShow All Products";
		file.open("D://csshope.txt",ios::in);
		if(!file)
	    cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Product Id    Product Name\n\n";
			file>>n_id>>n_name;
			while(!file.eof())
			{
				cout<<"     "<<n_id<<"\t\t"<<n_name<<"\n\n";
				file>>n_id>>n_name;
			}
			file.close();
		}
	}
	
	void cs_shope::check_product()
	{
		system("cls");
		fstream file;
		int count=0;
		string n_id,n_name,n_idd;
		cout<<"\n\n\t\t\t\t\tCheck Specific Product";
		file.open("D://csshope.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Product Id : ";
			cin>>n_idd;
			file>>n_id>>n_name;
			while(!file.eof())
			{
				if(n_idd==n_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\t Check Sepcific Product";
					cout<<"\n\n Product Id : "<<n_id;
					cout<<"\n\n\t\t\tProduct Name : "<<n_name;
					count++;
					break;
				}
				file>>n_id>>n_name;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Product Id Not Found...";
		}
	}
	
	void cs_shope::update_product()
	{
		system("cls");
		fstream file,file1;
		int count=0;
		string n_name,n_na,n_idd,n_id;
		cout<<"\n\n\t\t\t\tUpdate Product Record";
		file1.open("D://csshope1.txt",ios::app|ios::out);
		file.open("D://csshope.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Product Id : ";
			cin>>n_id;
			file>>n_idd>>n_name;
			while(!file.eof())
			{
				if(n_id == n_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Product Record";
					cout<<"\n\n New Product Name :";
					cin>>n_na;
					file1<<" "<<n_id<<" "<<n_na<<"\n";
			        count++;		
				}
				else
				file1<<" "<<n_idd<<" "<<n_name<<"\n";
				file>>n_idd>>n_name;
			}
			if(count == 0)
			cout<<"\n\n Product Id Not Found...";
		}
		file.close();
		file1.close();
		remove("D://csshope.txt");
		rename("D://csshope1.txt","D://csshope.txt");
	}
	
	void cs_shope::del_product()
	{
		system("cls");
		fstream file,file1;
		int count=0;
		string n_id,n_idd,n_name;
		cout<<"\n\n\t\t\t\tDelete Product Record";
		file1.open("D://csshope1.txt",ios::app|ios::out);
		file.open("D://csshope.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Product Id : ";
			cin>>n_id;
			file>>n_idd>>n_name;
			while(!file.eof())
			{
				if(n_id == n_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Product Record";
					cout<<"\n\n One Product is Deleted Successfuly...";
					count++;
				}
				else
				file1<<" "<<n_idd<<" "<<n_name<<"\n";
				file>>n_idd>>n_name;
			}
			if(count == 0)
			cout<<"\n\n Product Id Not Found...";
		}
		file.close();
		file1.close();
		remove("D://csshope.txt");
		rename("D://csshope1.txt","D://csshope.txt");
	}
 main()
{  
    int choice;
    char b;
    cs_shope a;
    p:
	a.shope_menue();
	cout<<"\n\n Enter Your Choice :";
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			a.add_product();
			cout<<"\n\n Do You Want to Add onther Product (y/n) : ";
			cin>>b;
		    }while( b=='y');
			break;
		case 2:
			a.show_product();
		    break;
		case 3:
			a.check_product();
		    break;
		case 4:
			a.update_product();
		    break;
		case 5:
			a.del_product();
		    break;
		case 6:
		    exit(0);	
		default:
		    cout<<"\n\n Invalid Value...Please Try Again...";				
	}
	getch();
	goto p;
}
