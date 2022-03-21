#include<iostream>
#include<time.h>
#include<fstream>
#include<cstdlib>
#include<string>
#include <chrono>
#include<vector>


using namespace std;
using namespace std::chrono;

class A{
	public:
		void generate_rand(string name,int N)
		{
			ofstream Myfile;
			Myfile.open(name);
			srand(time(0));
			for(int i=0;i<N;i++)
			{
				Myfile<<rand()<<endl;
				
			}
			Myfile.close();
		}
		
		
		
		float insertion(string name,int N)
		{
			auto start = high_resolution_clock::now();
			int k=0;
		    fstream Myfile;
	        int *arr=new int[N];
            Myfile.open(name);
            if(Myfile.is_open())
            {
                while(Myfile>>arr[k])
                {
			      k++;
			
	            }
                Myfile.close();
            }
	else{
		cout<<"FILE DOESNOT OPEN"<<endl;
	}
            int current, j, c = 0;
            for(int i=0;i<N;i++)
            {
               	current =arr[i];
                j=i-1;
	            while(arr[j]>current && j>=0)
                  	{
	                    c++;
	                    arr[j+1]=arr[j];
	                    j--;
                   	}
                	arr[j+1]=current;
                }
            Edit_file(arr,name,N);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration=duration/1000;
            return duration.count();

		}
		void print(int arr[],int N)
		{
			for(int i=0;i<N;i++)
			{
				cout<<arr[i]<<endl;
			}
		}
		void Edit_file(int arr[],string name,int N)
		{
		
			ofstream Myfile1;
			Myfile1.open(name);
			for(int i=0;i<N;i++)
			{
				Myfile1<<arr[i]<<endl;
			}
			Myfile1.close();
		}
		
		void swapping(int &a, int &b) {     //swap the content of a and b
            int temp;
            temp = a;
             a = b;
             b = temp;
        }


       void merge(int *array, int l, int m, int r) {
         int i, j, k, nl, nr;
          nl = m-l+1; nr = r-m;
          int larr[nl], rarr[nr];
   
       for(i = 0; i<nl; i++)
         larr[i] = array[l+i];
      for(j = 0; j<nr; j++)
         rarr[j] = array[m+1+j];
       i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}

int merge_Sort(string name,int l, int r, int N)
{
	int k=0;
		    fstream Myfile;
	        int *arr=new int[N];
            Myfile.open(name);
            auto start = high_resolution_clock::now();
            if(Myfile.is_open())
            {
                while(Myfile>>arr[k])
                {
			      k++;
			
	            }
                Myfile.close();
            }
            
            mergeSort(arr,l,r,N);
            Edit_file(arr,name,N);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration=duration/1000;
            return duration.count();
}
void mergeSort(int arr[], int l, int r,int N ) {
	
		
    int m = 0;
   if(l < r) {
      int m = l+(r-l)/2;
      
      mergeSort(arr, l, m, N);
      mergeSort(arr, m+1, r,N);
      merge(arr, l, m, r);
      
   }
}
int quick_mid(string name,int N)
{
	int k=0;
		    fstream Myfile;
	        int *arr=new int[N];
            Myfile.open(name);
            auto start = high_resolution_clock::now();
            if(Myfile.is_open())
            {
                while(Myfile>>arr[k])
                {
			      k++;
			
	            }
                Myfile.close();
            }
            
            quickSort_MID(arr, 0, N - 1); 
            Edit_file(arr,name,N);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration=duration/1000;
            return duration.count();
}
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
   

void quickSort_MID(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
         
        int pivot = partition(arr, low, high); 
   
        
        quickSort_MID(arr, low, pivot - 1); 
        quickSort_MID(arr, pivot + 1, high); 
    } 
} 
int partition_r(int arr[], int low, int high)
{
    
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}
 

