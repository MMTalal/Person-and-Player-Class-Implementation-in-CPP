#include <iostream>  // Include the input-output stream library
#include <string>    // Include the string library for handling string operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Define a class Person
class Person
{
    private:
        int id;      // Private member variable to store the ID
        string name; // Private member variable to store the name
        int age;     // Private member variable to store the age
    
    public:
        // Constructor section

        // Default constructor - initializes default values for the attributes
        Person()
        {
            id = 1;
            name = "Unknown";
            age = 0;
        }
        
        // Parameterized constructor - allows setting values when an object is created
        Person (int i, string n, int a)
        {
            // Validate and assign ID
            if (i <= 0)
            {
                cout << "ID can't be equal or less than zero!" << endl;
                id = 1; // Default value if invalid
            }
            else
            {
                id = i;
            }
            
            // Validate and assign Name
            if (n == " ")
            {
                cout << "The name is invalid!" << endl;
                name = "Unknown"; // Default value if invalid
            }
            else
            {
                name = n;
            }
            
            // Validate and assign Age
            if (a < 18)
            {
                cout << "Age can't be less than 18 years old" << endl;
                age = 18; // Default value if below 18
            }
            else
            {
                age = a;
            }
        }
    
    // Setter methods to modify private attributes

    // Set ID with validation
    void setID (int i)
    {
        if (i <= 0)
        {
            cout << "ID can't be equal or less than zero!" << endl;
            id = 1;
        }
        else
        {
            id = i;
        }
    }
    
    // Set Name with validation
    void setName (string n)
    {
        if (n == " ")
        {
            cout << "The name is invalid!" << endl;
            name = "Unknown";
        }
        else
        {
            name = n;
        }
    }
    
    // Set Age with validation
    void setAge (int a)
    {
        if (a < 18)
        {
            cout << "Age can't be less than 18 years old" << endl;
            age = 18; 
        }
        else
        {
            age = a;
        }
    }
    
    // Getter methods to access private attributes

    // Get ID
    int getId()
    {
        return id;
    }
    
    // Get Name
    string getName()
    {
        return name;
    }
    
    // Get Age
    int getAge()
    {
        return age;
    }
    
    // Method to display information about the person
    void info()
    {
        cout << "ID = " << id << " , Name is: \"" << name << "\" , and age is " << age << " years old." << endl;
    }
    
    // Destructor - called when an object is destroyed
    ~Person()
    {
        cout << "Goodbye, \"" << getName() << "\"." << endl;
    }
};

// Define a derived class Player that inherits from Person
class Player : public Person
{
    private:
        int rating; // Private member variable to store player rating
        int salary; // Private member variable to store player salary
    
    public:
    // Constructor section

    // Default constructor - initializes default values for Player attributes
    Player()
    {
        rating = 0;
        salary = 0;
    }
    
    // Parameterized constructor - allows setting values for Player attributes
    Player(int i, string n, int a, int r, int s) : Person (i, n, a)
    {
        setRating(r);  // Validate and set rating
        setSalary(s);  // Validate and set salary
    }
    
    // Setter methods for Player attributes

    // Set Rating with validation
    void setRating (int r)
    {
        if (r < 0)
        {
            cout << "Rating can't be negative!" << endl;
            rating = 0;
        }
        else
        {
            rating = r;
        }
    }
    
    // Set Salary with validation
    void setSalary(int s)
    {
        if (s < 0)
        {
            cout << "Salary can't be negative!" << endl;
            salary = 500000; // Default salary if invalid
        }
        else
        {
            salary = s;
        }
    }
    
    // Getter methods for Player attributes

    // Get Rating
    int getRating()
    {
        return rating;
    }
    
    // Get Salary
    int getSalary()
    {
        return salary;
    }
    
    // Method to display information about the player
    void info() 
    {
        Person::info(); // Call base class info method
        cout << "No: " << rating << " , Salary: $" << salary << endl;
    }
    
    // Destructor - called when a Player object is destroyed
    ~Player()
    {
        cout << "Player destructor called for \"" << getName() << "\"" << endl;
    }
};

int main() {
    // Creating an object of the Person class (Doctor)
    Person Doctor (1, "Mahmoud", 29);
    // Displaying information about the Person object
    Doctor.info();

    // Creating an object of the Player class (Forward position)
    Player forward (5, "Ronaldo", 42, 7, 500000);
    // Displaying information about the Player object
    forward.info();

    return 0; // Exit the program successfully
}