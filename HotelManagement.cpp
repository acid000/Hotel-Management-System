#include<bits/stdc++.h>
using namespace std;
// global variable 
// no of rooms 
int rooms=10;
int t=1;
int tt=1;
int logged=0;

// we will store a unique id against each name 
unordered_map<int,string>uid;

int random_number=0;
// vector of pair which stores food items and its price
vector<pair<string,int>>items;

// rooms and their owner list
unordered_map<string,int>m;

// rooms that are already visited/booked
vector<bool>visited(10,0);

// map to store ownwer and their booked items
unordered_map<string,vector<pair<string,int>>>ilist;

void login(int id){
    if(uid.count(id)){
         cout<<"successfully logged in"<<"\n\n";
        logged=1;
        t=0;
    }
    else{
        cout<<"wrong credential "<<"\n\n";
        logged =0;
        t=1;
    }
}
void signup(string name){
    int a=0;
     for(int i=0;i<name.size();i++){
       a=a*10+int(name[i]);
     }
     a=a*10+random_number;
     random_number++;
     uid.insert({a,name});
      cout<<"signup completed"<<"\n\n";
      cout<<"Your unique id is "<<a<<"\n";
      login(a);
    
}
void forgot(){
    cout<<"Enter Your name "<<"\n";
    string name;
    cout<<"\n";
    cin>>name;
    int checker=0;
    for(auto i:uid){
        if(i.second==name){
            checker=1;
            cout<<"we have found your previous details\n\n";
            cout<<"your unique id is"<<i.first<<"\n\n";
            break;
        }
    }
    if(checker==0){
        cout<<"sorry wrong credentials"<<"\n\n";
    }
}
void auth(){
    while(t){
    cout<<"\t\t\t\t\t_______________________\t\t\t\t\t"<<"\n\n\n";
    cout<<"\t\t\t\t\t"<<"WELCOME TO TAJ"<<"\t\t\t\t\t"<<"\n\n";
    cout<<"\t\t\t\t\t"<<"Press 1 for LOGIN"<<"\n\n";
    cout<<"\t\t\t\t\t"<<"Press 2 for SIGNUP"<<"\n\n";
    cout<<"\t\t\t\t\t"<<"Press 3 for FORGOT PASSWORD"<<"\n\n\n";
    cout<<"\t\t\t\t\t_______________________\t\t\t\t\t"<<"\n\n\n";
   while(tt){
   int press;
   cin>>press;
   cout<<"\n";
   if(press==1){
    cout<<"enter your unique id"<<"\n\n";
    int id;
    cin>>id;
    login(id);
    break;
   }
   else if(press==2){
    cout<<"plz enter your name "<<"\n\n";
    string name;
    cin>>name;
       signup(name);
        t=0;
    break;
       
   }
   else if(press==3){
         forgot();
        t=0;
    break;
   }
   }
    }
}
void administrator(){
    cout<<"\t\t\t\t\t\t Enter 1 for editing the food items \n";
    int choices;
    cin>>choices;
    
    if(choices==1){
            cout<<"\t\t\t\t\t\t enter the item name and it's price"<<"\n\n";
            string iname;
            int price;
            cin>>iname>>price;
            // searching food in item list
            int checker=0;
            for(auto i:items){
                if(i.first==iname){
                    checker++;
                    i.second=price;
                     cout<<"\t\t\t\t\t\t item already present in the menu ,price has been updated"<<"\n\n";
                    break;
                }
            }
            if(checker==0){
                items.push_back({iname,price});
                cout<<"\t\t\t\t\t\t item added successfully"<<"\n";
            }
        }
        else {
            cout<<"bad choice "<<"\n";
        }   
    

}

