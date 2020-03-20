#include <iostream>

using namespace std;


struct recs{
    int k;
    char str[256];
} ;

int main()
{

    int num;
    cout<<"vvedite num"<< endl;
    cin>>num;
    cout<<endl;

    recs *arr = new recs[num];

    cin.getline(arr[0].str, 256);

    int i = num;
    while(i!=0){
        cout<<"vvedite "<<num-i+1<<" stroky:"<<endl;
        i--;
        cin.getline(arr[i].str, 256);
        cout<<endl;
    }

    cout<<endl<<"array: "<<endl;
    while(i!=num){
        cout<<arr[i].str<<endl;
        i++;
    }

    delete [] arr;

    return 0;
}
