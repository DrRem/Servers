#include "SqlLinker.h"
#include "Socks.h"
int main() {
    SqlLinker linker;   //初始化SQL
    linker.CreateNewStudent("admin",1,0,"2000-01-01","localhost",'N',"admin","car");
    //创建管理员账户
    char* temp = nullptr;
    while (true){
        string car = temp;
        //等待客户端
        //管理员登录
        if(temp[0]=='0'){
            string passwd=car.substr(1);
            if(linker.Login(1,passwd.data())){
                linker.talk.SendMassage("admin");
                const char* p=linker.talk.ListenTo();
                string c=p;
                linker.Display(stoi(c)); //遍历发送序列化字符窜
            }else{
                linker.talk.SendMassage(" ");
            }
        }else if(temp[0] == '1'){           //注册
            ;
        }else if (temp[0] == '2'){          //登录
            string id=car.substr(1,12);
            string passwd=car.substr(12);
            if(linker.IfExist(stoi(id))){
                if(linker.Login(stoi(id),passwd.data())){
                    linker.talk.SendMassage((linker.SearchStudent(stoi(id))).data());       //发送序列化字符窜
                }else{
                    linker.talk.SendMassage("password error!");
                }
            }else{
                linker.talk.SendMassage("id not exist!");
            }
        }else{              //退出
            linker.talk.SendMassage("error : method not exist");
            break;
        }
        car.clear();
    }

}
