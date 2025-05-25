#include <iostream>
#include <string>
using namespace std;

class ComputerComponent {
protected:
    string manufacturer;
    int yearOfManufacture;

public:
    void setManufacturer(const string& m) { manufacturer = m; }
    void setYearOfManufacture(int y) { yearOfManufacture = y; }

    string getManufacturer() const { return manufacturer; }
    int getYearOfManufacture() const { return yearOfManufacture; }

    virtual void print(ostream& os) const = 0;
    virtual string getType() const = 0;
    virtual ~ComputerComponent() = default;
};

class StorageDevice : public ComputerComponent {
protected:
    long long capacity;

public:
    void setCapacity(long long c) { capacity = c; }
    long long getCapacity() const { return capacity; }
};

class HDD : public StorageDevice {
public:
    void print(ostream& os) const override {
        os << "Type: HDD\n"
            << "Manufacturer: " << manufacturer << "\n"
            << "Year: " << yearOfManufacture << "\n"
            << "Capacity: " << capacity << " bytes\n";
    }

    string getType() const override {
        return "HDD";
    }
};

class SSD : public StorageDevice {
private:
    long long tbw;
    long long bytesWritten;

public:
    void setTBW(long long t) { tbw = t; }
    void setBytesWritten(long long b) { bytesWritten = b; }

    long long getTBW() const { return tbw; }
    long long getBytesWritten() const { return bytesWritten; }

    void print(ostream& os) const override {
        os << "Type: SSD\n"
            << "Manufacturer: " << manufacturer << "\n"
            << "Year: " << yearOfManufacture << "\n"
            << "Capacity: " << capacity << " bytes\n"
            << "TBW: " << tbw << " bytes\n"
            << "Bytes Written: " << bytesWritten << " bytes\n";
    }

    string getType() const override {
        return "SSD";
    }
};

class Monitor : public ComputerComponent {
private:
    double diagonal;
    int resolutionWidth;
    int resolutionHeight;
    int refreshRate;

public:
    void setDiagonal(double d) { diagonal = d; }
    void setResolution(int width, int height) {
        resolutionWidth = width;
        resolutionHeight = height;
    }
    void setRefreshRate(int rate) { refreshRate = rate; }

    void print(ostream& os) const override {
        os << "Type: Monitor\n"
            << "Manufacturer: " << manufacturer << "\n"
            << "Year: " << yearOfManufacture << "\n"
            << "Diagonal: " << diagonal << " inches\n"
            << "Resolution: " << resolutionWidth << "x" << resolutionHeight << "\n"
            << "Refresh Rate: " << refreshRate << " Hz\n";
    }

    string getType() const override {
        return "Monitor";
    }
};

class Processor : public ComputerComponent {
private:
    string model;
    int coreCount;
    double baseFrequency;

public:
    void setModel(const string& m) { model = m; }
    void setCoreCount(int c) { coreCount = c; }
    void setBaseFrequency(double f) { baseFrequency = f; }

    void print(ostream& os) const override {
        os << "Type: Processor\n"
            << "Manufacturer: " << manufacturer << "\n"
            << "Year: " << yearOfManufacture << "\n"
            << "Model: " << model << "\n"
            << "Cores: " << coreCount << "\n"
            << "Base Frequency: " << baseFrequency << " GHz\n";
    }

    string getType() const override {
        return "Processor";
    }
};

int main() {
    SSD ssd;
    ssd.setManufacturer("Samsung");
    ssd.setYearOfManufacture(2022);
    ssd.setCapacity(512LL * 1024 * 1024 * 1024);
    ssd.setTBW(300LL * 1024 * 1024 * 1024);
    ssd.setBytesWritten(120LL * 1024 * 1024 * 1024);

    Processor cpu;
    cpu.setManufacturer("Intel");
    cpu.setYearOfManufacture(2021);
    cpu.setModel("i7-10700K");
    cpu.setCoreCount(8);
    cpu.setBaseFrequency(3.8);

    Monitor monitor;
    monitor.setManufacturer("Dell");
    monitor.setYearOfManufacture(2020);
    monitor.setDiagonal(24.0);
    monitor.setResolution(1920, 1080);
    monitor.setRefreshRate(60);

    HDD hdd;
    hdd.setManufacturer("Western Digital");
    hdd.setYearOfManufacture(2019);
    hdd.setCapacity(1024LL * 1024 * 1024 * 1024);

    ssd.print(cout);
    cout << endl;
    cpu.print(cout);
    cout << endl;
    monitor.print(cout);
    cout << endl;
    hdd.print(cout);
    cout << endl;

    return 0;
}
