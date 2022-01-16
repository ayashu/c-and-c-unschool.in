#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class Phonebook
{
  int RecordId;
  char name[40],gender,email[50],address[100],fatherName[40];
  char phoneNo[11],aadharNo[13];
  public:
  	Phonebook()
  	{
  		RecordId=0;//initializing the record id 
	  }
  	void Create(int i)
  	{
  		RecordId=i;
  		fflush(stdin);
  		cout<<endl<<"\t\tEnter name:";
  		cin.getline(name,40);
  		cout<<"\t\tEnter gender(Male-M/Female-F/Others-O) :";
  		cin>>gender;
  		fflush(stdin);
  		cout<<"\t\tEnter father's name :";
  		cin.getline(fatherName,40);
  		cout<<"\t\tEnter phone number :";
  		cin>>phoneNo;
  		cout<<"\t\tEnter email :";
  		cin>>email;
  		cout<<"\t\tEnter aadhar card number :";
  		cin>>aadharNo;
  		fflush(stdin);
  		cout<<"\t\tEnter address :";
  		cin.getline(address,100);
	}
		void Display()
	{
		cout<<endl<<"\t\tID:"<<RecordId<<endl;
		cout<<"\t\tNAME:"<<name<<endl;
		cout<<"\t\tGender:"<<gender<<endl;
		cout<<"\t\tEmail:"<<email<<endl;
		cout<<"\t\tAddress:"<<address<<endl;
		cout<<"\t\tFather Name:"<<fatherName<<endl;
		cout<<"\t\tPhone Number:"<<phoneNo<<endl;
		cout<<"\t\tAadhar number:"<<aadharNo<<endl<<endl;
	}
	
	friend void Modify();
    friend int Search(char SN[]);
    friend void Delete();
    friend int PhonebookEmpty();
};
int PhonebookEmpty()
{
	Phonebook a;
	ifstream obj("Phonebook.dat",ios::binary|ios::in);	
	while(obj.read((char *)&a,sizeof(a)))//reading till the end of the file
	  ;
	return a.RecordId;
}
int Search(char SN[])
{
    Phonebook a;
    ifstream obj("Phonebook.dat",ios::binary|ios::in);	
	int count=0;//counter for number of displayed records
	cout<<endl<<"\t\tThe records with the name "<<SN;
    while(obj.read((char *)&a,sizeof(a)))
    {
    	if(strcmp(SN,a.name)==0)
    	{
    	a.Display();
    	count++;
        }
	}
	if(count==0)//no records with the name specifed present in the file
	cout<<endl<<"\t\tThere are no such records in the phonebook"<<endl;	
    obj.close();
    return count;
}

void Modify()
    {
    	int ch,id;
    	Phonebook a;
    	ofstream obj_copy("New.dat",ios::binary);
    	ifstream obj("Phonebook.dat",ios::binary|ios::in);
    	
    	cout<<endl<<"\t\tEnter the id of the holder that you want to modify from list of record(s):";
		cin>>id;
		
		while(obj.read((char*)&a,sizeof(a)))
		{
			if(id==a.RecordId)
			{
    	   		do
    			{
					cout<<endl<<"\t\tEnter the field that you want to modify \n\t\t1.Name\t\t\t2.Gender\t\t3.Email\n\t\t4.Address\t\t5.Father Name\t\t6.Phone number\n\t\t7.Aadhar number\t\t8.Back To menu";
					cout<<endl<<"\t\tEnter your choice ";
					cin>>ch;
					switch(ch)
					{
						case 1:cout<<endl<<"\t\tEnter modified name:";
			       	       	   fflush(stdin);
			       	       	   cin.getline(a.name,40);
			       	       	   break;
						case 2:cout<<endl<<"\t\tEnter modified gender:";
			       	       	   cin>>a.gender;
			       	       	   break;
						case 3:cout<<endl<<"\t\tEnter modified email:";
			               	   cin>>a.email;
			               	   break;
						case 4:cout<<endl<<"\t\tEnter modified Address :";
			               	   fflush(stdin);
			               	   cin.getline(a.address,100);
			               	   break;
						case 5:cout<<endl<<"\t\tEnter modified father name:";
			               	   fflush(stdin);
			               	   cin.getline(a.fatherName,40);
			               	   break;
						case 6:cout<<endl<<"\t\tEnter modified phone number:";
			               	   cin>>a.phoneNo;
			               	   break;
						case 7:cout<<endl<<"\t\tEnter modified aadhar number:";
			               	   cin>>a.aadharNo;
			               	   break;
			        	case 8:break;
						default:cout<<endl<<"\t\tWrong choice of field";
			    	}	
	           }while(ch!=8);
	    	}
	       obj_copy.write((char*)&a,sizeof(a));//writing in New.dat
        }
        obj.close();
        obj_copy.close();
        remove("Phonebook.dat");
        rename("New.dat","Phonebook.dat");
        ifstream obj_new("Phonebook.dat",ios::binary);
        
	    cout<<endl<<"\t\tModified Record"<<endl;
	    while(obj_new.read((char*)&a,sizeof(a)))
	    {
	    if(id==a.RecordId)
	    a.Display();
	    }
	    obj_new.close();
    }
