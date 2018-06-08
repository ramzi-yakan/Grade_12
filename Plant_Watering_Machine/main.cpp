#include <iostream>
#include <cstdlib>
#include <ctime>        //required library to keep track of time
#include <thread>       //required library to allow two functions to run simultaneously
#include <vector>       //required library for the use of vectors
#include <windows.h>    //required library to use of the Sleep command

using namespace std;

class Plant
{
    public:
    string type;        //identifies each of the plants the user is growing
    string colour;      //identifies the colour of each of the plants the user is growing
    int waterLevel;     //keeps track of how much water each of the plants have
    string health;      //describes the current state of each of the plants
    bool beingWatered = false;     //determines if each of the plants are currently being watered by the user
};

class Environment
{
    public:
    int temperature;    //identifies the current temperature
    string weather;     //identifies the current weather
};

class Tank
{
    public:
    int nozzleSize = 10;    //identifies how much water goes into the plant (per hour) (10% of the plant's maximum water capacity by default)
    int waterVolume = 100;  //identifies what percentage of the tank is filled with water
};

Plant plants[4];        //a singular row of the 4 plants in this program
bool program = true;    //determines whether the program should still be running

void displayListOfCommands()    //menu with all of the different commands, along with brief descriptions of each,  that the user can choose from to input into the program
{
    cout << "'water plants' - water the plants'" << endl;
    cout << "'tank water level' - display the water level in the tank" << endl;
    cout << "'refill tank' - refill the tank" << endl;
    cout << "'adjust nozzle size' - adjust how much water is released when the machine waters the plants" << endl;
    cout << "'plant stats' - display the water levels and conditions of the plants" << endl;
    cout << "'exit' - quit the program" << endl;
}

void setPlantProperties()
{
    for (int i = 0; i < 4; i++)
    {
        int randomNumberType = rand() % 6;   //dummy variable that helps determine what each plant will be
        if (randomNumberType == 0)
        {
            plants[i].type = "Lily";
        }
        else if (randomNumberType == 1)
        {
            plants[i].type = "Daisy";
        }
        else if (randomNumberType == 2)
        {
            plants[i].type = "Tulip";
        }
        else if (randomNumberType == 3)
        {
            plants[i].type = "Protea";
        }
        else if (randomNumberType == 4)
        {
            plants[i].type = "Pansy";
        }
        else
        {
            plants[i].type = "Hibiscus";
        }
        int randomNumberColour = rand() % 6;    //dummy variable that helps determine what colour each plant will be
        if (randomNumberColour == 0)
        {
            plants[i].colour = "White";
        }
        else if (randomNumberColour == 1)
        {
            plants[i].colour = "Pink";
        }
        else if (randomNumberColour == 2)
        {
            plants[i].colour = "Red";
        }
        else if (randomNumberColour == 3)
        {
            plants[i].colour = "Yellow";
        }
        else if (randomNumberColour == 4)
        {
            plants[i].colour = "Orange";
        }
        else
        {
            plants[i].colour = "Violet";
        }
        plants[i].waterLevel = 50;             //each plant will start with 50% water
        plants[i].health = "okay - might need to water soon";   //what 50% water means for the plant's overall health
    }
}

void setupTemperature (Environment & _environment)
{
    _environment.temperature = rand() % 35;    //the initial temperature will be between -5°C and 30°C
    _environment.temperature-=5;
}

void setupWeather(Environment & _environment)
{
    int weatherCode = rand() % 3;       //dummy variable that helps determine the weather
    if (weatherCode == 0)
    {
        _environment.weather = "Sunny";
    }
    else if (weatherCode == 1)
    {
        _environment.weather = "Cloudy";
    }
    else
    {
        _environment.weather = "Rainy";
    }
}

