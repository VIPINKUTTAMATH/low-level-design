#include <iostream>

class IPushButton {
    public:
        virtual void Draw() = 0;
};

class IScrollButton {
    public:
        virtual void Draw() = 0;
};

class MacPushButton : public IPushButton {
    public:
        void Draw() {
            std::cout << "MAC Push Button" <<std::endl;
        }
};

class WinPushButton : public IPushButton {
    public:
        void Draw() {
            std::cout << "Win Push Button" <<std::endl;
        }
};

class MacScollButton : public IScrollButton {
    public:
        void Draw() {
            std::cout << "MAC Scroll Button" <<std::endl;
        }
};

class WinScollButton : public IScrollButton {
    public:
        void Draw() {
            std::cout << "WIN Scroll Button" <<std::endl;
        }
};

class IFactory {
    public:
        virtual IPushButton* CreatePushButton() = 0;
        virtual IScrollButton* CreateScrollButton() = 0;
};

class MACFactory : public IFactory {
    public:
        IPushButton* CreatePushButton() {
            return new MacPushButton();
        }
        IScrollButton* CreateScrollButton() {
            return new MacScollButton();
        }
};


class WindowsFactory : public IFactory {
    public:
        IPushButton* CreatePushButton() {
            return new WinPushButton();
        }
        IScrollButton* CreateScrollButton() {
            return new WinScollButton();
        }
};


IFactory * GetFactory(const std::string &osType) {
    if (osType == "MAC") {
        return new MACFactory();
    }

    else if (osType == "Windows") {
        return new WindowsFactory();
    }

    return nullptr;
}

int main () {
    std::cout << "Windows UI" << std::endl;
    IFactory* fac =  GetFactory("Windows");
    fac->CreatePushButton()->Draw();
    fac->CreateScrollButton()->Draw();


    std::cout << "MAC UI" << std::endl;
    fac =  GetFactory("MAC");

    fac->CreatePushButton()->Draw();
    fac->CreateScrollButton()->Draw();
}