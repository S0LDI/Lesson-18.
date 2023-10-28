#include <iostream>
#include <string>
#include <regex>

class IPAddress {
protected:
    std::string ipAddress;

public:
    IPAddress(const std::string& ip) : ipAddress(ip) {}

    void print() const {
        std::cout << ipAddress << std::endl;
    }
};

class IPAddressChecked : public IPAddress {
private:
    bool isValid;

public:
    IPAddressChecked(const std::string& ip) : IPAddress(ip) {
        isValid = isValidIP(ip);
    }

    void print() const {
        std::cout << ipAddress << " - " << (isValid ? "Правильно" : "Неправильно") << std::endl;
    }

private:
    bool isValidIP(const std::string& ip) {
        
        std::regex ipRegex("^\\b(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\\b");

        return std::regex_match(ip, ipRegex);
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    std::string ip1, ip2, ip3;

    std::cout << "Введіть IP-адресу 1: ";
    std::cin >> ip1;
    std::cout << "Введіть IP-адресу 2: ";
    std::cin >> ip2;
    std::cout << "Введіть IP-адресу 3: ";
    std::cin >> ip3;

    IPAddress ipObject(ip1);
    IPAddressChecked checkedIp1(ip1);
    IPAddressChecked checkedIp2(ip2);
    IPAddressChecked checkedIp3(ip3);

    std::cout << "IP-адреса 1: ";
    ipObject.print();
    std::cout << "IP-адреса 2: ";
    checkedIp1.print();
    std::cout << "IP-адреса 3: ";
    checkedIp2.print();
    std::cout << "IP-адреса 4: ";
    checkedIp3.print();

    return 0;
}
