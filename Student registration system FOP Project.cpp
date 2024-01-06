#include<iostream>
#include<string>
#include<windows.h> // header file to be able to place the position of the cursor at the required position on the screen. 
using namespace std;

int main();
void show_data();  //This function is used to show all records of students.
void delete_student(string searchkey);  //This function is used to delete record of existing student.
void delete_course(string searchkey);   //This function is used to delete record of existing assigned course.
void search_student(string searchkey);  //This function is used to search of a student.
void add_student(string searchkey);      //This function is used to add record of new student.
void add_course(string searchkey);       //This function is used to add record of new course for a student.
void update_studentR(string searchkey);   //function is used to update existing student.
void update_courseR(string searchkey);    //function is used to update existing course.
int i;
void gotoxy(int x, int y)  // gotoxy() used to place the position of the cursor at the required position on the screen.
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);}

struct Course{
	string course_name;
	string course_ID;
};
int k = 0;
int course_count[1000];

struct Student{    //Structure student is made to store student attributes.
  int rollno;
  string idnumber; 
  string name;
  string fname;
  string email_address;
  Course courses[5];
};
Student rec[1000];  //This is basic array of defined structure to sore data.   
int count=0;
int main()
{
int choice;
string searchkey;
 do
 {
	
  cout<<"\n\tWelcome to our Student Registeration System"<<endl;
  cout<<"\t-------------------------------------------"<<endl;
  cout<<"\tWhat do you want to do?"<<endl;
  cout<<"\t1-Add new student"<<endl;
  cout<<"\t2-Add new course for a student"<<endl;
  cout<<"\t3-Search for a student"<<endl;
  cout<<"\t4-Delete student record"<<endl;
  cout<<"\t5-Delete course from a student"<<endl;
  cout<<"\t6-update student record"<<endl;
  cout<<"\t7-ubdate course for a student"<<endl;
  cout<<"\t8-Display all students"<<endl;
  cout<<"\t9-Quit Program"<<endl;
  cout<<"\t----------------------"<<endl;
  
  cout<<"Enter your choice: ";
  cin>>choice;
  
  switch(choice)
 {
   case 1:         
     add_student(searchkey);
     break;
   case 2:
     add_course(searchkey);  
     break;
     main();
   case 3:
     search_student(searchkey);
     break;
     main();        //Return to main so user can input new record.
   case 4:
   	 delete_student(searchkey);
   	 break;
   	 main();
   case 5:
   	 delete_course(searchkey);
   	 break;
   	 main();
   case 6:
   	 update_studentR(searchkey);
     break;
     main();
   case 7:
   	 update_courseR(searchkey);
     break;
	 main();
   case 8:
   	 show_data();
   	 break;
   case 9:
     cout <<"Thank you for using our system.\n";
   	 exit(0);
   	 break;
   default:          
     cout<<"Invalid number."<<endl; //Default value for ivalid Input.
  }
  
 }while(choice != 9);
 
  return 0;
}

  
void get_data(int i,string searchkey)        //Function for receiving data from user and populatiing the variables with values.
{ 
int t,l;
   
  cout<<"Enter ID number in format(22XXXXXXX): ";
  cin >> searchkey;
  
  l=0; // check value 
  t = 0;
  
 	
	while(t<count-1){
		if(rec[t].idnumber != searchkey){
			t++;	
		}
		else{
			l=1; // changed if it idnumber value == searchkey
			break;
		}
	}

	
if(l == 1){
  count=count-1; // to make the count return to its actual value if student ID is already recorded or found
  i=i-1;  // i value is connected to count value so it also changed
  cout << "This student is already recorded";
}
else{
  rec[i].idnumber = searchkey;
  cout<<"Enter First name: ";
  cin >> rec[i].name;
  cout<<"Enter Family name: ";
  cin >> rec[i].fname;
  cout<<"Enter Email Address: ";
  cin >> rec[i].email_address;
  cout<<"\nStudent added successfully.\n";
  course_count[i]=0;
}
}


void add_student(string searchkey)   
{   
   
count++;
i=count-1; // for i to begain with 0
    get_data(i, searchkey);  
main();	        
}

