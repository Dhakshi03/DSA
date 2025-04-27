#include <iostream>
#include "l2q2classes.cpp"

/**
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
*/

int main()
{   
    int*choice=(int*)malloc(sizeof(int));
    while(1)
    {
        printf("\nCALCULATING THE AREA");
        printf("\n1.Square\n2.Rectangle\n3.Cube\n4.Cuboid\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",choice);
        
        int* len=(int*)malloc(sizeof(int));
        int* bre=(int*)malloc(sizeof(int));
        switch(*choice)
        {
            case 1:
            {
                //Area of square
                printf("\nEnter side length of square: ");
                scanf("%d",len);
                areas square;
                square.setlength(len);
                printf("\nArea of the square of side lenght %d is %d\n",*len, square.areasq());
                break;
            } 
            
            case 2:
            {
                //Area of rectangle
                printf("\nEnter side length of rectangle: ");
                scanf("%d",len);
                printf("\nEnter side breadth of rectangle: ");
                scanf("%d",bre);
                areas rect;
                rect.setlength(len);
                rect.setbreadth(bre);
                printf("\nArea of the rectangle of side lenght %d and breadth %d is %d\n",*len, *bre, rect.arearec());
                break;
            }
            
            case 3:
            {
                //Area of cube
                printf("\nEnter side length of cube: ");
                scanf("%d",len);
                areas cube;
                cube.setlength(len);
                printf("\nArea of the cube of side lenght %d is %d\n",*len, cube.areacube());
                break;
            }
            
            case 4:
            {
                //Area of cuboid
                printf("\nEnter side length of cuboid: ");
                scanf("%d",len);
                printf("\nEnter side breadth of cuboid: ");
                scanf("%d",bre);
                areas cuboid;
                cuboid.setlength(len);
                cuboid.setbreadth(bre);
                printf("\nArea of the cuboid of side length %d and breadth %d is %d\n",*len, *bre, cuboid.areacuboid());
                break;
            }
            
            case 5:
            {
                //Exit
                exit(0);
            }
        }
    }
    
    return 0;
    
}