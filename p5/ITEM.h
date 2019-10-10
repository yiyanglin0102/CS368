/********************************************************************
 * Name: Yiyang Lin
 * Wisc ID: 9080288724
 * OS: macOS
 * IDE (or text editor): Xcode
 * Compiler: Xcode
 * How long did the assignment take you to complete in minutes: 1200
 * What other resources did you consult (copy and paste links below: online
 ********************************r************************************
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

/**
 * Class ITEM,
 */
class ITEM {
public:
    string name;
    int option;
    int quantity;
    
    /**
     * Constructor of the ITEM class
     */
    ITEM() : name(""), quantity(0){}
    
    /**
     * Destructor of the ITEM class
     */
    ~ITEM() {}
    
    /**
     * Constructor of the ITEM class
     */
    ITEM(string name) : name(name), quantity(0) {}
    
    /**
     * Other classes will override this method
     */
    bool Process_Purchase(istream &cin, ostream &cout) {
        return true;
    }
    
    /**
     * A virtual method in ITEM class
     * Other classes will override this method
     */
    virtual int Get_Cost() const {
        cout<<"don't call this function"<<endl;
        return 0;
    }
    
    /**
     * Operator overload method
     */
    bool operator<(const ITEM& rhs) {
        return this->name < rhs.name;
    }
    
    /**
     * Other classes will override this method
     * Prints out the purchased items and quantity
     */
    virtual void Print(ostream &out=cout) const {
        out<<"Print the derived class info instead of this"<<endl;
    }
};

/**
 * Operator overload method
 */
ostream & operator<<(ostream &out, const ITEM &rhs) {
    rhs.Print(out);
    return out;
}

/**
 * Operator overload method, comparing left and right ITEM
 */
bool compare_pointers_to_items(ITEM *lhs, ITEM *rhs) {
    return *lhs < *rhs;
}

/**
 * Ball class inherits ITEM
 */
class BALLS : public ITEM {
public:
    
    /**
     * Constructor of BALLS class
     */
    BALLS() {
        Process_Purchase(cin, cout);
    }
    
    /**
     * Overrides Process_Purchase method in ITEM class
     */
    bool Process_Purchase(istream &cin, ostream &cout) {
        cout<<"Cannon Balls come in three sizes:"<<endl;
        cout<<"  1) Small     6 pieces of eight per Cannon Ball"<<endl;
        cout<<"  2) Medium   15 pieces of eight per Cannon Ball"<<endl;
        cout<<"  3) Large    52 pieces of eight per Cannon Ball"<<endl;
        cout<<"What size would you like?"<<endl;
        cin >> option;
        
        if(option == 1)
        {
            name = "Small Cannon Ball";
        }
        if(option == 2)
        {
            name = "Medium Cannon Ball";
        }
        if(option == 3)
        {
            name = "Large Cannon Ball";
        }
        if((option != 1) &&(option != 2) &&(option != 3))
        {
            return false;
        }
        
        cout<<"How many would you like?"<<endl;
        
        cin >> quantity;
        if(quantity <= 0)
        {
            cout<<"Happy hunting!"<<endl;
            name="";
            quantity=0;
            return false;
        }
        if(quantity == 1)
        {
            name += " ";
            return true;
        }
        if(quantity > 1)
        {
            name += "s";
            return true;
        }
        
        return false;
    }
    
    /**
     * overrides Print method in ITEM class
     */
    void Print(ostream &out=cout) const {
        out << quantity << " " << name;
    }
    
    /**
     * overrides Get_Cost method in ITEM class
     */
    int Get_Cost() const {
        if(name == "Small Cannon Ball " || name == "Small Cannon Balls" )
        {
            return 6 * quantity;
        }
        
        if(name == "Medium Cannon Ball " || name == "Medium Cannon Balls")
        {
            return 15 * quantity;
        }
        
        if(name == "Large Cannon Ball " || name == "Large Cannon Balls")
        {
            return 52 * quantity;
        }
        
        return 0;
    }
    
};

/**
 * Class RUM
 */
class RUM : public ITEM {
public:
    
    /**
     * Constructor of RUM class
     */
    RUM() {
        Process_Purchase(cin, cout);
    }
    
    /**
     * Overrides Print method in ITEM class
     */
    void Print(ostream &out=cout) const {
        out << quantity << " " << name;
    }
    
