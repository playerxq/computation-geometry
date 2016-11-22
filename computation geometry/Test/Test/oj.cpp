#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int stoi(string s){

int  num = 0;
for (int i =0; i<s.size(); i++)
	num = num * 10 + s[i]-'0';
return num;


}

struct DATA{
    int id;
    int time;
    DATA(int id, int time) :id(id), time(time){}
};

int main(){
    string line;
    while (getline(cin, line)){
        int pos = 0;
        string sub;
        list<DATA> mylist;
        do {
            if ((pos = line.find(':')) != -1){
                sub = line.substr(0, pos);
                if (sub == "starttimer"){
                    int last = pos + 1;
                    pos = line.find(',');
                    int id = stoi(line.substr(last, pos - last));
                    int time = stoi(line.substr(pos + 1));
                    mylist.push_back(DATA(id, time));
                }
                else if (sub == "stoptimer"){
                    int id = stoi(line.substr(pos + 1));
                    list<DATA>::iterator iter = mylist.begin();
                    while(iter != mylist.end()){
                        if (iter->id == id){
                            list<DATA>::iterator next = ++iter;
                            --iter;
                            mylist.erase(iter);
                            iter = next;
                        }
                        else
                            iter++;
                    }
                }
                else{
                    int time = stoi(line.substr(pos + 1));
                    list<DATA>::iterator iter = mylist.begin();
                    while (iter != mylist.end()){
                        if (iter->time <= time){
                            list<DATA>::iterator next = ++iter;
                            --iter;
                            mylist.erase(iter);
                            iter = next;
                        }
                        else{
                            iter->time -= time;
                            iter++;
                        }

                    }
                }
            }
            else
                break;
        } while (getline(cin, line));

        // output
        list<DATA>::iterator iter = mylist.begin();
        if (iter != mylist.end()){
            while (iter != mylist.end()){
                cout << "timer:" << iter->id << "," << iter->time << endl;
                iter++;
            }
        }
        else{
            cout << "none" << endl;
        }

    }

    return 0;
}