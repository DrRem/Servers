#include "SqlLinker.h"
#include "Socks.h"
int main() {
    SqlLinker linker;
    Socks a;
    string tmp=a.ListenTo();
    cout<<tmp;
    a.SendMassage("123");
}