#include <iostream>
#include <mutex>

class Logger {
    Logger()  = default;  // Disable creation of object outside class.
    
    /* Deleting Copy constructer and Asignment Operator*/
    Logger(const Logger&)= delete;
    Logger& operator=(const Logger&)= delete;
    Logger(const Logger&&)= delete;
    Logger& operator=(const Logger&&)= delete;

    public:
        static Logger * _instance; // Static instance
        static std::mutex _mx;
        int _counter = 0;
        static Logger * GetInstance () {
            if (!_instance) {
                _mx.lock();
                if(!_instance){
                    _instance = new Logger();
                }
                _mx.unlock();
            }
            return _instance;
        }

        void Display() {
            _counter++;
            std::cout << "Instance counter: " << _counter << std::endl;
        }
};

Logger* Logger::_instance = nullptr;
std::mutex Logger::_mx;

int main() {
    for (int i=0; i<10;i++) {
        Logger *logger = Logger::GetInstance();
        logger->Display();
    }

    // for (int i=0; i<10;i++) {
    //     Logger *logger = new Logger();  // Blocked - Will give Compilation error.
    //     logger->Display();
    // }
}

/* Note:
    Below code is an alternate option of thread safe singleton.
    Here static local variable static MySingleton instance is only initialized once.
    As C++11 ensure that static local instance is only intialized once in muti threaded env.
    class MySingleton{
        public:
        static MySingleton& getInstance(){
            static MySingleton instance;
            return instance;
        }
    };
};
*/