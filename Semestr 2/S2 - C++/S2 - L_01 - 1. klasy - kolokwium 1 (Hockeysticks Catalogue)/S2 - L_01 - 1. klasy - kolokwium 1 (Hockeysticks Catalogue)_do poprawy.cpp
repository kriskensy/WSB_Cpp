#include <iostream>
#include <string>

class Hockeystick
{
    public:
        Hockeystick() {}

        Hockeystick(std::string modelName, int modelNumber, float weight)
        : modelName(modelName), modelNumber(modelNumber), weight(weight) {}

        ~Hockeystick() {}

        void present()
        {
            std::cout << "Model: " << modelName << " Nr modelu: " << modelNumber << " Waga: " << weight << " gram." << std::endl; 
        }

        int getModelNumber() const
        {
            return modelNumber;
        }

        float getWeight() const
        {
            return weight;
        }

    private:
        std::string modelName;
        int modelNumber; //posłuży jako nr ID
        float weight;
};

class HockeystickCatalogue
{
    public:
        HockeystickCatalogue(int max)
        {
            array = new Hockeystick[max];
            hockeystickCounter = 0;
        }
//TODO:

/*
        void addHockeystick(std::string modelName, int modelNumber, float weight)
        {
            Hockeystick newOne = Hockeystick(modelName, modelNumber, weight);

            if (hockeystickCounter < max)
            {
                array[hockeystickCounter] = newOne;
                hockeystickCounter++;
            }
            int i = hockeystickCounter;
        } 

*/



        void addHockeystick(Hockeystick newOne)
        {
            int i = hockeystickCounter;
            while(i > 0 && (newOne.getWeight() > array[i-1].getWeight()
                || (newOne.getWeight() == array[i-1].getWeight())))
                {
                        array[i] = array[i-1];
                        i--;
                }
                    array[hockeystickCounter] = newOne;
                    hockeystickCounter++;
        }

//TODO:
/*
        void deleteHockeystick(int ID)
        {
            for (int i = 0; i < hockeystickCounter; i++)
            {
            if (array[i].getModelNumber() == ID)
            {
                for (int j = i; j < hockeystickCounter; j++)
                {
                    array[j] = array[j+1];
                }
                hockeystickCounter--;
            }
            }

        }
*/
        void presentCatalogue() const
        {
            for(int i = 0; i < hockeystickCounter; i++)
            {
                array[i].present();
            }
            std::cout << std::endl;
        }

    private:
        Hockeystick* array; //wsk na pierwszy element tablicy
        int hockeystickCounter;
};

int main()
{
    HockeystickCatalogue hockeysticks(5);

    Hockeystick h1("Grays", 20001, 450);
    hockeysticks.addHockeystick(h1);

    Hockeystick h2("Malik", 201, 520);
    hockeysticks.addHockeystick(h2);

    Hockeystick h3("Grays", 30001, 650);
    hockeysticks.addHockeystick(h3);

    Hockeystick h4("Malik", 84, 740);
    hockeysticks.addHockeystick(h4);

    Hockeystick h5("Malik", 401, 550);
    hockeysticks.addHockeystick(h5);

    hockeysticks.presentCatalogue();

//    hockeysticks.deleteHockeystick(201);
//    hockeysticks.deleteHockeystick(84);

    hockeysticks.presentCatalogue();
}