void Delete() 
{
		int ch,id;
    	Phonebook a;
    	ofstream obj_copy("New.dat",ios::binary);
    	ifstream obj("Phonebook.dat",ios::binary|ios::in);
    	
    	cout<<endl<<"\t\tEnter the id of the holder that you want to delete from list of record(s):";
		cin>>id;
		
		while(obj.read((char*)&a,sizeof(a)))
		{
			//maintaining the record id
			if(id>a.RecordId)//if record id is less than id to be deleted 
			{
				obj_copy.write((char*)&a,sizeof(a));//we write the record in the file
			}
			else if(id<a.RecordId)//if record id is more than id to be deleted 
			{
				a.RecordId--;//the id is adjusted
				obj_copy.write((char*)&a,sizeof(a));
			}
		}
		obj.close();
        obj_copy.close();
        remove("Phonebook.dat");
        rename("New.dat","Phonebook.dat");
        ifstream obj_new("Phonebook.dat",ios::binary);
        cout<<"\t\tRecord Deleted"<<endl;
}
    
int main()
{
	Phonebook a1;
	int ch,n=0,id;
	int temp;//storing the value of count
	char SName[40];
	do
	{
		ifstream obj_in("Phonebook.dat",ios::binary|ios::in);
	    ofstream obj_out("Phonebook.dat",ios::binary|ios::app);
		cout<<"\n\t\t**********WELCOME TO PHONEBOOK**********"<<endl;
		cout<<endl<<"\t\t\t\tMENU"<<endl;
		cout<<endl<<"\t\t1.Add New Record\t2.List The Records\n\t\t3.Modify Records\t4.Search Record\n\t\t5.Delete Record\t\t6.Exit"<<endl;
		cout<<endl<<"\t\t\tEnter your choice:";
		cin>>ch;
		cout<<endl<<"\t\t****************************************"<<endl;
		switch(ch)
		{
			case 1:id=PhonebookEmpty();
				   if(id>0)
				   {
				   	cout<<endl<<"\t\tEnter the number of records you want to add:";
				   	cin>>n;
				   	n=n+id;
				   	for(int i=id+1;i<=n;i++)
	               		{
	               			a1.Create(i);
	               			obj_out.write((char *)&a1,sizeof(a1));//storing data in file
	               		}
				   }
				   else//if no record in file
				   {
				   		cout<<endl<<"\t\tEnter the number of records:";
	               		cin>>n;
	               		for(int i=1;i<=n;i++)
	               		{
	               			a1.Create(i);
	               			obj_out.write((char *)&a1,sizeof(a1));//storing data in file
	               		}
	               }
	               obj_in.close();
			       obj_out.close();
				   break;
			case 2:obj_out.close();
			       id=PhonebookEmpty();
			       if(id==0)
			       {
			       	cout<<"\t\t\tPhonebook empty";
			       	cout<<"\t\t****************************************"<<endl;
			       	break;
				   }
			       cout<<endl<<"\t\tDetails of record(s):"<<endl;
			       cout<<"\t\t****************************************"<<endl;
			       while(obj_in.read((char *)&a1,sizeof(a1)))
	               a1.Display();
	               cout<<"\t\t****************************************"<<endl;
	               obj_in.close();
			       break;
			case 3:obj_in.close();
			       obj_out.close();
			       id=PhonebookEmpty();
			       if(id==0)
			       {
			       	cout<<"\t\t\tPhonebook empty";
			       	cout<<"\t\t****************************************"<<endl;
			       	break;
				   }
				   cout<<endl<<"\t\tEnter the full name of the record holder that you want to modify:";
			       fflush(stdin);
			       cin.getline(SName,40);
			       cout<<"\t\tDetails of record(s) with name "<<SName<<endl;
				   temp=Search(SName);
				   
		           if(temp!=0)
				   Modify();
				   else
				   cout<<"\t\tCannot be modified"<<endl;
			       break;
			case 4:obj_in.close();
			       obj_out.close();
			       id=PhonebookEmpty();
			       if(id==0)
			       {
			       	cout<<"\t\t\tPhonebook empty";
			       	cout<<"\t\t****************************************"<<endl;
			       	break;
				   }
			       cout<<endl<<"\t\tEnter the full name of the record holder that you want to search:";
			       fflush(stdin);
			       cin.getline(SName,40);
			       Search(SName);
			       break;
			case 5:id=PhonebookEmpty();
			       if(id==0)
			       {
			       	cout<<"\t\t\tPhonebook empty";
			       	cout<<"\t\t****************************************"<<endl;
			       	break;
				   }
			       obj_in.close();
			       obj_out.close();
			       cout<<endl<<"\t\tEnter the full name of the record holder that you want to delete:";
			       fflush(stdin);
			       cin.getline(SName,40);
			       temp=Search(SName);
			        
				   if(temp!=0)
				   Delete();
				   else
				   cout<<"\t\tCannot be Deleted"<<endl;
			       break;
			case 6:cout<<endl<<"\t\tExiting"<<endl;
			       obj_in.close();
			       obj_out.close();
			       break;
			default:cout<<endl<<"\t\tWrong choice"<<endl;	
		}
	}while(ch!=6);
	return 0;
}

