//courseID:CIS265-001HY
//names:Scott, Matea, Dan, Matthew, Min, Hyejin
//Prof. Wang
//Assignment: Group Project(Travel Expenses)
//Due by 2/21/2020

/***********************Travel Expenses Program***********************/
#include<iostream>
#include<iomanip>
using namespace std;


//Function Prototypes
int totalDays();
void getTime(int &, int &, int &, int &, int &, int &);
double roundTripAirFare();
void carRentalCost(int &, double &, double &);
void parkingFee(int, double &, double &);
void taxiFee(int, double &, double &);
double getSeminarFees();
void hotelTotal(int, double &, double &);
void mealTotal(int, int, int, int, int, double &, double &);
/***********************Main Function***********************/
//By Scott
int main()
{
    string depPeriod,       //string variable for AM/PM for departure time
    arrPeriod;       //string variable for AM/PM for arrival time
    
    double parkTotal,
    parkAllowed,
    airfee,
    taxiTotal,
    taxiAllowed,
    totalHotelCost = 0.0,
    allowedHotel,
    regFee,
    allMealsTotal = 0.0,
    allowedMealTotal = 0.0,
    carCost=0.0,
    totalMilesDriven,
    //TOTAL variables
    TOTALALLOWED,
    TOTALEXP,
    TOTALOWED,
    TOTALSAVED;
    int days,       //variable for days spent on trip
    Dhr,        //output variable for Departure Hours
    Dmin,       //output variable for Departure Minutes
    Dper,       //output variable for Departure Period(AM/PM)
    Ahr,        //output variable for Arrival Hours
    Amin,       //output variable for Arrival Minutes
    Aper,       //output variable for Arrival Period
    cars = 0;   //private car total counter
    
    //Output Formatting
    cout<<fixed<<showpoint<<setprecision(2);
    
    //Call all functions
    days = totalDays();
    cout<<"------------------------------------------------"<<endl;
    getTime(Dhr, Dmin, Dper, Ahr, Amin, Aper);
    cout<<"------------------------------------------------"<<endl;
    getTime(Dhr, Dmin, Dper, Ahr, Amin, Aper);
    cout<<"------------------------------------------------"<<endl;
    airfee = roundTripAirFare();
    cout<<"------------------------------------------------"<<endl;
    carRentalCost(cars, totalMilesDriven, carCost);
    cout<<"------------------------------------------------"<<endl;
    parkingFee(days, parkTotal, parkAllowed);
    cout<<"------------------------------------------------"<<endl;
    taxiFee(days, taxiTotal, taxiAllowed);
    cout<<"------------------------------------------------"<<endl;
    regFee = getSeminarFees();
    cout<<"------------------------------------------------"<<endl;
    hotelTotal(days, totalHotelCost, allowedHotel);
    cout<<"------------------------------------------------"<<endl;
    mealTotal(days, Dhr, Dmin, Ahr, Amin, allMealsTotal, allowedMealTotal);
    
    //Calculate TOTALS
    TOTALEXP = airfee + carCost + parkTotal + taxiTotal + regFee + totalHotelCost + allMealsTotal;
    TOTALALLOWED = airfee + carCost + parkAllowed + taxiAllowed + regFee + allowedHotel + allowedMealTotal;
    
    if (TOTALEXP > TOTALALLOWED)
    {
        TOTALOWED = TOTALEXP - TOTALALLOWED;
        TOTALSAVED = 0;
    }
    else if (TOTALEXP < TOTALALLOWED)
    {
        TOTALSAVED = TOTALALLOWED - TOTALEXP;
        TOTALOWED = 0;
    }
    //Output DATA
    cout<<"======================Data======================"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Totals Days spent on Trip: "<<days<<endl;
    cout<<"------------------------------------------------"<<endl;
    if (Dper == 2)
    {
        depPeriod = "PM";
        if (Dhr > 12 && Dhr <= 24)
            Dhr -= 12;
    }
    else if (Dper == 1)
    {
        depPeriod = "AM";
        if (Dhr == 0)
            Dhr = 12;
    }
    cout<<"Departure time: "<<Dhr<<":"<<Dmin<<" "<<depPeriod<<endl;
    if (Aper == 2)
    {
        arrPeriod = "PM";
        if (Ahr > 12 && Ahr <= 24)
            Ahr -= 12;
    }
    else if (Aper == 1)
    {
        arrPeriod = "AM";
        if (Ahr == 0)
            Ahr = 12;
    }
    cout<<"Arrival time: "<<Ahr<<":"<<Amin<<" "<<arrPeriod<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total roundtrip airfare: $"<<airfee<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Number of rental cars used: "<<cars<<endl;
    cout<<"Total miles driven in rental cars: "<<totalMilesDriven<<" miles"<<endl;
    cout<<"Total cost of rental car fees: $"<<carCost<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total parking fees: $"<<parkTotal<<endl;
    cout<<"Total allowed parking expenses: $"<<parkAllowed<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total taxi fees: $"<<taxiTotal<<endl;
    cout<<"Total allowed taxi expenses: $"<<taxiAllowed<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total for any registration/seminar fees: $"<<regFee<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total Hotel Cost: $"<<totalHotelCost<<endl;
    cout<<"Total allowed amount of Hotel Expenses: $"<<allowedHotel<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total meal expenses: $"<<allMealsTotal<<endl;
    cout<<"Total allowed meal expenses: $"<<allowedMealTotal<<endl;
    cout<<endl;
    //Output TOTALS
    cout<<"======================TOTALS======================"<<endl;
    cout<<"Total Expenses: $"<<TOTALEXP<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total Allowed Expenses: $"<<TOTALALLOWED<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total Saved Expenses: $"<<TOTALSAVED<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Total Owed Expenses: $"<<TOTALOWED<<endl;
    cout<<"------------------------------------------------"<<endl;
    
    return 0;
}
/***********************Total Days Function***********************/
//By Dan
int totalDays()
{
    int totalTripDays;
    
    //get total days
    cout << "How many total days was the trip?: ";
    cin >> totalTripDays;
    
    //input validation
    while (totalTripDays <= 0 || totalTripDays > 101)
    {
        cout << "ERROR: This program does not allow for trips over 101 days or less than 1 day."<< endl;
        cout << "How many total days is the trip?: " << endl;
        cin >> totalTripDays;
    }
    return totalTripDays;
}
/***********************Get Arrival/Departure Time Function***********************/
//By Scott
void getTime(int &Dhr, int &Dmin, int &Dper, int &Ahr, int &Amin, int &Aper)
{
    //time variables
    int Dhours,
    Dminutes,
    Dperiod,
    Ahours,
    Aminutes,
    Aperiod;
    //departure or arrival?
    char type;
    
    //get type
    cout<<"Departure time or arrival time?"<<endl;
    cout<<"Enter 'D' for Departure or 'A' for Arrival: ";
    cin>>type;
    //input validation
    while (type != 'D' && type != 'd' && type != 'A' && type != 'a')
    {
        cout<<"ERROR: INVALID INPUT"<<endl;
        cout<<"Departure time or arrival time?"<<endl;
        cout<<"Enter 'D' for Departure or 'A' for Arrival: ";
        cin>>type;
    }
    cout<<endl;
    
    if (type == 'D' || type == 'd')
        cout<<"What time did you depart for your trip?"<<endl;
    else if (type == 'A' || type == 'a')
        cout<<"What time did you arrive back home from your trip?"<<endl;
    //if D get departure time
    if (type == 'D' || type == 'd')
    {
        cout<<"Enter a positive integer between 1 and 12 for the hour: ";
        cin>>Dhours;
        while (Dhours <= 0 || Dhours > 12)
        {
            cout<<"ERROR: INVALID INPUT"<<endl;
            cout<<"Please re-enter a valid number for hours: ";
            cin>>Dhours;
        }
        cout<<"Enter a positive integer between 00 and 59 for minutes: ";
        cin>>Dminutes;
        while (Dminutes < 0 || Dminutes > 59)
        {
            cout<<"ERROR: INVALID INPUT"<<endl;
            cout<<"Please re-enter a valid number for minutes: ";
            cin>>Dminutes;
        }
        cout<<"Enter a 1 for AM or a 2 for PM: ";
        cin>>Dperiod;
        while (Dperiod != 1 && Dperiod != 2)
        {
            cout<<"ERROR: INVALID INPUT"<<endl;
            cout<<"Please re-enter a valid number for period: ";
            cin>>Dperiod;
        }
        //change departure time to military time
        if (Dperiod == 2)
        {
            if (Dhours <= 12 && Dhours > 0)
                Dhours += 12;
        }
        else if (Dperiod == 1 && Dhours == 12 && Dminutes > 0)
            Dhours = 0;
        //set departure variables
        Dhr = Dhours;
        Dmin = Dminutes;
        Dper = Dperiod;
    }
    //if A get arrival time
    else if (type == 'A' || type == 'a')
    {
        cout<<"Enter a positive integer between 1 and 12 for the hour: ";
        cin>>Ahours;
        while (Ahours <= 0 || Ahours > 12)
        {
            cout<<"ERROR: INVALID INPUT"<<endl;
            cout<<"Please re-enter a valid number for hours: ";
            cin>>Ahours;
        }
        cout<<"Enter a positive integer between 00 and 59 for minutes: ";
        cin>>Aminutes;
        while (Aminutes < 0 || Aminutes > 59)
        {
            cout<<"ERROR: INVALID INPUT"<<endl;
            cout<<"Please re-enter a valid number for minutes: ";
            cin>>Aminutes;
        }
        cout<<"Enter a 1 for AM or a 2 for PM: ";
        cin>>Aperiod;
        while (Aperiod != 1 && Aperiod != 2)
        {
            cout<<"ERROR: INVALID INPUT"<<endl;
            cout<<"Please re-enter a valid number for period: ";
            cin>>Aperiod;
        }
        //change arrival time to military time
        if (Aperiod == 2)
        {
            if (Ahours <= 12 && Ahours > 0)
                Ahours += 12;
        }
        else if (Aperiod == 1 && Ahours == 12 && Aminutes > 0)
            Ahours = 0;
        
        //set arrival variables
        Ahr = Ahours;
        Amin = Aminutes;
        Aper = Aperiod;
    }
    
}
/***********************Round Trip Air Fare Function***********************/
//By Hyejin
double roundTripAirFare()
{
    double airFare;
    //input validation/get airfare
    do
    {
        cout << "How much is the round trip airfare? $";
        cin >> airFare;
    } while (airFare < 0);
    
    return airFare;
}

