#include <iostream>

class IAnimal {
    public:
        virtual void Sound() = 0;
};

class Dog : public IAnimal{
    public:
        void Sound() {
            std::cout << "Bark!!!" << std::endl;
        }      
};

class Cat : public IAnimal{
    public:
        void Sound() {
            std::cout << "Meowww!!!" << std::endl;
        }      
};

class AnimalFactory { 
    public:
        IAnimal* CreateAnimal (const std::string &type) {
            if(type == "DOG") {
                return new Dog();
            }
            else if(type == "CAT") {
                return new Cat();
            }

            return nullptr;
        }
};

void AnimalSound(const std::string &type) {
    AnimalFactory factory;
    IAnimal* animal = factory.CreateAnimal(type);
    animal->Sound();
}

int main () {
    std::cout << "CAT Sound !!" << std::endl;
    AnimalSound("CAT");

    std::cout << "DOG Sound !!" << std::endl;
    AnimalSound("DOG");
}

// NOTE!
// For adding any new animal, Need to extend new class from IAnimal and 
// Update it in Create Animal function in Factory. 
// No changes to existing functionality.
// Open to extention and Closed for Modification. SOLID Principle.
