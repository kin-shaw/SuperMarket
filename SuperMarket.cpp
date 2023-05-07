#include<bits/stdc++.h>
#include<fstream>

using namespace std;

string user_na="";

bool isValid(string s){

    if(s=="1" || s=="2" || s=="3" || s=="4")
    return true;

    return false;
}

long key_generate()
{
    long key=0;

    for(int i=0;i<10;i++)
    {
        key=key*10 + (rand()%10);
    }
    return key;
}

class shop{
private:
    int id;
    float price;
    float disc;
    string name;
public:
    void main_menu(unordered_map<string,string> mi,int fl);
    void buyer(unordered_map<string,string> mi,int fl);
    void admin(unordered_map<string,string> mi,int fl);
    void add(unordered_map<string,string> mi,int fl);
    void update(unordered_map<string,string> mi,int fl);
    void del(unordered_map<string,string> mi,int fl);
    void reciept(unordered_map<string,string> mi,int fl);
    void prod_list(unordered_map<string,string> mi,int fl);
    void new_buyer(unordered_map<string,string> mi,int fl);
    void login(unordered_map<string,string> mi,int fl);
    void chng_pass(unordered_map<string,string> mi,int fl);
};

void shop::main_menu(unordered_map <string,string> mi,int fl){
 m:  string choice;//endl
     cout<<endl<<endl<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t"<<endl;
     cout<<"\t\t\t\t                -- MAIN MENU -- \t\t\t\t\t\t\t\t"<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t\t"<<endl<<endl<<endl;
     cout<<"\t\t\t\t\t   1. ADMINISTRATORS   \t\t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   2. BUYER    \t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   3. EXIT    \t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t"<<endl<<endl<<endl;

    cout<<"ENTER VALID CHOICE"<<endl<<endl;

    cin>>choice;

    if(isValid(choice))
    {
        int f=stoi(choice);
        switch(f)
        {
           case 1: admin(mi,fl);
           case 2: buyer(mi,fl);
           case 3: exit(0);
           default : goto m;
        }
    }
    else
    goto m;
};

void shop::admin(unordered_map<string,string> mi,int fl){

adm:string email,password;
    cout<<"\t\t\t Enter E-Mail Id"<<endl;
    cin>>email;
    cout<<endl;
    cout<<"\t\t\t Enter Password"<<endl;
    cin>>password;

    if(mi.find(email)!=mi.end())
    {
        if(mi[email]==password)
        {
            goto disp;
        }
        else
        {
            cout<<"INVALID EMAIL OR PASSWORD"<<endl;
            goto adm;
        }

    }
    else
    {
        cout<<"INVALID EMAIL OR PASSWORD"<<endl;
        goto adm;
    }

disp:string choice;

     cout<<endl<<endl<<endl<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t"<<endl;
     cout<<"\t\t\t\t                -- Administrators -- \t\t\t\t\t\t\t\t"<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t\t"<<endl<<endl<<endl;
     cout<<"\t\t\t\t\t   1. ADD PRODUCT   \t\t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   2. UPDATE PRODUCT    \t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   3. DELETE PRODUCT    \t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   4. PRODUCT LIST    \t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   5. MAIN MENU    \t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t"<<endl<<endl<<endl;

     cout<<"ENTER VALID CHOICE"<<endl;
     cin>>choice;
     if(isValid(choice))
     {
         int f=stoi(choice);
         switch(f)
         {
         case 1: add(mi,fl);
         case 2: update(mi,fl);
         case 3: del(mi,fl);
         case 4: prod_list(mi,fl);
         case 5: main_menu(mi,fl);

         default: goto disp;
         }
     }
     else
        goto disp;
};

void shop:: buyer(unordered_map<string,string> mi,int fl)
{
    if(fl==0)
    {
        int choose;
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t 1. NEW USER | 2. LOGIN "<<endl;
        cin>>choose;
        cout<<endl;
        switch(choose)
        {
           case 1: new_buyer(mi,fl);
           case 2: login(mi,fl);
        }
    }
else
{
buy : string choice;

     cout<<endl<<endl<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t"<<endl;
     cout<<"\t\t\t\t                -- BUYER -- \t\t\t\t\t\t\t\t"<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   1. PRODUCT LIST   \t\t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   2. BUY & CHECK OUT    \t\t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   3. CHANGE PASSWORD    \t\t\t\t"<<endl<<endl;
     cout<<"\t\t\t\t\t   4. MAIN MENU    \t\t\t\t"<<endl<<endl;
     //cout<<"|\t\t\t\t    4. BUYER PROFILE   \t\t\t\t\t\t\t\t\t\t\t|"<<endl<<endl;
     cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t"<<endl<<endl;

    cout<<"ENTER VALID CHOICE"<<endl<<endl;
    cin>>choice;
    cout<<endl;

    if(isValid(choice))
    {
        int f=stoi(choice);
       switch(f)
       {
        case 1: prod_list(mi,fl);
        case 2: reciept(mi,fl);
        case 3: chng_pass(mi,fl);
        case 4: main_menu(mi,fl=0);
        default : goto buy;
       }
    }
    else
        goto buy;
}
}



