#include <iostream>

class areas{
    
    private: 
        int* length=(int*)malloc(sizeof(int)); 
        int* breadth=(int*)malloc(sizeof(int));
    
    public:
        areas(){
            *length=1,*breadth=1;
        }
            void setlength(int*l)
            {
                *length=*l;
            }
            void setbreadth(int*b)
            {
                *breadth=*b;
            }
            int areasq(){
                int*area=(int*)malloc(sizeof(int));
                *area=(*length)*(*length);
                return *area;
            }
            int arearec(){
                int*area=(int*)malloc(sizeof(int)); 
                *area=(*length)*(*breadth);
                return *area;
            }
            int areacube(){
                int*area=(int*)malloc(sizeof(int)); 
                *area=6*(*length)*(*length);
                return *area;
            }
            int areacuboid(){
                int*area=(int*)malloc(sizeof(int)); 
                *area=(4*(*length)*(*breadth))+(2*(*length)*(*length));
                return *area;
            }
            
};