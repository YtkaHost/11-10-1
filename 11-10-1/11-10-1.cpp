#include <iostream>

class Bolt {
private:
    std::string head_size;
    std::string rod_shape;
    std::string thread_pitch;
    double durability;

    void set_head_size(std::string new_head_size) {
        head_size = new_head_size;
    }
    void set_rod_shape(std::string new_rod_shape) {
        rod_shape = new_rod_shape;
    }
    void set_thread_pitch(std::string new_thread_pitch) {
        thread_pitch = new_thread_pitch;
    }
    void set_durability(double new_durability) {
        durability = new_durability;
    }

public:
    std::string get_head_size() {
        return head_size;
    }
    std::string get_rod_shape() {
        return rod_shape;
    }
    std::string get_thread_pitch() {
        return thread_pitch;
    }
    double get_durability() {
        return durability;
    }

    void user_head_size() {
        int a;
        std::string b;
        std::cout << "Choose what head size you need:\n1 - Hex head\n2 - Round head\n3 - Carriage head" << std::endl;
        std::cin >> a;
        while (a < 1 || a > 3) {
            std::cout << "Invalid choice. Please choose again:" << std::endl;
            std::cin >> a;
        }
        switch (a) {
        case 1:
            b = "Hex head";
            break;
        case 2:
            b = "Round head";
            break;
        case 3:
            b = "Carriage head";
            break;
        }
        set_head_size(b);
    }

    void user_rod_shape() {
        int a;
        std::string b;
        std::cout << "Choose what rod shape you need:\n1 - Cylindrical Bolt\n2 - Hex Bolt\n3 - Cone Bolt" << std::endl;
        std::cin >> a;
        while (a < 1 || a > 3) {
            std::cout << "Invalid choice. Please choose again:" << std::endl;
            std::cin >> a;
        }
        switch (a) {
        case 1:
            b = "Cylindrical Bolt";
            break;
        case 2:
            b = "Hex Bolt";
            break;
        case 3:
            b = "Cone Bolt";
            break;
        }
        set_rod_shape(b);
    }

    void user_thread_pitch() {
        int a;
        std::string b;
        std::cout << "Choose what thread pitch you need:\n1 - Coarse Thread Bolt\n2 - Fine Thread Bolt\n3 - Right-Hand Thread Bolt" << std::endl;
        std::cin >> a;
        while (a < 1 || a > 3) {
            std::cout << "Invalid choice. Please choose again:" << std::endl;
            std::cin >> a;
        }
        switch (a) {
        case 1:
            b = "Coarse Thread Bolt";
            break;
        case 2:
            b = "Fine Thread Bolt";
            break;
        case 3:
            b = "Right-Hand Thread Bolt";
            break;
        }
        set_thread_pitch(b);
    }

    void user_durability() {
        int a;
        double b;
        std::cout << "Choose what durability you need:\n1 - Grade 12.9 Bolt\n2 - Grade 8 Bolt\n3 - Grade 5 Bolt" << std::endl;
        std::cin >> a;
        while (a < 1 || a > 3) {
            std::cout << "Invalid choice. Please choose again:" << std::endl;
            std::cin >> a;
        }
        switch (a) {
        case 1:
            b = 12.9;
            break;
        case 2:
            b = 8;
            break;
        case 3:
            b = 5;
            break;
        }
        set_durability(b);
    }

    double calculate_price() {
        double base_price = 10.0;
        double base_modifier = 1.0;
        if (head_size == "Hex head") {
            base_modifier += 0.1;
        }
        else if (head_size == "Round head") {
            base_modifier += 0.2;
        }
        else if (head_size == "Carriage head") {
            base_modifier += 0.3;
        }

        if (rod_shape == "Cylindrical Bolt") {
            base_modifier += 0.1;
        }
        else if (rod_shape == "Hex Bolt") {
            base_modifier += 0.2;
        }
        else if (rod_shape == "Cone Bolt") {
            base_modifier += 0.3;
        }

        if (thread_pitch == "Coarse Thread Bolt") {
            base_modifier += 0.1;
        }
        else if (thread_pitch == "Fine Thread Bolt") {
            base_modifier += 0.2;
        }
        else if (thread_pitch == "Right-Hand Thread Bolt") {
            base_modifier += 0.3;
        }

        if (durability == 12.9) {
            base_modifier += 0.3;
        }
        else if (durability == 8) {
            base_modifier += 0.2;
        }
        else if (durability == 5) {
            base_modifier += 0.1;
        }

        return base_price * base_modifier;
    }
};

int main() {
    Bolt bolt;

    bolt.user_head_size();
    bolt.user_rod_shape();
    bolt.user_thread_pitch();
    bolt.user_durability();

    double final_price = bolt.calculate_price();
    std::cout << "The final price of the bolt is: $" << final_price << std::endl;

    return 0;
}
