#include <iostream>
#include <vector>

class IDocument {
    public:
       virtual IDocument * Clone() = 0;
       virtual void Display() = 0; 
};

class XMLDoc: public IDocument {
    public:
        IDocument *Clone() override {
            return new XMLDoc();
        }

        void Display() override {
            std::cout << "Displaying XML format" << std::endl;      
        }
};

class JsonDoc: public IDocument {
    public:
        IDocument *Clone() override {
            return new JsonDoc();
        }

        void Display() override {
            std::cout << "Displaying Json format" << std::endl;      
        }
};

enum Docs{
    xml=1,
    json
};

class DocumentMgr{
    public:
        static IDocument * CreateDoc(Docs type) {
            return document_ptrs[type]->Clone();
        }

        static std::vector<IDocument*> document_ptrs;
};

std::vector<IDocument*> DocumentMgr::document_ptrs = {
    0, new XMLDoc(), new JsonDoc()
};

int main() {
    DocumentMgr::CreateDoc(Docs::json)->Display();
    DocumentMgr::CreateDoc(Docs::xml)->Display();
    return 0;
}