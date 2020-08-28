#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class DynamicSafeArray
{
	
		int *data;
		int size;
	public:	
	 DynamicSafeArray()
	 {
	 	data=0;
	 	size=0;
	 }
	 DynamicSafeArray(int s)
	 {
	 	size=s;
	 	data=new int[s];
	 	memset(data,0,sizeof(int)*size);
	 }
	 
	  DynamicSafeArray (const  DynamicSafeArray &obj)
	  {
	  	  size=obj.size;
		  data=new int[size];
		  copy(obj.data,data+size,data);
	  	   
	}
	int &operator [](int i)const
	{
		
				return data[i];
		
	}

	DynamicSafeArray &operator =(const DynamicSafeArray &obj)
	{
	     if(this!=&obj)
		 {
		    delete []data;
		    data=new int[obj.size];
		    size=obj.size;
			
			copy(obj.data,data+size,data);
			return *this;
			 	
		}	
		else return *this;
	  	
	}
	
	void kquery(ifstream &outfile)
	{
		ofstream infile("output.txt");
		int i,j,k,n,count=0;
		outfile>>n;
	   for(int l=0;l<n;l++)
	   {
	   	  outfile>>i>>j>>k;
	   	  if(i<0||j>=size)
	   	  {
	   	     cout<<"\nInvalid query\n";
				exit(1);	
		  }
		  else if(data[l]==0)
		  {
		  	continue;		      //if our element is 0 query will be skipped
	      }
	     
		 for(int m=i;m<=j;m++)
		 {
		 	if(data[m]>k)
		 	{
		 	
		 	   count++;	
		 	}
		 	
		 }
		   
		  cout<<count<<endl;
		  infile<<count<<endl; 
		  count=0; 	
	   	
	    } 
		outfile.close();
		infile.close();	
		
	}
  friend ostream& operator <<(ostream&out,DynamicSafeArray &obj)
{

	
	  for(int i=0;i<obj.size;i++)
	  {
	  	 out<<obj.data[i]<<endl;
      }
      
    

	return out;
}

friend istream& operator >>(istream&in,DynamicSafeArray &obj)
{
	
	
	for(int i=0;i<obj.size;i++)
	 in>>obj.data[i];
	
	return in;
}
 
	
	~ DynamicSafeArray()
	{
	    if(data!=0)
		delete[]data;
		data=0;	
		
	}
	
	
	
};



int main()
{
    ifstream outfile("A1P3IO6.txt"); //input file
	int n;
	
	outfile>>n;
	DynamicSafeArray D1(n);
    outfile>>D1;
    D1.kquery(outfile);
    return 0;

	
}