void userInput()
{
    Tank _tank;
    Environment _environment;
    string input;   //variable that represents the command that the user inputs
    vector<string> subInput;    //vector that splits the inputted command into singular words
    int position;   //variable that represents the position of each inddividual word in the vector
    cout << "Welcome to the Plant Watering Machine Program" << endl;
    cout << "Type 'help' for a list of commands" << endl;
    while(true)
    {
        //reset input
        position = 0;
        subInput.clear();
        input.clear();
        cout << endl;
        cout << "Farm:\\>";
        getline(cin,input);     //get inputted command from user
        for(unsigned int i = 0; i < input.size(); i++)
        {
            input[i] = tolower(input[i]);   //converts all uppercase letters in inputted command to lowercase
        }
        //generate substrings
        input += " ";
        while(input.find_first_not_of(" ",position) != string::npos)
        {
            subInput.push_back(input.substr(input.find_first_not_of(" ",position),
                                input.find(" ",input.find_first_not_of(" ",position))
                                - input.find_first_not_of(" ",position)));
            position = input.find(" ",input.find_first_not_of(" ",position));
        }
        input.erase(input.size()-1);
        cout << endl;
        if (subInput.size() == 1)   //if inputted command contains one word
        {
            if (subInput[0] == "help")
            {
                displayListOfCommands();
            }
            else if (subInput[0] == "exit")
            {
                program = false;
            }
            else   //i.e. if inputted command was not one of the options the user had
            {
                cout << "Nice try Mr. Lauder." << endl;
            }
        }
        else if (subInput.size() == 2)  //if inputted command contains two words
        {
            if ((subInput[0] == "water") and (subInput[1] == "plants"))
            {
                if (_environment.weather == "Rainy")
                {
                    cout << "It is raining. Let the rain water the plants for you." << endl;
                }
                else
                {
                    int chosenPlant = 0;    //variable that represents the user's choice of plant to water
                    cout << endl;
                    cout << "Which plant would you like to water?" << endl;
                    for (int i = 0; i < 4; i++)
                    {
                        cout << "Plant " << i+1 << endl;
                        cout << "Type: " << plants[i].type << endl;
                        cout << "Colour: " << plants[i].colour << endl;
                        cout << endl;
                    }
                    //check to make sure the user's response is valid
                    while ((chosenPlant < 1) or (chosenPlant > 4) or (cin.fail() == true))
                    {
                        cin >> chosenPlant;
                        if ((chosenPlant < 1) or (chosenPlant > 4) or (cin.fail() == true))
                        {
                            cout << "Nice try Mr. Lauder." << endl;
                            if (cin.fail() == true)
                            {
                                cin.clear();
                                cin.ignore();
                                chosenPlant = 0;
                            }
                        }
                        cin.ignore();
                    }
                    if (plants[chosenPlant-1].waterLevel > 0)
                    {
                        plants[chosenPlant-1].beingWatered = true;    //the chosen plant is now being watered
                    }
                    else
                    {
                        cout << "You left this plant unwatered for too long. It is now dead." << endl;
                    }
                }
            }
            else if ((subInput[0] == "refill") and (subInput[1] == "tank"))
            {
                if (_tank.waterVolume != 100)
                {
                    _tank.waterVolume = 100;    //completely refills the tank with water
                    cout << "Tank refilled." << endl;
                }
                else
                {
                    cout << "Tank already full." << endl;   //the tank is already completely filled with water
                }
            }
            else if ((subInput[0] == "plant") and (subInput[1] == "stats"))
            {
                //display each plant's water level and health
                for (int i = 0; i < 4; i++)
                {
                    cout << "Plant " << i+1 << endl;
                    cout << "Water Level: " << plants[i].waterLevel << "%" << endl;
                    cout << "Health: " << plants[i].health << endl;
                    cout << endl;
                }
            }
            else
            {
                cout << "Nice try Mr. Lauder." << endl;
            }
        }
        else if (subInput.size() == 3)      //if inputted command contains three words
        {
            if ((subInput[0] == "tank") and (subInput[1] == "water") and (subInput[2] == "level"))
            {
                cout << "Water Level in Tank: " << _tank.waterVolume << "%" << endl;    //displays how much water is currently in the tank
            }
            else if ((subInput[0] == "adjust") and (subInput[1] == "nozzle") and (subInput[2] == "size"))
            {
                //the user gets to choose how much water goes into the plant (per hour)
                cout << "How much water do you want released from the tank every hour? (Tank is currently releasing " << _tank.nozzleSize << "% of its maximum capacity per hour.)" << endl;
                cout << "Enter a number between 1 and 100." << endl;
                cin >> _tank.nozzleSize;
                cout << "New nozzle size set." << endl;
                cin.ignore();
            }
            else
            {
                cout << "Nice try Mr. Lauder." << endl;
            }
        }
        else    //i.e. if inputted command was not one of the options the user had AND was longer than three words
        {
            cout << "Nice try Mr. Lauder." << endl;
        }
        cout << endl << endl << endl;
        if (program == false)
        {
            break;
        }
    }
}