/***********************Car Rental Fees Function***********************/
//By Matea
void carRentalCost(int &cars, double &totalMilesDriven, double &carCost)
{
    char carRent;
    double miles;
    
    //check if rented car
    cout<< "Enter Y if you rented a private car and N if you did not: ";
    cin>>carRent;
    
    //input validation
    while (carRent!= 'n' && carRent!= 'N' && carRent!= 'y' && carRent!= 'Y')
    {
        cout<<"Please enter a valid answer: "<<endl;
        cout<< "Enter Y if you rented a private car and N if you did not: ";
        cin>>carRent;
    }
    //if yes get how many cars and total amount of miles driven
    if (carRent == 'y' || carRent == 'Y')
    {
        cout<<"How many cars did you rent? ";
        cin>>cars;
        
        while(cars<0)
        {
            cout<<"Amount of cars rented cannot be less than 0. Please re-Enter: ";
            cin>>cars;
        }
        
        cout<<"Enter sum of all miles driven with private cars throughtout the entire trip: ";
        cin>>miles;
        
        while(miles<0)
        {
            cout<<"Total amount of miles cannot be less than 0.Please re-Enter: ";
            cin>>miles;
        }
        carCost = miles * 0.27;
    }
    
    //if no miles is 0
    if (carRent== 'n'|| carRent== 'N')
        miles = 0.0;
    
    //set variable
    totalMilesDriven = miles;
}
/***********************Parking Fee Function***********************/
//By Hyejin
void parkingFee(int dayCount, double &parkTotal, double &parkAllowed)
{
    char park;
    int numDays;
    double rate;
    
    //check if accrued any parking fees
    cout<<"Did you accrue any parking fees throughout your trip?"<<endl;
    cout<<"If yes type 'Y' or if no type 'n': ";
    cin>>park;
    //input validation
    while (park !='y' && park !='Y' && park !='n' && park !='N')
    {
        cout<<"ERROR: INVALID INPUT";
        cout<<"Did you accrue any parking fees throughout your trip?"<<endl;
        cout<<"If yes type 'Y' or if no type 'n': ";
        cin>>park;
    }
    //if yes, get how many days parked and parking rate
    if (park == 'y' || park == 'Y')
    {
        do
        {
            cout << "How many days did you park? ";
            cin >> numDays;
            while (numDays > dayCount)
            {
                cout<<"ERROR: You can not enter a number of parking days greater than the total number of days spent on the trip."<<endl;
                cout <<"How many days did you park? ";
                cin >> numDays;
            }
            cout << "What is the parking rate? $";
            cin >> rate;
        } while (numDays < 1 || rate < 0);
        
        //calculate allowed expenses
        parkTotal = numDays * rate;
        if (parkTotal > 6 * numDays)
        {
            parkAllowed = 6 * numDays;
        }
        else
        {
            parkAllowed = parkTotal;
        }
    }
    //if no parking total/allowed is 0
    else if (park == 'n' || park == 'N')
    {
        parkTotal = 0;
        parkAllowed = 0;
    }
}
/***********************Taxi Fee Function***********************/
//By Matthew
void taxiFee(int dayCount, double &taxiTotal, double &taxiAllowed)
{
    char cont;
    int days;
    //check if taxi was used
    cout<<"Was a taxi used at all during your business trip?"<<endl;
    cout<<"Type 'Y' for yes or 'N' for no: ";
    cin>>cont;
    //input validation
    while (cont !='y' && cont !='Y' && cont !='n' && cont !='N')
    {
        cout<<"ERROR: INVALID INPUT."<<endl;
        cout<<"Was a taxi used at all during your business trip?"<<endl;
        cout<<"Type 'Y' for yes or 'N' for no: ";
        cin>>cont;
    }
    //if yes get number of days used for taxi and total taxi fare
    if (cont == 'y' || cont == 'Y')
    {
        cout<<"How many days did you take a taxi? ";
        cin>>days;
        while (days < 1 || days > dayCount)
        {
            cout<<"ERROR: Must be an integer of atleast 1 and no more then total days spent on trip."<<endl;
            cout<<"How many days did you take a taxi? ";
            cin>>days;
        }
        cout<<"How much did you spend in total on taxi fare? $";
        cin>>taxiTotal;
        taxiAllowed = days * 10.0;
    }
    //if no taxi total/allowed is 0
    else if (cont == 'n' || cont == 'N')
    {
        taxiTotal = 0.0;
        taxiAllowed = 0.0;
    }
}
/***********************Conference/Seminar Registration Fees Function***********************/
//By Min
double getSeminarFees()
{
    double registrationFee;
    /* Get: Conference and/or seminar registration fees */
    cout << "What was the total amount of any conference or seminar registration fees? $";
    cin >> registrationFee;
    
    /* Validate: Input */
    while (registrationFee < 0.0)
    {
        cout << "Invalid input. The registration fee can not be negative."<<endl;
        cout << "What was the total amount of any conference or seminar registration fees? $";
        cin >> registrationFee;
    }
    /* Return: registrationFees */
    return registrationFee;
}
/***********************Hotel Expenses Function***********************/
//By Min
void hotelTotal(int dayCount, double &totalHotelCost, double &allowedHotel)
{
    int nights = (dayCount - 1),
    numbHotels,
    nightCount = 0,
    nightsPerHotel[10];
    char answer;
    double hotelRate,
    hRate[nights],
    totalPerNight[nights];
    //calculate total allowed hotel expenses
    allowedHotel = nights * 90;
    //check if stayed at more than 1 hotel
    cout<<"Did you stay at one hotel for the entire trip?"<<endl;
    cout<<"Type 'Y' for yes and 'N' for no: ";
    cin>>answer;
    //if yes get nightly rate and calculate total hotel expenses
    if (answer == 'y' || answer == 'Y')
    {
        cout<<"How much was the nightly rate of the hotel? $";
        cin>>hotelRate;
        while (hotelRate < 0.0)
        {
            cout<<"ERROR: Cannot be a negative value."<<endl;
            cout<<"How much was the nightly rate of the hotel? $";
            cin>>hotelRate;
        }
        totalHotelCost = nights * hotelRate;
    }
    //if no get number of hotels and rate for each. Then calculate total hotel expenses
    else if (answer == 'n' || answer == 'N')
    {
        cout<<"How many different hotels did you stay at?"<<endl;
        cin>>numbHotels;
        while (numbHotels > nights || numbHotels < 2)
        {
            cout<<"ERROR: The maximum number of hotels you are allowed to stay at is "<<nights<<"."<<endl;
            cout<<"The minimum number of hotels you can enter is 2."<<endl;
            cout<<"How many different hotels did you stay at?"<<endl;
            cin>>numbHotels;
        }
        for (int count = 0; count < numbHotels; count++)
        {
            cout<<"What was the nightly rate for hotel "<<count+1<<"? ";
            cin>>hRate[count];
            cout<<"How many nights did you stay at this hotel for?";
            cin>>nightsPerHotel[count];
            while (nightsPerHotel[count] < 1)
            {
                cout<<"ERROR: INVALID INPUT."<<endl;
                cout<<"How many nights did you stay at this hotel for?";
                cin>>nightsPerHotel[count];
            }
        }
        for (int count = 0; count < numbHotels; count++)
        {
            nightCount += nightsPerHotel[count];
        }
        
        while (nightCount != nights)
        {
            cout<<"ERROR: Invalid Input."<<endl;
            cout<<"Total number of nights you entered that accrued from each hotel: "<<nightCount<<endl;
            cout<<"Total number of nights spent on trip: "<<nights<<endl;
            cout<<"The total number of nights you entered from each hotel stay does not equal the total number of nights spent on the trip."<<endl;
            nightCount = 0;
            for (int count = 0; count < numbHotels; count++)
            {
                cout<<"What was the nightly rate for hotel "<<count+1<<"? ";
                cin>>hRate[count];
                cout<<"How many nights did you stay at this hotel for?";
                cin>>nightsPerHotel[count];
                while (nightsPerHotel[count] < 1)
                {
                    cout<<"ERROR: INVALID INPUT."<<endl;
                    cout<<"How many nights did you stay at this hotel for?";
                    cin>>nightsPerHotel[count];
                }
            }
            for (int count = 0; count < numbHotels; count++)
            {
                nightCount += nightsPerHotel[count];
            }
        }
        
        for (int count = 0; count < numbHotels; count++)
        {
            totalPerNight[count] = hRate[count] * nightsPerHotel[count];
        }
        
        for (int count = 0; count < numbHotels; count++)
        {
            totalHotelCost += totalPerNight[count];
        }
        
    }
    
}
/***********************Meal Expenses Function***********************/
//By Dan
void mealTotal(int dayCount, int depHour, int depMinute, int arrHour, int arrMinute, double &allMealsTotal, double &allowedMealTotal)
{
    const int COLS = 3;
    string mealNames[3] = {"Breakfast", "Lunch", "Dinner"};
    
    double DayMealArray[dayCount][COLS],
    AllowedArray[dayCount][COLS],
    allowedExp[3] = {9.0, 12.0, 16.0},
    owedSavedVar;
    
    //loop through days
    for (int row = 0; row < dayCount; row++)
    {
        cout<<"------------------------"<<endl;
        cout<<"Meal Expenses for day "<<(row+1)<<":"<<endl;
        cout<<"------------------------"<<endl;
        //determine how many meals are allowed on day 1
        if (row == 0)
        {
            if (depHour >= 0 && depHour < 7)
            {
                cout<<"On the first day of your business trip you were allowed expenses for all 3 meals."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    cout<<"How much was "<<mealNames[col]<<"? $";
                    cin>>DayMealArray[row][col];
                    AllowedArray[row][col] = allowedExp[col];
                }
            }
            else if (depHour < 12)
            {
                cout<<"On the first day of your business trip you were allowed expenses for lunch and dinner."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    if (col == 0)
                    {
                        DayMealArray[row][col] = 0;
                        AllowedArray[row][col] = 0;
                        continue;
                    }
                    cout<<"How much was "<<mealNames[col]<<"? $";
                    cin>>DayMealArray[row][col];
                    AllowedArray[row][col] = allowedExp[col];
                }
            }
            else if (depHour < 18)
            {
                cout<<"On the first day of your business trip you were allowed expenses for only dinner."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    if (col == 0 || col == 1)
                    {
                        DayMealArray[row][col] = 0;
                        AllowedArray[row][col] = 0;
                        continue;
                    }
                    cout<<"How much was "<<mealNames[col]<<"? $";
                    cin>>DayMealArray[row][col];
                    AllowedArray[row][col] = allowedExp[col];
                }
            }
            else if (depHour >= 18 && depHour < 24)
            {
                cout<<"You do not qualify for any allowed expenses for any meals on the first day."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    DayMealArray[row][col] = 0;
                    AllowedArray[row][col] = 0;
                }
            }
        }
        //determine how many meals are allowed on final day
        else if (row == dayCount-1)
        {
            if (arrHour > 19)
            {
                cout<<"On the last day of your business trip you were allowed expenses for all 3 meals."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    cout<<"How much was "<<mealNames[col]<<"? $";
                    cin>>DayMealArray[row][col];
                    AllowedArray[row][col] = allowedExp[col];
                }
            }
            else if (arrHour > 13)
            {
                cout<<"On the last day of your business trip you were allowed expenses for lunch and dinner."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    if (col == 0)
                    {
                        DayMealArray[row][col] = 0;
                        AllowedArray[row][col] = 0;
                        continue;
                    }
                    cout<<"How much was "<<mealNames[col]<<"? $";
                    cin>>DayMealArray[row][col];
                    AllowedArray[row][col] = allowedExp[col];
                }
            }
            else if (arrHour > 8)
            {
                cout<<"On the last day of your business trip you were allowed expenses for only dinner."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    if (col == 0 || col == 1)
                    {
                        DayMealArray[row][col] = 0;
                        AllowedArray[row][col] = 0;
                        continue;
                    }
                    cout<<"How much was "<<mealNames[col]<<"? $";
                    cin>>DayMealArray[row][col];
                    AllowedArray[row][col] = allowedExp[col];
                }
            }
            else if (arrHour >= 0 && arrHour <= 8)
            {
                cout<<"You do not qualify for any allowed expenses for any meals on the last day."<<endl;
                for (int col = 0; col < COLS; col++)
                {
                    DayMealArray[row][col] = 0;
                    AllowedArray[row][col] = 0;
                }
            }
        }
        else
        {
            for (int col = 0; col < COLS; col++)
            {
                cout<<"How much was "<<mealNames[col]<<"? $";
                cin>>DayMealArray[row][col];
                AllowedArray[row][col] = allowedExp[col];
            }
        }
    }
    //add up total meal expense and allowed meal expenses and set variable
    for (int row = 0; row < dayCount; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            allMealsTotal += DayMealArray[row][col];
            allowedMealTotal += AllowedArray[row][col];
        }
    }
    //print meal table
    cout<<"--------------------------------------------------"<<endl;
    cout<<left<<setw(13)<<"Meals"<<"|";
    for (int row = 0; row < 3; row++)
    {
        cout<<left<<setw(11)<<mealNames[row]<<"|";
    }
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
    for (int row = 0; row < dayCount; row++)
    {
        cout<<left<<"Day "<<row+1<<setw(8)<<" Spent"<<"|";
        for (int col = 0; col < COLS; col++)
        {
            cout<<left<<"$"<<setw(10)<<DayMealArray[row][col]<<"|";
        }
        cout<<endl;
        cout<<left<<setw(13)<<"Allowed"<<"|";
        for (int col = 0; col < COLS; col++)
        {
            cout<<left<<"$"<<setw(10)<<AllowedArray[row][col]<<"|";
        }
        cout<<endl;
        cout<<left<<setw(13)<<"Owed/Saved"<<"|";
        for (int col = 0; col < COLS; col++)
        {
            owedSavedVar = AllowedArray[row][col] - DayMealArray[row][col];
            cout<<left<<"$"<<setw(10)<<owedSavedVar<<"|";
        }
        cout<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }
}