void shop::new_buyer(unordered_map<string,string> mi,int fl){

n_by:string user_name;
    string password;

    cout<<"CREATE USER NAME"<<endl;
    cin>>user_name;
    cout<<"CREATE PASSWORD"<<endl;
    cin>>password;

    fstream cred;

    string t_n;
    string t_p;
    int flag=0;

    cred.open("credentials.txt",ios::in);
    if(!cred)
    {
        cred.open("credentials.txt",ios::app|ios::out);
        cred<<user_name<<" "<<password<<endl;
        cred.close();
        fstream user;
        user.open(user_name +".txt",ios::app|ios::out);
        cout<<" Successfully Registered "<<endl;
        buyer(mi,fl=0);
    }
    else
    {
        cred>>t_n>>t_p;
        while(!cred.eof())
        {
            if(t_n==user_name)
            {
                flag=1;
                cout<<"ENTER UNIQUE USER NAME"<<endl;
                goto n_by;
            }
            cred>>t_n>>t_p;
        }
        cred.close();
        cred.open("credentials.txt",ios::app);
        if(flag==0)
        {
            cred<<user_name<<" "<<password<<endl;
            fstream user;
            user.open(user_name+".txt",ios::app|ios::out);
            cout<<" Successfully Registered "<<endl;
            cred.close();
            buyer(mi,fl=0);
        }
    }

}

void shop::login(unordered_map<string,string> mi,int fl)
{
    string user_name;
    string password;

    cout<<"ENTER YOUR USER NAME"<<endl;
    cin>>user_name;
    cout<<"ENTER PASSWORD"<<endl;
    cin>>password;

    fstream cred;

    string t_n;
    string t_p;
    fl=0;

    cred.open("credentials.txt",ios::in);
    if(!cred)
    {
        cout<<"NO USER REGISTERED YET"<<endl;
    }
    else
    {
        cred>>t_n>>t_p;
        while(!cred.eof())
        {
            if(t_n==user_name && t_p == password)
            {
                fl=1;
                user_na=user_name;
                buyer(mi,fl);
            }
            cred>>t_n>>t_p;
        }
        if(fl==0)
        {
            cout<<"ENTER CORRECT CREDENTIALS OR REGISTER"<<endl;
            buyer(mi,fl);
        }

    }
}

void shop::chng_pass(unordered_map<string,string> mi,int fl){
chng:fstream cred,cred1;

     string t_n,t_p;
     cred.open("credentials.txt",ios::in);
     cred1.open("creden.txt",ios::in);
     if(!cred1)
     {
         cred1.close();
         cred1.open("c1.txt",ios::app|ios::out);
     }
     else
     {
         cred1.close();
         cred1.open("c1.txt",ios::app);
     }

    cred>>t_n>>t_p;
    while(!cred.eof())
    {
        if(t_n==user_na)
        {
            string c_pass;
            cout<<"\t\t Enter Current Password"<<endl<<endl;
            cin>>c_pass;
            if(c_pass==t_p)
            {
              string n_pass;
              cout<<"\t\t Enter New Password"<<endl<<endl;
              cin>>n_pass;
              cred1<<t_n<<" "<<n_pass<<endl;
            }
            else
            {
                cout<<"\t\t Enter Correct Current Password"<<endl<<endl;
                buyer(mi,fl);
            }
        }
        else
        {
            cred1<<t_n<<" "<<t_p<<endl;
        }
        cred>>t_n>>t_p;
    }
    cred.close();
    cred1.close();
    remove("credentials.txt");
    rename("creden.txt","credentials.txt");
    main_menu(mi,fl);
}
void shop:: add(unordered_map<string,string> mi,int fl){

ad: fstream data;

    int t_id;
    float t_price;
    float t_disc;
    string t_name;


    cout<<"Enter Product Id"<<endl;
    cin>>id;
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        cout<<"Enter Name"<<endl;
        cin>>name;
        cout<<"Enter Price"<<endl;
        cin>>price;
        cout<<"Enter Discount"<<endl;
        cin>>disc;

        data<<id<<" "<<name<<" "<<price<<" "<<disc<<" "<<endl;
        data.close();
    }
    else{
        //data.open("database.txt",ios::in);
        data>>t_id>>t_name>>t_price>>t_disc;
        while(!data.eof())
        {
            if(t_id==id)
            {
               //qty++;
               cout<<"Product Already Exists"<<endl;
               admin(mi,fl);
               data.close();
               goto ad;
            }
            data>>t_id>>t_name>>t_price>>t_disc;
        }
        data.close();

        cout<<"Enter Name"<<endl;
        cin>>name;
        cout<<"Enter Price"<<endl;
        cin>>price;
        cout<<"Enter Discount"<<endl;
        cin>>disc;
        data.open("database.txt",ios::app);
        data<<id<<" "<<name<<" "<<price<<" "<<disc<<" "<<endl;
        data.close();
    }
    admin(mi,fl);
};