    /**
     * Overrides Process_Purchase method in ITEM class
     */
    bool Process_Purchase(istream &cin, ostream &cout) {
        cout<<"We have three different qualities of Rum in stock:"<<endl;
        cout<<"  1) Swill     1 pieces of eight per barrel"<<endl;
        cout<<"  2) Grog      5 pieces of eight per barrel"<<endl;
        cout<<"  3) Fine Rum 19 pieces of esight per barrel"<<endl;
        cout<<"What kind would you like?"<<endl;
        cin >> option;
        if(option == 1)
        {
            name = "Barrels of Swill";
            cout<<"Gotta keep the crew happy!"<<endl;
        }
        if(option == 2)
        {
            name = "Barrels of Grog";
            cout<<"The officers will love it!"<<endl;
        }
        if(option == 3)
        {
            name = "Barrels of Fine Rum";
            cout<<"Nothing but the best for the captain!"<<endl;
        }
        if((option != 1) &&(option != 2) &&(option != 3)){
            name="";
            return false;
        }
        
        cout<<"How many would you like?"<<endl;
        
        cin >> quantity;
        
        if(quantity <= 0)
        {
            cout<<"Transaction cancelled."<<endl;
            name="";
            quantity = 0;
            return false;
        }
        if(quantity == 1 && option == 1)
        {
           name = "Barrel of Swill";
        }
        if(quantity == 1 && option == 2)
        {
            name = "Barrel of Grog";
        }
        if(quantity == 1 && option == 3)
        {
            name = "Barrel of Fine Rum";
        }
        
        return true;
    }
    
    /**
     * Overrides Get_Cost method in ITEM class
     */
    int Get_Cost() const {
        
        if(name == "Barrels of Swill" || name == "Barrel of Swill")
        {
            return 1 * quantity;
        }
        
        if(name == "Barrels of Grog" || name == "Barrel of Grog")
        {
            return 5 * quantity;
        }
        
        if(name == "Barrels of Fine Rum" || name == "Barrel of Fine Rum")
        {
            return 19 * quantity;
        }
        return 0;
    }
};

/**
 * Class LIMES
 */
class LIMES : public ITEM {
public:
    
    /**
     * Constructor of LIMES class
     */
    LIMES() {
        name = "Limes";
        Process_Purchase(cin, cout);
    }
    
    /**
     * Overrides Print method in ITEM class
     */
    void Print(ostream &out=cout) const {
        out << 12 * quantity << " " << name;
    }
    
    /**
     * Overrides Get_Cost method in ITEM class
     */
    int Get_Cost() const {
        return 7 * quantity;
    }
    
    
    /**
     * Overrides Process_Purchase method in ITEM class
     */
    bool Process_Purchase(istream &cin, ostream &cout) {
        cout<<"Limes arrr delicious. They're on sale for 7 pieces of eight per dozen."<<endl;
        cout<<"How many dozen would you like?"<<endl;
        cin >> quantity;
        
        if(quantity <= 0)
        {
            cout<<"Transaction cancelled."<<endl;
            name="";
            quantity = 0;
            return false;
        }
       
        return true;
    }
};

/**
 * Class APPAREL
 */
class APPAREL : public ITEM {
public:
    
    /**
     * Constructor of the APPAREL class
     */
    APPAREL() {
        Process_Purchase(cin, cout);
    }
    void Print(ostream &out=cout) const {
        out << quantity << " " << name;
    }
    
    /**
     * Overrides Process_Purchase method in ITEM class
     */
    bool Process_Purchase(istream &cin, ostream &cout) {
        cout<<"That looks like a rough injury."<<endl;
        cout<<"  1) Eyepatch  4 pieces of eight"<<endl;
        cout<<"  2) Pegleg   13 pieces of eight"<<endl;
        cout<<"  3) Hook     43 pieces of eight"<<endl;
        cout<<"You're going to need a ... "<<endl;
        cin >> option;
        
        if(option == 1)
        {
            name = "Eyepatch";
        }
        if(option == 2)
        {
            cout<<"We'll be getting more crutches in stock early next week."<<endl;
            name = "Pegleg";
        }
        if(option == 3)
        {
            name = "Hook";
        }
        if((option != 1) &&(option != 2) &&(option != 3)){
            cout<<"Transaction cancelled."<<endl;
            name="";
            return false;
        }
        
        quantity = 1;
        
        return true;
    }
    
    /**
     * Overrides Get_Cost method in ITEM class
     */
    int Get_Cost() const {
        if(name == "Eyepatch")
        {
            return 4 * quantity;
        }
        
        if(name == "Pegleg")
        {
            return 13 * quantity;
        }
        
        if(name == "Hook")
        {
            return 43 * quantity;
        }
        return 0;
    }
};

#endif
