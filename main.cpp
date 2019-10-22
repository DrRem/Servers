#include "Student.h"
#include "Socks.h"
int main() {

    SqlLinker linker;   //初始化SQL
    linker.CreateNewStudent("admin",1,0,"2000-01-01","localhost",'N',"admin","car");
    //创建管理员账户
    char* temp = nullptr;
    while (true){
        temp = linker.talk.ListenTo();
        //接收客户端请求
        string car = temp;
        //管理员登录
        if(temp[0]=='0'){
            cout<<"user try to login as admin!"<<endl;
            string passwd=car.substr(1);
            if(linker.Login(1,passwd.data())){
                linker.talk.SendMassage("welcome,admin!");
                cout<<"admin login!"<<endl;
                const char* p=linker.talk.ListenTo();
                string c=p;
                linker.Display(stoi(c)); //遍历发送序列化字符窜
            }else{
                linker.talk.SendMassage("password error!");
                cout<<" password error!"<<endl;
            }
        }else if(temp[0] == '1'){           //注册
            cout<<"user registered!"<<endl;
            Student tmp;
            string ser = car.substr(1);
            tmp.deserialization(ser);
            if(linker.IfExist(tmp.id)){
                linker.CreateNewStudent(tmp.name.data(),tmp.id,tmp.Class,tmp.birthday.to_serialization().data(),
                        tmp.address.data(),tmp.sex,tmp.passwd.data(),tmp.serialization().data());
                linker.talk.SendMassage(" Created successfully !");
                cout<<"successfully!"<<endl;
                cout<<"Created user:"+tmp.name+to_string(tmp.id)<<endl;
            }else{
                linker.talk.SendMassage(" Error! : Object already exists!");
                cout<<"User tries to register an existing user !"<<endl;
            }
        }else if (temp[0] == '2'){          //登录
            cout<<"user try to login as normal :"<<endl;
            string id=car.substr(1,10);
            string passwd=car.substr(10);
            if(linker.IfExist(stoi(id))){
                if(linker.Login(stoi(id),passwd.data())){
                    linker.talk.SendMassage((linker.SearchStudent(stoi(id))).data());       //发送序列化字符窜
                }else{
                    linker.talk.SendMassage("password error!");
                    cout<<"User entered the wrong password..."<<endl;
                }
            }else{
                linker.talk.SendMassage("id not exist!");
                cout<<"User attempts to log in to an account that does not exist ..."<<endl;
            }
        }else{              //退出
            linker.talk.SendMassage("bye~");
            cout<<" user quit!"<<endl;
            break;
        }
        car.clear();
    }
}