void quickSort_rand(int arr[], int low, int high)
{
    if (low < high) {
 
        
        int pi = partition_r(arr, low, high);
 
       
        quickSort_rand(arr, low, pi - 1);
        quickSort_rand(arr, pi + 1, high);
    }
}
int quick_rand(string name,int N)
{
	int k=0;
		    fstream Myfile;
	        int *arr=new int[N];
            Myfile.open(name);
            auto start = high_resolution_clock::now();
            if(Myfile.is_open())
            {
                while(Myfile>>arr[k])
                {
			      k++;
			
	            }
                Myfile.close();
            }
            quickSort_rand(arr,0,N-1);
            Edit_file(arr,name,N);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration=duration/1000;
            return duration.count();
}
int partition_pivot_last(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1);
 
	for (int j = low; j < high; j++) {
		if (array[j] < pivot) {
		swap(array[++i], array[j]);
		}
	}
 
	swap(array[i + 1], array[high]);
	return (i + 1);
}
int partition_pivot_median(int array[], int low, int high) {
	
	int pivot;
	int mid = (low + high) / 2;
	if (array[mid] < array[low]) 
		swap(array[mid], array[low]);
	if (array[high] < array[low])
		swap(array[high], array[low]);
	if (array[high] < array[mid])
		swap(array[high], array[mid]);
	swap(array[mid], array[high-1]);
	
	pivot = array[high-1];
 
	return partition_pivot_last(array, low, high);
}
 
void quickSort_MED(int array[], int low, int high) {	
	if (low < high) {
		
		int pi = partition_pivot_median(array, low, high);
 
		
		quickSort_MED(array, low, pi - 1);
		quickSort_MED(array, pi + 1, high);
	}
}

int quick_median(string name,int N)
{
	int k=0;
		    fstream Myfile;
	        int *arr=new int[N];
            Myfile.open(name);
            auto start = high_resolution_clock::now();
            if(Myfile.is_open())
            {
                while(Myfile>>arr[k])
                {
			      k++;
			
	            }
                Myfile.close();
            }
            quickSort_MED(arr,0,N-1);
            Edit_file(arr,name,N);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration=duration/1000;
            return duration.count();
}

int Quick_Updated_Median(string name,int N)
{
	int k=0;
		    fstream Myfile;
	        int *arr=new int[N];
            Myfile.open(name);
            auto start = high_resolution_clock::now();
            if(Myfile.is_open())
            {
                while(Myfile>>arr[k])
                {
			      k++;
			
	            }
                Myfile.close();
            }
            quickSort_MED(arr,0,N-1);
            Edit_file(arr,name,N);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration=duration/1000;
            return duration.count();
}

void print_graph(int arr[],string name,int N)
{
	int i=0;
	ofstream Myfile;
	Myfile.open(name);
	if(Myfile.is_open())
	{
		for(int i=0;i<6;i++)
		{
			Myfile<<arr[i]<<endl;
		}
		
	}
}
	
};

