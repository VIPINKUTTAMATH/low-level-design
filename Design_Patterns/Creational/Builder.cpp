#include <iostream>
#include <vector>

class IItem {
    public:
        virtual void Display() = 0;
};

class Coke : public IItem {
    public:
        void Display() {
            std::cout << "Coke" << std::endl;
        }
};

class LimeJuice : public IItem {
    public:
        void Display() {
            std::cout << "LimeJuice" << std::endl;
        }
};

class Fries : public IItem {
    public:
        void Display() {
            std::cout << "Fries" << std::endl;
        }
};

class Biriyani : public IItem{
    public:
        void Display() {
            std::cout << "Biriyani" << std::endl;
        }
};

class Burger : public IItem{
    public:
        void Display() {
            std::cout << "Burger" << std::endl;
        }
};

class Pizza : public IItem{
    public:
        void Display() {
            std::cout << "Pizza" << std::endl;
        }
};


class Meal {
    std::vector<IItem*> contents;

    public:
        void Display() {
            std::cout << "Meal Contains ->" << std::endl;
            for (auto it: contents){
                it->Display();
            }
            std::cout << "**********************" << std::endl;
        }

        void AddItem(IItem* item) {
            contents.push_back(item);
        }

};

class IMealBuilder {
    public:
        virtual void AddDrink(Meal *meal) = 0;
        virtual void AddStarter(Meal *meal) = 0;
        virtual void AddMainCourse(Meal *meal) = 0;
};

class  IndianMeal : public IMealBuilder {
    public:
        virtual void AddDrink(Meal *meal) {
            meal->AddItem(new LimeJuice());
        }
        virtual void AddStarter(Meal *meal) {
            meal->AddItem(new Fries());
        }
        virtual void AddMainCourse(Meal *meal) {
            meal->AddItem(new Biriyani());
        }
};

class  ItalianMeal : public IMealBuilder {
    public:
        virtual void AddDrink(Meal *meal) {
            meal->AddItem(new Coke());
        }
        virtual void AddStarter(Meal *meal) {
            meal->AddItem(new Fries());
        }
        virtual void AddMainCourse(Meal *meal) {
            meal->AddItem(new Pizza());
        }
};

class Director {
    public:
        Meal* CreateMeal(IMealBuilder * builder) {
            Meal * meal =  new Meal();
            builder->AddDrink(meal);
            builder->AddStarter(meal);
            builder->AddMainCourse(meal);
            return meal;
        }
};

int main() {
    Director dir;
    Meal * meal = nullptr;
    IndianMeal * indian = new IndianMeal();
    meal = dir.CreateMeal(indian);
    meal->Display();

    ItalianMeal *italian = new ItalianMeal();
    meal = dir.CreateMeal(italian);
    meal->Display();
}