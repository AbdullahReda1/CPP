#include <iostream>
using namespace std;


class Data {
    private:
        string CryptoMSG = "97F2A05A";
        int    Password  = 123       ;

    protected:
        float PublicData;
        int ProtectivID = 102;

        int getPassword(void) {
            return Password;
        }

        int inputPassword(void) {
            int pw;
            cout << "Enter the password" << endl;
            cin >> pw;
            return pw;
        }

        string getCryptoMSG(void) {
            return CryptoMSG;
        }

    public:
        void setPublicData(float d) {
            PublicData = d;
        }

        float getPublicData(void) {
            return PublicData;
        }
};

class BankData : public Data {
    private:
        bool checkPassword (int PW) {
            return (getPassword() == PW);
        }

    public:
        int getProtectivID(void) {
            return ProtectivID;
        }

        string getCryptoMSG (void){
            if(checkPassword (inputPassword()))
                return (Data::getCryptoMSG());
            else 
                return "NOT CORRECT";
        }
};


int main() {
    BankData b;

    b.setPublicData(5.06);
    b.getPublicData();

    b.getProtectivID();

    b.getCryptoMSG();

    return 0;
}