void shop:: update(unordered_map<string,string> mi,int fl){

upd:fstream data,data1;

    int t_id;
    float t_price;
    float t_disc;
    string t_name;

    cout<<"Enter Product Id"<<endl;
    cin>>id;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"FILE DOES NOT EXIST"<<endl;
        admin(mi,fl);
        //break;
    }
    data1.open("database1.txt",ios::app|ios::out);
    data>>t_id>>t_name>>t_price>>t_disc;
        while(!data.eof())
        {
            if(t_id==id)
            {
               int n;
               cout<<"Enter New Product Id"<<endl;
               cin>>n;
               cout<<"Enter New Name"<<endl;
               cin>>t_name;
               cout<<"Enter New Price"<<endl;
               cin>>t_price;
               cout<<"Enter New Discount"<<endl;
               cin>>t_disc;

               data1<<n<<" "<<t_name<<" "<<t_price<<" "<<t_disc<<" "<<endl;
            }
            else
            {
                data1<<t_id<<" "<<t_name<<" "<<t_price<<" "<<t_disc<<" "<<endl;
            }
            data>>t_id>>t_name>>t_price>>t_disc;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        admin(mi,fl);
};

void shop::del(unordered_map<string,string> mi,int fl){
d:  fstream data,data1;

    int t_id;
    float t_price;
    float t_disc;
    string t_name;

    cout<<"Enter Product Id"<<endl;
    cin>>id;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"FILE DOES NOT EXIST"<<endl;
        admin(mi,fl);
        //break;
    }
    data1.open("database1.txt",ios::app|ios::out);
    data>>t_id>>t_name>>t_price>>t_disc;
        while(!data.eof())
        {
            if(t_id != id)
            {
               data1<<t_id<<" "<<t_name<<" "<<t_price<<" "<<t_disc<<" "<<endl;
            }
            data>>t_id>>t_name>>t_price>>t_disc;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        admin(mi,fl);
};

void shop::prod_list(unordered_map<string,string> mi,int fl){
 li:   fstream data;
       int t_id;
       float t_price;
       float t_disc;
       string t_name;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t--------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t           List Of Products   \t\t\t\t\t\t\t\t"<<endl<<endl;
    cout<<"\t\t\t\t\t--------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t ID      NAME             PRICE          DISCOUNT"<<endl<<endl;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"FILE DOES NOT EXIST"<<endl;
        main_menu(mi,fl);
        //break;
    }
    data>>t_id>>t_name>>t_price>>t_disc;
    while(!data.eof())
    {
        cout<<"\t\t\t\t\t "<<t_id<<"      "<<t_name<<"             "<<t_price<<"          "<<t_disc<<endl;

        data>>t_id>>t_name>>t_price>>t_disc;
    }
    data.close();

    string choice;

    cout<<endl<<endl<<"\t\t\t\t  1. BUYER MENU | 2. ADMIN "<<endl<<endl;
    cin>>choice;
    cout<<endl;

    if(isValid(choice))
    {
        int f=stoi(choice);
        switch(f)
       {
        case 1: buyer(mi,fl);
        case 2: admin(mi,fl);
        default:buyer(mi,fl);
       }
    }
    else
    buyer(mi,fl);



};


