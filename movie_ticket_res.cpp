#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
#define FOR(i,a,b) for(ll i = a;i<b;++i)
#define pb push_back
vector< pair<string, vector<vll > > > v;

bool is_aisle(ll num, vll vec){
    vll::iterator it;
    it = find(vec.begin(),vec.end(),num);
    if(it!=vec.end())return true;
    else return false;
}

void disp(vll v){
    for(ll i=0;i<v.size();++i){
        if(i!=v.size()-1)cout<<v[i]<<" ";
        else cout<<v[i];
    }
}

void add_screen(vs str){
    
    
    ll v_len = v.size();
    bool flag = false;
    FOR(i,0,v_len){
        if(v[i].first==str[1]){
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<"failure"<<endl;
        return;
    }
    ll len = str.size();
    //cout<<"length of str"<<len<<"    ";
    vll aisle;
    FOR(i,4,len){
        aisle.pb(stoll(str[i])-1);
    }
    string name = str[1];
    pair<string, vector<vll > > p;
    vector<vll > mat;
    p.first = name;
    ll rows = stoll(str[2]);
    ll cols = stoll(str[3]);
    FOR(i,0,rows){
        vll row;
        FOR(j,0,cols){
            if(is_aisle(j,aisle))row.pb(2);
            else row.pb(0);
        }
        mat.pb(row);
    }
    p.second = mat;
    v.pb(p);
    //disp(aisle);
    cout<<"success"<<endl;
    return;
}

void reserve_seat(vs str){
    ll v_len = v.size(),index = 0;
    bool flag = false;
    FOR(i,0,v_len){
        if(v[i].first==str[1]){
            flag = true;
            index = i;
            break;
        }
    }
    if(flag==false){
        cout<<"failure"<<endl;
        return;
    }
    ll len = str.size();
    vector<vll > screen = v[index].second;
    ll row = stoll(str[2]) - 1;
    vll  res_col;
    FOR(i,3,len){
        res_col.pb(stoll(str[i])-1);
    }
    flag = true;
    FOR(i,0,res_col.size()){
        if(screen[row][res_col[i]]==1||screen[row][res_col[i]]==3){
            flag = false;
            break;
        }
    }
    if(flag==false){
        cout<<"failure"<<endl;
        return;
    }
    else{
        //disp(res_col);
        FOR(i,0,res_col.size()){
            if(screen[row][res_col[i]]==0){
                screen[row][res_col[i]] = 1;
            }
            else if(screen[row][res_col[i]]==2){
                screen[row][res_col[i]] = 3;
            }
        }
        v[index].second = screen;
        cout<<"success"<<endl;
        return;
    }
}

void get_unres(vs str){
    ll v_len = v.size(),index = 0;
    bool flag = false;
    FOR(i,0,v_len){
        if(v[i].first==str[1]){
            flag = true;
            index = i;
            break;
        }
    }
    if(flag==false){
        cout<<"failure"<<endl;
        return;
    }
    
    vector<vll > screen = v[index].second;
    ll row = stoll(str[2]) - 1;
    vll pri;
    FOR(i,0,screen[0].size()){
        if(screen[row][i]==0||screen[row][i]==2){
            pri.pb(i+1);
        }
    }
    disp(pri);
}

ll min(ll a,ll b){
    if(a>b)return b;
    else return a;
}

ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}

bool occupied(vll v){
    bool flag = true;
    FOR(i,0,v.size()){
        if(v[i]==1||v[i]==3){
            flag = false;
            break;
        }
    }
    if(v.size()==1)return flag;
    FOR(i,1,v.size()-1){
        if(v[i]==2){
            flag = false;
            break;
        }
    }
    return flag;
}

void suggest_cont(vs str){
    ll v_len = v.size(),index = 0;
    bool flag = false;
    FOR(i,0,v_len){
        if(v[i].first==str[1]){
            flag = true;
            index = i;
            break;
        }
    }
    if(flag==false){
        cout<<"failure"<<endl;
        return;
    }
    vector<vll > screen = v[index].second;
    ll row = stoll(str[3]) - 1;
    ll choice = stoll(str[4]) - 1;
    ll num = stoll(str[2]);
    vector<vll > pri;
    if(screen[row][choice]==1||screen[row][choice]==3){
        cout<<"none"<<endl;
        return;
    }
    ll len = screen[0].size();
    FOR(i,min(0,num-choice),min(len,num+choice+1)){
        vll seats;
        vll indices;
        FOR(j,i,i+num){
            seats.pb(screen[row][j]);
            indices.pb(j+1);
        }
        if(occupied(seats))pri.pb(indices);
    }
    if(pri.size()==0)cout<<"none"<<endl;
    else{
        FOR(i,0,pri.size()){
            disp(pri[i]);
            cout<<"\n";
        }
    }
}

int main(){
    ll t;
    string test;
    getline(cin,test);
    t = stoll(test);
    while(t--){
        string s;
        cin.clear();
        getline(cin,s);
        vs str;
        
        string temp="";
        FOR(i,0,s.length()){
            while(i<s.length()&&s[i]!=' ')
            {temp+=s[i++];}
            str.pb(temp);
            if(i>=s.length())break;
            temp = "";
        }
        if(str[0]=="add-screen"){
            //cout<<"screenadded";
            //FOR(i,0,str.size())cout<<str[i]<<"\n";
            add_screen(str);
        }
        else if(str[0]=="reserve-seat"){
            //cout<<"reserveseat";
            reserve_seat(str);
        }
        else if(str[0]=="get-unreserved-seats"){
            get_unres(str);
        }
        else if(str[0]=="suggest-contiguous-seats"){
            suggest_cont(str);
        }
        else{
            cout<<"failure"<<endl;
        }
    }
    
}
/*
7
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen2 4 13 4
 */