void add_course(string searchkey){        
string s;
cout <<"Enter student ID number: ";
	cin >> searchkey;
	i = 0;
	while(i<count){
		if(rec[i].idnumber != searchkey){
			i++;	
		}
		else{
			break;
		}
	}
if(rec[i].idnumber == searchkey){
	k=course_count[i]; // to use k as course count without changing the course_count[i] value
  if(k < 5){
  cout <<"\t************ courses list ************\n";
  cout <<"\t--------------------------------------\n";
  cout <<"\tCourse Name      "<<"  "<<"  Course ID\n";
  cout <<"\t--------------------------------------\n";
  cout <<"\tMath             "<<"  "<<"  101\n";
  cout <<"\tComputer         "<<"  "<<"  102\n";
  cout <<"\tArt              "<<"  "<<"  103\n";
  cout <<"\tAccounting       "<<"  "<<"  104\n";
  cout <<"\tHistory          "<<"  "<<"  105\n";
  cout <<"\tEnglish          "<<"  "<<"  106\n";
  cout <<"\tStatistics       "<<"  "<<"  107\n\n";
  
cout <<"Enter course ID: ";
cin >> s;
int y = 0, c = 0; // check value
 while(y <course_count[i]){
		if(rec[i].courses[y].course_ID != s){
			y++;
		}
		else{
			c = 1;
			break;
		}
	    }
	  if (c==1){
	    y--; 
	    course_count[i]--; // to return the course count to its actual value if the course ID is already recorded or found
		cout<<"This course is already recorded";
	}
	  else{
	  	 
		 rec[i].courses[k].course_ID = s;
		 cout <<"Enter course name: ";
         cin >> rec[i].courses[k].course_name;
         cout <<"\nCourse added successfully.\n";
         course_count[i]++;
         
	    }

    }
   else{
     cout <<"Only 5 courses allowed for a student.";
       }
  }
else{

  cout <<"This student is not recorded.";	
}
}
  
  void delete_student(string searchkey)         //This function is used to delete record of existing student.
{   
 
cout <<"Enter student ID number: ";
	cin >> searchkey;
	int i = 0;
	int j=0;
	while(i<count){
		if(rec[i].idnumber != searchkey){
			i++;	
		}
		else{
			j=1;
			break;
		}
	}
	if(j == 1){
		
	
			
		if (i==count-1){// if student want to delete was the last one we will just decrease the value of count
			count--;
		}
		else{ // if student want to delete was somewhere else rather than last one do the following
		
			for(i=i;i<count;i++){
				rec[i].idnumber = rec[i + 1].idnumber;
				rec[i].name = rec[i + 1].name;
				rec[i].email_address = rec[i + 1].email_address;
			}
			count--;
			}
			
              cout << "student deleted.\n\n";
}
else{
	cout <<"This student is not recorded";
} 
  }
  
  void delete_course(string searchkey){
  	
int j=0, k =0;
bool found = false;
string searchCourse;
cout <<"Enter student ID number: ";
	cin >> searchkey;
	i = 0;
	while(i<count){
		if(rec[i].idnumber != searchkey){
			i++;	
		}
		else{
			j = 1;
			break;
		}
	}
	if(j == 1){
		  cout <<"Enter course ID: ";
		  cin >> searchCourse;
		  while(k<course_count[i]){
		  	if(rec[i].courses[k].course_ID != searchCourse){
		  		k++;
			  }
		    else{
		    	found = true;
		    	course_count[i]--;
		    	for(k = k; k<course_count[i]; k++){
		    	rec[i].courses[k].course_ID = rec[i].courses[k + 1].course_ID;
				rec[i].courses[k].course_name = rec[i].courses[k + 1].course_name;
                 }
                break;
			}
		  } 
	}
	if(!found){
		cout <<"This course is not recorded.";
	}
	else{
		cout <<"Course deleted."; 
	}
	  }
  	
  
  void show_data( )      //Function for showing student data on the screen.
{
	 char key;
	 int var = 0; //to control the posision of rows for table values
     system("cls");
     gotoxy(10,0);
     cout<<"------------------------------------------------------------------------------------"<<endl;
     gotoxy(10,1);
     cout<<"--------------------------------Student record Table--------------------------------"<<endl;
     gotoxy(10,2);
     cout<<"------------------------------------------------------------------------------------"<<endl; 
     gotoxy(10,3);
     cout<<"Roll  ID         Name      Family Name    Email Address    Courses\n";
     gotoxy(10,4);
     cout<<"------------------------------------------------------------------------------------"<<endl;
     
  for(int i=0;i<count;i++){
  	
     gotoxy(10,i+var+5);
     cout<<i;
     gotoxy(16,i+var+5);
	 cout<<rec[i].idnumber;
	 gotoxy(27,i+var+5);
	 cout<<rec[i].name;
	 gotoxy(37,i+var+5);
	 cout<<rec[i].fname;
	 gotoxy(52,i+var+5);
	 cout<<rec[i].email_address;
     
     for(int k=0;k<course_count[i];k++){
     	gotoxy(69,i+k+var+5);
     	cout<<rec[i].courses[k].course_ID<<endl;
     	gotoxy(73,i+k+var+5);
   		cout<<rec[i].courses[k].course_name;
   		var++;
	 }
	 var++;
	 
}
gotoxy(10,20);
cout<<"Enter (R) key if want to return to main menu or any other key to exit program: ";
cin >> key;
if(key == 'R' || key == 'r'){
	main(); // to return to main function
}
else
exit(0); // to exit the program

}