int main()
{
	A a;
	int arr[10],arr1[10],arr2[10],arr3[10],arr4[10],arr5[10],arr6[10];
	
	cout<<"*****SORTING FOR 50 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random50.txt",50);
	cout<<"TIME TAKEN FOR INSERTION IS   "<<a.insertion("Random50.txt",50)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR MERGE IS       "<<a.merge_Sort("Random50.txt",0,50-1,50)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 1 IS     "<<a.quick_rand("Random50.txt",50)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 2 IS     "<<a.quick_median("Random50.txt",50)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 3 IS     "<<a.quick_mid("Random50.txt",50)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 4 IS     "<<a.Quick_Updated_Median("Random50.txt",50)<<" sec"<<endl;
	
	cout<<endl<<"*****SORTING FOR 100 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random100.txt",100);
	cout<<"TIME TAKEN FOR INSERTION IS "<<a.insertion("Random100.txt",100)<<" sec"<<endl;;
	cout<<"TIME TAKEN FOR MERSGE  IS   "<<a.merge_Sort("Random100.txt",0,100-1,100)<<" sec"<<endl;;
	cout<<"TIME TAKEN FOR QUICK 1 IS   "<<a.quick_rand("Random100.txt",100)<<" sec"<<endl;;
	cout<<"TIME TAKEN FOR QUICK 2 IS   "<<a.quick_median("Random100.txt",100)<<" sec"<<endl;;
	cout<<"TIME TAKEN FOR QUICK 3 IS   "<<a.quick_mid("Random100.txt",100)<<" sec"<<endl;;
	cout<<"TIME TAKEN FOR QUICK 4 IS   "<<a.Quick_Updated_Median("Random100.txt",100)<<" sec"<<endl;
	
	cout<<endl<<"*****SORTING FOR 200 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random200.txt",200);
	cout<<"TIME TAKEN FOR INSERTION IS "<<a.insertion("Random200.txt",200)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR MERGE IS     "<<a.merge_Sort("Random200.txt",0,200-1,200)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 1 IS   "<<a.quick_rand("Random200.txt",200)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 2 IS   "<<a.quick_median("Random200.txt",200)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 3 IS   "<<a.quick_mid("Random200.txt",200)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 4 IS   "<<a.Quick_Updated_Median("Random200.txt",200)<<" sec"<<endl;
	
	cout<<endl<<"*****SORTING FOR 300 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random300.txt",300);
	cout<<"TIME TAKEN FOR INSERTION IS "<<a.insertion("Random300.txt",300)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR MERGE IS     "<<a.merge_Sort("Random300.txt",0,300-1,300)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 1 IS   "<<a.quick_rand("Random300.txt",300)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 2 IS   "<<a.quick_median("Random300.txt",300)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 3 IS   "<<a.quick_mid("Random300.txt",300)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 4 IS   "<<a.Quick_Updated_Median("Random300.txt",300)<<" sec"<<endl;
	
		cout<<endl<<"*****SORTING FOR 400 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random400.txt",400);
	cout<<"TIME TAKEN FOR INSERTION IS "<<a.insertion("Random400.txt",400)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR MERGE IS     "<<a.merge_Sort("Random400.txt",0,400-1,400)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 1 IS   "<<a.quick_rand("Random400.txt",400)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 2 IS   "<<a.quick_median("Random400.txt",400)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 3 IS   "<<a.quick_mid("Random400.txt",400)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 4 IS   "<<a.Quick_Updated_Median("Random400.txt",400)<<" sec"<<endl;
	
	cout<<endl<<"*****SORTING FOR 500 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random500.txt",500);
	cout<<"TIME TAKEN FOR INSERTION IS "<<a.insertion("Random500.txt",500)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR MERGE IS     "<<a.merge_Sort("Random500.txt",0,500-1,500)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 1 IS   "<<a.quick_rand("Random500.txt",500)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 2 IS   "<<a.quick_median("Random500.txt",500)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 3 IS   "<<a.quick_mid("Random500.txt",500)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 4 IS   "<<a.Quick_Updated_Median("Random500.txt",500)<<" sec"<<endl;
	
		cout<<endl<<"*****SORTING FOR 1000 RANDOM NUMBERS*****"<<endl<<endl;
	a.generate_rand("Random1000.txt",1000);
	cout<<"TIME TAKEN FOR INSERTION IS "<<a.insertion("Random1000.txt",1000)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR MERGE IS     "<<a.merge_Sort("Random500.txt",0,1000-1,1000)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 1 IS   "<<a.quick_rand("Random1000.txt",1000)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 2 IS   "<<a.quick_median("Random1000.txt",1000)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 3 IS   "<<a.quick_mid("Random1000.txt",1000)<<" sec"<<endl;
	cout<<"TIME TAKEN FOR QUICK 4 IS   "<<a.Quick_Updated_Median("Random1000.txt",1000)<<" sec"<<endl;
	

	
}
