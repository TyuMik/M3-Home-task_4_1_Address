
#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int flat;
public:
    /* Address(std::string city, std::string street, int house, int flat)
     {
         this->city = city;
         this->street = street;
         this->house = house;
         this->flat = flat;
     }*/
    void set_city(std::string city) {
        this->city = city;
    }
    void set_street(std::string street) {
        this->street = street;
    }
    void set_house(int house) {
        this->house = house;
    }
    void set_flat(int flat) {
        this->flat = flat;
    }
    std::string getNewAddress() {
          std::string new_address = city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
          return new_address;
     }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    std::ifstream input_data("in.txt");
    if (input_data.is_open()) {
        
        int N, house, flat;
        std::string city, street;

        input_data >> N;

        Address* input_address = new Address[N];

        for (int i = 0; i < N; i++) {
            input_data >> city >> street >> house >> flat;
            input_address[i].set_city(city);
            input_address[i].set_street(street);
            input_address[i].set_house(house);
            input_address[i].set_flat(flat);
        }
        
        input_data.close();
       
        std::ofstream output_data("out.txt");
        output_data << N << std::endl;
        for (int i = N-1; i >= 0; i--) {
            output_data << input_address[i].getNewAddress() << std::endl;
        }
        output_data.close();
        delete[] input_address;
    } 
    else {
        std::cout << "Ошибка! Не удалось открыть файл";
    }
    return 0;
}
