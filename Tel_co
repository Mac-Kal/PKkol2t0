#include <iostream>
#include <string>
#include <stdexcept>

class Operator {
public:
    explicit Operator(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

enum class StanTelefonu {
    Wlaczony,
    Wylaczony,
    Zablokowany
};

class Telefon {
public:
    Telefon(const std::string& numer, int bateria, StanTelefonu stan, const Operator& operatorInfo)
        : numer(numer), bateria(bateria), stan(stan), operatorInfo(operatorInfo) {
        if (stan == StanTelefonu::Zablokowany) {
            throw std::invalid_argument("Telefon nie może być utworzony w stanie zablokowanym.");
        }
    }

    virtual ~Telefon() = default;

    // Gettery
    std::string getNumer() const {
        return numer;
    }

    int getBateria() const {
        return bateria;
    }

    StanTelefonu getStan() const {
        return stan;
    }

    const Operator& getOperatorInfo() const {
        return operatorInfo;
    }

    // Oblicz czas działania telefonu
    virtual double obliczCzasDzialania() const {
        return 20.0 * bateria; // 20 min za każdy p. procentowy stanu baterii
    }

    // Operator +=
    Telefon& operator+=(int procent) {
        if (procent < 0) {
            // Rozładowanie baterii
            bateria += procent;
            if (bateria <= 0) {
                stan = StanTelefonu::Wylaczony;
                bateria = 0;
            }
        } else {
            // Doładowanie baterii
            bateria += procent;
            if (bateria > 100) {
                bateria = 100;
            }
        }
        return *this;
    }

protected:
    std::string numer;
    int bateria;
    StanTelefonu stan;
    const Operator& operatorInfo;
};

class SystemOperacyjny {
public:
    SystemOperacyjny(const std::string& nazwa, double kosztObliczeniowy)
        : nazwa(nazwa), kosztObliczeniowy(kosztObliczeniowy) {}

    std::string getNazwa() const {
        return nazwa;
    }

    double getKosztObliczeniowy() const {
        return kosztObliczeniowy;
    }

private:
    std::string nazwa;
    double kosztObliczeniowy;
};

class Smartfon : public Telefon {
public:
    Smartfon(const std::string& numer, int bateria, StanTelefonu stan, const Operator& operatorInfo,
             const SystemOperacyjny& system)
        : Telefon(numer, bateria, stan, operatorInfo), system(system) {}

    // Oblicz czas działania smartfona
    double obliczCzasDzialania() const override {
        return 20.0 - 10.0 * system.getKosztObliczeniowy() * bateria;
    }

private:
    const SystemOperacyjny& system;
};

int main() {
    Operator orange("Orange");
    SystemOperacyjny android("Android", 0.3);

    Telefon telefon1("123-456-789", 80, StanTelefonu::Wlaczony, orange);
    Smartfon smartfon1("987-654-321", 60, StanTelefonu::Wlaczony, orange, android);

    std::cout << "Czas działania telefonu: " << telefon1.obliczCzasDzialania() << " minut\n";
    std::cout << "Czas działania smartfona: " << smartfon1.obliczCzasDzialania() << " minut\n";

    telefon1 += 20; // Doładowanie baterii o 20%
    std::cout << "Stan baterii telefonu po doładowaniu: " << telefon1.getBateria() << "%\n";

    telefon1 += -30; // Rozładowanie baterii o 30%
    std::cout << "Stan baterii telefonu po rozładowaniu: " << telefon1.getBateria() << "%\n";

    return 0;
}
