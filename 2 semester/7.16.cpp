#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <cstdlib>


using namespace std;

int main(){

    int n;
    setlocale(LC_CTYPE, "rus");
    cout<<"введите кол-во строк"<<endl;
    cin>>n;
    string s;

    // 1 пункт

    fstream file;
    file.open ("file_1.txt", ios_base::out);
    if (!file) {
        cout<< "Error opening file" << endl;
        exit(1);
    }


    cin.get();
    for(int i=0; i<n; i++){
        getline(cin, s);
        file<<s<<endl;
    }
    file.close();


    //2-4 пункты

    fstream ifile;
    file.open("file_2.txt", ios_base::out);
    ifile.open ("file_1.txt", ios_base::in);
    if (!ifile) {
        cerr << "Error opening ifile" << endl;
        exit(1);
    }
    if (!file) {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    char q;
    while (getline(ifile, s)) {
        file << s <<endl;
    }

    ifile.close();
    ifile.open("file_1.txt", ios_base::in);
    cout<<endl<<endl;
    int k=0;
    while((q=char(ifile.get()))!=EOF){
        cout<<q;
        k++;
    }

    if (!ifile.eof ()) {
        cerr << "Error reading ifile" << endl;
        exit(1);
    }

    file.close();
    ifile.close();


    // 5-6 пункты

    ifile.open("file_2.txt", ios_base::in | ios_base::ate | ios_base::out );
    if (!ifile) {
        cout<< "Error opening file" << endl;
        exit(1);
    }
    char q5, q8;
    ifile.seekg(4, ios_base::beg);
    ifile.read((char*)(&q5), 1);
    cout<<endl<<"q5="<<q5;
    ifile.seekg((k-9), ios_base::beg);
    ifile.read((char*)(&q8), 1);
    cout<<endl<<"q8="<<q8;

    ifile.seekg(4, ios_base::beg);
    ifile<<q8;
    ifile.seekg((k-9), ios_base::beg);
    ifile<<q5;

    // 7 пункт
    cout<<endl<<endl<<"размер файла: "<<k-1<<endl;
    ifile.close();

    return 0;
}
