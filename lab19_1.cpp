#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream file("name_score.txt");
    string textline;
    char name[60];
    int a,b,c;
    while (getline(file,textline)){ 
        char format[]="%[^:]: %d %d %d";
        sscanf(textline.c_str(),format,name,&a,&b,&c);
        names.push_back(name);
        int score = a+b+c;
        scores.push_back(score);
        grades.push_back(score2grade(score));
    }
    file.close();
}

void getCommand(string &command,string &key){
    string text;
    char x[100];
    char y[100];
    char format[] = "%s %[^\n]";
    cout<<"Please input your command: ";
    getline(cin,text);
    sscanf(text.c_str(),format,x,y);
    command=x;
    key=y;
}

void searchName(vector<string> &names,vector<int> &scores,vector<char> &grades,string key){
    int x=0;
    cout << "---------------------------------"<<endl;
for (unsigned int i=0; i< names.size(); i++){
    if (key == toUpperStr(names[i])){
        cout << names[i] << "'s "<< "score = " << scores[i] << endl;
        cout << names[i] << "'s "<< "grade = " << grades[i] << endl;
        x++;
    }
}
    if(x ==0 ) {
        cout << "Cannot found."<<endl;
    }
    cout << "---------------------------------"<< endl;
}


void searchGrade(vector<string> &names,vector<int> &scores,vector<char> &grades,string key){
    int x =0;
    cout << "---------------------------------"<<endl;
for (unsigned int i=0; i<grades.size(); i++){
    if(key[0] == grades[i]){
        cout << names[i] << " (" << scores[i] << ")" << endl;
        x++;
    }
}
    if(x==0){
        cout << "Cannot found."<<endl;
    }
    cout << "---------------------------------"<< endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
