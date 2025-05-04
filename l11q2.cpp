    //Quadratic probing

    #include<iostream>
    #define tsize 10

    class hash{
        private:
            int hasht[tsize];
        public:
            hash(){
                for(int i=0;i<tsize;i++){
                    hasht[i]=-1;
                }
            }
            
            //Hash function
            int hashf(int key){
                return key % tsize;
            }

            //Function to insert
            int insert(int key){
                int i=1,index;
                index=hashf(key);
                int index_ori=index;

                while(hasht[index]!=-1 && hasht[index]!=-2){
                    index=(index_ori + i*i) % tsize;
                    if(index==index_ori){
                        printf("Hash table is full!\n");
                        return 0;
                    }
                    i++;
                }

                hasht[index]=key;
                printf("Successfull!\n");
                return 1;

            }

            int del_h(int key){
                int i=1,index;
                index=hashf(key);
                int index_ori=index;

                while(hasht[index]!=-1){
                    
                    if(hasht[index]==key){
                        hasht[index]=-2;
                        printf("Deleted!\n");
                        return 1;
                    }
                    i++;
                    index=(index_ori + i*i) % tsize;
                }

                printf("Not found!\n");
                return 0;
            }

            int search(int key){
                int i=1,index;
                index=hashf(key);
                int index_ori=index;

                while(hasht[index]!=-1){
                    
                    if(hasht[index]==key){
                        
                        printf("Found!\n");
                        return 1;
                    }
                    i++;
                    index=(index_ori + i*i) % tsize;
                }

                printf("Not found!\n");
                return 0;
            }
            //Function to display
            void display(){
                int i=0,flag=0;
                for(i;i<tsize;i++){
                    if(hasht[i]!=-1){
                        flag=1;
                        break;
                    }
                }

                if(flag!=1){
                    printf("Hash table is empty!\n");
                    return;
                }
                else{
                    for(i=0;i<tsize;i++){
                        if(hasht[i]==-1){
                            printf("Empty ");
                        }
                        else if(hasht[i]==-2){
                            printf("Deleted ");
                        }
                        else{
                            printf("%d ",hasht[i]);
                        }
                    }
                    return;
                }
            }
                    
                    
                
    };


    int main(){
        hash ht;
        int choice,key;
        while(1){
            printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice){
                case 1:
                    printf("Enter the key to be inserted: ");
                    scanf("%d",&key);
                    ht.insert(key);
                    break;
                case 2:
                    printf("Enter the key to be  deleted: ");
                    scanf("%d",&key);
                    ht.del_h(key);
                    break;
                case 3:
                    ht.display();
                    break;
                case 4:
                    printf("Enter the key to be  searched: ");
                    scanf("%d",&key);
                    ht.search(key);
                    break;
                case 5:
                    printf("Exited!\n");
                    return 0;
                    break;
                    
                default:
                    printf("Enter valid choice!\n");
                    break;
            }
        }
        return 0;
    }