void shop:: reciept(unordered_map<string,string> mi,int fl){

        int total=0;
        unordered_map<int,int> b_id;
temp:   fstream data;
        data.open("database.txt",ios::in);

        int choice;

        cout<<endl<<endl<<endl;
        cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t   1. Buy Product   \t\t\t\t\t\t"<<endl<<endl;
        cout<<"\t\t\t\t\t   2. Cancel Product    \t\t\t\t\t"<<endl<<endl;
        cout<<"\t\t\t\t\t   3. My Cart    \t\t\t\t"<<endl<<endl;
        cout<<"\t\t\t\t\t   4. Generate Reciept   \t\t\t\t\t\t\t\t\t\t\t|"<<endl<<endl;
        cout<<"\t\t\t\t\t   5. Buyer Menu   \t\t\t\t\t\t\t\t\t\t\t|"<<endl<<endl;
        cout<<"\t\t\t\t-----------------------------------------------------\t\t\t\t\t\t\t\t\t"<<endl<<endl;

        cout<<"ENTER VALID CHOICE"<<endl;
        cin>>choice;
        cout<<endl;
        if(choice==1)
        {
            int c_id;
            string c_name;
            float c_price;
            float c_disc;
            int t_id,t_qty;
            cout<<"Enter Product Id"<<endl;
            cin>>t_id;
            //rep_prod.insert(t_id);
            cout<<"Enter Quantity required"<<endl;
            cin>>t_qty;
            bool tkn=false;
            data>>c_id>>c_name>>c_price>>c_disc;
            while(!data.eof())
            {
                if(c_id==t_id)
                {
                  tkn=true;
                  if(b_id.find(c_id)!=b_id.end())
                  {
                      cout<<" ENTER ANOTHER NEW PRODUCT"<<endl;
                      goto temp;
                  }
                  else
                  {
                     b_id.insert({t_id,t_qty});
                  }
                }
                data>>c_id>>c_name>>c_price>>c_disc;
             }
            if(tkn==false)
            {
               cout<<"Product Not Found"<<endl;
            }
            goto temp;
        }
    else if(choice==2)
    {
        int ch;
        cout<<"ENTER PRODUCT ID TO BE CANCELLED"<<endl;
        cin>>ch;

        if(b_id.find(ch)!=b_id.end())
        {
            b_id.erase(ch);
        }
        else
        {
            cout<<"ENTER CORRECT ID OF THE PRODUCT TO BE CANCELLED"<<endl<<endl;
        }
        goto temp;
    }
    else if(choice==5)
    {
        buyer(mi,fl);
    }
    else if(choice==3)
    {
            cout<<endl<<endl;

            cout<<"\t\t\t\t\t---------------------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t\t                         My Products   \t\t\t\t\t\t\t\t"<<endl<<endl;
            cout<<"\t\t\t\t\t----------------------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t\t ID     NAME           PRICE          DISCOUNT  QUANTITY AMOUNT"<<endl<<endl;
            fstream data;
            data.open("database.txt",ios::in);
            int c_id;
            string c_name;
            float c_price;
            float c_disc;
            int flag=0;
            data>>c_id>>c_name>>c_price>>c_disc;
            while(!data.eof())
            {
                if(b_id.find(c_id)!=b_id.end())
                {
                    flag=1;
                    int q=b_id[c_id];
                    float amt;
                    amt= c_price*(1-c_disc/100)*q;
                    total+=amt;
                    cout<<"\t\t"<<c_id<<"     "<<c_name<<"           "<<c_price<<"      "<<c_disc<<"    "<<q<<"   "<<amt<<" "<<endl;
                }
                      data>>c_id>>c_name>>c_price>>c_disc;
            }
            if(flag==0)
            {
                cout<<endl;
                cout<<"\t\t No Product Bought Yet "<<endl;
            }
            cout<<endl<<endl;
        goto temp;
    }
    else
    {
            fstream data,rec;
            float total=0;
            data.open("database.txt",ios::in);
            if(!data)
            {
                 cout<<"FILE DOES NOT EXIST"<<endl;
                 main_menu(mi,fl);
            }
            rec.open(user_na+".txt",ios::app);

                 //rec.open("reciept.txt",ios::app|ios::out);
                 rec<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl;
                 rec<<"\t\t\t\t\t                Your Receipt        \t\t\t\t\t\t\t\t\t"<<endl;
                 rec<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl<<endl;
                 rec<<"\t\t\t\t\t ID     NAME           PRICE      DISCOUNT    QUANTITY   AMOUNT    "<<endl<<endl;
                 //rec.close();

            //rec.open("reciept.txt",ios::app);
            int c_id;
            string c_name;
            float c_price;
            float c_disc;
            data>>c_id>>c_name>>c_price>>c_disc;
            while(!data.eof())
            {
                if(b_id.find(c_id)!=b_id.end())
                {
                    int q=b_id[c_id];
                    float amt;
                    amt= c_price*(1-c_disc/100)*q;
                    total+=amt;
                    rec<<"\t\t\t\t\t"<<c_id<<"     "<<c_name<<"           "<<c_price<<"      "<<c_disc<<"    "<<q<<"   "<<amt<<" "<<endl;
                }
                      data>>c_id>>c_name>>c_price>>c_disc;
            }
            rec<<endl<<endl<<endl<<"\t\t\t\t\t TOTAL AMOUNT PAID IS : "<<total<<endl;
            rec.close();
            data.close();
            cout<<"Check Your Reciept in the reciept.txt file"<<endl;
    }
};


int main()
{
    unordered_map<string,string> mi;
    int fl=0;
    mi.insert({"com","123"});

    shop s;
    s.main_menu(mi,fl);
    return 0;
}