void roomBooking(){
    cout<<"plz enter the number of rooms you want to book"<<"\n\n";
    int nrm;
    cin>>nrm;
    cout<<"checking for available rooms"<<"\n\n";
    int cnt=0;
    string s="";
    for(int i=0;i<10;i++){
        if(visited[i]==false){
            cnt++;
            s=s+to_string(i);
            if(cnt==nrm){
                cout<<"rooms are available "<<"\n\n";
                //s="";
                break;
            }
        }
    }
    if(cnt!=nrm){
        cout<<"sorry rooms are not available"<<"\n\n";
        s="";
    }
    else{
        cout<<"plz enter your unique id"<<"\n\n";
        int id;
        cin>>id;
        if(uid.count(id)){
            cout<<"Hi "<<uid[id]<<"\n\n";
            if(m.count(uid[id])){
                int allready_booked_room=m[uid[id]];
                m.insert({uid[id],nrm+allready_booked_room});
            }
            else{
            m.insert({uid[id],nrm});
            }
            for(int i=0;i<s.size();i++){
                visited[s[i]-'0']=true;
            }
            cout<<"congrats rooms has been allocated"<<"\n\n";
        }
        else{
            cout<<"You have enter a wrong id...try again"<<"\n\n";
        }
     
    }
}
void bookingdetails(){
    cout<<"plz enter your unique id"<<"\n\n";
    int id;
    cin>>id;
    int ch=0;
    if(uid.count(id)){
    
    for(auto i:m){
        if(i.first==uid[id]){
            ch++;
            cout<<"your name is "<<i.first<<" "<<"and you have "<<i.second<<" "<<"rooms booked"<<"\n\n";
            break;
        }
    }
    }
    if(ch==0){
        cout<<"sorry wrong credential"<<"\n\n";
    }
}
void orderfood(){
    cout<<"plz enter your unique id"<<"\n\n";
    int id;
    cin>>id;
    if(m.count(uid[id])){
        cout<<" your order will be delivered to your room"<<"\n\n";
        cout<<" plz order sir"<<"\n\n";
        cout<<"right now we have following items in menu"<<"\n\n";
        for(auto i:items){
            cout<<i.first<<"\n\n";
        }
        cout<<"\n\n\n";
        string iname;
        cout<<"enter item name"<<"\n\n";
        cin>>iname;
        cout<<"enter quantity"<<"\n\n";
        int quantity;
        cin>>quantity;
        cout<<"Your order has been placed"<<"\n\n";
        ilist[uid[id]].push_back({iname,quantity});
        

    }
    else{
        cout<<"plz wait we are making your order"<<"\n\n";
        
        cout<<"right now we have following items in menu"<<"\n\n";
        for(auto i:items){
            cout<<i.first<<"\n";
        }
        cout<<"enter the item name"<<"\n\n";
        string iname;
        cin>>iname;
        cout<<"enter quantity"<<"\n\n";
        int quantity;
        cin>>quantity;
        ilist[uid[id]].push_back({iname,quantity});
        cout<<"your order has been placed"<<"\n\n";
    }
}
void orderdetails(){
     cout<<"plz enter your unique id"<<"\n\n";
    int id;
    cin>>id;
    cout<<"\n\n";
    cout<<"wait a minute checking for order details..."<<"\n\n";
    int ch=0;
    for(auto i:ilist){
        if(i.first==uid[id]){
            ch++;
            cout<<"hi sir there are following orders on your name->"<<"\n\n";
            for(auto j:i.second){
                cout<<j.first<<"->"<<j.second<<"\n";
            }
            cout<<"\n\n";
            cout<<"your total bill is RS-> ";
            int sum=0;
            for(auto q:items){
                for(auto k:i.second){
                    if(q.first==k.first){
                        sum=sum+k.second*q.second;
                    }
                }
            }
            cout<<sum<<"\n\n";
            break;
        }
    }
    if(ch==0){
        cout<<"sorry sir there is no order on your name"<<"\n\n\n";
    }
}
int main(){
    // manually adding data

    items.push_back({"chai",50});
    items.push_back({"burger",100});
    items.push_back({"pizza",300});
    items.push_back({"butter chicken",120});
    while(true){
     auth();
    while(logged){
    cout<<"\t\t\t\t\t\t enter 1 if you are administrator "<<"\n\n";
    cout<<"\t\t\t\t\t\t enter 2 for booking "<<"\n\n";
    cout<<"\t\t\t\t\t\t enter 3 for room details "<<"\n\n";
    cout<<"\t\t\t\t\t\t enter 4 for orderfood "<<"\n\n";
    cout<<"\t\t\t\t\t\t enter 5 for order details "<<"\n\n";
    cout<<"\t\t\t\t\t\t enter 6 for logout"<<"\n\n";
    int c;
    cin>>c;
    int x=1;
   while(x){
        if(c==1){
            administrator();
            x=0;
        }
        else if(c==2){
            roomBooking();
            x=0;
            
        }
        else if(c==3){
            bookingdetails();
            x=0;
        }
        else if(c==4){
            orderfood();
            x=0;
        }
         else if(c==5){
             orderdetails();
             x=0;
        }
        else {
            cout<<"make sure You have Checked Out"<<"\n\n";
            logged=0;
            t=1;
            tt=1;
            break;
        }
    }
    }
    }
}