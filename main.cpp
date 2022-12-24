/*
#include <iostream>
using namespace std;

class Plane
{

private:
    string type; // Marfa sau pasageri

public:
    Plane(string type) : type(type) {}

    static Plane *getPlane(string &type)
    {
        return new Plane(type);
    }

    Plane &operator=(const Plane &pla1)
    {
        // Item 11
        if (this == &pla1)
        {
            return *this;
        }
        else
        {
            this->type = pla1.type;
            return *this; // Item 10
        }
    }

    // Item5
    // Copyconstructor lipsa

    void toString()
    {
        cout << "Type of plane: " << type << endl;
    }

protected:
    string getType()
    {
        return type;
    }
};

class Pilot : public Plane
{

private:
    string name;
    string CNP;
    string flightNumber;
    int yearsOfExperience;

public:
    Pilot(string name, string CNP, string flightNumber, int yearsOfExperience, string type) : name(name),
                                                                                              CNP(CNP),
                                                                                              flightNumber(flightNumber),
                                                                                              yearsOfExperience(yearsOfExperience),
                                                                                              Plane(type) {}

    /*~Pilot()
    {
        delete plane;
    }*/
/*
    Pilot(const Pilot &pil1) : name(pil1.name),
                               CNP(pil1.CNP),
                               flightNumber(pil1.flightNumber),
                               yearsOfExperience(pil1.yearsOfExperience),
                               Plane(pil1) {}

    Pilot &operator=(const Pilot &pil1)
    {
        // Item 11
        if (this == &pil1)
        {
            return *this;
        }
        else
        {
            this->name = pil1.name;
            this->CNP = pil1.CNP;
            this->flightNumber = pil1.flightNumber;
            this->yearsOfExperience = pil1.yearsOfExperience;
            Plane::operator=(pil1); // Item 12
            return *this;           // Item 10;
        }
    }

    void toString()
    {
        cout << "Name: " << name << " CNP: " << CNP << " Flight Number: " << flightNumber << " Years of Experience: " << yearsOfExperience << endl;
        cout << "Plane type: " << getType() << endl;
    }
};

class Uncopyable
{
protected:           // allow construction
    Uncopyable() {}  // and destruction of
    ~Uncopyable() {} // derived objects...
private:
    Uncopyable(const Uncopyable &); // ...but prevent copying
    Uncopyable &operator=(const Uncopyable &);
};

class Passenger : private Uncopyable
{
private:
    string name;
    string flightNumber;

public:
    Passenger(string name, string flightNumber) : name(name), flightNumber(flightNumber) {}

    void toString()
    {
        cout << "Name of Passenger: " << name << " Flight number: " << flightNumber << endl;
    }
};

int main(int, char **)
{
    // Item4
    Pilot p1("Andrei", "1234567890333", "WZ3464", 10, "Passengers");
    Pilot p2(p1);
    Pilot p3 = p1;

    p1.toString();
    p2.toString();
    p3.toString();
    cout << "------------------" << endl;

    // Item5
    Plane pl1("Passengers");
    Plane pl2(pl1);

    pl1.toString();
    pl2.toString();
    cout << "------------------" << endl;
    // Item6
    Passenger pa1("George", "WZ3464");
    /// Passenger pa2(pa1);
    pa1.toString();

    return 0;
}

*/
#define _HAS_AUTO_PTR_ETC 1
#include<iostream>
#include<cstring>
#include <memory>
using namespace std;


class Pet
{

    public:
        Pet(const string &name, const string &type, const int &age,const string &colour);
        // Default constructor for item 13
        Pet(void);
        void printPet()
	    {
            cout<<"name:"<<name<<" type:"<<type<<" age:"<<age<<" color:"<<colour;
        }
        Pet& operator=(Pet& other)       
        {
            //item 11
            if(this != &other)
            {
                this->name = other.name;
                this->type= other.type;
                this->age = other.age;
                this->colour = other.colour;
            }
            else
            {
                cout<<"This and other have the same reference";
            }

            // item 10
            return *this;          
        }
        Pet* createPet();
        
        void setName(string name)
        {
            this->name = name;
        }
        void setType(string type)
         {
            this->type = type;
         }
        void setAge(int age)
        {
            this->age = age;
        }
        void setColour(string colour)
        {
            this->colour = colour;
        }
        // Getter
        
        string getName() 
        {
            return this->name;
        }
        string getType() 
        {
            return this->type;
        }
        int getAge() 
        {
            return this->age;
        }
        string getColour() 
        {
            return this->colour;
        }



    private:
        
        string name;
        string type;
        int age;
        string colour;
};

Pet::Pet( const string &name,const string &type, const int &age,const string &colour)
    :name(name),
    type(type),
    age(age),
    colour(colour)
{}
Pet::Pet()
    :name(),
    type(),
    age(),
    colour()
{}
//item 13
Pet* createPet(){                   
    return (new Pet);
}
//premature return ->item 13
int function()
{
    Pet *p= createPet();
    p->setAge(3);
    if (p->getAge() != 0) return -1;
    cout<<"got to delete\n";
    delete p;
    return 0;
}


// item 14
class Petshop{
    private:
        string name;
        bool locked = false;
    public:

    Petshop(string name){
        this->name = name;
    }

    Petshop(const Petshop &z){
        this->name = z.name;
        this->locked = z.locked;
    }

    ~Petshop(){
        std::cout<<"Petshop deleted"<<std::endl;
    }

    string getName(){
        return this->name;
    }

    bool getLocked(){
        return this->locked;
    }

    void setLocked(bool locked){
        this->locked = locked;
    }

    void isPetshopLocked(){
        if(this->locked == false) 
            std::cout<<"The Petshop "<< this->name <<" is not locked"<<"\n";
        else
            std::cout<<"The Petshop "<<this->name<<" is locked"<<"\n";
    }

};
//  item 14
void lock(Petshop &p){         
    p.setLocked(true);
}

void unlock(Petshop &p){
    p.setLocked(false);
}

//item 14
class PetshopResponsible{            
    private:
        Petshop &petshop;
    public:
    PetshopResponsible(Petshop &p):
    petshop(p){
        lock(petshop);
    }
    ~PetshopResponsible(){
        unlock(petshop);
    }
};



int main()
{
   

    //Item 13: auto_ptr deletes the objects by itself.
    auto_ptr<Pet> pet1(createPet());

    pet1->setName("Lola");
    pet1->setType("Pisica");
    pet1->setAge(3);
    pet1->setColour("white");
    auto_ptr<Pet> pet2(pet1);
    std::cout<<"\n"<<pet2->getName()<<"\n"; 
    std::cout<<"\n"<<pet2->getType()<<"\n";
    std::cout<<"\n"<<pet2->getAge()<<"\n";
    std::cout<<"\n"<<pet2->getColour()<<"\n";

    shared_ptr<Pet> pet3(createPet());
    pet3->setAge(4);
    shared_ptr<Pet> pet4;
    pet4 = pet3;
    std::cout<<"\n"<<pet3->getAge()<<"\n";     
    std::cout<<"\n"<<pet4->getAge()<<"\n";  

     //if function is not applied, it will not reach delete because of the premature return                                                  
    //function();

     //Item 14 lock and unlocked
    Petshop petshop("Petshop1");
    petshop.isPetshopLocked();                  
    std::cout<<"\n";
    PetshopResponsible employee(petshop);      
    petshop.isPetshopLocked();
    std::cout<<"\n";




    return 0;
}