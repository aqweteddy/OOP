#include "circularlist"

class Polinomial{
public:
    Polinomial(int poli[], int size){
        set(poli, size);
    }

    Polinomial(Polinomial& copy){
        data=copy.data;
    }


    Polinomial(CircularList c){
        data=c;
    }

    void set(int poli[], int size){
        for(int i=0; i<size-2; i+=2){
            data.push(poli[i], poli[i+1]);
        }
    }

    void get(int poli[], int size){
        data.reset_current();

        for(int i=0; i<size-2; i++){
            data.next();
            poli[i]=data.get_coefficient();
            poli[i+1]=data.get_index();
        }

        poli[size-1]=-1;
        poli[size-2]=0;
    }

    Polinomial operator+(const Polinomial &a){
        Polinomial ans=Polinomial(data);
        msize=max(data.size(), a.size())-1;
        return ans;
    }

private:
    data=CircularList();

}
