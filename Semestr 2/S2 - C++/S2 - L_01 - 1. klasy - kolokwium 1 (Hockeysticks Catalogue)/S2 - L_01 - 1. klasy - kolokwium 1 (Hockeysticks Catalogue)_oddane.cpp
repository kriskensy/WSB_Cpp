#include <iostream>

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

        void addHockeystick(std::string modelName, int modelNumber, float weight)
        {
            Hockeystick newOne = Hockeystick(modelName, modelNumber, weight);
            int i = hockeystickCounter;

//TODO: licznik nie rośnie, do poprawy
            while(i > 0)
            {
                if (newOne.getWeight() > array[i-1].getWeight())
                {
                        array[i] = array[i-1];
                        i--;
                } else if (newOne.getWeight() == array[i-1].getWeight()) {

                         array[i] = array[i-1];
                        i--;
                }
                    array[hockeystickCounter] = newOne;
                    hockeystickCounter++;
            }
        }


        void deleteHockeystick(int modelNumber)
        {
            for(int i = 0; i < hockeystickCounter; i++)
            {
                if (array[i].getModelNumber() == modelNumber) {
                for (int j = i; j < hockeystickCounter; j++) {
                    array[j] = array[j+1];
                }
                hockeystickCounter--;
            }
            }

        }

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

    hockeysticks.addHockeystick("Grays", 20001, 450);
    hockeysticks.addHockeystick("Malik", 201, 520);
    hockeysticks.addHockeystick("Grays", 30001, 650);
    hockeysticks.addHockeystick("TK", 84, 740);
    hockeysticks.addHockeystick("Malik", 401, 550);

    hockeysticks.presentCatalogue();

//    hockeysticks.deleteHockeystick(h3);
//    hockeysticks.deleteHockeystick(h5);

    hockeysticks.presentCatalogue();
}