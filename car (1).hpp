#ifndef CAR_HPP
#define CAR_HPP

struct Car{
	int id;  //unique identifier for car
	int stops;  //number of stops this car will make
	int type;   //car type : Passenger = 1, Social = 2, Cargo = 3, Miscellaneous = 4
    
	//default constructor
	Car(){
		id =0;
		stops =0;
		type = 0;
	}
	
	//parameterized constructor
	Car(int id_, int s, int t){
		id = id_;
		stops = s;
		type = t;
	}
};

// convert numeric car type into a word
const char* typeName(int t){
	switch(t){
		case 1:
			return "Passenger";
		case 2:
			return "Social";
		
		case 3:
			return "Cargo";
		case 4:
			return "Miscellaneous";
		
		default:
			return "Unknown";
	}
}

// convert a numeric car type to character
char typeLetter(int t){
	switch(t){
		case 1:
		 return 'P';
		 break;

		case 2:
		 return 'S';
		 break;

		case 3:
		 return 'C';
		 break;

		case 4:
		 return 'M';
		 break;

	}
	return '?';
}

#endif
