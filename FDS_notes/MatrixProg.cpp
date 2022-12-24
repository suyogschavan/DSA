#include<iostream>
using namespace std;

struct  Element
{
    /* data */
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse* &s){
    cout<<"Enter the Dimensions: ";
    cin>>s->m>>s->n;
    cout<<"Number of non-zero elements: ";
    cin>>s->num;

    s->ele=(struct Element *)malloc(s->num*(struct Element));
    cout<<"Enter the non-zero elements";
    for(int i=0; i<s->num;i++){
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
    }
}

void display(struct Sparse s)
{
    int i, j, k = 0;
    for (i=0; i<s->m; i++){
        for(j=0; j<s->n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                cout<<s.ele[k++].x;
            }else{
                cout<<"0";
            }
        }
            cout<<"\n";
    }
}

int main(){

    struct Sparse s;

    create(&s);
    display(s);
    return 0;
}