void search_student(string searchkey){
	cout <<"Enter student ID number: ";
	cin >> searchkey;
	i = 0;
	while(i<count){
		if(rec[i].idnumber != searchkey){
			i++;	
		}
		else{
			break;
		}
	}
if(i==count){ // after searching about ID and not found i will reach to count value so that mean that the student is not found
cout<<"Student not found.";
}
else
{
if(rec[i].idnumber == searchkey){
	 char key;
	 cout<<"\nExisted information about this record:\n\n";
     cout<<"Roll : "<<i<<endl;
	 cout<<"ID : "<<rec[i].idnumber<<endl;
	 cout<<"First Name: "<<rec[i].name<<endl;
	 cout<<"Family Name: "<<rec[i].fname<<endl;
	 cout<<"Email Address: "<<rec[i].email_address<<endl;
     cout <<"Courses: \n";
     for(int k=0;k<course_count[i];k++){
     	cout<<rec[i].courses[k].course_ID<<" "<<rec[i].courses[k].course_name<<endl;
	 }
	 
	 cout<<"\nEnter (R) key if want to return to main menu or any other key to exit program: ";
     cin >> key;
     if(key == 'R' || key == 'r'){
	 main();
     }
     else
     exit(0);	 
}
else
	cout <<"This student is not recorded";
}
 
 
}

	
void update_studentR(string searchkey){
    cout <<"Enter student ID number: ";
	cin >> searchkey;
	i = 0;
	while(i<count){
		if(rec[i].idnumber != searchkey){
			i++;	
		}
		else{
			break;
		}
	}
if(i==count){ // after searching about ID and not found i will reach to count value so that mean that the student is not found
cout<<"Student not found.";
}
else
{
if(rec[i].idnumber == searchkey){
	 
	 cout<<"\nExisted information about this record:\n\n";
     cout<<"Roll : "<<i<<endl;
	 cout<<"ID : "<<rec[i].idnumber<<endl;
	 cout<<"First Name: "<<rec[i].name<<endl;
	 cout<<"Family Name: "<<rec[i].fname<<endl;
	 cout<<"Email Address: "<<rec[i].email_address<<endl;
     cout <<"Courses: \n";
     for(int k=0;k<course_count[i];k++){
     	cout<<rec[i].courses[k].course_ID<<" "<<rec[i].courses[k].course_name<<endl;
	 }
     cout<<"\n\nEnter new data for above shown record: "<<endl;
     int t,l;
     string search;
     cout<<"Enter ID number in format(22XXXXXXX): ";
     cin >> search;
     l=0;
     t = 0;
  
	while(t<count-1){
		if(rec[t].idnumber != search){
			t++;	
		}
		else{
			l=1;
			break;
		}
	}

	
 if(l == 1){
   count=count-1;
   i=i-1;
   cout << "This student is already recorded";
}
 else{
   rec[i].idnumber = search;
   cout<<"Enter First name: ";
   cin >> rec[i].name;
   cout<<"Enter Family name: ";
   cin >> rec[i].fname;
   cout<<"Enter Email Address: ";
   cin >> rec[i].email_address;
   cout<<"\nRecord updated successfully."<<endl;
}
}
else{
	cout <<"This student is not recorded";
} 	
}

}

			
void update_courseR(string searchkey){
string search;	
cout <<"Enter student ID number: ";
	cin >> searchkey;
	i = 0;
	while(i<count){
		if(rec[i].idnumber != searchkey){
			i++;	
		}
		else{
			break;
		}
	}
if(rec[i].idnumber == searchkey){
	 cout<<"\nExisted courses for this student:\n\n";
     cout <<"Courses: "<<endl;
     for(int k=0;k<course_count[i];k++){
     	cout<<rec[i].courses[k].course_ID<<" "<<rec[i].courses[k].course_name<<endl;
	 }
	 cout <<"\n\nEnter course ID you want to update: ";
	 cin >> search;
	 int k=0, e = 0, v=0 ;
	 while(k<course_count[i]){
		if(rec[i].courses[k].course_ID != search){
			k++;
		}
		else{
			v = k; // for knowing exactly the index of the course we want to update that is v value
			e = 1;
			break;
		}
	 }
    if(e == 1){
		string s;
		int c =0, k= 0;
		cout<<"Enter new data for above course record: "<<endl;
		cout <<"Enter course ID: ";
		cin>>s;
	  while(k<course_count[i]){
		if(rec[i].courses[k].course_ID != s){
			k++;
		}
		else{
			c = 1;
			break;
		}
	    }
	  if (c==1)
		cout<<"This course is already recorded";
	  else{
	  	k--; // to stop at the index of course ID we want to update after increasing k value above fo searching  
        rec[i].courses[v].course_ID = s;
        cout <<"Enter course name: ";
        cin >> rec[i].courses[v].course_name;
        cout <<"\nRecord updated successfully.";
    }
	 }
	else
		cout<<"This course is not recorded.";
	
    }
else
	cout <<"This student is not recorded.";

 
}

	
