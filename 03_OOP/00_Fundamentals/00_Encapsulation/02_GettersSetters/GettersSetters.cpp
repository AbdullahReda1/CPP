#include <iostream>
using namespace std;


class Data {
    // Only accessible inside Data
    private:
        string CryptoMSG = "97F2A05A";
        int    Password  = 123;

    // Accessible in Data and BankData
    protected:
        float PublicData;
        int ProtectivID = 102;

        // Accessible in Data and BankData
        int getPassword(void) {
            return Password;
        }

        // Accessible in Data and BankData
        int inputPassword(void) {
            int pw;
            cout << "Enter the password" << endl;
            cin >> pw;
            return pw;
        }

        // Accessible in Data and BankData
        string getCryptoMSG(void) {
            return CryptoMSG;
        }

    // Accessible from anywhere (main, etc.)
    public:
        void setPublicData(float d) {
            PublicData = d;
        }

        // Accessible from anywhere (main, etc.)
        float getPublicData(void) {
            return PublicData;
        }
};

class BankData : public Data {
    // Only accessible inside BankData
    private:
        bool checkPassword (int PW) {
            // Calls protected getPassword() from Data
            return (getPassword() == PW);
        }

    // Accessible from anywhere (main, etc.)
    public:
        int getProtectivID(void) {
            // Accesses protected member from Data
            return ProtectivID;
        }

        // Accessible from anywhere (main, etc.)
        string getCryptoMSG (void){
            // Calls private checkPassword() from DataBank and protected inputPassword() from Data
            if(checkPassword (inputPassword()))
                // Calls protected getCryptoMSG() from Data
                return (Data::getCryptoMSG());
            else 
                return "NOT CORRECT";
        }
};


int main() {
    BankData b;

    // NOte: when using getters we use cout to print the returned value.
    // Set and get public data
    b.setPublicData(5.06);
    cout << "Public Data: " << b.getPublicData() << endl;

    // Get protected ID
    cout << "ProtectivID: " << b.getProtectivID() << endl;

    // Try to get CryptoMSG (requires password)
    cout << "CryptoMSG: " << b.getCryptoMSG() << endl;

    return 0;
}