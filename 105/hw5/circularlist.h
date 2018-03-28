
struct node{
    int coefficient, index;
    node* next;
};

class CircularList{
public:

    CircularList(){
        head=new node;
        head->next=head;
        head->coefficient=0;
        head->index=-1;
        cur=head;
        back=head;
        sizes=1;
    }

    void edit_coefficient(int cof){
        cur->coefficient=cof;
    }

    void edit_index(int dex){
        cur->index=dex;
    }

    void push(int cof, int dex){
        back->next=new node;
        back=back->next;
        back->coefficient=cof;
        back->index=dex;
        back->next=head;
        sizes++;
    }

    void next(){
        cur=cur->next;
    }

    void reset_current(){
        cur=head;
    }

    int get_coefficient(){
        return cur->coefficient;
    }

    int get_index(){
        return cur->index;
    }

    int size(){
        return sizes;
    }

    CircularList operator=(CircularList a){

    }

    CircularList operator+(int a){
        node *tmp=head;

        do{
            if(tmp->index==0){
                tmp->coefficient++;
            }

            tmp=tmp->next;
        }while(tmp!=head);
    }

private:
    node *head;
    node *back;
    node *cur;
    int sizes; 
};