void timer()
{
    clock();    //starts the timer for the program
    Tank _tank;
    Environment _environment;
    setupTemperature(_environment);
    setPlantProperties();
    while (program == true)
    {
            if (clock()/CLOCKS_PER_SEC % 60 == 0)   //i.e. one minute in real life has passed, which is the equivalent of one hour in this program
            {
                setupWeather(_environment);
                int tempChangeSign = rand() % 2;    //dummy variable that determines whether the temperature will increase or decrease
                int tempChangeValue = rand() % 4;   //dummy variable that determines how much the temperature will increase or decrease (temperature can increase or decrease as much as 3°C per hour
                if ((tempChangeSign == 0) and (_environment.temperature < 30))
                {
                    _environment.temperature += tempChangeValue;    //same as saying _environment.temperature = _environment.temperature + tempChangeValue;
                }
                else if ((tempChangeSign == 1) and (_environment.temperature > 0))
                {
                    _environment.temperature -= tempChangeValue;    //same as saying _environment.temperature = _environment.temperature - tempChangeValue;
                }
                for (int i = 0; i < 4; i++)     //the beginning of a series of checks for each plant
                {
                    if (_environment.weather == "Rainy")
                    {
                        if (plants[i].waterLevel <= 90)    //if it is raining and the tank isn't close to full
                        {
                            plants[i].waterLevel += _tank.nozzleSize-10;    //increase water in the tank by 10% of the tank's maximum capacity
                        }
                        else     //if it is raining and the tank is close to full
                        {
                            plants[i].waterLevel = 100;    //fill up the rest of the tank
                        }
                    }
                    else if (plants[i].beingWatered == true) //if any of the plants are being watered
                    {
                        plants[i].waterLevel += _tank.nozzleSize;   //the amount of water in each of the watered plants increases by whatever rate water goes into the plant (per hour)
                        _tank.waterVolume -= _tank.nozzleSize;
                    }
                    else
                    {
                        plants[i].waterLevel -= 10;
                    }
                    //series of if statements that determine what impact the new water level of each plant has on the overall health of each plant
                    if (plants[i].waterLevel <= 0)
                    {
                        plants[i].waterLevel = 0;
                        plants[i].health = "dead";
                    }
                    else if ((plants[i].waterLevel > 0) and (plants[i].waterLevel <= 20))
                    {
                        plants[i].health = "dying - desperately needs water";
                    }
                    else if ((plants[i].waterLevel > 20) and (plants[i].waterLevel <= 40))
                    {
                        plants[i].health = "unhealthy - needs water";
                    }
                    else if ((plants[i].waterLevel = 40) and (plants[i].waterLevel <= 60))
                    {
                        plants[i].health = "okay - might need to water soon";
                    }
                    else if ((plants[i].waterLevel > 60) and (plants[i].waterLevel <= 80))
                    {
                        plants[i].health = "healthy";
                    }
                    else
                    {
                        plants[i].health = "very healthy";
                    }
                }
                if (_environment.weather == "Rainy")   //when it starts raining
                {
                    cout << endl;
                    cout << "It has started to rain. Let the rain water the plants for you." << endl;
                    for (int i = 0; i < 4; i++)
                    {
                            plants[i].beingWatered = false;     //plants are no longer being watered MANUALLY (rain in this program is the equivalent of the plants being watered automatically)
                    }
                }
                if (_environment.temperature <= 0) //when it becomes too cold to water the plants
                {
                    cout << endl;
                    cout << "It is now too cold to water the plants." << endl;
                    for (int i = 0; i < 4; i++)
                    {
                        plants[i].beingWatered = false;     //plants are no longer being watered
                    }
                }
                if (_tank.waterVolume == 0)
                {
                    cout << endl;
                    cout << "The tank is out of water to water the plants. Refill the tank to continue watering the plants." << endl;
                    for (int i = 0; i < 4; i++)
                    {
                        plants[i].beingWatered = false;     //plants are no longer being watered
                    }
                }
                Sleep(1000);    //jump a second in time in order to not be stuck in a loop, since modulos only check int values
                cout << endl << endl;
                //display current conditions
                cout << "Current Conditions:" << endl;
                cout << "Temperature: " << _environment.temperature <<" degrees Celcius" << endl;
                cout << "Weather: " << _environment.weather << endl;
                cout << endl << endl;
                cout << "Farm:\\>";
            }
    }
}

int main()
{
    srand(time(NULL));     //allows for even more randomness than just regular rand() (yay!)
    //the two threads that will allow the two main functions of this program to run simultaneously
    thread _userInput(userInput);
    thread _timer(timer);
    //.join forces int main wait for both functions/threads to finish before moving on
    _userInput.join();
    _timer.join();
    return 0;
}
