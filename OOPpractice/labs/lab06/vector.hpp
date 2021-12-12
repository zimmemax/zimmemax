#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
template <class T>
class vector {
   private:
      T *v;
      int s;
      int capacity;
   public:
      vector(){
             s=0;
             v=NULL;
             capacity = s + 1;
      }
 
      ~vector(){
             delete [] v;
      }

      int size() {
             return s;
      }
      vector(vector<T> &other)
      {
        v = new T[other.size()];
        for(int i = 0; i < other.size(); i++)
        {
            v[i] = other.v[i];
        }
      }



      void operator=(vector<T> &other)
      {
        delete[] v;
        if(v != NULL){
            delete[] v;
        }
        v = new T[other.size()];
        for(int i = 0; i < other.size(); i++)
        {
            v[i] = other.v[i];
        }
        
      }

      void push_back(T ele) {
             T *temp;
             temp = new T[capacity+1];
             if(s >= capacity)
             {
                 resize();
             }
             for(int i=0; i<s; i++)
                temp[i]=v[i];
             delete [] v;
             s++;
             capacity++;
             v = temp;
             
      }
      T& operator[](int index)
      {
          return v[index];
      } //Only performs address arithmetic
      T& at(int index)
      {
        if(s > index)
        {
            return v[index];
        }
        else
        {
            return v[0];
        }
      }
      
    void print_array()
    {
        for(int i = 0; i < s; i++)
        {
            cout << v[i] << "  ";
        }
    }

    void resize(int size)
    {
        T temp* = new T[s];
        for(int i = 0; i < capacity; i++)
        {
            temp_array[i] = v[i];
        }

        delete[] v;
        v=temp_array;

    }

    int get_capacity()
    {
        return capacity;
    }
};