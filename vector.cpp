#include <iostream>

using namespace std ;



class vector{
  
    private : 
    
    // next insert location
    int curr_pointer = 0 ;

    // current capacity 
    int max_capacity = 1 ;
  
    // the array to hold data 
    int *arr ;
    
    // to allocate the space 
    void allocate_the_array(){
        int *new_arr = new int[max_capacity] ;
        for(int i = 0 ; i<curr_pointer ; i++ ){
            new_arr[i] = arr[i] ;
        }
        for(int i = curr_pointer ; i<max_capacity ; i++ ){
            new_arr[i] = 0 ;
        }
        arr = new_arr ;
    }
  
    void expand_the_array( int size_to_fit ){
        while(max_capacity < size_to_fit  ){
            max_capacity*=2 ;
        } 
    }
    
    //public methods start here 

    public : 
    
    // constructor 1 - empty vector 
    vector(){
        allocate_the_array() ;
    }
    
    // constructor 2 - vector of gives size 
    vector( int given_size ){
        
        expand_the_array(given_size) ;
        allocate_the_array() ;

        curr_pointer = given_size ; 
    }
    
    int size(){
        return curr_pointer ;
    }
    
    void push_back( int data ){

        if(curr_pointer==max_capacity){
            expand_the_array(curr_pointer+1) ;
            allocate_the_array(); 
        }

        arr[curr_pointer] = data ; 
        curr_pointer++;
    }
  
    void pop_back( ){
        if(curr_pointer>0){
            arr[curr_pointer]=0;
            curr_pointer--;
        }
    }
  
    int & operator[]( int idx ){
        if(idx<curr_pointer){
            return arr[idx] ;
        } 
        else{ 
            int *k = new int(-1) ;
            // int k = -1 ;
            return (*k) ;
        }
    }
    // or konsi chiz chahiye vector ki
  // basyehi hota h sab

};

int main()
{
    cout<<"hello" << endl ;

    vector vec(4) ;

    for(int i = 0 ; i<1000000; i++ ){
        vec.push_back(i) ;
    }

    cout << vec.size() << endl ;
    for(int i = 0; i<vec.size() ; i++ ){
        cout << vec[i] << " " ;
    }
    cout << endl ;

    return 0;
}
