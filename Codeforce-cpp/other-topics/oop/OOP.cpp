#include <iostream>
using namespace std;

class Animal {
	protected:
		bool isMammal;
		bool isCarnivorous;
		string greet;
		string getGreet(){
			return greet;
		}
		string getCarnivorousString(){
			if(isCarnivorous){
				return "is carnivorous";
			} else{
				return "is not carnivorous";
			}
		}
		string getMammalString(){
			if(isMammal){
				return "is a mammal";
			} else{
				return "is not a mammal";
			}
		}
	public:
		bool getIsMammal(){
			return isMammal;
		}
		bool getIsCarnivorous(){
			return isCarnivorous;
		}
		virtual void getGreeting() = 0;
};

class Dog: public Animal{
	public:
		Dog(){
			isMammal = true;
			isCarnivorous = true;
			greet = "woof";
		}
		void getGreeting(){
			cout << "A dog says '" + getGreet() + "', " + getCarnivorousString() + ", and " + getMammalString() + ". " << endl; 
		}
};

class Cow: public Animal{
	public:
		Cow(){
			isMammal = true;
			isCarnivorous = false;
			greet = "moo";
		}
		void getGreeting(){
			cout << "A cow says '" + getGreet() + "', " + getCarnivorousString() + ", and " + getMammalString() + ". " << endl; 
		}
};

class Duck: public Animal{
	public:
		Duck(){
			isMammal = false;
			isCarnivorous = false;
			greet = "quack";
		}
		void getGreeting(){
			cout << "A duck says '" + getGreet() + "', " + getCarnivorousString() + ", and " + getMammalString() + ". " << endl; 
		}
};

int main(){
    Dog myDog;
    myDog.getGreeting();
    Cow myCow;
    myCow.getGreeting();
    Duck myDuck;
    myDuck.getGreeting();
    return 0;
}

